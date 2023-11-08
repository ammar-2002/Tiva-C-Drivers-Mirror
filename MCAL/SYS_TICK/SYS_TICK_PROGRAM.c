/********************************************************
 * AUTHOR      : AMMAR WAEL
 * MICRO       : TM4C123GH6PM (TIVA C)
 * LAYER       : MCAL
 * DRIVER      : SYS_TICK_Driver
 * FILE        : SYS_TICK_Program.c
 * VERSION     : 1.0
 * CREATED     : October 25, 2023
 *
 * DESCRIPTION :
 * This file contains the program code for the SYS_TICK_Driver.
 * It includes the implementation of functions for initializing,
 * configuring, and using the System Tick Timer on the TM4C123GH6PM
 * (TIVA C) microcontroller. Additionally, it defines the interrupt
 * handler for the System Tick Timer.
 *
 ********************************************************
 ********************************************************/

/***************************************************************
*************************** Includes ***************************
****************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYS_TICK_INTERFACE.h"
#include "SYS_TICK_PRIVATE.h"
#include "SYS_TICK_CONFIG.h"

/***************************************************************
**************************** Globals ***************************
****************************************************************/
static void (*SYS_TICK_callback)(void) = 0;
static void (*SYS_TICK_callbackOneArgument)(u8) = 0;
u8 Argument;
u8 FunctionOneArgumentFlag;
u8 DelayCounter;
u32 FloatFlag;

/***************************************************************
****************************** APIs ****************************
****************************************************************/

void SYS_TICK_VoidInit() {
    /* Initialize and configure the System Tick Timer */
    SYS_TICK_REG->STCTRL.B.ENABLE = ENABLE_DEFINE;
    SYS_TICK_REG->STCTRL.B.CLK_SRC = SYS_TICK_CLOCK_SOURCE;
    SYS_TICK_REG->STCTRL.B.INTEN = INTERRUPT_STATE;
}

void SYS_TICK_VoidSetPreLoad(u32 copy_u32PreLoadValue) {
    /* Set the preload value for the System Tick Timer */
    SYS_TICK_REG->STRELOAD.B.RELOAD = copy_u32PreLoadValue;
    SYS_TICK_REG->STCURRENT.B.CURRENT = DUMMY_VALUE;
}

void SYS_TICK_VoidDelaySeconds(u8 copy_u8Seconds) {
    /* Delay program execution for a specified number of seconds */
    SYS_TICK_REG->STCTRL.B.INTEN = DISABLE_DEFINE;
    DelayCounter = (u32)((copy_u8Seconds * TICKS_PER_SECOND) / MAX_TICKS);
    FloatFlag = (copy_u8Seconds * TICKS_PER_SECOND) % MAX_TICKS;
    SYS_TICK_VoidSetPreLoad(MAX_TICKS);
    while (DelayCounter)
        if (SYS_TICK_U8ReadFlag() == COUNTED_TO_ZERO)
            DelayCounter--;
    SYS_TICK_VoidSetPreLoad(FloatFlag);
    while (FloatFlag)
        if (SYS_TICK_U8ReadFlag() == COUNTED_TO_ZERO)
            FloatFlag = 0;
    DelayCounter = 0;
    SYS_TICK_REG->STCTRL.B.INTEN = INTERRUPT_STATE;
}

void SYS_TICK_VoidDelayMiliSeconds(u32 copy_u32MiliSeconds) {
    /* Delay program execution for a specified number of milliseconds */
    SYS_TICK_REG->STCTRL.B.INTEN = DISABLE_DEFINE;
    DelayCounter = (u32)(((copy_u32MiliSeconds / 1000.0) * TICKS_PER_SECOND) / MAX_TICKS);
    FloatFlag = (u32)((copy_u32MiliSeconds / 1000.0) * TICKS_PER_SECOND) % MAX_TICKS;
    SYS_TICK_VoidSetPreLoad(MAX_TICKS);
    while (DelayCounter)
        if (SYS_TICK_U8ReadFlag() == COUNTED_TO_ZERO)
            DelayCounter--;
    SYS_TICK_VoidSetPreLoad(FloatFlag);
    while (FloatFlag)
        if (SYS_TICK_U8ReadFlag() == COUNTED_TO_ZERO)
            FloatFlag = 0;
    DelayCounter = 0;
    SYS_TICK_REG->STCTRL.B.INTEN = INTERRUPT_STATE;
}

void SYS_TICK_VoidSetTimeCycle(u8 copy_u8Seconds) {
    /* Set the time cycle for the System Tick Timer */
    SYS_TICK_REG->STCTRL.B.INTEN = ENABLE_DEFINE;
    DelayCounter = (u32)((copy_u8Seconds * TICKS_PER_SECOND) / MAX_TICKS);
    FloatFlag = (copy_u8Seconds * TICKS_PER_SECOND) % MAX_TICKS;
    if (DelayCounter)
        SYS_TICK_VoidSetPreLoad(MAX_TICKS);
    else
        SYS_TICK_VoidSetPreLoad(FloatFlag);
}

void SYS_TICK_VoidSetCallback(void (*func)(void)) {
    /* Set a callback function to be executed when the timer interrupt occurs */
    SYS_TICK_callback = func;
    FunctionOneArgumentFlag = 0;
}

void SYS_TICK_VoidSetCallbackWithOneArgument(void (*func)(u8), u8 copy_u8Argument) {
    /* Set a callback function with one argument to be executed when the timer interrupt occurs */
    SYS_TICK_callbackOneArgument = func;
    Argument = copy_u8Argument;
    FunctionOneArgumentFlag = 1;
}

u32 SYS_TICK_U32GetElapsedTimeInMiliSeconds() {
    /* Get the elapsed time in milliseconds since the timer started */
    return (u32)((SYS_TICK_REG->STRELOAD.B.RELOAD - SYS_TICK_REG->STCURRENT.B.CURRENT) / (TICKS_PER_SECOND / 1000));
}

u32 SYS_TICK_U32GetRemainingTimeInMiliSeconds() {
    /* Get the remaining time in milliseconds until the next timer interrupt */
    return (u32)(SYS_TICK_REG->STCURRENT.B.CURRENT / (TICKS_PER_SECOND / 1000));
}

u8 SYS_TICK_U8ReadFlag() {
    /* Read the timer flag to check if the timer has counted to zero */
    return SYS_TICK_REG->STCTRL.B.COUNT;
}

void SYS_TICK_Handler(void) {
    static u8 copy_delayCount = 0;
    static u8 finished = 0;
    static u8 firstTime = 1;

    if (firstTime) {
        firstTime = 0;
        copy_delayCount = DelayCounter;
    }

    if (copy_delayCount)
        copy_delayCount--;

    if (copy_delayCount == 0 && finished == 1) {
        copy_delayCount = DelayCounter;
        finished = 0;

        if (copy_delayCount)
            SYS_TICK_VoidSetPreLoad(MAX_TICKS);

        if (FunctionOneArgumentFlag)
            (*SYS_TICK_callbackOneArgument)(Argument);
        else
            (*SYS_TICK_callback)();
    } else if (copy_delayCount != 0);
    else {
        SYS_TICK_VoidSetPreLoad(FloatFlag);
        finished = 1;
    }
}
