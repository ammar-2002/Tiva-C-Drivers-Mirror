/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : NVIC_Driver
 * FILE    : NVIC_Private.h
 * VERSION : 1.0
 * CREATED : October 24, 2023
 *
 * DESCRIPTION:
 * This file contains the private definitions and structures used by the NVIC (Nested Vector Interrupt Controller)
 * driver for the TM4C123GH6PM (TIVA C) microcontroller. It defines the structure of the NVIC registers, including
 * the Priority registers, and the base address of the NVIC peripheral.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
 ********************** Type Definitions ************************
 ****************************************************************/

/* Structure for NVIC Priority Register (PRI) */
typedef struct {
    u32 reserved1:5;
    u32 INTA:3;
    u32 reserved2:5;
    u32 INTB:3;
    u32 reserved3:5;
    u32 INTC:3;
    u32 reserved4:5;
    u32 INTD:3;
} PRI_st;

/* Union to access PRI register as both a 32-bit value and bitfields */
typedef union {
    u32 R;
    PRI_st B;
} PRI_t;

/* Structure for NVIC registers */
typedef struct {
    u32 reserved1[64];
    u32 EN0[5];
    u32 reserved2[27];
    u32 DIS[5];
    u32 reserved3[27];
    u32 PEND[5];
    u32 reserved4[27];
    u32 UNPEND[5];
    u32 reserved5[27];
    u32 ACTIVE[5];
    u32 reserved6[59];
    PRI_t PRI[35];
    u32 reserved7[669];
    u32 SWTRIG;
} NVIC_t;

/***************************************************************
 *************************** Defines ****************************
 ****************************************************************/

/* NVIC Register divisible (Number of bits per NVIC register) */
#define NVIC_REGISTER_DIVISIBLE                 32

/* NVIC PRI Register divisible (Number of bits per NVIC priority register) */
#define NVIC_PRI_REGISTER_DIVISIBLE             4

/* Base address of the NVIC peripheral */
#define NVIC_BASE                               0xE000E000

/* Pointer that points to the NVIC peripheral in memory */
#define NVIC_REG                                ((NVIC_t *)NVIC_BASE)

/* NVIC INT types in PRI Register */
#define INTA_TYPE                               0
#define INTB_TYPE                               1
#define INTC_TYPE                               2
#define INTD_TYPE                               3

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
