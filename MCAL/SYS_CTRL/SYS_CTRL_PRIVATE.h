/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : MCAL
DRIVER  : SYS_CTRL_Driver
File    : PRIVATE File
Version : 1.0
CREATED : September 17, 2023
**********************************************************
*********************************************************/

#ifndef MCAL_SYS_CTRL_SYS_CTRL_PRIVATE_H_
#define MCAL_SYS_CTRL_SYS_CTRL_PRIVATE_H_

/***************************************************************
********************** Type Definitions ************************
****************************************************************/

// Register No. 1
typedef struct {
    u32 MINOR:8;
    u32 MAJOR:8;
    u32 CLASS:8;
    u32 reserved1:4;
    u32 VER:3;
    u32 reserved2:1;
}DID0_st;

typedef union {
    u32 R;
    DID0_st B;
}DID0_t;

// Register No. 2
typedef struct {
    u32 QUAL:2;
    u32 ROHS:1;
    u32 PKG:2;
    u32 TEMP:3;
    u32 reserved1:5;
    u32 PINCOUNT:3;
    u32 PARTNO:8;
    u32 FAM:4;
    u32 VER:4;
}DID1_st;

typedef union{
    u32 R;
    DID1_st B;
}DID1_t;

// Register No. 3
typedef struct{
    u32 reserved1:1;
    u32 BOR1:1;
    u32 BOR2:1;
    u32 reserved2:29;
}PBORCTL_st;

typedef union{
    PBORCTL_st B;
    u32 R;
}PBORCTL_t;

// Register No. 4
typedef struct{
    u32 reserved1:1;
    u32 BOR1RIS:1;
    u32 reserved2:1;
    u32 MOFRIS:1;
    u32 reserved3:2;
    u32 PLLLRIS:1;
    u32 USBPLLLRIS:1;
    u32 MOSCPUPRIS:1;
    u32 reserved4:1;
    u32 VDDARIS:1;
    u32 BOR0RIS:1;
    u32 reserved5:20;
}RIS_st;

typedef union{
    u32 R;
    RIS_st B;
}RIS_t;

// Register No. 5
typedef struct{
    u32 reserved1:1;
    u32 BOR1IM:1;
    u32 reserved2:1;
    u32 MOFIM:1;
    u32 reserved3:2;
    u32 PLLLIM:1;
    u32 USBPLLLIM:1;
    u32 MOSCPUPIM:1;
    u32 reserved4:1;
    u32 VDDAIM:1;
    u32 BOR0IM:1;
    u32 reserved5:20;
}IMC_st;

typedef union{
    u32 R;
    IMC_st B;
}IMC_t;

// Register No. 6
typedef struct{
    u32 reserved1:1;
    u32 BOR1MIS:1;
    u32 reserved2:1;
    u32 MOFMIS:1;
    u32 reserved3:2;
    u32 PLLLMIS:1;
    u32 USBPLLLMIS:1;
    u32 MOSCPUPMIS:1;
    u32 reserved4:1;
    u32 VDDAMIS:1;
    u32 BOR0MIS:1;
    u32 reserved5:20;
}MISC_st;

typedef union{
    MISC_st B;
    u32 R;
}MISC_t;

// Register No. 7
typedef struct{
    u32 EXT:1;
    u32 POR:1;
    u32 BOR:1;
    u32 WDT0:1;
    u32 SW:1;
    u32 WDT1:1;
    u32 reserved1:10;
    u32 MOSCFAIL:1;
    u32 reserved2:15;
}RESC_st;

typedef union{
    RESC_st B;
    u32 R;
}RESC_t;

// Register No. 8
typedef struct{
    u32 MOSCDIS:1;
    u32 reserved1:3;
    u32 OSCSRC:2;
    u32 XTAL: 5;
    u32 BYPASS:1;
    u32 reserved2:1;
    u32 PWRDN:1;
    u32 reserved3:3;
    u32 PWMDIV:3;
    u32 USEPWMDIV:1;
    u32 reserved4:1;
    u32 USESYSDIV:1;
    u32 SYSDIV:4;
    u32 ACG:1;
    u32 reserved5:4;
}RCC_st;

typedef union{
    RCC_st B;
    u32 R;
}RCC_t;

// Register No. 9
typedef struct{
    u32 PORTA:1;
    u32 PORTB:1;
    u32 PORTC:1;
    u32 PORTD:1;
    u32 PORTE:1;
    u32 PORTF:1;
    u32 reserved:26;
}GPIOHBCTL_st;

typedef union{
    u32 R;
    GPIOHBCTL_st B;
}GPIOHBCTL_t;

// Register No. 10
typedef struct{
    u32 reserved1:4;
    u32 OSCSRC2:3;
    u32 reserved2:4;
    u32 BYPASS2:1;
    u32 reserved3:1;
    u32 PWRDN2:1;
    u32 USBPWRDN:1;
    u32 reserved4:7;
    u32 SYSDIV2LSB:1;
    u32 SYSDIV2:6;
    u32 reserved5:1;
    u32 DIV400:1;
    u32 USERCC2:1;
}RCC2_st;

typedef union{
    RCC2_st B;
    u32 R;
}RCC2_t;

// Register No. 11
typedef struct{
    u32 CVAL:1;
    u32 MOSCIM:1;
    u32 NOXTAL:1;
    u32 reserved:29;
}MOSCCTL_st;

typedef union{
    u32 R;
    MOSCCTL_st B;
}MOSCCTL_t;

// Register No. 12
typedef struct{
    u32 reserved1:1;
    u32 PIOSCPD:1;
    u32 reserved2:2;
    u32 DSOSCSRC:3;
    u32 reserved3:16;
    u32 DSDIVORIDE:6;
    u32 reserved4:3;
}DSLPCLKCFG_st;

typedef union{
    DSLPCLKCFG_st B;
    u32 R;
}DSLPCLKCFG_t;

// Register No. 13
typedef struct{
    u32 FPU:1;
    u32 reserved1:7;
    u32 FLASHLPM:1;
    u32 reserved2:1;
    u32 SRAMLPM:1;
    u32 SRAMSM:1;
    u32 PIOSCPDE:1;
    u32 reserved3:19;
}SYSPROP_st;

typedef union{
    SYSPROP_st B;
    u32 R;
}SYSPROP_t;

// Register No. 14
typedef struct{
    u32 UT:7;
    u32 reserved1:1;
    u32 UPDATE:1;
    u32 CAL:1;
    u32 reserved2:21;
    u32 UTEN:1;
}PIOSCCAL_st;

typedef union{
    PIOSCCAL_st B;
    u32 R;
}PIOSCCAL_t;

// Register No. 15
typedef struct{
    u32 CT:7;
    u32 reserved1:1;
    u32 RESULT:2;
    u32 reserved2:6;
    u32 DT:7;
    u32 reserved3:9;
}PIOSCSTAT_st;

typedef union{
    PIOSCSTAT_st B;
    u32 R;
}PIOSCSTAT_t;

// Register No. 16
typedef struct{
    u32 MINT:10;
    u32 MFRAC:10;
    u32 reserved:12;
}PLLFREQ0_st;

typedef union{
    PLLFREQ0_st B;
    u32 R;
}PLLFREQ0_t;

// Register No. 17
typedef struct{
    u32 N:5;
    u32 reserved1:3;
    u32 Q:5;
    u32 reserved2:19;
}PLLFREQ1_st;

typedef union{
    PLLFREQ1_st B;
    u32 R;
}PLLFREQ1_t;

// Register No. 18
typedef struct{
    u32 LOCK:1;
    u32 reserved:31;
}PLLSTAT_st;

