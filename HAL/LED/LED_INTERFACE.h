/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : LED_Driver
File    : INTERFACE File
Version : 1.0
CREATED : October 16, 2023
**********************************************************
*********************************************************/

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_

/***************************************************************
*********************** Type definitions ***********************
****************************************************************/

/*** Enum for available leds ***/
typedef enum {
    LED_RED     =1,
    LED_BLUE    =2,
    LED_GREEN   =3
}LED_t;

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: LED_VoidLedInit
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Initialize the led chossen
 * */
void LED_VoidLedInit(LED_t copy_tLed);

/*Func: LED_VoidLedOn
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for turn on the led choosen
 * */
void LED_VoidLedOn(LED_t copy_tLed);

/*Func: LED_VoidLedOff
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for turn off the led choosen
 * */
void LED_VoidLedOff(LED_t copy_tLed);

/*Func: LED_VoidLedToggle
 * Return: void
 * Parameters: LED_t copy_tLed
 * documentation: Function for toggle the led choosen
 * */
void LED_VoidLedToggle(LED_t copy_tLed);


#endif /* HAL_LED_LED_INTERFACE_H_ */
