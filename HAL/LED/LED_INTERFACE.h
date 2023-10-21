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

typedef enum {
    LED_RED     =1,
    LED_BLUE    =2,
    LED_GREEN   =3
}LED_t;


void LED_VoidLedInit(LED_t copy_tLed);
void LED_VoidLedOn(LED_t copy_tLed);
void LED_VoidLedOff(LED_t copy_tLed);
void LED_VoidLedToggle(LED_t copy_tLed);


#endif /* HAL_LED_LED_INTERFACE_H_ */