typedef union{
    PLLSTAT_st B;
    u32 R;
}PLLSTAT_t;

// Register No. 19
typedef struct{
    u32 SRAMPM:2;
    u32 reserved1:2;
    u32 FLASHPM:2;
    u32 reserved2:26;
}SLPPWRCFG_st;

typedef union{
    SLPPWRCFG_st B;
    u32 R;
}SLPPWRCFG_t;

// Register No. 20
typedef struct{
    u32 SRAMPM:2;
    u32 reserved1:2;
    u32 FLASHPM:2;
    u32 reserved2:26;
}DSLPPWRCFG_st;

typedef union{
    DSLPPWRCFG_st B;
    u32 R;
}DSLPPWRCFG_t;

// Register No. 21
typedef struct{
    u32 VLDO:8;
    u32 reserved:23;
    u32 VADJEN:1;
}LDOSPCTL_st;

typedef union{
    LDOSPCTL_st B;
    u32 R;
}LDOSPCTL_t;

// Register No. 22
typedef struct{
    u32 NOPLL:8;
    u32 WITHPLL:8;
    u32 reserved:16;
}LDOSPCAL_st;

typedef union{
    LDOSPCAL_st B;
    u32 R;
}LDOSPCAL_t;

// Register No. 23
typedef struct{
    u32 VLDO:8;
    u32 reserved:23;
    u32 VADJEN:1;
}LDODPCTL_st;

typedef union{
    LDODPCTL_st B;
    u32 R;
}LDODPCTL_t;

// Register No. 24
typedef struct{
    u32 NOPLL:8;
    u32 _30KHZ:8;
    u32 reserved:16;
}LDODPCAL_st;

typedef union{
    LDODPCAL_st B;
    u32 R;
}LDODPCAL_t;

// Register No. 25
typedef struct{
    u32 SPDERR:1;
    u32 FPDERR:1;
    u32 PPDERR:1;
    u32 LDMINERR:1;
    u32 LSMINERR:1;
    u32 reserved1:1;
    u32 LMAXERR:1;
    u32 PPDW:1;
    u32 reserved2:8;
    u32 PRACT:1;
    u32 LOWPWR:1;
    u32 FLASHLP:1;
    u32 LDOUA:1;
    u32 reserved3:12;
}SDPMST_st;

typedef union{
    SDPMST_st B;
    u32 R;
}SDPMST_t;

// Register No. 26
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 reserved:30;
}PPWD_st;

typedef union{
    PPWD_st B;
    u32 R;
}PPWD_t;

// Register No. 27
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 P4:1;
    u32 P5:1;
    u32 reserved:26;
}PPTIMER_st;

typedef union{
    PPTIMER_st B;
    u32 R;
}PPTIMER_t;

// Register No. 28
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 P4:1;
    u32 P5:1;
    u32 P6:1;
    u32 P7:1;
    u32 P8:1;
    u32 P9:1;
    u32 P10:1;
    u32 P11:1;
    u32 P12:1;
    u32 P13:1;
    u32 P14:1;
    u32 reserved:17;
}PPGPIO_st;

typedef union{
    PPGPIO_st B;
    u32 R;
}PPGPIO_t;

// Register No. 29
typedef struct{
    u32 P0:1;
    u32 reserved:31;
}PPDMA_st;

typedef union{
    PPDMA_st B;
    u32 R;
}PPDMA_t;

// Register No. 30
typedef struct{
    u32 P0:1;
    u32 reserved:31;
}PPHIB_st;

typedef union{
    PPHIB_st B;
    u32 R;
}PPHIB_t;

// Register No. 31
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 P4:1;
    u32 P5:1;
    u32 P6:1;
    u32 P7:1;
    u32 reserved:24;
}PPUART_st;

typedef union{
    PPUART_st B;
    u32 R;
}PPUART_t;

//Register No. 32
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 reserved:28;
}PPSSI_st;

typedef union{
    PPSSI_st B;
    u32 R;
}PPSSI_t;

//Register No. 33
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 P4:1;
    u32 P5:1;
    u32 reserved:26;
}PPI2C_st;

typedef union{
    PPI2C_st B;
    u32 R;
}PPI2C_t;

//Register No. 34
typedef struct{
    u32 P0:1;
    u32 reserved:31;
}PPUSB_st;

typedef union{
    PPUSB_st B;
    u32 R;
}PPUSB_t;

//Register No. 35
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 reserved:30;
}PPCAN_st;

typedef union{
    PPCAN_st B;
    u32 R;
}PPCAN_t;

//Register No. 36
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 reserved:30;
}PPADC_st;

typedef union{
    PPADC_st B;
    u32 R;
}PPADC_t;

//Register No. 37
typedef struct{
    u32 P0:1;
    u32 reserved:31;
}PPACMP_st;

typedef union{
    PPACMP_st B;
    u32 R;
}PPACMP_t;

//Register No. 38
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 reserved:30;
}PPPWM_st;

typedef union{
    PPPWM_st B;
    u32 R;
}PPPWM_t;

//Register No. 39
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 reserved:30;
}PPQEI_st;

typedef union{
    PPQEI_st B;
    u32 R;
}PPQEI_t;

//Register No. 40
typedef struct{
    u32 P0:1;
    u32 reserved:31;
}PPEEPROM_st;

typedef union{
    PPEEPROM_st B;
    u32 R;
}PPEEPROM_t;

//Register No. 41
typedef struct{
    u32 P0:1;
    u32 P1:1;
    u32 P2:1;
    u32 P3:1;
    u32 P4:1;
    u32 P5:1;
    u32 reserved:26;
}PPWTIMER_st;

typedef union{
    PPWTIMER_st B;
    u32 R;
}PPWTIMER_t;

//Register No. 42
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}SRWD_st;

typedef union{
    SRWD_st B;
    u32 R;
}SRWD_t;

//Register No. 43
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}SRTIMER_st;

typedef union{
    SRTIMER_st B;
    u32 R;
}SRTIMER_t;

//Register No. 44
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}SRGPIO_st;

typedef union{
    SRGPIO_st B;
    u32 R;
}SRGPIO_t;

//Register No. 45
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}SRDMA_st;

typedef union{
    SRDMA_st B;
    u32 R;
}SRDMA_t;

//Register No. 46
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}SRHIB_st;

typedef union{
    SRHIB_st B;
    u32 R;
}SRHIB_t;

//Register No. 47
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 R6:1;
    u32 R7:1;
    u32 reserved:24;
}SRUART_st;

typedef union{
    SRUART_st B;
    u32 R;
}SRUART_t;

//Register No. 48
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}SRSSI_st;

typedef union{
    SRSSI_st B;
    u32 R;
}SRSSI_t;

//Register No. 49
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}SRI2C_st;

typedef union{
    SRI2C_st B;
    u32 R;
}SRI2C_t;

//Register No. 50
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}SRUSB_st;

typedef union{
    SRUSB_st B;
    u32 R;
}SRUSB_t;

//Register No. 51
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}SRCAN_st;

typedef union{
    SRCAN_st B;
    u32 R;
}SRCAN_t;

//Register No. 52
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}SRADC_st;

typedef union{
    SRADC_st B;
    u32 R;
}SRADC_t;

//Register No. 53
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}SRACMP_st;

typedef union{
    SRACMP_st B;
    u32 R;
}SRACMP_t;

//Register No. 54
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}SRPWM_st;

typedef union{
    SRPWM_st B;
    u32 R;
}SRPWM_t;

//Register No. 55
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}SRQEI_st;

typedef union{
    SRQEI_st B;
    u32 R;
}SRQEI_t;

//Register No. 56
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}SREEPROM_st;

