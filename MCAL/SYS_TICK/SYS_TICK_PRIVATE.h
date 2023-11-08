/*********************************************************
* AUTHOR    : AMMAR WAEL
* MICRO     : TM4C123GH6PM (TIVA C)
* LAYER     : MCAL
* DRIVER    : SYS_TICK_Driver
* FILE      : SYS_TICK_Private.h
* VERSION   : 1.0
* CREATED   : October 25, 2023
* DESCRIPTION: This is a private header file for the
*              SYS_TICK_Driver. It contains low-level
*              configurations and definitions specific to
*              the System Tick Timer for the TM4C123GH6PM
*              (TIVA C) microcontroller.
*********************************************************
*********************************************************/


#ifndef MCAL_SYS_TICK_SYS_TICK_PRIVATE_H_
#define MCAL_SYS_TICK_SYS_TICK_PRIVATE_H_

/***************************************************************
*************************** Includes ***************************
****************************************************************/
#include "STD_TYPES.h"

/***************************************************************
********************** Type Definitions ************************
****************************************************************/

// Register No.1
typedef struct {
    u32 ENABLE:1;      // Bit to enable the timer
    u32 INTEN:1;       // Bit to enable timer interrupt
    u32 CLK_SRC:1;     // Bit to select the clock source
    u32 reserved1:13;  // Reserved bits
    u32 COUNT:1;       // Bit to indicate whether the timer has counted to zero
    u32 reserved2:15;  // Reserved bits
} STCTRL_st;

typedef union {
    u32 R;
    STCTRL_st B;
} STCTRL_t;

// Register No.2
typedef struct {
    u32 RELOAD:24;     // Value to reload the timer with
    u32 reserved:8;    // Reserved bits
} STRELOAD_st;

typedef union {
    u32 R;
    STRELOAD_st B;
} STRELOAD_t;

// Register No.3
typedef struct {
    u32 CURRENT:24;    // Current value of the timer
    u32 reserved:8;    // Reserved bits
} STCURRENT_st;

typedef union {
    u32 R;
    STCURRENT_st B;
} STCURRENT_t;

typedef struct {
    u32 reserved[4];
    STCTRL_t STCTRL;
    STRELOAD_t STRELOAD;
    STCURRENT_t STCURRENT;
} SYS_TICK_t;

/***************************************************************
*************************** Defines ****************************
****************************************************************/

/* Base address of the SYS_TICK peripheral */
#define SYS_TICK_BASE               0xE000E000

/* Pointer that points to SYS_TICK peripheral in memory */
#define SYS_TICK_REG                ((SYS_TICK_t *)SYS_TICK_BASE)

/* SYS_TICK Clock source */
#define SYSTEM_CLOCK                1
#define PIOSC_DIVIDE_BY_4           0

/* SYS_TICK enable/disable defines */
#define ENABLE_DEFINE               1
#define DISABLE_DEFINE              0

/* Bit value to indicate timer counted to zero */
#define COUNTED_TO_ZERO             1

/* Dummy value for resetting the counter */
#define DUMMY_VALUE                 0

/* Tick time per second based on the clock source */
#if SYS_TICK_CLOCK_SOURCE == PIOSC_DIVIDE_BY_4
#define TICKS_PER_SECOND            4000000
#else
#define TICKS_PER_SECOND            SYSTEM_CLOCK_ENTRY
#endif

/* Maximum ticks for SYS_TICK */
#define MAX_TICKS                   0x00FFFFFF

#endif /* MCAL_SYS_TICK_SYS_TICK_PRIVATE_H_ */
