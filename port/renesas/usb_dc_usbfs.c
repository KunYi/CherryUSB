#include "usbd_core.h"
#include "usb_ra_regs.h"


#define USBD_BASE (g_usbdev_bus[0].reg_base)
#define RA_USBFS   ((ra_usbfs_t *)(USBD_BASE))
#ifndef USBD_IRQHandler
#define USBD_IRQHandler USBD_IRQHandler
#endif

#ifndef USB_NUM_BIDIR_ENDPOINTS
#define USB_NUM_BIDIR_ENDPOINTS 10
#endif

/* Endpoint state */
struct usb_dc_ep_state {
    uint16_t ep_mps;    /* Endpoint max packet size */
    uint8_t ep_type;    /* Endpoint type */
    uint8_t ep_stalled; /* Endpoint stall flag */
    uint8_t *xfer_buf;
    uint32_t xfer_len;
    uint32_t actual_xfer_len;
};

/* Driver state */
struct rausb_udc {
    __attribute__((aligned(4))) struct usb_setup_packet setup;
    volatile uint8_t dev_addr;
    struct usb_dc_ep_state in_ep[USB_NUM_BIDIR_ENDPOINTS];  /*!< IN endpoint parameters*/
    struct usb_dc_ep_state out_ep[USB_NUM_BIDIR_ENDPOINTS]; /*!< OUT endpoint parameters */
} g_rausb_udc;

static inline uint16_t rausb_ep0_maxpacket(void) {
    return (RA_USBFS->DCPMAXP & USB_MAXP);
}

static inline uint16_t rausb_ep_maxpacket(uint8_t ep) {
    RA_USBFS->PIPESEL = ep;
    return (RA_USBFS->PIPEMAXP & 0x1FF);
}

static inline void rausb_module_usbfs(const uint8_t mode) {
    if (mode) {
        MSTPCRB &= ~STOP_MODULE_USBFS;
        RA_USBFS->SYSCFG |= USB_SCKE;
        while(1) {
            if (RA_USBFS->SYSCFG & USB_SCKE)
              break;
        }
    }
    else {
        RA_USBFS->SYSCFG &= ~USB_SCKE;
        MSTPCRB |= STOP_MODULE_USBFS;
    }
}

static inline void rausb_set_mode(const uint8_t mode)
{
    if (mode == USB_OTG_MODE_HOST) {
        RA_USBFS->SYSCFG |= (USB_DCFM | USB_DRPD);
    } else if (mode == USB_OTG_MODE_DEVICE) {
        RA_USBFS->SYSCFG &= ~(USB_DCFM | USB_DRPD);
    }
}

static inline void rausb_start(const uint8_t mode) {
    if (mode) {
        RA_USBFS->SYSCFG |= USB_USBE;
    } else {
        RA_USBFS->SYSCFG &= ~(USB_USBE);
    }
}

static inline void rausb_fifo_bw16(void) {
    RA_USBFS->CFIFOSEL = USB_MBW_16;
    RA_USBFS->D0FIFOSEL = USB_MBW_16;
    RA_USBFS->D1FIFOSEL = USB_MBW_16;
}

statuc inline void rausb_connect(uint8_t mode) {
    if (mode) {
        RA_USBFS->SYSCFG |= USB_DPRPU;
    } else {
        RA_USBFS->SYSCFG &= (~USB_DPRPU);
    }
}

__WEAK void usb_dc_low_level_init(void)
{
}

__WEAK void usb_dc_low_level_deinit(void)
{
}

int usb_dc_init(uint8_t busid)
{
    memset(&g_rausb_udc, 0, sizeof(struct rausb_udc));
    usb_dc_low_level_init();

    rausb_module_usbfs(true);
    rausb_set_mode(USB_OTG_MODE_DEVICE);
    RA_USBFS->PHYSLEW = 0xEu; /* */
    rausb_start(true);
    rausb_fifo_bw16();

    /* set interrupt */
    RA_USBFS->INTSTS0 = 0;
    RA_USBFS->INTSTS1 = 0;
    RA_USBFS->INTENB0 = (USB_BEMPE | USB_BRDYE | USB_VBSE | USB_DVSE | USB_CTRE);
    RA_USBFS->DPUSR0R_FS &= ~(1u<<4); /* set FIXPHY0 equal zero, Normal mode */
    /* check the device attached status */
    if (RA_USBFS->INTSTS0 & USB_VBSTS) {
        rausb_connect(true); /* pull up on for D+ */
    }
    return 0;
}

int usb_dc_deinit(uint8_t busid)
{
    return 0;
}

int usbd_set_address(uint8_t busid, const uint8_t addr)
{
    uint8_t usbd_addr = (RA_USBFS->USBADDR & 0x7Fu);
    if ((usbd_addr == 0) && (usbd_addr != addr)) {
        g_rausb_udc.dev_addr = usbd_addr;
    }
    return 0;
}