typedef union{
    SREEPROM_st B;
    u32 R;
}SREEPROM_t;

//Register No. 57
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}SRWTIMER_st;

typedef union{
    SRWTIMER_st B;
    u32 R;
}SRWTIMER_t;

//Register No. 58
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}RCGCWD_st;

typedef union{
    RCGCWD_st B;
    u32 R;
}RCGCWD_t;

//Register No. 59
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}RCGCTIMER_st;

typedef union{
    RCGCTIMER_st B;
    u32 R;
}RCGCTIMER_t;

//Register No. 60
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}RCGCGPIO_st;

typedef union{
    RCGCGPIO_st B;
    u32 R;
}RCGCGPIO_t;

//Register No. 61
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}RCGCDMA_st;

typedef union{
    RCGCDMA_st B;
    u32 R;
}RCGCDMA_t;

//Register No. 62
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}RCGCHIB_st;

typedef union{
    RCGCHIB_st B;
    u32 R;
}RCGCHIB_t;

//Register No. 63
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 R6:1;
    u32 R7:1;
    u32 reserved:24;
}RCGCUART_st;

typedef union{
    RCGCUART_st B;
    u32 R;
}RCGCUART_t;

//Register No. 64
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}RCGCSSI_st;

typedef union{
    RCGCSSI_st B;
    u32 R;
}RCGCSSI_t;

//Register No. 65
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}RCGCI2C_st;

typedef union{
    RCGCI2C_st B;
    u32 R;
}RCGCI2C_t;

//Register No. 66
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}RCGCUSB_st;

typedef union{
    RCGCUSB_st B;
    u32 R;
}RCGCUSB_t;

//Register No. 67
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}RCGCCAN_st;

typedef union{
    RCGCCAN_st B;
    u32 R;
}RCGCCAN_t;

//Register No. 68
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}RCGCADC_st;

typedef union{
    RCGCADC_st B;
    u32 R;
}RCGCADC_t;

//Register No. 69
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}RCGCACMP_st;

typedef union{
    RCGCACMP_st B;
    u32 R;
}RCGCACMP_t;

//Register No. 70
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}RCGCPWM_st;

typedef union{
    RCGCPWM_st B;
    u32 R;
}RCGCPWM_t;

//Register No. 71
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}RCGCQEI_st;

typedef union{
    RCGCQEI_st B;
    u32 R;
}RCGCQEI_t;

//Register No. 72
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}RCGCEEPROM_st;

typedef union{
    RCGCEEPROM_st B;
    u32 R;
}RCGCEEPROM_t;

//Register No. 73
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}RCGCWTIMER_st;

typedef union{
    RCGCWTIMER_st B;
    u32 R;
}RCGCWTIMER_t;

//Register No. 74
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 reserved:30;
}SCGCWD_st;

typedef union{
    SCGCWD_st B;
    u32 R;
}SCGCWD_t;

//Register No. 75
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 S4:1;
    u32 S5:1;
    u32 reserved:26;
}SCGCTIMER_st;

typedef union{
    SCGCTIMER_st B;
    u32 R;
}SCGCTIMER_t;

//Register No. 76
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 S4:1;
    u32 S5:1;
    u32 reserved:26;
}SCGCGPIO_st;

typedef union{
    SCGCGPIO_st B;
    u32 R;
}SCGCGPIO_t;

//Register No. 77
typedef struct{
    u32 S0:1;
    u32 reserved:31;
}SCGCDMA_st;

typedef union{
    SCGCDMA_st B;
    u32 R;
}SCGCDMA_t;

//Register No. 78
typedef struct{
    u32 S0:1;
    u32 reserved:31;
}SCGCHIB_st;

typedef union{
    SCGCHIB_st B;
    u32 R;
}SCGCHIB_t;

//Register No. 79
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 S4:1;
    u32 S5:1;
    u32 S6:1;
    u32 S7:1;
    u32 reserved:24;
}SCGCUART_st;

typedef union{
    SCGCUART_st B;
    u32 R;
}SCGCUART_t;

//Register No. 80
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 reserved:28;
}SCGCSSI_st;

typedef union{
    SCGCSSI_st B;
    u32 R;
}SCGCSSI_t;

//Register No. 81
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 reserved:28;
}SCGCI2C_st;

typedef union{
    SCGCI2C_st B;
    u32 R;
}SCGCI2C_t;

//Register No. 82
typedef struct{
    u32 S0:1;
    u32 reserved:31;
}SCGCUSB_st;

typedef union{
    SCGCUSB_st B;
    u32 R;
}SCGCUSB_t;

//Register No. 83
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 reserved:30;
}SCGCCAN_st;

typedef union{
    SCGCCAN_st B;
    u32 R;
}SCGCCAN_t;

//Register No. 84
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 reserved:30;
}SCGCADC_st;

typedef union{
    SCGCADC_st B;
    u32 R;
}SCGCADC_t;

//Register No. 85
typedef struct{
    u32 S0:1;
    u32 reserved:31;
}SCGCACMP_st;

typedef union{
    SCGCACMP_st B;
    u32 R;
}SCGCACMP_t;

//Register No. 86
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 reserved:30;
}SCGCPWM_st;

typedef union{
    SCGCPWM_st B;
    u32 R;
}SCGCPWM_t;

//Register No. 87
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 reserved:30;
}SCGCQEI_st;

typedef union{
    SCGCQEI_st B;
    u32 R;
}SCGCQEI_t;

//Register No. 88
typedef struct{
    u32 S0:1;
    u32 reserved:31;
}SCGCEEPROM_st;

typedef union{
    SCGCEEPROM_st B;
    u32 R;
}SCGCEEPROM_t;

//Register No. 89
typedef struct{
    u32 S0:1;
    u32 S1:1;
    u32 S2:1;
    u32 S3:1;
    u32 S4:1;
    u32 S5:1;
    u32 reserved:26;
}SCGCWTIMER_st;

typedef union{
    SCGCWTIMER_st B;
    u32 R;
}SCGCWTIMER_t;

//Register No. 90
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 reserved:30;
}DCGCWD_st;

typedef union{
    DCGCWD_st B;
    u32 R;
}DCGCWD_t;

//Register No. 91
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 D4:1;
    u32 D5:1;
    u32 reserved:26;
}DCGCTIMER_st;

typedef union{
    DCGCTIMER_st B;
    u32 R;
}DCGCTIMER_t;

//Register No. 92
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 D4:1;
    u32 D5:1;
    u32 reserved:26;
}DCGCGPIO_st;

typedef union{
    DCGCGPIO_st B;
    u32 R;
}DCGCGPIO_t;

//Register No. 93
typedef struct{
    u32 D0:1;
    u32 reserved:31;
}DCGCDMA_st;

typedef union{
    DCGCDMA_st B;
    u32 R;
}DCGCDMA_t;

//Register No. 94
typedef struct{
    u32 D0:1;
    u32 reserved:31;
}DCGCHIB_st;

typedef union{
    DCGCHIB_st B;
    u32 R;
}DCGCHIB_t;

//Register No. 95
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 D4:1;
    u32 D5:1;
    u32 D6:1;
    u32 D7:1;
    u32 reserved:24;
}DCGCUART_st;

typedef union{
    DCGCUART_st B;
    u32 R;
}DCGCUART_t;

//Register No. 96
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 reserved:28;
}DCGCSSI_st;

typedef union{
    DCGCSSI_st B;
    u32 R;
}DCGCSSI_t;

//Register No. 97
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 reserved:28;
}DCGCI2C_st;

typedef union{
    DCGCI2C_st B;
    u32 R;
}DCGCI2C_t;

