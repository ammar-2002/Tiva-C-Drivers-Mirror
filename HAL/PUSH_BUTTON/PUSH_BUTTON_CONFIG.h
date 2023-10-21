/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : PUSH_BUTTON_Driver
File    : CONFIG File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

#ifndef HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_
#define HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_

/*
 * To select button resistor
 *
 * BUTTON_0_RESISTANCE =
 *      PULL_UP_RESISTOR
 *      PULL_DOWN_RESISTOR
 *
 * */
#define BUTTON_1_RESISTANCE  PULL_UP_RESISTOR

/*
 * To select button resistor
 *
 * BUTTON_1_RESISTANCE =
 *      PULL_UP_RESISTOR
 *      PULL_DOWN_RESISTOR
 *
 * */
#define BUTTON_2_RESISTANCE  PULL_UP_RESISTOR

#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_CONFIG_H_ */
