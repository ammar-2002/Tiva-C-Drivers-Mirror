/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : KEY_PAD_Driver
File    : PROGRAM File
Version : 1.0
CREATED : October 20, 2023
**********************************************************
*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "SYS_CTRL_INTERFACE.h"
#include "KEY_PAD_INTERFACE.h"
#include "KEY_PAD_PRIVATE.h"
#include "KEY_PAD_CONFIG.h"

void KEY_PAD_VoidInit(){
    SYS_CTRL_VoidClockInit();
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOE_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOE);
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOA_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOA);

    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X0, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X1, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X2, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X3, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y0, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y1, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y2, PIN_CONFIG_ALLOW);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y3, PIN_CONFIG_ALLOW);

    GPIO_VoidPinState(KEY_PAD_X0, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_X1, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_X2, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_X3, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_Y0, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_Y1, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_Y2, PIN_ENABLE);
    GPIO_VoidPinState(KEY_PAD_Y3, PIN_ENABLE);

    GPIO_VoidPinDirection(KEY_PAD_X0,OUTPUT);
    GPIO_VoidPinDirection(KEY_PAD_X1,OUTPUT);
    GPIO_VoidPinDirection(KEY_PAD_X2,OUTPUT);
    GPIO_VoidPinDirection(KEY_PAD_X3,OUTPUT);

    GPIO_VoidPinData(KEY_PAD_X0,HIGH);
    GPIO_VoidPinData(KEY_PAD_X1,HIGH);
    GPIO_VoidPinData(KEY_PAD_X2,HIGH);
    GPIO_VoidPinData(KEY_PAD_X3,HIGH);

    GPIO_VoidPinDirection(KEY_PAD_Y0,INPUT);
    GPIO_VoidPinDirection(KEY_PAD_Y1,INPUT);
    GPIO_VoidPinDirection(KEY_PAD_Y2,INPUT);
    GPIO_VoidPinDirection(KEY_PAD_Y3,INPUT);

    GPIO_VoidPinInputMode(KEY_PAD_Y0,PULL_UP);
    GPIO_VoidPinInputMode(KEY_PAD_Y1,PULL_UP);
    GPIO_VoidPinInputMode(KEY_PAD_Y2,PULL_UP);
    GPIO_VoidPinInputMode(KEY_PAD_Y3,PULL_UP);

    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X0, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X1, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X2, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTE, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_X3, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y0, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y1, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y2, PIN_CONFIG_BLOCK);
    GPIO_VoidPortLockState(PORTA, ALLOW);
    GPIO_VoidPinConfig(KEY_PAD_Y3, PIN_CONFIG_BLOCK);
}

u8 KEY_PAD_U8Read(){
    u8 temp,value;
    GPIO_PINS row,column;
    temp = 0;value = 0;
    for(row=KEY_PAD_X0;row<=KEY_PAD_X3;row++){
        GPIO_VoidPinData(row,LOW);
        for (column=KEY_PAD_Y0;column<=KEY_PAD_Y3;column++){
            temp = GPIO_U8PinRead(column);
            if(temp == PRESSED){
                value = KEY_PAD_BUTTONS[column - KEY_PAD_Y0][row - KEY_PAD_X0];  //must fill the array first according to the key pad
                while((temp = GPIO_U8PinRead(column)) == PRESSED);
                GPIO_VoidPinData(row,HIGH);
                return(value);
            }
        }
        GPIO_VoidPinData(row,HIGH);
    }
    return value;
}
