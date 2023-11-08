/********************************************************
 * AUTHOR    : AMMAR WAEL
 * MICRO     : TM4C123GH6PM (TIVA C)
 * LAYER     : MCAL
 * DRIVER    : SYS_TICK_Driver
 * FILE      : SYS_TICK_Config.h
 * VERSION   : 1.0
 * CREATED   : October 25, 2023
 *
 * DESCRIPTION:
 * This configuration header file for the SYS_TICK_Driver contains
 * settings that allow you to customize the behavior of the System
 * Tick Timer on the TM4C123GH6PM (TIVA C) microcontroller. You can
 * configure the clock source for the timer, the interrupt state,
 * and the system clock frequency.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_SYS_TICK_SYS_TICK_CONFIG_H_
#define MCAL_SYS_TICK_SYS_TICK_CONFIG_H_

/*
 * To select the clock source for the System Tick Timer.
 *
 * SYS_TICK_CLOCK_SOURCE can be one of the following:
 *   - SYSTEM_CLOCK: Use the system clock as the timer source.
 *   - PIOSC_DIVIDE_BY_4: Use the Precision Internal Oscillator divided by 4 as the timer source.
 */
#define SYS_TICK_CLOCK_SOURCE   PIOSC_DIVIDE_BY_4

/*
 * To select the interrupt state for the System Tick Timer.
 *
 * INTERRUPT_STATE can be one of the following:
 *   - ENABLE_DEFINE: Enable the timer interrupt.
 *   - DISABLE_DEFINE: Disable the timer interrupt.
 */
#define INTERRUPT_STATE         ENABLE_DEFINE

/*
 * To set the frequency of the system clock in Hertz.
 *
 * SYSTEM_CLOCK_ENTRY should be set to the desired system clock frequency.
 * Example: For a system clock of 16 MHz, set SYSTEM_CLOCK_ENTRY to 16000000.
 */
#define SYSTEM_CLOCK_ENTRY      16000000

#endif /* MCAL_SYS_TICK_SYS_TICK_CONFIG_H_ */
