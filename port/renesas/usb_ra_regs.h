#ifndef __USB_RA_REG_H__
#define __USB_RA_REG_H__
#include <stdint.h>

#define     __I     const volatile     /*!<Defines 'readonly' permissions     */
#define     __IO    volatile           /*!<Defines 'read / write' permissions */

/**
 * @brief R_USB_FS0_PIPE_TR [PIPE_TR] (Pipe Transaction Counter Registers)
 */
typedef struct ra_usb_pipe_tr_type_s {
    __IO uint16_t E;              /*!< (@ 0x00000000) Pipe Transaction Counter Enable Register                   */
    __IO uint16_t N;              /*!< (@ 0x00000002) Pipe Transaction Counter Register                          */
} ra_usbfs_pipe_tr_type_t, ra_usbhs_pipe_tr_type_t;

/**
 * @brief USB 2.0 Module (RA_USB_FS)
 */
typedef struct ra_usbfs_s {
    __IO uint16_t SYSCFG;         /*!< (@ 0x00000000) System Configuration Control Register                      */
    __IO uint16_t BUSWAIT;        /*!< (@ 0x00000002) CPU Bus Wait Register 				     */
    __I  uint16_t SYSSTS0;        /*!< (@ 0x00000004) System Configuration Status Register 0                     */
    __I  uint16_t PLLSTA;         /*!< (@ 0x00000006) PLL Status Register                                        */
    __IO uint16_t DVSTCTR0;       /*!< (@ 0x00000008) Device State Control Register 0                            */
    __I  uint16_t RESERVED01;
    __IO uint16_t TESTMODE;       /*!< (@ 0x0000000C) USB Test Mode Register                                     */
    __I  uint16_t RESERVED02;
    __I  uint32_t RESERVED03;
    __IO uint32_t CFIFO;	      /*!< (@ 0x00000014) CFIFO Port Register                                        */
    __IO uint32_t D0FIFO;         /*!< (@ 0x00000018) D0FIFO Port Register                                       */
    __IO uint32_t D1FIFO;         /*!< (@ 0x0000001C) D1FIFO Port Register                                       */
    __IO uint16_t CFIFOSEL;       /*!< (@ 0x00000020) CFIFO Port Select Register                                 */
    __IO uint16_t CFIFOCTR;       /*!< (@ 0x00000022) CFIFO Port Control Register                                */
    __I  uint32_t RESERVED04;
    __IO uint16_t D0FIFOSEL;      /*!< (@ 0x00000028) D0FIFO Port Select Register                                */
    __IO uint16_t D0FIFOCTR;      /*!< (@ 0x0000002A) D0FIFO Port Control Register                               */
    __IO uint16_t D1FIFOSEL;      /*!< (@ 0x0000002C) D1FIFO Port Select Register                                */
    __IO uint16_t D1FIFOCTR;      /*!< (@ 0x0000002E) D1FIFO Port Control Register                               */
    __IO uint16_t INTENB0;        /*!< (@ 0x00000030) Interrupt Enable Register 0                                */
    __IO uint16_t INTENB1;        /*!< (@ 0x00000032) Interrupt Enable Register 1                                */
    __I  uint16_t RESERVED05;
    __IO uint16_t BRDYENB;        /*!< (@ 0x00000036) BRDY Interrupt Enable Register                             */
    __IO uint16_t NRDYENB;        /*!< (@ 0x00000038) NRDY Interrupt Enable Register                             */
    __IO uint16_t BEMPENB;        /*!< (@ 0x0000003A) BEMP Interrupt Enable Register                             */
    __IO uint16_t SOFCFG;         /*!< (@ 0x0000003C) SOF Output Configuration Register                          */
    __IO uint16_t PHYSET;         /*!< (@ 0x0000003E) PHY Setting Register                                       */
    __IO uint16_t INTSTS0;        /*!< (@ 0x00000040) Interrupt Status Register 0                                */
    __IO uint16_t INTSTS1;        /*!< (@ 0x00000042) Interrupt Status Register 1                                */
    __I  uint16_t RESERVED06;
    __IO uint16_t BRDYSTS;        /*!< (@ 0x00000046) BRDY Interrupt Status Register                             */
    __IO uint16_t NRDYSTS;        /*!< (@ 0x00000048) NRDY Interrupt Status Register                             */
    __IO uint16_t BEMPSTS;        /*!< (@ 0x0000004A) BEMP Interrupt Status Register                             */
    __IO uint16_t FRMNUM;         /*!< (@ 0x0000004C) Frame Number Register                                      */
    __IO uint16_t UFRMNUM;        /*!< (@ 0x0000004E) uFrame Number Register                                     */
    __IO uint16_t USBADDR;        /*!< (@ 0x00000050) USB Address Register                                       */
    __I  uint16_t RESERVED07;
    __IO uint16_t USBREQ;         /*!< (@ 0x00000054) USB Request Type Register                                  */
    __IO uint16_t USBVAL;         /*!< (@ 0x00000056) USB Request Value Register                                 */
    __IO uint16_t USBINDX;        /*!< (@ 0x00000058) USB Request Index Register                                 */
    __IO uint16_t USBLENG;        /*!< (@ 0x0000005A) USB Request Length Register                                */
    __IO uint16_t DCPCFG;         /*!< (@ 0x0000005C) DCP Configuration Register                                 */
    __IO uint16_t DCPMAXP;        /*!< (@ 0x0000005E) DCP Maximum Packet Size Register                           */
    __IO uint16_t DCPCTR;         /*!< (@ 0x00000060) DCP Control Register                                       */
    __I  uint16_t RESERVED08;
    __IO uint16_t PIPESEL;        /*!< (@ 0x00000064) Pipe Window Select Register                                */
    __I  uint16_t RESERVED09;
    __IO uint16_t PIPECFG;        /*!< (@ 0x00000068) Pipe Configuration Register                                */
    __I  uint16_t RESERVED10;
    __IO uint16_t PIPEMAXP;       /*!< (@ 0x0000006C) Pipe Maximum Packet Size Register                          */
    __IO uint16_t PIPEPERI;       /*!< (@ 0x0000006E) Pipe Cycle Control Register                                */
    __IO uint16_t PIPE_CTR[9];    /*!< (@ 0x00000070) Pipe [0..8] Control Register                               */
    __I  uint16_t RESERVED11;
    __I  uint32_t RESERVED12[3];
    __IO ra_usbfs_pipe_tr_type_t PIPE_TR[5]; /*!< (@ 0x00000090) Pipe Transaction Counter Registers                         */
    __I  uint32_t RESERVED13[3];
    __IO uint16_t USBBCCTRL0;     /*!< (@ 0x000000B0) BC Control Register 0                                      */
    __I  uint16_t RESERVED14;
    __I  uint32_t RESERVED15[4];
    __IO uint16_t UCKSEL;         /*!< (@ 0x000000C4) USB Clock Selection Register                               */
    __I  uint16_t RESERVED16;
    __I  uint32_t RESERVED17;
    __IO uint16_t USBMC;          /*!< (@ 0x000000CC) USB Module Control Register                                */
    __I  uint16_t RESERVED18;
    __IO uint16_t DEVADD[10];     /*!< (@ 0x000000D0) Device Address Configuration Register                      */
    __I  uint32_t RESERVED19[3];
    __IO uint32_t PHYSLEW;        /*!< (@ 0x000000F0) PHY Cross Point Adjustment Register                        */
    __I  uint32_t RESERVED20[3];
    __IO uint16_t LPCTRL;         /*!< (@ 0x00000100) Low Power Control Register                                 */
    __IO uint16_t LPSTS;          /*!< (@ 0x00000102) Low Power Status Register                                  */
    __I  uint32_t RESERVED21[15];
    __IO uint16_t BCCTRL;         /*!< (@ 0x00000140) Battery Charging Control Register                          */
    __I  uint16_t RESERVED22;
    __IO uint16_t PL1CTRL1;       /*!< (@ 0x00000144) Function L1 Control Register 1                             */
    __IO uint16_t PL1CTRL2;       /*!< (@ 0x00000146) Function L1 Control Register 2                             */
    __IO uint16_t HL1CTRL1;       /*!< (@ 0x00000148) Host L1 Control Register 1                                 */
    __IO uint16_t HL1CTRL2;       /*!< (@ 0x0000014A) Host L1 Control Register 2                                 */
    __I  uint32_t RESERVED23[5];
    __I  uint32_t DPUSR0R;        /*!< (@ 0x00000160) Deep Standby USB Transceiver Control/Pin Monitor Register */
    __IO uint32_t DPUSR1R;        /*!< (@ 0x00000164) Deep Standby USB Suspend/Resume Interrupt Register        */
    __IO uint16_t DPUSR2R;        /*!< (@ 0x00000168) Deep Standby USB Suspend/Resume Interrupt Register        */
    __IO uint16_t DPUSRCR;        /*!< (@ 0x0000016A) Deep Standby USB Suspend/Resume Command Register          */
    __I  uint32_t RESERVED24[165];
    __IO uint32_t DPUSR0R_FS;     /*!< (@ 0x00000400) Deep Software Standby USB Transceiver Control/Pin Monitor Register */
    __IO uint32_t DPUSR1R_FS;     /*!< (@ 0x00000404) Deep Software Standby USB Suspend/Resume Interrupt Register */
} ra_usbfs_t;                     /*!< Size = 1032 (0x408)                                                      */