int usbd_ep_open(uint8_t busid, const struct usb_endpoint_descriptor *ep)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep->bEndpointAddress);

    if (USB_EP_DIR_IS_OUT(ep->bEndpointAddress)) {
        g_rausb_udc.out_ep[ep_idx].ep_mps = USB_GET_MAXPACKETSIZE(ep->wMaxPacketSize);
        g_rausb_udc.out_ep[ep_idx].ep_type = USB_GET_ENDPOINT_TYPE(ep->bmAttributes);
    } else {
        g_rausb_udc.in_ep[ep_idx].ep_mps = USB_GET_MAXPACKETSIZE(ep->wMaxPacketSize);
        g_rausb_udc.in_ep[ep_idx].ep_type = USB_GET_ENDPOINT_TYPE(ep->bmAttributes);
    }

    if (ep_idx > 0) {
        RA_USBFS->PIPESEL = ep_idx;
        RA_USBFS->PIPEMAXP = g_rausb_udc.out_ep[ep_idx].ep_mps;
        RA_USBFS->PIPE_CTR[ep_idx - 1] = USB_ACLRM | USB_SQCLR;
        RA_USBFS->PIPE_CTR[ep_idx - 1] = 0;
        switch(g_rausb_udc.in_ep[ep_idx].ep_type) {
        case USB_ENDPOINT_TYPE_BULK:
            RA_USBFS->PIPECFG =
            break;
        case USB_ENDPOINT_TYPE_ISOCHRONOUS:
            break;
        case USB_ENDPOINT_TYPE_INTERRUPT:
            break;
        }
    }
    return 0;
}

int usbd_ep_close(uint8_t busid, const uint8_t ep)
{
    return 0;
}

int usbd_ep_set_stall(uint8_t busid, const uint8_t ep)
{
    usb_dc_ep_state *ep_state;
    const uint8_t epid = USB_EP_GET_IDX(ep);

    if (USB_EP_DIR_IS_OUT(ep)) {
        ep_state = &g_rausb_udc.out_ep[ep_idx];
    } else {
        ep_state = &g_rausb_udc.in_ep[ep_idx];
    }

    if (epid == 0) {
        RA_USBFS->DCPCTR &= ~(USB_PID);
        RA_USBFS->DCPCTR |= USB_PID_STALL;
    } else {
        RA_USBFS->PIPE_CTR[epid - 1] &= ~(USB_PID);
        RA_USBFS->PIPE_CTR[epid - 1] |= USB_PID_STALL;
    }
    ep_state->ep_stalled = 1;
    return 0;
}

int usbd_ep_clear_stall(uint8_t busid, const uint8_t ep)
{
    usb_dc_ep_state *ep_state;
    const uint8_t epid = USB_EP_GET_IDX(ep);

    if (USB_EP_DIR_IS_OUT(ep)) {
        ep_state = &g_rausb_udc.out_ep[ep_idx];
    } else {
        ep_state = &g_rausb_udc.in_ep[ep_idx];
    }

    if (epid == 0) {
        RA_USBFS->DCPCTR &= ~(USB_PID_STALL);

    } else {
        RA_USBFS->PIPE_CTR[epid - 1] &= ~(USB_PID_STALL);
    }
    ep_state->ep_stalled = 0;
    return 0;
}

int usbd_ep_is_stalled(uint8_t busid, const uint8_t ep, uint8_t *stalled)
{
    usb_dc_ep_state *ep_state;
    const uint8_t epid = USB_EP_GET_IDX(ep);

    if (USB_EP_DIR_IS_OUT(ep)) {
        ep_state = &g_rausb_udc.out_ep[ep_idx];
    } else {
        ep_state = &g_rausb_udc.in_ep[ep_idx];
    }

    if (epid == 0) {
        ep_state->ep_stalled = (RA_USBFS->DCPCTR & USB_PID_STALL) ? 1 : 0;
        if (stalled) {
            *stalled = ep_state->ep_stalled;
        }
    } else {
        ep_state->ep_stalled = (RA_USBFS->PIPE_CTR[epid - 1] & USB_PID_STALL) ? 1 : 0;
        if (stalled) {
            *stalled =  ep_state->ep_stalled;
        }
    }
    return 0;
}

static __inline void rausb_write_packet(volatile const uint16_t *reg, uint8_t const *ptr, const uint32_t len) {
        while (len >= 2) {
            *((uint16_t *)reg) = *((uint16_t *)ptr);
            ptr += 2;
            len -= 2;
        }
        if (len != 0)
            *((uint8_t *)reg)  = *ptr;
}

