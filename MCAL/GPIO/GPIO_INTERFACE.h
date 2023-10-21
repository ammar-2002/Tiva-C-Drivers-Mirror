/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : MCAL
DRIVER  : GPIO_Driver
File    : INTERFACE File
Version : 1.0
CREATED : September 29, 2023
**********************************************************
*********************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum {
    PIN_0 = 1,
    PIN_1 = 2,
    PIN_2 = 4,
    PIN_3 = 8,
    PIN_4 = 16,
    PIN_5 = 32,
    PIN_6 = 64,
    PIN_7 = 128,
    ALL_PINS = 255
}GPIODATA_PIN_OPEN;

typedef enum{
    PA0=10,
    PA1=11,
    PA2=12,
    PA3=13,
    PA4=14,
    PA5=15,
    PA6=16,
    PA7=17,
    PB0=20,
    PB1=21,
    PB2=22,
    PB3=23,
    PB4=24,
    PB5=25,
    PB6=26,
    PB7=27,
    PC0=30,
    PC1=31,
    PC2=32,
    PC3=33,
    PC4=34,
    PC5=35,
    PC6=36,
    PC7=37,
    PD0=40,
    PD1=41,
    PD2=42,
    PD3=43,
    PD4=44,
    PD5=45,
    PD6=46,
    PD7=47,
    PE0=50,
    PE1=51,
    PE2=52,
    PE3=53,
    PE4=54,
    PE5=55,
    PE6=56,
    PE7=57,
    PF0=60,
    PF1=61,
    PF2=62,
    PF3=63,
    PF4=64,
    PF5=65,
    PF6=66,
    PF7=67
}GPIO_PINS;

typedef enum{
    HIGH=1,
    LOW=0
}DATA_OUTPUT;

typedef enum{
    INPUT=0,
    OUTPUT=1
}PIN_DIRECTION;

typedef enum{
    PULL_UP=1,
    PULL_DOWN=0
}PIN_INPUT_MODE;

typedef enum{
    ALLOW=0,
    BLOCK=1
}PORT_LOCK;

typedef enum{
    PIN_CONFIG_ALLOW=1,
    PIN_CONFIG_BLOCK=0
}PIN_CONFIG_STATE;

typedef enum{
    PORTA=1,
    PORTB=2,
    PORTC=3,
    PORTD=4,
    PORTE=5,
    PORTF=6,
}GPIO_PORTS;

typedef enum{
    PIN_ENABLE,
    PIN_DISABLE
}GPIO_PIN_STATE;

void GPIO_VoidPinDirection(GPIO_PINS copy_tPins,PIN_DIRECTION copy_tPinDirection);
void GPIO_VoidPinData(GPIO_PINS copy_tPins,DATA_OUTPUT copy_tData);
void GPIO_VoidPinState(GPIO_PINS copy_tPins,GPIO_PIN_STATE copy_tPinState);
void GPIO_VoidPortLockState(GPIO_PORTS copy_tPorts,PORT_LOCK copy_tPortLockState);
void GPIO_VoidPinInputMode(GPIO_PINS copy_tPins,PIN_INPUT_MODE copy_tPinInputMode);
void GPIO_VoidPinConfig(GPIO_PINS copy_tPins,PIN_CONFIG_STATE copy_tPinConfigState);
void GPIO_VoidPinToggle(GPIO_PINS copy_tPins);
void GPIO_VoidPortData(GPIO_PORTS copy_tPorts,u8 copy_u8Data);
void GPIO_VoidPortDataMasked(GPIO_PORTS copy_tPorts,u8 copy_u8Data,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size);
u8   GPIO_U8PortRead(GPIO_PORTS copy_tPorts);
u8   GPIO_U8PortReadMasked(GPIO_PORTS copy_tPorts,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size);
u8   GPIO_U8PinRead(GPIO_PINS copy_tPins);
PORT_LOCK GPIO_TGetPortLockState(GPIO_PORTS copy_tPorts);


#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