/**
 * @brief USB 2.0 High-Speed Module (RA_USB_HS)
 */
typedef struct ra_usbhs_s {
    __IO uint16_t SYSCFG;         /*!< (@ 0x00000000) System Configuration Control Register                      */
    __IO uint16_t BUSWAIT;        /*!< (@ 0x00000002) CPU Bus Wait Register                                      */
    __I  uint16_t SYSSTS0;        /*!< (@ 0x00000004) System Configuration Status Register                       */
    __I  uint16_t PLLSTA;         /*!< (@ 0x00000006) PLL Status Register                                        */
    __IO uint16_t DVSTCTR0;       /*!< (@ 0x00000008) Device State Control Register 0                            */
    __I  uint16_t RESERVED00;
    __IO uint16_t TESTMODE;       /*!< (@ 0x0000000C) USB Test Mode Register                                     */
    __I  uint16_t RESERVED01;
    __I  uint32_t RESERVED02;
    __IO uint32_t CFIFO;          /*!< (@ 0x00000014) CFIFO Port Register                                        */
    __IO uint32_t D0FIFO;         /*!< (@ 0x00000018) D0FIFO Port Register                                       */
    __IO uint32_t D1FIFO;         /*!< (@ 0x0000001C) D1FIFO Port Register                                       */
    __IO uint16_t CFIFOSEL;       /*!< (@ 0x00000020) CFIFO Port Select Register                                 */
    __IO uint16_t CFIFOCTR;       /*!< (@ 0x00000022) CFIFO Port Control Register                                */
    __I  uint32_t RESERVED03;
    __IO uint16_t D0FIFOSEL;      /*!< (@ 0x00000028) D0FIFO Port Select Register                                */
    __IO uint16_t D0FIFOCTR;      /*!< (@ 0x0000002A) D0FIFO Port Control Register                               */
    __IO uint16_t D1FIFOSEL;      /*!< (@ 0x0000002C) D1FIFO Port Select Register                                */
    __IO uint16_t D1FIFOCTR;      /*!< (@ 0x0000002E) D1FIFO Port Control Register                               */
    __IO uint16_t INTENB0;        /*!< (@ 0x00000030) Interrupt Enable Register 0                                */
    __IO uint16_t INTENB1;        /*!< (@ 0x00000032) Interrupt Enable Register 1                                */
    __I  uint16_t RESERVED04;
    __IO uint16_t BRDYENB;        /*!< (@ 0x00000036) BRDY Interrupt Enable Register                             */
    __IO uint16_t NRDYENB;        /*!< (@ 0x00000038) NRDY Interrupt Enable Register                             */
    __IO uint16_t BEMPENB;        /*!< (@ 0x0000003A) BEMP Interrupt Enable Register                             */
    __IO uint16_t SOFCFG;         /*!< (@ 0x0000003C) SOF Pin Configuration Register                             */
    __IO uint16_t PHYSET;         /*!< (@ 0x0000003E) PHY Setting Register                                       */
    __IO uint16_t INTSTS0;        /*!< (@ 0x00000040) Interrupt Status Register 0                                */
    __IO uint16_t INTSTS1;        /*!< (@ 0x00000042) Interrupt Status Register 1                                */
    __I  uint16_t RESERVED05;
    __IO uint16_t BRDYSTS;        /*!< (@ 0x00000046) BRDY Interrupt Status Register                             */
    __IO uint16_t NRDYSTS;        /*!< (@ 0x00000048) NRDY Interrupt Status Register                             */
    __IO uint16_t BEMPSTS;        /*!< (@ 0x0000004A) BEMP Interrupt Status Register                             */
    __IO uint16_t FRMNUM;         /*!< (@ 0x0000004C) Frame Number Register                                      */
    __IO uint16_t UFRMNUM;        /*!< (@ 0x0000004E) uFrame Number Register                                     */
    __IO uint16_t USBADDR;        /*!< (@ 0x00000050) USB Address Register                                       */
    __I  uint16_t RESERVED06;
    __IO uint16_t USBREQ;         /*!< (@ 0x00000054) USB Request Type Register                                  */
    __IO uint16_t USBVAL;         /*!< (@ 0x00000056) USB Request Value Register                                 */
    __IO uint16_t USBINDX;        /*!< (@ 0x00000058) USB Request Index Register                                 */
    __IO uint16_t USBLENG;        /*!< (@ 0x0000005A) USB Request Length Register                                */
    __IO uint16_t DCPCFG;         /*!< (@ 0x0000005C) DCP Configuration Register                                 */
    __IO uint16_t DCPMAXP;        /*!< (@ 0x0000005E) DCP Maximum Packet Size Register                           */
    __IO uint16_t DCPCTR;         /*!< (@ 0x00000060) DCP Control Register                                       */
    __I  uint16_t RESERVED07;
    __IO uint16_t PIPESEL;        /*!< (@ 0x00000064) Pipe Window Select Register                                */
    __I  uint16_t RESERVED08;
    __IO uint16_t PIPECFG;        /*!< (@ 0x00000068) Pipe Configuration Register                                */
    __IO uint16_t PIPEBUF;        /*!< (@ 0x0000006A) Pipe Buffer Register                                       */
    __IO uint16_t PIPEMAXP;       /*!< (@ 0x0000006C) Pipe Maximum Packet Size Register                          */
    __IO uint16_t PIPEPERI;       /*!< (@ 0x0000006E) Pipe Cycle Control Register                                */
    __IO uint16_t PIPE_CTR[9];    /*!< (@ 0x00000070) PIPE Control Register                                      */
    __I  uint16_t RESERVED09;
    __I  uint32_t RESERVED10[3];
    __IO ra_usbhs_pipe_tr_type_t PIPE_TR[5]; /*!< (@ 0x00000090) Pipe Transaction Counter Registers              */
    __I  uint32_t RESERVED11[11];
    __IO uint16_t DEVADD[10];     /*!< (@ 0x000000D0) Device Address Configuration Register                      */
    __I  uint32_t RESERVED12[7];
    __IO uint16_t LPCTRL;         /*!< (@ 0x00000100) Low Power Control Register                                 */
    __IO uint16_t LPSTS;          /*!< (@ 0x00000102) Low Power Status Register                                  */
    __I  uint32_t RESERVED13[15];
    __IO uint16_t BCCTRL;         /*!< (@ 0x00000140) Battery Charging Control Register                          */
    __I  uint16_t RESERVED14;
    __IO uint16_t PL1CTRL1;       /*!< (@ 0x00000144) Function L1 Control Register 1                             */
    __IO uint16_t PL1CTRL2;       /*!< (@ 0x00000146) Function L1 Control Register 2                             */
    __IO uint16_t HL1CTRL1;       /*!< (@ 0x00000148) Host L1 Control Register 1                                 */
    __IO uint16_t HL1CTRL2;       /*!< (@ 0x0000014A) Host L1 Control Register 2                                 */
    __I  uint32_t RESERVED15;
    __IO uint16_t PHYTRIM1;       /*!< (@ 0x00000150) PHY Timing Register 1                                      */
    __IO uint16_t PHYTRIM2;       /*!< (@ 0x00000152) PHY Timing Register 2                                      */
    __I  uint32_t RESERVED16[3];
    __I  uint32_t DPUSR0R;        /*!< (@ 0x00000160) Deep Standby USB Transceiver Control/Pin Monitor Register  */
    __IO uint32_t DPUSR1R;        /*!< (@ 0x00000164) Deep Standby USB Suspend/Resume Interrupt Register         */
    __IO uint16_t DPUSR2R;        /*!< (@ 0x00000168) Deep Standby USB Suspend/Resume Interrupt Register         */
    __IO uint16_t DPUSRCR;        /*!< (@ 0x0000016A) Deep Standby USB Suspend/Resume Command Register           */
} ra_usbhs_t;                     /*!< Size = 364 (0x16c)                                                        */

