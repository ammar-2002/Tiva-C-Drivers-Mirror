/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : KEY_PAD_Driver
File    : PRIVATE File
Version : 1.0
CREATED : October 20, 2023
**********************************************************
*********************************************************/

#ifndef HAL_KEY_PAD_KEY_PAD_PRIVATE_H_
#define HAL_KEY_PAD_KEY_PAD_PRIVATE_H_

#define KEY_PAD_X0 PE0
#define KEY_PAD_X1 PE1
#define KEY_PAD_X2 PE2
#define KEY_PAD_X3 PE3

#define KEY_PAD_Y0 PA4
#define KEY_PAD_Y1 PA5
#define KEY_PAD_Y2 PA6
#define KEY_PAD_Y3 PA7

#define PRESSED 0

u8 KEY_PAD_BUTTONS[4][4]={
        {'1','2','3','+'},
        {'4','5','6','-'},
        {'7','8','9','*'},
        {'.','0','=','/'}
    };

#endif /* HAL_KEY_PAD_KEY_PAD_PRIVATE_H_ */
