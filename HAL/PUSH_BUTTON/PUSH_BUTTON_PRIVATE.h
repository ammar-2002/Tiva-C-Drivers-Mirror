/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : PUSH_BUTTON_Driver
File    : PRIVATE File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

#ifndef HAL_PUSH_BUTTON_PUSH_BUTTON_PRIVATE_H_
#define HAL_PUSH_BUTTON_PUSH_BUTTON_PRIVATE_H_

/***************************************************************
*************************** Defines ****************************
****************************************************************/

/************** Button Pins ******************/
#define BUTTON_1_PIN    PF4
#define BUTTON_2_PIN    PF0

/************** Resistor options ******************/
#define PULL_UP_RESISTOR    1
#define PULL_DOWN_RESISTOR  2

#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_PRIVATE_H_ */