/* System Configuration Control Register */
 #define USB_SCKE                  (0x0400U) /* b10: USB clock enable */
 #define USB_CNEN                  (0x0100U) /* b8: Single end receiver */
 #define USB_HSE                   (0x0080U) /* b7: Hi-speed enable */
 #define USB_DCFM                  (0x0040U) /* b6: Function select */
 #define USB_DRPD                  (0x0020U) /* b5: D+/D- pull down control */
 #define USB_DPRPU                 (0x0010U) /* b4: D+ pull up control */
 #define USB_DMRPU                 (0x0008U) /* b3: D- pull up control *//* For low speed */
 #define USB_USBE                  (0x0001U) /* b0: USB module enable */
 #define USB_OTG_MODE_HOST         (1u)      /* DCFM -- Host controller   */
 #define USB_OTG_MODE_DEVICE       (0u)      /* DCFM -- Device controller */

/* CPU Bus Wait Register */
 #define USB_BWAIT                 (0x0F0FU) /* b3-0: Bus wait bit */
 #define USB_BWAIT_15              (0x0F0FU) /* 15 wait (access cycle 17) */
 #define USB_BWAIT_14              (0x0F0EU) /* 14 wait (access cycle 16) */
 #define USB_BWAIT_13              (0x0F0DU) /* 13 wait (access cycle 15) */
 #define USB_BWAIT_12              (0x0F0CU) /* 12 wait (access cycle 14) */
 #define USB_BWAIT_11              (0x0F0BU) /* 11 wait (access cycle 13) */
 #define USB_BWAIT_10              (0x0F0AU) /* 10 wait (access cycle 12) */
 #define USB_BWAIT_9               (0x0F09U) /*  9 wait (access cycle 11) */
 #define USB_BWAIT_8               (0x0F08U) /*  8 wait (access cycle 10) */
 #define USB_BWAIT_7               (0x0F07U) /*  7 wait (access cycle  9) */
 #define USB_BWAIT_6               (0x0F06U) /*  6 wait (access cycle  8) */
 #define USB_BWAIT_5               (0x0F05U) /*  5 wait (access cycle  7) */
 #define USB_BWAIT_4               (0x0F04U) /*  4 wait (access cycle  6) */
 #define USB_BWAIT_3               (0x0F03U) /*  3 wait (access cycle  5) */
 #define USB_BWAIT_2               (0x0F02U) /*  2 wait (access cycle  4) */
 #define USB_BWAIT_1               (0x0F01U) /*  1 wait (access cycle  3) */
 #define USB_BWAIT_0               (0x0F00U) /*  0 wait (access cycle  2) */
 #define USB_BWAIT_B11_B8_WRITE    (0x0F00U) /*  b11-b8: Reserved bit write */