//Register No. 98
typedef struct{
    u32 D0:1;
    u32 reserved:31;
}DCGCUSB_st;

typedef union{
    DCGCUSB_st B;
    u32 R;
}DCGCUSB_t;

//Register No. 99
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 reserved:30;
}DCGCCAN_st;

typedef union{
    DCGCCAN_st B;
    u32 R;
}DCGCCAN_t;

//Register No. 100
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 reserved:30;
}DCGCADC_st;

typedef union{
    DCGCADC_st B;
    u32 R;
}DCGCADC_t;

//Register No. 101
typedef struct{
    u32 D0:1;
    u32 reserved:31;
}DCGCACMP_st;

typedef union{
    DCGCACMP_st B;
    u32 R;
}DCGCACMP_t;

//Register No. 102
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 reserved:30;
}DCGCPWM_st;

typedef union{
    DCGCPWM_st B;
    u32 R;
}DCGCPWM_t;

//Register No. 103
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 reserved:30;
}DCGCQEI_st;

typedef union{
    DCGCQEI_st B;
    u32 R;
}DCGCQEI_t;

//Register No. 104
typedef struct{
    u32 D0:1;
    u32 reserved:31;
}DCGCEEPROM_st;

typedef union{
    DCGCEEPROM_st B;
    u32 R;
}DCGCEEPROM_t;

//Register No. 105
typedef struct{
    u32 D0:1;
    u32 D1:1;
    u32 D2:1;
    u32 D3:1;
    u32 D4:1;
    u32 D5:1;
    u32 reserved:26;
}DCGCWTIMER_st;

typedef union{
    DCGCWTIMER_st B;
    u32 R;
}DCGCWTIMER_t;

//Register No. 106
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}PRWD_st;

typedef union{
    PRWD_st B;
    u32 R;
}PRWD_t;

//Register No. 107
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}PRTIMER_st;

typedef union{
    PRTIMER_st B;
    u32 R;
}PRTIMER_t;

//Register No. 108
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}PRGPIO_st;

typedef union{
    PRGPIO_st B;
    u32 R;
}PRGPIO_t;

//Register No. 109
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}PRDMA_st;

typedef union{
    PRDMA_st B;
    u32 R;
}PRDMA_t;

//Register No. 110
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}PRHIB_st;

typedef union{
    PRHIB_st B;
    u32 R;
}PRHIB_t;

//Register No. 111
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 R6:1;
    u32 R7:1;
    u32 reserved:24;
}PRUART_st;

typedef union{
    PRUART_st B;
    u32 R;
}PRUART_t;

//Register No. 112
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}PRSSI_st;

typedef union{
    PRSSI_st B;
    u32 R;
}PRSSI_t;

//Register No. 113
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 reserved:28;
}PRI2C_st;

typedef union{
    PRI2C_st B;
    u32 R;
}PRI2C_t;

//Register No. 114
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}PRUSB_st;

typedef union{
    PRUSB_st B;
    u32 R;
}PRUSB_t;

//Register No. 115
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}PRCAN_st;

typedef union{
    PRCAN_st B;
    u32 R;
}PRCAN_t;

//Register No. 116
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}PRADC_st;

typedef union{
    PRADC_st B;
    u32 R;
}PRADC_t;

//Register No. 117
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}PRACMP_st;

typedef union{
    PRACMP_st B;
    u32 R;
}PRACMP_t;

//Register No. 118
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}PRPWM_st;

typedef union{
    PRPWM_st B;
    u32 R;
}PRPWM_t;

//Register No. 119
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 reserved:30;
}PRQEI_st;

typedef union{
    PRQEI_st B;
    u32 R;
}PRQEI_t;

//Register No. 120
typedef struct{
    u32 R0:1;
    u32 reserved:31;
}PREEPROM_st;

typedef union{
    PREEPROM_st B;
    u32 R;
}PREEPROM_t;

//Register No. 121
typedef struct{
    u32 R0:1;
    u32 R1:1;
    u32 R2:1;
    u32 R3:1;
    u32 R4:1;
    u32 R5:1;
    u32 reserved:26;
}PRWTIMER_st;

typedef union{
    PRWTIMER_st B;
    u32 R;
}PRWTIMER_t;

//Register No. 122
typedef struct{
    u32 FLASHSZ:16;
    u32 SRAMSZ:16;
}DC0_st;

typedef union{
    DC0_st B;
    u32 R;
}DC0_t;

//Register No. 123
typedef struct{
    u32 JTAG:1;
    u32 SWD:1;
    u32 SWO:1;
    u32 WDT0:1;
    u32 PLL:1;
    u32 TEMPSNS:1;
    u32 HIB:1;
    u32 MPU:1;
    u32 MAXADC0SPD:2;
    u32 MAXADC1SPD:2;
    u32 MINSYSDIV:4;
    u32 ADC0:1;
    u32 ADC1:1;
    u32 reserved1:2;
    u32 PWM0:1;
    u32 PWM1:1;
    u32 reserved2:2;
    u32 CAN0:1;
    u32 CAN1:1;
    u32 reserved3:2;
    u32 WDT1:1;
    u32 reserved4:3;
}DC1_st;

typedef union{
    DC1_st B;
    u32 R;
}DC1_t;

//Register No. 124
typedef struct{
    u32 UART0:1;
    u32 UART1:1;
    u32 UART2:1;
    u32 reserved1:1;
    u32 SSI0:1;
    u32 SSI1:1;
    u32 reserved2:2;
    u32 QEI0:1;
    u32 QEI1:1;
    u32 reserved3:2;
    u32 I2C0:1;
    u32 I2C0HS:1;
    u32 I2C1:1;
    u32 I2C1HS:1;
    u32 TIMER0:1;
    u32 TIMER1:1;
    u32 TIMER2:1;
    u32 TIMER3:1;
    u32 reserved4:4;
    u32 COMP0:1;
    u32 COMP1:1;
    u32 COMP2:1;
    u32 reserved5:1;
    u32 I2S0:1;
    u32 reserved6:1;
    u32 EPI0:1;
    u32 reserved7:1;
}DC2_st;

typedef union{
    DC2_st B;
    u32 R;
}DC2_t;

//Register No. 125
typedef struct{
    u32 PWM0:1;
    u32 PWM1:1;
    u32 PWM2:1;
    u32 PWM3:1;
    u32 PWM4:1;
    u32 PWM5:1;
    u32 C0MINUS:1;
    u32 C0PLUS:1;
    u32 C0O:1;
    u32 C1MINUS:1;
    u32 C1PLUS:1;
    u32 C1O:1;
    u32 C2MINUS:1;
    u32 C2PLUS:1;
    u32 C2O:1;
    u32 PWMFAULT:1;
    u32 ADC0AIN0:1;
    u32 ADC0AIN1:1;
    u32 ADC0AIN2:1;
    u32 ADC0AIN3:1;
    u32 ADC0AIN4:1;
    u32 ADC0AIN5:1;
    u32 ADC0AIN6:1;
    u32 ADC0AIN7:1;
    u32 CCP0:1;
    u32 CCP1:1;
    u32 CCP2:1;
    u32 CCP3:1;
    u32 CCP4:1;
    u32 CCP5:1;
    u32 reserved:1;
    u32 _32KHZ_:1;
}DC3_st;

typedef union{
    DC3_st B;
    u32 R;
}DC3_t;

