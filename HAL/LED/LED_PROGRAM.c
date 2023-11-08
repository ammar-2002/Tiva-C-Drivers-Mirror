/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : LED_Driver
File    : PROGRAM File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "SYS_CTRL_INTERFACE.h"
#include "LED_INTERFACE.h"
#include "LED_PRIVATE.h"
#include "LED_CONFIG.h"

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: LED_VoidLedInit
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Initialize the led chossen
 * */
void LED_VoidLedInit(LED_t copy_tLed){
    SYS_CTRL_VoidClockInit();
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOF_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOF);
    switch(copy_tLed){
        case LED_RED:
            GPIO_VoidPinState(LED_RED_PIN, PIN_ENABLE);
            GPIO_VoidPinDirection(LED_RED_PIN,OUTPUT);
            break;
        case LED_BLUE:
            GPIO_VoidPinState(LED_BLUE_PIN, PIN_ENABLE);
            GPIO_VoidPinDirection(LED_BLUE_PIN,OUTPUT);
            break;
        case LED_GREEN:
            GPIO_VoidPinState(LED_GREEN_PIN, PIN_ENABLE);
            GPIO_VoidPinDirection(LED_GREEN_PIN,OUTPUT);
            break;
        default:
            break;
    }
}

/*Func: LED_VoidLedOn
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for turn on the led choosen
 * */
void LED_VoidLedOn(LED_t copy_tLed){
    switch(copy_tLed){
        case LED_RED:
            GPIO_VoidPinData(LED_RED_PIN, HIGH);
            break;
        case LED_BLUE:
            GPIO_VoidPinData(LED_BLUE_PIN, HIGH);
            break;
        case LED_GREEN:
            GPIO_VoidPinData(LED_GREEN_PIN, HIGH);
            break;
        default:
            break;
    }
}

/*Func: LED_VoidLedOff
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for turn off the led choosen
 * */
void LED_VoidLedOff(LED_t copy_tLed){
    switch(copy_tLed){
        case LED_RED:
            GPIO_VoidPinData(LED_RED_PIN, LOW);
            break;
        case LED_BLUE:
            GPIO_VoidPinData(LED_BLUE_PIN, LOW);
            break;
        case LED_GREEN:
            GPIO_VoidPinData(LED_GREEN_PIN, LOW);
            break;
        default:
            break;
    }
}

/*Func: LED_VoidLedToggle
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for toggle the led choosen
 * */
void LED_VoidLedToggle(LED_t copy_tLed){
    switch(copy_tLed){
        case LED_RED:
            GPIO_VoidPinToggle(LED_RED_PIN);
            break;
        case LED_BLUE:
            GPIO_VoidPinToggle(LED_BLUE_PIN);
            break;
        case LED_GREEN:
            GPIO_VoidPinToggle(LED_GREEN_PIN);
            break;
        default:
            break;
    }
}