/* System Configuration Status Register */
 #define USB_OVCMON                (0xC000U) /* b15-14: Over-current monitor */
 #define USB_OVCBIT                (0x8000U) /* b15-14: Over-current bit */
 #define USB_HTACT                 (0x0040U) /* b6: USB Host Sequencer Status Monitor */
 #define USB_SOFEA                 (0x0020U) /* b5: SOF monitor */
 #define USB_IDMON                 (0x0004U) /* b2: ID-pin monitor */
 #define USB_LNST                  (0x0003U) /* b1-0: D+, D- line status */
 #define USB_SE1                   (0x0003U) /* SE1 */
 #define USB_FS_KSTS               (0x0002U) /* Full-Speed K State */
 #define USB_FS_JSTS               (0x0001U) /* Full-Speed J State */
 #define USB_LS_JSTS               (0x0002U) /* Low-Speed J State */
 #define USB_LS_KSTS               (0x0001U) /* Low-Speed K State */
 #define USB_SE0                   (0x0000U) /* SE0 */

/* PLL Status Register */
 #define USB_PLLLOCK               (0x0001U)

/* Device State Control Register */
 #define USB_HNPBTOA               (0x0800U) /* b11: Host negotiation protocol (BtoA) */
 #define USB_EXICEN                (0x0400U) /* b10: EXICEN output terminal control */
 #define USB_VBUSEN                (0x0200U) /* b9: VBUS output terminal control */
 #define USB_WKUP                  (0x0100U) /* b8: Remote wakeup */
 #define USB_RWUPE                 (0x0080U) /* b7: Remote wakeup sense */
 #define USB_USBRST                (0x0040U) /* b6: USB reset enable */
 #define USB_RESUME                (0x0020U) /* b5: Resume enable */
 #define USB_UACT                  (0x0010U) /* b4: USB bus enable */
 #define USB_RHST                  (0x0007U) /* b2-0: Reset handshake status */
 #define USB_HSPROC                (0x0004U) /* HS handshake processing */
 #define USB_HSMODE                (0x0003U) /* Hi-Speed mode */
 #define USB_FSMODE                (0x0002U) /* Full-Speed mode */
 #define USB_LSMODE                (0x0001U) /* Low-Speed mode */
 #define USB_UNDECID               (0x0000U) /* Undecided */