//Register No. 126
typedef struct{
    u32 GPIOA:1;
    u32 GPIOB:1;
    u32 GPIOC:1;
    u32 GPIOD:1;
    u32 GPIOE:1;
    u32 GPIOF:1;
    u32 GPIOG:1;
    u32 GPIOH:1;
    u32 GPIOJ:1;
    u32 reserved1:3;
    u32 ROM:1;
    u32 UDMA:1;
    u32 CCP6:1;
    u32 CCP7:1;
    u32 reserved2:2;
    u32 PICAL:1;
    u32 reserved3:5;
    u32 E1588:1;
    u32 reserved4:3;
    u32 EMAC0:1;
    u32 reserved5:1;
    u32 EPHY0:1;
    u32 reserved6:1;
}DC4_st;

typedef union{
    DC4_st B;
    u32 R;
}DC4_t;

//Register No. 127
typedef struct{
    u32 PWM0:1;
    u32 PWM1:1;
    u32 PWM2:1;
    u32 PWM3:1;
    u32 PWM4:1;
    u32 PWM5:1;
    u32 PWM6:1;
    u32 PWM7:1;
    u32 reserved1:12;
    u32 PWMESYNC:1;
    u32 PWMEFLT:1;
    u32 reserved2:2;
    u32 PWMFAULT0:1;
    u32 PWMFAULT1:1;
    u32 PWMFAULT2:1;
    u32 PWMFAULT3:1;
    u32 reserved3:4;
}DC5_st;

typedef union{
    DC5_st B;
    u32 R;
}DC5_t;

//Register No. 128
typedef struct{
    u32 USB0:2;
    u32 reserved1:2;
    u32 USB0PHY:1;
    u32 reserved2:27;
}DC6_st;

typedef union{
    DC6_st B;
    u32 R;
}DC6_t;

//Register No. 129
typedef struct{
    u32 DMACH0:1;
    u32 DMACH1:1;
    u32 DMACH2:1;
    u32 DMACH3:1;
    u32 DMACH4:1;
    u32 DMACH5:1;
    u32 DMACH6:1;
    u32 DMACH7:1;
    u32 DMACH8:1;
    u32 DMACH9:1;
    u32 DMACH10:1;
    u32 DMACH11:1;
    u32 DMACH12:1;
    u32 DMACH13:1;
    u32 DMACH14:1;
    u32 DMACH15:1;
    u32 DMACH16:1;
    u32 DMACH17:1;
    u32 DMACH18:1;
    u32 DMACH19:1;
    u32 DMACH20:1;
    u32 DMACH21:1;
    u32 DMACH22:1;
    u32 DMACH23:1;
    u32 DMACH24:1;
    u32 DMACH25:1;
    u32 DMACH26:1;
    u32 DMACH27:1;
    u32 DMACH28:1;
    u32 DMACH29:1;
    u32 DMACH30:1;
    u32 reserved:1;
}DC7_st;

typedef union{
    DC7_st B;
    u32 R;
}DC7_t;

//Register No. 130
typedef struct{
    u32 ADC0AIN0:1;
    u32 ADC0AIN1:1;
    u32 ADC0AIN2:1;
    u32 ADC0AIN3:1;
    u32 ADC0AIN4:1;
    u32 ADC0AIN5:1;
    u32 ADC0AIN6:1;
    u32 ADC0AIN7:1;
    u32 ADC0AIN8:1;
    u32 ADC0AIN9:1;
    u32 ADC0AIN10:1;
    u32 ADC0AIN11:1;
    u32 ADC0AIN12:1;
    u32 ADC0AIN13:1;
    u32 ADC0AIN14:1;
    u32 ADC0AIN15:1;
    u32 ADC1AIN0:1;
    u32 ADC1AIN1:1;
    u32 ADC1AIN2:1;
    u32 ADC1AIN3:1;
    u32 ADC1AIN4:1;
    u32 ADC1AIN5:1;
    u32 ADC1AIN6:1;
    u32 ADC1AIN7:1;
    u32 ADC1AIN8:1;
    u32 ADC1AIN9:1;
    u32 ADC1AIN10:1;
    u32 ADC1AIN11:1;
    u32 ADC1AIN12:1;
    u32 ADC1AIN13:1;
    u32 ADC1AIN14:1;
    u32 ADC1AIN15:1;
}DC8_st;

typedef union{
    DC8_st B;
    u32 R;
}DC8_t;

//Register No. 131
typedef struct{
    u32 reserved1:3;
    u32 WDT0:1;
    u32 reserved2:2;
    u32 HIB:1;
    u32 reserved3:9;
    u32 ADC0:1;
    u32 ADC1:1;
    u32 reserved4:2;
    u32 PWM0:1;
    u32 reserved5:3;
    u32 CAN0:1;
    u32 CAN1:1;
    u32 reserved6:2;
    u32 WDT1:1;
    u32 reserved7:3;
}SRCR0_st;

typedef union{
    SRCR0_st B;
    u32 R;
}SRCR0_t;

//Register No. 132
typedef struct{
    u32 UART0:1;
    u32 UART1:1;
    u32 UART2:1;
    u32 reserved1:1;
    u32 SSI0:1;
    u32 SSI1:1;
    u32 reserved2:2;
    u32 QEI0:1;
    u32 QEI1:1;
    u32 reserved3:2;
    u32 I2C0:1;
    u32 reserved4:1;
    u32 I2C1:1;
    u32 reserved5:1;
    u32 TIMER0:1;
    u32 TIMER1:1;
    u32 TIMER2:1;
    u32 TIMER3:1;
    u32 reserved6:4;
    u32 COMP0:1;
    u32 COMP1:1;
    u32 reserved7:6;
}SRCR1_st;

typedef union{
    SRCR1_st B;
    u32 R;
}SRCR1_t;

//Register No. 133
typedef struct{
    u32 GPIOA:1;
    u32 GPIOB:1;
    u32 GPIOC:1;
    u32 GPIOD:1;
    u32 GPIOE:1;
    u32 GPIOF:1;
    u32 reserved1:7;
    u32 UDMA:1;
    u32 reserved2:2;
    u32 USB0:1;
    u32 reserved3:15;
}SRCR2_st;

typedef union{
    SRCR2_st B;
    u32 R;
}SRCR2_t;

//Register No. 134
typedef struct{
    u32 reserved1:3;
    u32 WDT0:1;
    u32 reserved2:2;
    u32 HIB:1;
    u32 reserved3:1;
    u32 MAXADC0SPD:2;
    u32 MAXADC1SPD:2;
    u32 reserved4:4;
    u32 ADC0:1;
    u32 ADC1:1;
    u32 reserved5:2;
    u32 PWM0:1;
    u32 reserved6:3;
    u32 CAN0:1;
    u32 CAN1:1;
    u32 reserved7:2;
    u32 WDT1:1;
    u32 reserved8:3;
}RCGC0_st;

typedef union{
    RCGC0_st B;
    u32 R;
}RCGC0_t;

//Register No. 135
typedef struct{
    u32 UART0:1;
    u32 UART1:1;
    u32 UART2:1;
    u32 reserved1:1;
    u32 SSI0:1;
    u32 SSI1:1;
    u32 reserved2:2;
    u32 QEI0:1;
    u32 QEI1:1;
    u32 reserved3:2;
    u32 I2C0:1;
    u32 reserved4:1;
    u32 I2C1:1;
    u32 reserved5:1;
    u32 TIMER0:1;
    u32 TIMER1:1;
    u32 TIMER2:1;
    u32 TIMER3:1;
    u32 reserved6:4;
    u32 COMP0:1;
    u32 COMP1:1;
    u32 reserved7:6;
}RCGC1_st;

typedef union{
    RCGC1_st B;
    u32 R;
}RCGC1_t;

