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

#include "STD_TYPES.h"

typedef enum {
    BUTTON_1    =1,
    BUTTON_2    =2
}BUTTON_t;

void BUTTON_VoidButtonInit(BUTTON_t copy_tButton);
u8   BUTTON_U8ButtonRead(BUTTON_t copy_tButton);

#endif /* HAL_PUSH_BUTTON_PUSH_BUTTON_INTERFACE_H_ */
