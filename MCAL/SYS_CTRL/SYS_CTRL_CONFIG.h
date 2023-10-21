/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : MCAL
DRIVER  : SYS_CTRL_Driver
File    : CONFIG File
Version : 1.0
CREATED : September 17, 2023
**********************************************************
*********************************************************/

#ifndef MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_
#define MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_

/*
 * To select system clock
 *
 * RCC_SYSCLK =
 *      RCC_MOSC
 *      RCC_PIOSC
 *      RCC_PIOSC_DIVIDED_BY_4
 *      RCC_LFIOSC
 *      RCC_EXTERNAL_OSC_32KHZ
 *      RCC_PLL
 *
 * */

#define RCC_SYSCLK  RCC_MOSC

/*
 * To select if system divisor is used or not
 *
 * SYSDIV_STATE =
 *      SYSDIV_OFF
 *      SYSDIV_ON
 *
 * */

#define SYSDIV_STATE  SYSDIV_OFF

/*
 * To select the value of system divisor
 *
 * SYSDIV_VALUE =
 *      SYSDIV_BY_3
 *      SYSDIV_BY_4
 *      SYSDIV_BY_5
 *      SYSDIV_BY_6
 *      SYSDIV_BY_7
 *      SYSDIV_BY_8
 *      SYSDIV_BY_9
 *      SYSDIV_BY_10
 *      SYSDIV_BY_11
 *      SYSDIV_BY_12
 *      SYSDIV_BY_13
 *      SYSDIV_BY_14
 *      SYSDIV_BY_15
 *      SYSDIV_BY_16
 *      SYSDIV_BY_17
 *      SYSDIV_BY_18
 *      SYSDIV_BY_19
 *      SYSDIV_BY_20
 *      SYSDIV_BY_21
 *      SYSDIV_BY_22
 *      SYSDIV_BY_23
 *      SYSDIV_BY_24
 *      SYSDIV_BY_25
 *      SYSDIV_BY_26
 *      SYSDIV_BY_27
 *      SYSDIV_BY_28
 *      SYSDIV_BY_29
 *      SYSDIV_BY_30
 *      SYSDIV_BY_31
 *      SYSDIV_BY_32
 *      SYSDIV_BY_33
 *      SYSDIV_BY_34
 *      SYSDIV_BY_35
 *      SYSDIV_BY_36
 *      SYSDIV_BY_37
 *      SYSDIV_BY_38
 *      SYSDIV_BY_39
 *      SYSDIV_BY_40
 *      SYSDIV_BY_41
 *      SYSDIV_BY_42
 *      SYSDIV_BY_43
 *      SYSDIV_BY_44
 *      SYSDIV_BY_45
 *      SYSDIV_BY_46
 *      SYSDIV_BY_47
 *      SYSDIV_BY_48
 *      SYSDIV_BY_49
 *      SYSDIV_BY_50
 *      SYSDIV_BY_51
 *      SYSDIV_BY_52
 *      SYSDIV_BY_53
 *      SYSDIV_BY_54
 *      SYSDIV_BY_55
 *      SYSDIV_BY_56
 *      SYSDIV_BY_57
 *      SYSDIV_BY_58
 *      SYSDIV_BY_59
 *      SYSDIV_BY_60
 *      SYSDIV_BY_61
 *      SYSDIV_BY_62
 *      SYSDIV_BY_63
 *      SYSDIV_BY_64
 *      SYSDIV_BY_2_5
 *      SYSDIV_BY_3_5
 *      SYSDIV_BY_4_5
 *      SYSDIV_BY_5_5
 *      SYSDIV_BY_6_5
 *      SYSDIV_BY_7_5
 *      SYSDIV_BY_8_5
 *      SYSDIV_BY_9_5
 *      SYSDIV_BY_10_5
 *      SYSDIV_BY_11_5
 *      SYSDIV_BY_12_5
 *      SYSDIV_BY_13_5
 *      SYSDIV_BY_14_5
 *      SYSDIV_BY_15_5
 *      SYSDIV_BY_16_5
 *      SYSDIV_BY_17_5
 *      SYSDIV_BY_18_5
 *      SYSDIV_BY_19_5
 *      SYSDIV_BY_20_5
 *      SYSDIV_BY_21_5
 *      SYSDIV_BY_22_5
 *      SYSDIV_BY_23_5
 *      SYSDIV_BY_24_5
 *      SYSDIV_BY_25_5
 *      SYSDIV_BY_26_5
 *      SYSDIV_BY_27_5
 *      SYSDIV_BY_28_5
 *      SYSDIV_BY_29_5
 *      SYSDIV_BY_30_5
 *      SYSDIV_BY_31_5
 *      SYSDIV_BY_32_5
 *      SYSDIV_BY_33_5
 *      SYSDIV_BY_34_5
 *      SYSDIV_BY_35_5
 *      SYSDIV_BY_36_5
 *      SYSDIV_BY_37_5
 *      SYSDIV_BY_38_5
 *      SYSDIV_BY_39_5
 *      SYSDIV_BY_40_5
 *      SYSDIV_BY_41_5
 *      SYSDIV_BY_42_5
 *      SYSDIV_BY_43_5
 *      SYSDIV_BY_44_5
 *      SYSDIV_BY_45_5
 *      SYSDIV_BY_46_5
 *      SYSDIV_BY_47_5
 *      SYSDIV_BY_48_5
 *      SYSDIV_BY_49_5
 *      SYSDIV_BY_50_5
 *      SYSDIV_BY_51_5
 *      SYSDIV_BY_52_5
 *      SYSDIV_BY_53_5
 *      SYSDIV_BY_54_5
 *      SYSDIV_BY_55_5
 *      SYSDIV_BY_56_5
 *      SYSDIV_BY_57_5
 *      SYSDIV_BY_58_5
 *      SYSDIV_BY_59_5
 *      SYSDIV_BY_60_5
 *      SYSDIV_BY_61_5
 *      SYSDIV_BY_62_5
 *      SYSDIV_BY_63_5
 *
 * */

#define SYSDIV_VALUE SYSDIV_BY_3

/*
 * To choose the PLL entry clock mode
 *
 * PLL_CLOCK_MODE =
 *      PLL_CLOCK_MOSC
 *      PLL_CLOCK_PIOSC
 *
 * */

#define PLL_CLOCK_MODE  PLL_CLOCK_PIOSC

#endif /* MCAL_SYS_CTRL_SYS_CTRL_CONFIG_H_ */