//Register No. 136
typedef struct{
    u32 GPIOA:1;
    u32 GPIOB:1;
    u32 GPIOC:1;
    u32 GPIOD:1;
    u32 GPIOE:1;
    u32 GPIOF:1;
    u32 reserved1:7;
    u32 UDMA:1;
    u32 reserved2:2;
    u32 USB0:1;
    u32 reserved3:15;
}RCGC2_st;

typedef union{
    RCGC2_st B;
    u32 R;
}RCGC2_t;

//Register No. 137
typedef struct{
    u32 reserved1:3;
    u32 WDT0:1;
    u32 reserved2:2;
    u32 HIB:1;
    u32 reserved3:9;
    u32 ADC0:1;
    u32 ADC1:1;
    u32 reserved4:2;
    u32 PWM0:1;
    u32 reserved5:3;
    u32 CAN0:1;
    u32 CAN1:1;
    u32 reserved6:2;
    u32 WDT1:1;
    u32 reserved7:3;
}SCGC0_st;

typedef union{
    SCGC0_st B;
    u32 R;
}SCGC0_t;

//Register No. 138
typedef struct{
    u32 UART0:1;
    u32 UART1:1;
    u32 UART2:1;
    u32 reserved1:1;
    u32 SSI0:1;
    u32 SSI1:1;
    u32 reserved2:2;
    u32 QEI0:1;
    u32 QEI1:1;
    u32 reserved3:2;
    u32 I2C0:1;
    u32 reserved4:1;
    u32 I2C1:1;
    u32 reserved5:1;
    u32 TIMER0:1;
    u32 TIMER1:1;
    u32 TIMER2:1;
    u32 TIMER3:1;
    u32 reserved6:4;
    u32 COMP0:1;
    u32 COMP1:1;
    u32 reserved7:6;
}SCGC1_st;

typedef union{
    SCGC1_st B;
    u32 R;
}SCGC1_t;

//Register No. 139
typedef struct{
    u32 GPIOA:1;
    u32 GPIOB:1;
    u32 GPIOC:1;
    u32 GPIOD:1;
    u32 GPIOE:1;
    u32 GPIOF:1;
    u32 reserved1:7;
    u32 UDMA:1;
    u32 reserved2:2;
    u32 USB0:1;
    u32 reserved3:15;
}SCGC2_st;

typedef union{
    SCGC2_st B;
    u32 R;
}SCGC2_t;

//Register No. 140
typedef struct{
    u32 reserved1:3;
    u32 WDT0:1;
    u32 reserved2:2;
    u32 HIB:1;
    u32 reserved3:9;
    u32 ADC0:1;
    u32 ADC1:1;
    u32 reserved4:2;
    u32 PWM0:1;
    u32 reserved5:3;
    u32 CAN0:1;
    u32 CAN1:1;
    u32 reserved6:2;
    u32 WDT1:1;
    u32 reserved7:3;
}DCGC0_st;

typedef union{
    DCGC0_st B;
    u32 R;
}DCGC0_t;

//Register No. 141
typedef struct{
    u32 UART0:1;
    u32 UART1:1;
    u32 UART2:1;
    u32 reserved1:1;
    u32 SSI0:1;
    u32 SSI1:1;
    u32 reserved2:2;
    u32 QEI0:1;
    u32 QEI1:1;
    u32 reserved3:2;
    u32 I2C0:1;
    u32 reserved4:1;
    u32 I2C1:1;
    u32 reserved5:1;
    u32 TIMER0:1;
    u32 TIMER1:1;
    u32 TIMER2:1;
    u32 TIMER3:1;
    u32 reserved6:4;
    u32 COMP0:1;
    u32 COMP1:1;
    u32 reserved7:6;
}DCGC1_st;

typedef union{
    DCGC1_st B;
    u32 R;
}DCGC1_t;

//Register No. 142
typedef struct{
    u32 GPIOA:1;
    u32 GPIOB:1;
    u32 GPIOC:1;
    u32 GPIOD:1;
    u32 GPIOE:1;
    u32 GPIOF:1;
    u32 reserved1:7;
    u32 UDMA:1;
    u32 reserved2:2;
    u32 USB0:1;
    u32 reserved3:15;
}DCGC2_st;

typedef union{
    DCGC2_st B;
    u32 R;
}DCGC2_t;

//Register No. 143
typedef struct{
    u32 ADC0DC0:1;
    u32 ADC0DC1:1;
    u32 ADC0DC2:1;
    u32 ADC0DC3:1;
    u32 ADC0DC4:1;
    u32 ADC0DC5:1;
    u32 ADC0DC6:1;
    u32 ADC0DC7:1;
    u32 reserved1:8;
    u32 ADC1DC0:1;
    u32 ADC1DC1:1;
    u32 ADC1DC2:1;
    u32 ADC1DC3:1;
    u32 ADC1DC4:1;
    u32 ADC1DC5:1;
    u32 ADC1DC6:1;
    u32 ADC1DC7:1;
    u32 reserved2:8;
}DC9_st;

typedef union{
    DC9_st B;
    u32 R;
}DC9_t;

//Register No. 144
typedef struct{
    u32 FWB:1;
    u32 reserved:31;
}NVMSTAT_st;

typedef union{
    NVMSTAT_st B;
    u32 R;
}NVMSTAT_t;