int usbd_ep_start_write(uint8_t busid, const uint8_t ep, const uint8_t *data, uint32_t data_len)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);
    uint32_t tmp;

    if (!data && data_len) {
        return -1;
    }

    g_rausb_udc.in_ep[ep_idx].xfer_buf = (uint8_t *)data;
    g_rausb_udc.in_ep[ep_idx].xfer_len = data_len;
    g_rausb_udc.in_ep[ep_idx].actual_xfer_len = 0;
    if (ep_idx == 0) {
        const uint32_t mps = rausb_ep0_maxpacket();
        uint32_t len = (data_len > mps) ? mps : data_len;
        rausb_write_packet(RA_USBFS->CFIFO, data, len);
        if (len < mps) {
             /* launch SIE transmitter, when len == mps will auto start */
            RA_USBFS->CFIFOCTR |= USB_BVAL;
        }
        g_rausb_udc.in_ep[ep_idx].xfer_len = len;

    }
    else {
        const uint32_t mps = rausb_ep_maxpacket();
        const uint32_t len = (data_len > mps) ? mps : data_len;
        if (len == 0) {
            /* zero packet */
        }
    }
    return 0;
}


int usbd_ep_start_read(uint8_t busid, const uint8_t ep, uint8_t *data, uint32_t data_len)
{
    uint8_t ep_idx = USB_EP_GET_IDX(ep);

    if (!data && data_len) {
        return -1;
    }

    g_rausb_udc.out_ep[ep_idx].xfer_buf = (uint8_t *)data;
    g_rausb_udc.out_ep[ep_idx].xfer_len = data_len;
    g_rausb_udc.out_ep[ep_idx].actual_xfer_len = 0;
    if (ep_idx == 0) {

    }
    else {

    }
    return 0;
}

uint8_t usbd_get_port_speed(uint8_t busid, const uint8_t port)
{
    /* Device controller only support full-speed */
    return USB_SPEED_FULL;
}

static inline void rausb_handle_vbus_interrupt(const uint16_t status) {
    if (status & USB_VBINT) {
        rausb_connect((status & USB_VBSTS)); /* pull up on/off for D+ */
    }
}

static inline void rausb_handle_device_state_change(const uint16_t status) {
    if (status & USB_DVST) {
        /* usb bus reset */
        if ((status & USB_DVSQ) == USB_DS_DFLT) {
            usbd_event_reset_handler(0);
        }

        else if (status & USB_DVSQ == USB_DS_ADDS) {
            // usbd_set_address(0, 0);
        }
    }
}

static inline int rausb_handle_control_transfer(const uint16_t status) {
    if (status & USB_CTRT) {
        const uint16_t ctsq = status & USB_CTSQ;
        if (ctsq == USB_CS_IDST) {
        } else if ((ctsq == USB_CS_RDDS) || (ctsq == USB_CS_WRDS) || (ctsq == USB_CS_WRND)) {
            if (status & USB_VALID) {
                RA_USBFS->INTSTS0 &= ~(USB_VALID);

                g_rausb_udc.setup.bmRequestType = (RA_USBFS->USBREQ & USB_BMREQUESTTYPE);
                g_rausb_udc.setup.bRequest = 0;
                g_rausb_udc.setup.wValue = RA_USBFS->USBVAL;
                g_rausb_udc.setup.wIndex = RA_USBFS->USBINDX;
                g_rausb_udc.setup.wLength = RA_USBFS->USBLENG;
                if (ctsq == USB_CS_RDDS)
                    return 0;
            }
        }
    }
    return 1;
}

static inline void rausb_handle_buffer_empty(const uint16_t status) {
    if (status & USB_BEMP) {
        const uint16_t bemps = RA_USBFS->BEMPSTS;
        RA_USBFS->BEMPSTS = 0;
        if (bemps & USB_BEMP0) {
            uint8_t ep_idx = 0;
            /* for ctrl pipe */
            if (g_rausb_udc.in_ep[ep_idx].xfer_len >= g_rausb_udc.in_ep[ep_idx].ep_mps) {
               g_rausb_udc.in_ep[ep_idx].xfer_len -= g_rausb_udc.in_ep[ep_idx].ep_mps;
               g_rausb_udc.in_ep[ep_idx].actual_xfer_len += g_rausb_udc.in_ep[ep_idx].ep_mps;
               ep0_tx_data_toggle ^= 1;
            } else {
                g_rausb_udc.in_ep[ep_idx].actual_xfer_len += g_rausb_udc.in_ep[ep_idx].xfer_len;
                g_rausb_udc.in_ep[ep_idx].xfer_len = 0;
                ep0_tx_data_toggle = true;
            }
            usbd_event_ep_in_complete_handler(0, ep_idx | 0x80u, g_rausb_udc.in_ep[ep_idx].actual_xfer_len);
        }
    }
}

static inline void rausb_handle_buffer_ready(const uint16_t status) {
    if (status & USB_BRDY) {

    }
}

void USBD_IRQHandler(void) {
    uint16_t status = RA_USBFS->INTSTS0;
    RA_USBFS->INTSTS0 &= ~(USB_BEMP | USB_BRDY | USB_VBINT | USB_DVST | USB_CTRT);
    rausb_handle_vbus_interrupt(status);
    rausb_handle_device_state_change(status);
    if (rausb_handle_control_transfer(status) == 0) {
        usbd_event_ep0_setup_complete_handler(0, &g_rausb_udc.setup);
    }
    rausb_handle_buffer_empty(status);
    rausb_handle_buffer_ready(status);
}