/* Test Mode Register */
 #define USB_UTST                  (0x000FU) /* b3-0: Test mode */
 #define USB_H_TST_F_EN            (0x000DU) /* HOST TEST FORCE ENABLE */
 #define USB_H_TST_PACKET          (0x000CU) /* HOST TEST Packet */
 #define USB_H_TST_SE0_NAK         (0x000BU) /* HOST TEST SE0 NAK */
 #define USB_H_TST_K               (0x000AU) /* HOST TEST K */
 #define USB_H_TST_J               (0x0009U) /* HOST TEST J */
 #define USB_H_TST_NORMAL          (0x0000U) /* HOST Normal Mode */
 #define USB_P_TST_PACKET          (0x0004U) /* PERI TEST Packet */
 #define USB_P_TST_SE0_NAK         (0x0003U) /* PERI TEST SE0 NAK */
 #define USB_P_TST_K               (0x0002U) /* PERI TEST K */
 #define USB_P_TST_J               (0x0001U) /* PERI TEST J */
 #define USB_P_TST_NORMAL          (0x0000U) /* PERI Normal Mode */

/* CFIFO/DxFIFO Port Select Register */
 #define USB_RCNT                  (0x8000U) /* b15: Read count mode */
 #define USB_REW                   (0x4000U) /* b14: Buffer rewind */
 #define USB_DCLRM                 (0x2000U) /* b13: Automatic buffer clear mode */
 #define USB_DREQE                 (0x1000U) /* b12: DREQ output enable */
 #define USB_MBW                   (0x0C00U) /* b10: Maximum bit width for FIFO access */
 #define USB_MBW_32                (0x0800U) /* FIFO access : 32bit */
 #define USB_MBW_16                (0x0400U) /* FIFO access : 16bit */
 #define USB_MBW_8                 (0x0000U) /* FIFO access : 8bit */
 #define USB_BIGEND                (0x0100U) /* b8: Big endian mode */
 #define USB_FIFO_BIG              (0x0100U) /* Big endian */
 #define USB_FIFO_LITTLE           (0x0000U) /* Little endian */
 #define USB_ISEL                  (0x0020U) /* b5: DCP FIFO port direction select */
 #define USB_CURPIPE               (0x000FU) /* b2-0: PIPE select */

/* CFIFO/DxFIFO Port Control Register */
 #define USB_BVAL                  (0x8000U) /* b15: Buffer valid flag */
 #define USB_BCLR                  (0x4000U) /* b14: Buffer clear */
 #define USB_FRDY                  (0x2000U) /* b13: FIFO ready */
 #define USB_DTLN                  (0x0FFFU) /* b11-0: FIFO data length */

/* Interrupt Enable Register 0 */
 #define USB_VBSE                  (0x8000U) /* b15: VBUS interrupt */
 #define USB_RSME                  (0x4000U) /* b14: Resume interrupt */
 #define USB_SOFE                  (0x2000U) /* b13: Frame update interrupt */
 #define USB_DVSE                  (0x1000U) /* b12: Device state transition interrupt */
 #define USB_CTRE                  (0x0800U) /* b11: Control transfer stage transition interrupt */
 #define USB_BEMPE                 (0x0400U) /* b10: Buffer empty interrupt */
 #define USB_NRDYE                 (0x0200U) /* b9: Buffer notready interrupt */
 #define USB_BRDYE                 (0x0100U) /* b8: Buffer ready interrupt */