typedef struct {
    DID0_t DID0;            //0x000
    DID1_t DID1;            //0x004
    DC0_t DC0;              //0x008
    u32 reserved1;          //0x00C
    DC1_t DC1;              //0x010
    DC2_t DC2;              //0x014
    DC3_t DC3;              //0x018
    DC4_t DC4;              //0x01C
    DC5_t DC5;              //0x020
    DC6_t DC6;              //0x024
    DC7_t DC7;              //0x028
    DC8_t DC8;              //0x02C
    PBORCTL_t PBORCTL;      //0x030
    u32 reserved2[3];       //0x034 -> 0x03C
    SRCR0_t SRCR0;          //0x040
    SRCR1_t SRCR1;          //0x044
    SRCR2_t SRCR2;          //0x048
    u32 reserved3;          //0x04C
    RIS_t RIS;              //0x050
    IMC_t IMC;              //0x054
    MISC_t MISC;            //0x058
    RESC_t RESC;            //0x05C
    RCC_t RCC;              //0x060
    u32 reserved4[2];       //0x064 -> 0x068
    GPIOHBCTL_t GPIOHBCTL;  //0x06C
    RCC2_t RCC2;            //0x070
    u32 reserved5[2];       //0x074 -> 0x078
    MOSCCTL_t MOSCCTL;      //0x07C
    u32 reserved6[32];      //0x080 -> 0x0FC
    RCGC0_t RCGC0;          //0x100
    RCGC1_t RCGC1;          //0x104
    RCGC2_t RCGC2;          //0x108
    u32 reserved7;          //0x10C
    SCGC0_t SCGC0;          //0x110
    SCGC1_t SCGC1;          //0x114
    SCGC2_t SCGC2;          //0x118
    u32 reserved8;          //0x11C
    DCGC0_t DCGC0;          //0x120
    DCGC1_t DCGC1;          //0x124
    DCGC2_t DCGC2;          //0x128
    u32 reserved9[6];       //0x12C -> 0x140
    DSLPCLKCFG_t DSLPCLKCFG;//0x144
    u32 reserved10;         //0x148
    SYSPROP_t SYSPROP;      //0x14C
    PIOSCCAL_t PIOSCCAL;    //0x150
    PIOSCSTAT_t PIOSCSTAT;  //0x154
    u32 reserved11[2];      //0x158 -> 0x15C
    PLLFREQ0_t PLLFREQ0;    //0x160
    PLLFREQ1_t PLLFREQ1;    //0x164
    PLLSTAT_t PLLSTAT;      //0x168
    u32 reserved12[7];      //0x16C -> 0x184
    SLPPWRCFG_t SLPPWRCFG;  //0x188
    DSLPPWRCFG_t DSLPPWRCFG;//0x18C
    DC9_t DC9;              //0x190
    u32 reserved13[3];      //0x194 -> 19C
    NVMSTAT_t NVMSTAT;      //0x1A0
    u32 reserved14[4];      //0x1A4 -> 1B0
    LDOSPCTL_t LDOSPCTL;    //0x1B4
    LDOSPCAL_t LDOSPCAL;    //0x1B8
    LDODPCTL_t LDODPCTL;    //0x1BC
    LDODPCAL_t LDODPCAL;    //0x1C0
    u32 reserved15[2];      //0x1C4 -> 0x1C8
    SDPMST_t SDPMST;        //0x1CC
    u32 reserved16[76];     //0x1D0 -> 2FC
    PPWD_t PPWD;            //0x300
    PPTIMER_t PPTIMER;      //0x304
    PPGPIO_t PPGPIO;        //0x308
    PPDMA_t PPDMA;          //0x30C
    u32 reserved17;         //0x310
    PPHIB_t PPHIB;          //0x314
    PPUART_t PPUART;        //0x318
    PPSSI_t PPSSI;          //0x31C
    PPI2C_t PPI2C;          //0x320
    u32 reserved18;         //0x324
    PPUSB_t PPUSB;          //0x328
    u32 reserved19[2];      //0x32C -> 0x330
    PPCAN_t PPCAN;          //0x334
    PPADC_t PPADC;          //0x338
    PPACMP_t PPACMP;        //0x33C
    PPPWM_t PPPWM;          //0x340
    PPQEI_t PPQEI;          //0x344
    u32 reserved20[4];      //0x348 -> 0x354
    PPEEPROM_t PPEEPROM;    //0x358
    PPWTIMER_t PPWTIMER;    //0x35C
    u32 reserved21[104];    //0x360 -> 0x4FC
    SRWD_t SRWD;            //0x500
    SRTIMER_t SRTIMER;      //0x504
    SRGPIO_t SRGPIO;        //0x508
    SRDMA_t SRDMA;          //0x50C
    u32 reserved22;         //0x510
    SRHIB_t SRHIB;          //0x514
    SRUART_t SRUART;        //0x518
    SRSSI_t SRSSI;          //0x51C
    SRI2C_t SRI2C;          //0x520
    u32 reserved23;         //0x524
    SRUSB_t SRUSB;          //0x528
    u32 reserved24[2];      //0x52C -> 0x530
    SRCAN_t SRCAN;          //0x534
    SRADC_t SRADC;          //0x538
    SRACMP_t SRACMP;        //0x53C
    SRPWM_t SRPWM;          //0x540
    SRQEI_t SRQEI;          //0x544
    u32 reserved25[4];      //0x548 -> 0x554
    SREEPROM_t SREEPROM;    //0x558
    SRWTIMER_t SRWTIMER;    //0x55C
    u32 reserved26[40];     //0x560 - 0x5FC
    RCGCWD_t RCGCWD;        //0x600
    RCGCTIMER_t RCGCTIMER;  //0x604
    RCGCGPIO_t RCGCGPIO;    //0x608
    RCGCDMA_t RCGCDMA;      //0x60C
    u32 reserved27;         //0x610
    RCGCHIB_t RCGCHIB;      //0x614
    RCGCUART_t RCGCUART;    //0x618
    RCGCSSI_t RCGCSSI;      //0x61C
    RCGCI2C_t RCGCI2C;      //0x620
    u32 reserved28;         //0x624
    RCGCUSB_t RCGCUSB;      //0x628
    u32 reserved29[2];      //0x62C -> 0x630
    RCGCCAN_t RCGCCAN;      //0x634
    RCGCADC_t RCGCADC;      //0x638
    RCGCACMP_t RCGCACMP;    //0x63C
    RCGCPWM_t RCGCPWM;      //0x640
    RCGCQEI_t RCGCQEI;      //0x644
    u32 reserved30[4];      //0x648 -> 0x654
    RCGCEEPROM_t RCGCEEPROM;//0x658
    RCGCWTIMER_t RCGCWTIMER;//0x65C
    u32 reserved31[40];     //0x660 -> 0x6FC
    SCGCWD_t SCGCWD;        //0x700
    SCGCTIMER_t SCGCTIMER;  //0x704
    SCGCGPIO_t SCGCGPIO;    //0x708
    SCGCDMA_t SCGCDMA;      //0x70C
    u32 reserved32;         //0x710
    SCGCHIB_t SCGCHIB;      //0x714
    SCGCUART_t SCGCUART;    //0x718
    SCGCSSI_t SCGCSSI;      //0x71C
    SCGCI2C_t SCGCI2C;      //0x720
    u32 reserved33;         //0x724
    SCGCUSB_t SCGCUSB;      //0x728
    u32 reserved34[2];      //0x72C -> 0x730
    SCGCCAN_t SCGCCAN;      //0x734
    SCGCADC_t SCGCADC;      //0x738
    SCGCACMP_t SCGCACMP;    //0x73C
    SCGCPWM_t SCGCPWM;      //0x740
    SCGCQEI_t SCGCQEI;      //0x744
    u32 reserved35[4];      //0x748 -> 0x754
    SCGCEEPROM_t SCGCEEPROM;//0x758
    SCGCWTIMER_t SCGCWTIMER;//0x75C
    u32 reserved36[40];     //0x760 -> 7FC
    DCGCWD_t DCGCWD;        //0x800
    DCGCTIMER_t DCGCTIMER;  //0x804
    DCGCGPIO_t DCGCGPIO;    //0x808
    DCGCDMA_t DCGCDMA;      //0x80C
    u32 reserved37;         //0x810
    DCGCHIB_t DCGCHIB;      //0x814
    DCGCUART_t DCGCUART;    //0x818
    DCGCSSI_t DCGCSSI;      //0x81C
    DCGCI2C_t DCGCI2C;      //0x820
    u32 reserved38;         //0x824
    DCGCUSB_t DCGCUSB;      //0x828
    u32 reserved39[2];      //0x82C -> 0x830
    DCGCCAN_t DCGCCAN;      //0x834
    DCGCADC_t DCGCADC;      //0x838
    DCGCACMP_t DCGCACMP;    //0x83C
    DCGCPWM_t DCGCPWM;      //0x840
    DCGCQEI_t DCGCQEI;      //0x844
    u32 reserved40[4];      //0x848 -> 0x854
    DCGCEEPROM_t DCGCEEPROM;//0x858
    DCGCWTIMER_t DCGCWTIMER;//0x85C
    u32 reserved41[104];    //0x860 -> 0x9FC
    PRWD_t PRWD;            //0xA00
    PRTIMER_t PRTIMER;      //0xA04
    PRGPIO_t PRGPIO;        //0xA08
    PRDMA_t PRDMA;          //0xA0C
    u32 reserved42;         //0xA10
    PRHIB_t PRHIB;          //0xA14
    PRUART_t PRUART;        //0xA18
    PRSSI_t PRSSI;          //0xA1C
    PRI2C_t PRI2C;          //0xA20
    u32 reserved43;         //0xA24
    PRUSB_t PRUSB;          //0xA28
    u32 reserved44[2];      //0xA2C -> 0xA30
    PRCAN_t PRCAN;          //0xA34
    PRADC_t PRADC;          //0xA38
    PRACMP_t PRACMP;        //0xA3C
    PRPWM_t PRPWM;          //0xA40
    PRQEI_t PRQEI;          //0xA44
    u32 reserved45[4];      //0xA48 -> 0xA54
    PREEPROM_t PREEPROM;    //0xA58
    PRWTIMER_t PRWTIMER;    //0xA5C
}SYS_CTRL_t;

