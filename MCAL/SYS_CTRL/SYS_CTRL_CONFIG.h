/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : SYS_CTRL_Driver
 * FILE    : SYS_CTRL_Config.h
 * VERSION : 1.0
 * CREATED : September 17, 2023
 *
 * DESCRIPTION:
 * This file contains the configuration options for the SYS_CTRL_Driver,
 * which is responsible for configuring and controlling the system clock
 * and peripheral clocks on the TM4C123GH6PM (TIVA C) microcontroller.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_
#define MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_

/**
 * Choose the system clock source.
 *
 * RCC_SYSCLK can be one of the following:
 * - RCC_MOSC
 * - RCC_PIOSC
 * - RCC_PIOSC_DIVIDED_BY_4
 * - RCC_LFIOSC
 * - RCC_EXTERNAL_OSC_32KHZ
 * - RCC_PLL
 */
#define RCC_SYSCLK  RCC_MOSC

/**
 * Select whether the system divisor is used or not.
 *
 * SYSDIV_STATE can be either:
 * - SYSDIV_OFF
 * - SYSDIV_ON
 */
#define SYSDIV_STATE  SYSDIV_OFF

/**
 * Choose the value of the system divisor.
 *
 * SYSDIV_VALUE can be one of the following:
 * (you can select the value that best fits your requirements)
 * - SYSDIV_BY_3
 * - SYSDIV_BY_4
 * - SYSDIV_BY_5
 * - SYSDIV_BY_6
 * - ...
 * - SYSDIV_BY_63
 * - SYSDIV_BY_64
 * - SYSDIV_BY_2_5
 * - SYSDIV_BY_3_5
 * - SYSDIV_BY_4_5
 * - SYSDIV_BY_5_5
 * - SYSDIV_BY_6_5
 * - ...
 * - SYSDIV_BY_63_5
 */
#define SYSDIV_VALUE SYSDIV_BY_3

/**
 * Choose the PLL entry clock mode.
 *
 * PLL_CLOCK_MODE can be one of the following:
 * - PLL_CLOCK_MOSC
 * - PLL_CLOCK_PIOSC
 */
#define PLL_CLOCK_MODE  PLL_CLOCK_PIOSC

#endif /* MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_ */
