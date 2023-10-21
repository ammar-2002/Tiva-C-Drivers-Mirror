/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : PUSH_BUTTON_Driver
File    : PROGRAM File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "SYS_CTRL_INTERFACE.h"
#include "PUSH_BUTTON_INTERFACE.h"
#include "PUSH_BUTTON_PRIVATE.h"
#include "PUSH_BUTTON_CONFIG.h"

void BUTTON_VoidButtonInit(BUTTON_t copy_tButton){
    SYS_CTRL_VoidClockInit();
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOF_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOF);
    GPIO_VoidPortLockState(PORTF, ALLOW);
    switch(copy_tButton){
    case BUTTON_1:
        GPIO_VoidPinConfig(BUTTON_1_PIN, PIN_CONFIG_ALLOW);
        GPIO_VoidPinState(BUTTON_1_PIN, PIN_ENABLE);
        GPIO_VoidPinDirection(BUTTON_1_PIN, INPUT);
        #if BUTTON_1_RESISTANCE == PULL_UP_RESISTOR
        GPIO_VoidPinInputMode(BUTTON_1_PIN, PULL_UP);
        #elif BUTTON_1_RESISTANCE == PULL_UP_RESISTOR
        GPIO_VoidPinInputMode(BUTTON_1_PIN, PULL_DOWN);
        #else
        #error "Unknown resistor type"
        #endif
        GPIO_VoidPortLockState(PORTF, ALLOW);
        GPIO_VoidPinConfig(BUTTON_1_PIN, PIN_CONFIG_BLOCK);
        break;
    case BUTTON_2:
        GPIO_VoidPinConfig(BUTTON_2_PIN, PIN_CONFIG_ALLOW);
        GPIO_VoidPinState(BUTTON_2_PIN, PIN_ENABLE);
        GPIO_VoidPinDirection(BUTTON_2_PIN, INPUT);
        #if BUTTON_1_RESISTANCE == PULL_UP_RESISTOR
        GPIO_VoidPinInputMode(BUTTON_2_PIN, PULL_UP);
        #elif BUTTON_1_RESISTANCE == PULL_UP_RESISTOR
        GPIO_VoidPinInputMode(BUTTON_2_PIN, PULL_DOWN);
        #else
        #error "Unknown resistor type"
        #endif
        GPIO_VoidPortLockState(PORTF, ALLOW);
        GPIO_VoidPinConfig(BUTTON_2_PIN, PIN_CONFIG_BLOCK);
        break;
    }
}

u8 BUTTON_U8ButtonRead(BUTTON_t copy_tButton){
    u8 value = LOW;
    switch(copy_tButton){
    case BUTTON_1:
        value = GPIO_U8PinRead(BUTTON_1_PIN);
        break;
    case BUTTON_2:
        value = GPIO_U8PinRead(BUTTON_2_PIN);
    }
    return value;
}