/***************************************************************
*************************** Defines ****************************
****************************************************************/

/*Used to set the clock type in the configuration file*/
#define RCC_MOSC                                0
#define RCC_PIOSC                               1
#define RCC_PIOSC_DIVIDED_BY_4                  2
#define RCC_LFIOSC                              3
#define RCC_EXTERNAL_OSC_32KHZ                  7
#define RCC_PLL                                 0xF

/*Used to choose if system divisor is used or not*/
#define SYSDIV_ON                               1
#define SYSDIV_OFF                              0

/*Used to choose system divisor value*/
#define SYSDIV_BY_3                             2
#define SYSDIV_BY_4                             3
#define SYSDIV_BY_5                             4
#define SYSDIV_BY_6                             5
#define SYSDIV_BY_7                             6
#define SYSDIV_BY_8                             7
#define SYSDIV_BY_9                             8
#define SYSDIV_BY_10                            9
#define SYSDIV_BY_11                            10
#define SYSDIV_BY_12                            11
#define SYSDIV_BY_13                            12
#define SYSDIV_BY_14                            13
#define SYSDIV_BY_15                            14
#define SYSDIV_BY_16                            15
#define SYSDIV_BY_17                            16
#define SYSDIV_BY_18                            17
#define SYSDIV_BY_19                            18
#define SYSDIV_BY_20                            19
#define SYSDIV_BY_21                            20
#define SYSDIV_BY_22                            21
#define SYSDIV_BY_23                            22
#define SYSDIV_BY_24                            23
#define SYSDIV_BY_25                            24
#define SYSDIV_BY_26                            25
#define SYSDIV_BY_27                            26
#define SYSDIV_BY_28                            27
#define SYSDIV_BY_29                            28
#define SYSDIV_BY_30                            29
#define SYSDIV_BY_31                            30
#define SYSDIV_BY_32                            31
#define SYSDIV_BY_33                            32
#define SYSDIV_BY_34                            33
#define SYSDIV_BY_35                            34
#define SYSDIV_BY_36                            35
#define SYSDIV_BY_37                            36
#define SYSDIV_BY_38                            37
#define SYSDIV_BY_39                            38
#define SYSDIV_BY_40                            39
#define SYSDIV_BY_41                            40
#define SYSDIV_BY_42                            41
#define SYSDIV_BY_43                            42
#define SYSDIV_BY_44                            43
#define SYSDIV_BY_45                            44
#define SYSDIV_BY_46                            45
#define SYSDIV_BY_47                            46
#define SYSDIV_BY_48                            47
#define SYSDIV_BY_49                            48
#define SYSDIV_BY_50                            49
#define SYSDIV_BY_51                            50
#define SYSDIV_BY_52                            51
#define SYSDIV_BY_53                            52
#define SYSDIV_BY_54                            53
#define SYSDIV_BY_55                            54
#define SYSDIV_BY_56                            55
#define SYSDIV_BY_57                            56
#define SYSDIV_BY_58                            57
#define SYSDIV_BY_59                            58
#define SYSDIV_BY_60                            59
#define SYSDIV_BY_61                            60
#define SYSDIV_BY_62                            61
#define SYSDIV_BY_63                            62
#define SYSDIV_BY_64                            63

/*Used to choose more system divisor value only with PLL*/
#define SYSDIV_BY_2_5                           66
#define SYSDIV_BY_3_5                           67
#define SYSDIV_BY_4_5                           68
#define SYSDIV_BY_5_5                           69
#define SYSDIV_BY_6_5                           70
#define SYSDIV_BY_7_5                           71
#define SYSDIV_BY_8_5                           72
#define SYSDIV_BY_9_5                           73
#define SYSDIV_BY_10_5                          74
#define SYSDIV_BY_10_5                          74
#define SYSDIV_BY_11_5                          75
#define SYSDIV_BY_12_5                          76
#define SYSDIV_BY_13_5                          77
#define SYSDIV_BY_14_5                          78
#define SYSDIV_BY_15_5                          79
#define SYSDIV_BY_16_5                          80
#define SYSDIV_BY_17_5                          81
#define SYSDIV_BY_18_5                          82
#define SYSDIV_BY_19_5                          83
#define SYSDIV_BY_20_5                          84
#define SYSDIV_BY_21_5                          85
#define SYSDIV_BY_22_5                          86
#define SYSDIV_BY_23_5                          87
#define SYSDIV_BY_24_5                          88
#define SYSDIV_BY_25_5                          89
#define SYSDIV_BY_26_5                          90
#define SYSDIV_BY_27_5                          91
#define SYSDIV_BY_28_5                          92
#define SYSDIV_BY_29_5                          93
#define SYSDIV_BY_30_5                          94
#define SYSDIV_BY_31_5                          95
#define SYSDIV_BY_32_5                          96
#define SYSDIV_BY_33_5                          97
#define SYSDIV_BY_34_5                          98
#define SYSDIV_BY_35_5                          99
#define SYSDIV_BY_36_5                          100
#define SYSDIV_BY_37_5                          101
#define SYSDIV_BY_38_5                          102
#define SYSDIV_BY_39_5                          103
#define SYSDIV_BY_40_5                          104
#define SYSDIV_BY_41_5                          105
#define SYSDIV_BY_42_5                          106
#define SYSDIV_BY_43_5                          107
#define SYSDIV_BY_44_5                          108
#define SYSDIV_BY_45_5                          109
#define SYSDIV_BY_46_5                          110
#define SYSDIV_BY_47_5                          111
#define SYSDIV_BY_48_5                          112
#define SYSDIV_BY_49_5                          113
#define SYSDIV_BY_50_5                          114
#define SYSDIV_BY_51_5                          115
#define SYSDIV_BY_52_5                          116
#define SYSDIV_BY_53_5                          117
#define SYSDIV_BY_54_5                          118
#define SYSDIV_BY_55_5                          119
#define SYSDIV_BY_56_5                          120
#define SYSDIV_BY_57_5                          121
#define SYSDIV_BY_58_5                          122
#define SYSDIV_BY_59_5                          123
#define SYSDIV_BY_60_5                          124
#define SYSDIV_BY_61_5                          125
#define SYSDIV_BY_62_5                          126
#define SYSDIV_BY_63_5                          127

/*Used to select clock for PLL*/
#define PLL_CLOCK_MOSC                                0
#define PLL_CLOCK_PIOSC                               1

/*Base address of the SYS_CTRL*/
#define SYS_CTRL_BASE                           0x400FE000

/*Pointer that point to SYS_CTRL peripheral in the memory*/
#define SYS_CTRL_REG                            ((SYS_CTRL_t *)SYS_CTRL_BASE)

/*PERIPHERAL_t Divider*/
#define SYS_CTRL_RCC_PERIPHERAL_DIVIDER         32

/*When divide PERIPHERAL_t by 32 this should be the result*/
#define SYS_CTRL_GPIO_RCC_REGISTER              0

/*When divide PERIPHERAL_CLOCK_t by 32 this should be the result*/
#define SYS_CTRL_RCGC0_REGISTER                 0
#define SYS_CTRL_RCGC1_REGISTER                 1
#define SYS_CTRL_RCGC2_REGISTER                 2

/*Defines alternative for 1 and 0*/
#define ENABLE                                  1
#define DISABLE                                 0

#endif /* MCAL_SYS_CTRL_SYS_CTRL_PRIVATE_H_ */
