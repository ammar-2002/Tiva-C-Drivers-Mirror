/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : PUSH_BUTTON_Driver
File    : INTERFACE File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

#ifndef HAL_PUSH_BUTTON_PUSH_BUTTON_INTERFACE_H_
#define HAL_PUSH_BUTTON_PUSH_BUTTON_INTERFACE_H_

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
*********************** Type definitions ***********************
****************************************************************/

/*** Enum for push buttons connected to the controller ***/
typedef enum {
    BUTTON_1    =1,
    BUTTON_2    =2
}BUTTON_t;

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: BUTTON_VoidButtonInit
 * Return: void
 * Parameters: BUTTON_t copy_tButton
 * documentation: Used to initialize the buttons
 * */
void BUTTON_VoidButtonInit(BUTTON_t copy_tButton);

/*Func: BUTTON_U8ButtonRead
 * Return: u8 => Data returned from button if pressed or not
 * Parameters: BUTTON_t copy_tButton
 * documentation: Used to read the buttons
 * */
u8   BUTTON_U8ButtonRead(BUTTON_t copy_tButton);

#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_INTERFACE_H_ */