/* Interrupt Enable Register 1 */
 #define USB_OVRCRE                (0x8000U) /* b15: Over-current interrupt */
 #define USB_BCHGE                 (0x4000U) /* b14: USB bus change interrupt */
 #define USB_DTCHE                 (0x1000U) /* b12: Detach sense interrupt */
 #define USB_ATTCHE                (0x0800U) /* b11: Attach sense interrupt */
 #define USB_L1RSMENDE             (0x0200U) /* b9: L1 resume completion interrupt */
 #define USB_LPMENDE               (0x0100U) /* b8: LPM transaction completion interrupt */
 #define USB_EOFERRE               (0x0040U) /* b6: EOF error interrupt */
 #define USB_SIGNE                 (0x0020U) /* b5: SETUP IGNORE interrupt */
 #define USB_SACKE                 (0x0010U) /* b4: SETUP ACK interrupt */
 #define USB_PDDETINTE             (0x0001U) /* b0: PDDET detection interrupt */

/* BRDY Interrupt Enable/Status Register */
 #define USB_BRDY9                 (0x0200U) /* b9: PIPE9 */
 #define USB_BRDY8                 (0x0100U) /* b8: PIPE8 */
 #define USB_BRDY7                 (0x0080U) /* b7: PIPE7 */
 #define USB_BRDY6                 (0x0040U) /* b6: PIPE6 */
 #define USB_BRDY5                 (0x0020U) /* b5: PIPE5 */
 #define USB_BRDY4                 (0x0010U) /* b4: PIPE4 */
 #define USB_BRDY3                 (0x0008U) /* b3: PIPE3 */
 #define USB_BRDY2                 (0x0004U) /* b2: PIPE2 */
 #define USB_BRDY1                 (0x0002U) /* b1: PIPE1 */
 #define USB_BRDY0                 (0x0001U) /* b1: PIPE0 */

/* NRDY Interrupt Enable/Status Register */
 #define USB_NRDY9                 (0x0200U) /* b9: PIPE9 */
 #define USB_NRDY8                 (0x0100U) /* b8: PIPE8 */
 #define USB_NRDY7                 (0x0080U) /* b7: PIPE7 */
 #define USB_NRDY6                 (0x0040U) /* b6: PIPE6 */
 #define USB_NRDY5                 (0x0020U) /* b5: PIPE5 */
 #define USB_NRDY4                 (0x0010U) /* b4: PIPE4 */
 #define USB_NRDY3                 (0x0008U) /* b3: PIPE3 */
 #define USB_NRDY2                 (0x0004U) /* b2: PIPE2 */
 #define USB_NRDY1                 (0x0002U) /* b1: PIPE1 */
 #define USB_NRDY0                 (0x0001U) /* b1: PIPE0 */

/* BEMP Interrupt Enable/Status Register */
 #define USB_BEMP9                 (0x0200U) /* b9: PIPE9 */
 #define USB_BEMP8                 (0x0100U) /* b8: PIPE8 */
 #define USB_BEMP7                 (0x0080U) /* b7: PIPE7 */
 #define USB_BEMP6                 (0x0040U) /* b6: PIPE6 */
 #define USB_BEMP5                 (0x0020U) /* b5: PIPE5 */
 #define USB_BEMP4                 (0x0010U) /* b4: PIPE4 */
 #define USB_BEMP3                 (0x0008U) /* b3: PIPE3 */
 #define USB_BEMP2                 (0x0004U) /* b2: PIPE2 */
 #define USB_BEMP1                 (0x0002U) /* b1: PIPE1 */
 #define USB_BEMP0                 (0x0001U) /* b0: PIPE0 */

/* SOF Pin Configuration Register */
 #define USB_TRNENSEL              (0x0100U) /* b8: Select transaction enable period */
 #define USB_BRDYM                 (0x0040U) /* b6: BRDY clear timing */
 #define USB_INTL                  (0x0020U) /* b5: Interrupt sense select */
 #define USB_EDGESTS               (0x0010U) /* b4:  */
 #define USB_SOFMODE               (0x000CU) /* b3-2: SOF pin select */
 #define USB_SOF_125US             (0x0008U) /* SOF 125us Frame Signal */
 #define USB_SOF_1MS               (0x0004U) /* SOF 1ms Frame Signal */
 #define USB_SOF_DISABLE           (0x0000U) /* SOF Disable */

 #define USB_HSEB                  (0x8000U) /* b15: CL only mode bit */

 #define USB_REPSTART              (0x0800U) /* b11: Terminator adjustment forcible starting bit */
 #define USB_REPSEL                (0x0300U) /* b9-8: Terminator adjustment cycle setting */
 #define USB_REPSEL_128            (0x0300U) /* 128 sec */
 #define USB_REPSEL_64             (0x0200U) /* 64 sec */
 #define USB_REPSEL_16             (0x0100U) /* 16 sec */
 #define USB_REPSEL_NONE           (0x0000U) /* - */
 #define USB_CLKSEL                (0x0030U) /* b5-4: System clock setting */
 #define USB_CLKSEL_24             (0x0030U) /* 24MHz */
 #define USB_CLKSEL_20             (0x0020U) /* 20MHz */
 #define USB_CLKSEL_48             (0x0010U) /* 48MHz */
 #define USB_CLKSEL_12             (0x0000U) /* 12MHz */
 #define USB_CDPEN                 (0x0008U) /* b3: Charging downstream port enable */
 #define USB_PLLRESET              (0x0002U) /* b1: PLL reset control */
 #define USB_DIRPD                 (0x0001U) /* b0: Power down control */

/* Interrupt Status Register 0 */
 #define USB_VBINT                 (0x8000U) /* b15: VBUS interrupt */
 #define USB_RESM                  (0x4000U) /* b14: Resume interrupt */
 #define USB_SOFR                  (0x2000U) /* b13: SOF update interrupt */
 #define USB_DVST                  (0x1000U) /* b12: Device state transition interrupt */
 #define USB_CTRT                  (0x0800U) /* b11: Control transfer stage transition interrupt */
 #define USB_BEMP                  (0x0400U) /* b10: Buffer empty interrupt */
 #define USB_NRDY                  (0x0200U) /* b9: Buffer notready interrupt */
 #define USB_BRDY                  (0x0100U) /* b8: Buffer ready interrupt */
 #define USB_VBSTS                 (0x0080U) /* b7: VBUS input port */
 #define USB_DVSQ                  (0x0070U) /* b6-4: Device state */
 #define USB_DS_SPD_CNFG           (0x0070U) /* Suspend Configured */
 #define USB_DS_SPD_ADDR           (0x0060U) /* Suspend Address */
 #define USB_DS_SPD_DFLT           (0x0050U) /* Suspend Default */
 #define USB_DS_SPD_POWR           (0x0040U) /* Suspend Powered */
 #define USB_DS_SUSP               (0x0040U) /* Suspend */
 #define USB_DS_CNFG               (0x0030U) /* Configured */
 #define USB_DS_ADDS               (0x0020U) /* Address */
 #define USB_DS_DFLT               (0x0010U) /* Default */
 #define USB_DS_POWR               (0x0000U) /* Powered */
 #define USB_DVSQS                 (0x0030U) /* b5-4: Device state */
 #define USB_VALID                 (0x0008U) /* b3: Setup packet detect flag */
 #define USB_CTSQ                  (0x0007U) /* b2-0: Control transfer stage */
 #define USB_CS_SQER               (0x0006U) /* Sequence error */
 #define USB_CS_WRND               (0x0005U) /* Ctrl write nodata status stage */
 #define USB_CS_WRSS               (0x0004U) /* Ctrl write status stage */
 #define USB_CS_WRDS               (0x0003U) /* Ctrl write data stage */
 #define USB_CS_RDSS               (0x0002U) /* Ctrl read status stage */
 #define USB_CS_RDDS               (0x0001U) /* Ctrl read data stage */
 #define USB_CS_IDST               (0x0000U) /* Idle or setup stage */

/* Interrupt Status Register 1 */
 #define USB_OVRCR                 (0x8000U) /* b15: Over-current interrupt */
 #define USB_BCHG                  (0x4000U) /* b14: USB bus change interrupt */
 #define USB_DTCH                  (0x1000U) /* b12: Detach sense interrupt */
 #define USB_ATTCH                 (0x0800U) /* b11: Attach sense interrupt */
 #define USB_L1RSMEND              (0x0200U) /* b9: L1 resume completion interrupt */
 #define USB_LPMEND                (0x0100U) /* b8: LPM transaction completion interrupt */
 #define USB_EOFERR                (0x0040U) /* b6: EOF-error interrupt */
 #define USB_SIGN                  (0x0020U) /* b5: Setup ignore interrupt */
 #define USB_SACK                  (0x0010U) /* b4: Setup ack interrupt */
 #define USB_PDDETINT              (0x0001U) /* b0: PDDET detection interrupt */

/* Frame Number Register */
 #define USB_OVRN                  (0x8000U) /* b15: Overrun error */
 #define USB_CRCE                  (0x4000U) /* b14: Received data error */
 #define USB_FRNM                  (0x07FFU) /* b10-0: Frame number */

/* Device State Change Register */ /* For USB0 */
 #define USB_DVCHG                 (0x8000U) /* b15: Device state change */

/* Micro Frame Number Register */ /* For USBHS */
 #define USB_UFRNM                 (0x0007U) /* b2-0: Micro frame number */

/* USB Address / Low Power Status Recovery Register */
 #define USB_STSRECOV              (0x0F00U) /* b11-8: Status Recovery */
 #define USB_USBADDR_MASK          (0x007FU) /* b6-0: USB address */

/* USB Request Type Register */
 #define USB_BMREQUESTTYPE         (0x00FFU) /* b7-0: USB_BMREQUESTTYPE */
 #define USB_BMREQUESTTYPEDIR      (0x0080U) /* b7  : Data transfer direction */
 #define USB_BMREQUESTTYPETYPE     (0x0060U) /* b6-5: Type */
 #define USB_BMREQUESTTYPERECIP    (0x001FU) /* b4-0: Recipient */

/* USB Request Value Register */
 #define USB_WVALUE                (0xFFFFU) /* b15-0: wValue */
 #define USB_DT_TYPE               (0xFF00U)
 #define USB_GET_DT_TYPE(v)    (((v) & USB_DT_TYPE) >> 8)
 #define USB_DT_INDEX              (0x00FFU)
 #define USB_CONF_NUM              (0x00FFU)
 #define USB_ALT_SET               (0x00FFU)

/* USB Request Index Register */
 #define USB_WINDEX                (0xFFFFU) /* b15-0: wIndex */
 #define USB_TEST_SELECT           (0xFF00U) /* b15-b8: Test Mode Selectors */
 #define USB_TEST_J                (0x0100U) /* Test_J */
 #define USB_TEST_K                (0x0200U) /* Test_K */
 #define USB_TEST_SE0_NAK          (0x0300U) /* Test_SE0_NAK */
 #define USB_TEST_PACKET           (0x0400U) /* Test_Packet */
 #define USB_TEST_FORCE_ENABLE     (0x0500U) /* Test_Force_Enable */
 #define USB_TEST_STSelectors      (0x0600U) /* Standard test selectors */
 #define USB_TEST_RESERVED         (0x4000U) /* Reserved */
 #define USB_TEST_VSTMODES         (0xC000U) /* VendorSpecific test modes */

/* USB Request Length Register */
 #define USB_WLENGTH               (0xFFFFU) /* b15-0: wLength */

/* Refer to r_usb_cdefusbip.h */
 #define USB_TYPE                  (0xC000U) /* b15-14: Transfer type */
 #define USB_BFRE                  (0x0400U) /* b10: Buffer ready interrupt mode select */

 #define USB_DEVSEL                (0xF000U) /* b15-14: Device address select */
 #define USB_MAXP                  (0x007FU) /* b6-0: Maxpacket size of default control pipe */
 #define USB_MXPS                  (0x07FFU) /* b10-0: Maxpacket size */

 #define USB_BSTS                  (0x8000U) /* b15: Buffer status */
 #define USB_SUREQ                 (0x4000U) /* b14: Send USB request  */
 #define USB_INBUFM                (0x4000U) /* b14: IN buffer monitor (Only for PIPE1 to 5) */
 #define USB_CSCLR                 (0x2000U) /* b13: c-split status clear */
 #define USB_CSSTS                 (0x1000U) /* b12: c-split status */
 #define USB_SUREQCLR              (0x0800U) /* b11: stop setup request */
 #define USB_ATREPM                (0x0400U) /* b10: Auto repeat mode */
 #define USB_ACLRM                 (0x0200U) /* b9: buffer auto clear mode */
 #define USB_SQCLR                 (0x0100U) /* b8: Sequence bit clear */
 #define USB_SQSET                 (0x0080U) /* b7: Sequence bit set */
 #define USB_SQMON                 (0x0040U) /* b6: Sequence bit monitor */
 #define USB_PBUSY                 (0x0020U) /* b5: pipe busy */
 #define USB_PINGE                 (0x0010U) /* b4: ping enable */
 #define USB_CCPL                  (0x0004U) /* b2: Enable control transfer complete */
 #define USB_PID                   (0x0003U) /* b1-0: Response PID */
 #define USB_PID_STALL             (0x0002U) /* STALL */
 #define USB_PID_BUF               (0x0001U) /* BUF */
 #define USB_PID_NAK               (0x0000U) /* NAK */

 #define USB_PIPENM                (0x0007U) /* b2-0: Pipe select */

/* Refer to r_usb_cdefusbip.h */
 #define USB_BUFSIZE               (0x7C00U) /* b14-10: Pipe buffer size */
 #define USB_BUFNMB                (0x007FU) /* b6-0: Pipe buffer number */
 #define USB_PIPE0BUF              (256U)
 #define USB_PIPEXBUF              (64U)

 #define USB_TRENB                 (0x0200U) /* b9: Transaction count enable */
 #define USB_TRCLR                 (0x0100U) /* b8: Transaction count clear */
 #define USB_TRNCNT                (0xFFFFU) /* b15-0: Transaction counter */

 #define USB_UCKSELC               (0x0001U) /* b0: USB Clock Seielction Bit */

 #define USB_VDCEN                 (0x0080U) /* b7: Regulator ON/OFF control */

 #define USB_UPPHUB                (0x7800U) /* b14-11: HUB register */
 #define USB_HUBPORT               (0x0700U) /* b10-8: HUB port */
 #define USB_USBSPD                (0x00C0U) /* b7-6: Device speed */

 #define USB_BYTE_MASK             (0x00FFU) /* b0-b7: Byte data Mask */

 #define USB_CPU_DELAY_US          (100U)    /* USB CPU delay time microsecond */

 #define USB_DEVICE_ADDRESS_MAX    (127)     /* Device Address Max */


#endif /* end of #ifndef __USB_RA_REG_H__ */
