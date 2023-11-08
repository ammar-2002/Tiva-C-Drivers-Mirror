/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : NVIC_Driver
 * FILE    : NVIC_Config.h
 * VERSION : 1.0
 * CREATED : October 24, 2023
 *
 * DESCRIPTION:
 * This is the configuration file for the NVIC (Nested Vector Interrupt Controller) driver.
 * It is currently empty, as there are no specific configuration parameters required for this driver.
 * Configuration options, if needed in the future, will be added here.
 *
 ********************************************************
 ********************************************************/

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: GPIO_VoidPinDirection
 * Return: void
 * Parameters: GPIO_PINS copy_tPins,PIN_DIRECTION copy_tPinDirection
 * documentation: Used to set pin direction if input or output
 * */
void GPIO_VoidPinDirection(GPIO_PINS copy_tPins,PIN_DIRECTION copy_tPinDirection){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    switch(port){
    case PORTA:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOA_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOA_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    case PORTB:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOB_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOB_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    case PORTC:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOC_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOC_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    case PORTD:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOD_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOD_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    case PORTE:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOE_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOE_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    case PORTF:
        switch(copy_tPinDirection){
        case INPUT:
            CLR_BIT(GPIOF_REG.APB->GPIODIR.B.DIR,pin);
            break;
        case OUTPUT:
            SET_BIT(GPIOF_REG.APB->GPIODIR.B.DIR,pin);
            break;
        }
        break;
    }
}

/*Func: GPIO_VoidPinData
 * Return: void
 * Parameters: GPIO_PINS copy_tPins,DATA_OUTPUT copy_tData
 * documentation: Function used to write on a specifc pin
 * */
void GPIO_VoidPinData(GPIO_PINS copy_tPins,DATA_OUTPUT copy_tData){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    u8 gpioDataIndex = 1;
    u8 i;
    for(i=0;i<pin;i++){
        gpioDataIndex = gpioDataIndex * 2;
    }
    switch(port){
    case PORTA:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    case PORTB:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    case PORTC:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    case PORTD:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    case PORTE:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    case PORTF:
        switch(copy_tData){
        case HIGH:
            SET_BIT(GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        case LOW:
            CLR_BIT(GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
            break;
        }
        break;
    }
}

/*Func: GPIO_VoidPinState
 * Return: void
 * Parameters: GPIO_PINS copy_tPins,GPIO_PIN_STATE copy_tPinState
 * documentation: Function used for setting the state of pin if enable or disable
 * */
void GPIO_VoidPinState(GPIO_PINS copy_tPins,GPIO_PIN_STATE copy_tPinState){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    switch(port){
    case PORTA:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOA_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOA_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    case PORTB:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOB_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOB_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    case PORTC:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOC_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOC_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    case PORTD:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOD_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOD_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    case PORTE:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOE_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOE_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    case PORTF:
        switch(copy_tPinState){
        case PIN_ENABLE:
            SET_BIT(GPIOF_REG.APB->GPIODEN.B.DEN,pin);
            break;
        case PIN_DISABLE:
            CLR_BIT(GPIOF_REG.APB->GPIODEN.B.DEN,pin);
            break;
        }
        break;
    }
}

/*Func: GPIO_VoidPortLockState
 * Return: void
 * Parameters: GPIO_PORTS copy_tPorts,PORT_LOCK copy_tPortLockState
 * documentation: Function for setting port lock state if locked 🔒 or unlocked 🔓
 * */
void GPIO_VoidPortLockState(GPIO_PORTS copy_tPorts,PORT_LOCK copy_tPortLockState){
    switch(copy_tPorts){
    case PORTA:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOA_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOA_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    case PORTB:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOB_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOB_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    case PORTC:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOC_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOC_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    case PORTD:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOD_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOD_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    case PORTE:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOE_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOE_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    case PORTF:
        switch(copy_tPortLockState){
        case BLOCK:
            GPIOF_REG.APB->GPIOLOCK.R = 0x0;
            break;
        case ALLOW:
            GPIOF_REG.APB->GPIOLOCK.R = 0x4C4F434B;
            break;
        }
        break;
    }
}

/*Func: GPIO_TGetPortLockState
 * Return: PORT_LOCK => Lock state of the port
 * Parameters: GPIO_PORTS copy_tPorts
 * documentation: Function used for getting the lock state for the port chosen
 * */
PORT_LOCK GPIO_TGetPortLockState(GPIO_PORTS copy_tPorts){
    switch(copy_tPorts){
    case PORTA:
        return (PORT_LOCK)GPIOA_REG.APB->GPIOLOCK.R;
    case PORTB:
        return (PORT_LOCK)GPIOB_REG.APB->GPIOLOCK.R;
    case PORTC:
        return (PORT_LOCK)GPIOC_REG.APB->GPIOLOCK.R;
    case PORTD:
        return (PORT_LOCK)GPIOD_REG.APB->GPIOLOCK.R;
    case PORTE:
        return (PORT_LOCK)GPIOE_REG.APB->GPIOLOCK.R;
    case PORTF:
        return (PORT_LOCK)GPIOF_REG.APB->GPIOLOCK.R;
    }
    return BLOCK;
}

/*Func: GPIO_U8PinRead
 * Return: u8 => Data read from pin
 * Parameters: GPIO_PINS copy_tPins
 * documentation: Function used for read the pin
 * */
u8 GPIO_U8PinRead(GPIO_PINS copy_tPins){
    u8 value = LOW;
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    u8 gpioDataIndex = 1;
    u8 i;
    for(i=0;i<pin;i++){
        gpioDataIndex = gpioDataIndex * 2;
    }
    switch(port){
    case PORTA:
        value = GET_BIT(GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTB:
        value = GET_BIT(GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTC:
        value = GET_BIT(GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTD:
        value = GET_BIT(GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTE:
        value = GET_BIT(GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTF:
        value = GET_BIT(GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    }
    return value;
}

/*Func: GPIO_VoidPinInputMode
 * Return: void
 * Parameters: GPIO_PINS copy_tPins,PIN_INPUT_MODE copy_tPinInputMode
 * documentation: Function used for setting input mode for specific pin if PULL-UP or PULL-Down
 * */
void GPIO_VoidPinInputMode(GPIO_PINS copy_tPins,PIN_INPUT_MODE copy_tPinInputMode){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    switch(port){
    case PORTA:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOA_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOA_REG.APB->GPIOPDR.R,pin);
            break;
        }
        break;
    case PORTB:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOB_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOB_REG.APB->GPIOPDR.R,pin);
            break;
        }
        break;
    case PORTC:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOC_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOC_REG.APB->GPIOPDR.R,pin);
            break;
                }
        break;
    case PORTD:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOD_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOD_REG.APB->GPIOPDR.R,pin);
            break;
        }
        break;
    case PORTE:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOE_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOE_REG.APB->GPIOPDR.R,pin);
            break;
        }
        break;
    case PORTF:
        switch(copy_tPinInputMode){
        case PULL_UP:
            SET_BIT(GPIOF_REG.APB->GPIOPUR.R,pin);
            break;
        case PULL_DOWN:
            SET_BIT(GPIOF_REG.APB->GPIOPDR.R,pin);
            break;
        }
        break;
    }
}

/*Func: GPIO_VoidPinConfig
 * Return: void
 * Parameters: GPIO_PINS copy_tPins,PIN_CONFIG_STATE copy_tPinConfigState
 * documentation: Function used for allowing to the pin to be configured or not
 * */
void GPIO_VoidPinConfig(GPIO_PINS copy_tPins,PIN_CONFIG_STATE copy_tPinConfigState){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    switch(port){
    case PORTA:
        if(GPIO_TGetPortLockState(PORTA) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
            SET_BIT(GPIOA_REG.APB->GPIOCR.R,pin);
            break;
        case PIN_CONFIG_BLOCK:
            CLR_BIT(GPIOA_REG.APB->GPIOCR.R,pin);
            break;
        }
        break;
    case PORTB:
        if(GPIO_TGetPortLockState(PORTB) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
           SET_BIT(GPIOB_REG.APB->GPIOCR.R,pin);
           break;
        case PIN_CONFIG_BLOCK:
           CLR_BIT(GPIOB_REG.APB->GPIOCR.R,pin);
           break;
        }
        break;
    case PORTC:
        if(GPIO_TGetPortLockState(PORTC) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
           SET_BIT(GPIOC_REG.APB->GPIOCR.R,pin);
           break;
        case PIN_CONFIG_BLOCK:
           CLR_BIT(GPIOC_REG.APB->GPIOCR.R,pin);
           break;
        }
        break;
    case PORTD:
        if(GPIO_TGetPortLockState(PORTD) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
           SET_BIT(GPIOD_REG.APB->GPIOCR.R,pin);
           break;
        case PIN_CONFIG_BLOCK:
           CLR_BIT(GPIOD_REG.APB->GPIOCR.R,pin);
           break;
        }
        break;
    case PORTE:
        if(GPIO_TGetPortLockState(PORTE) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
           SET_BIT(GPIOE_REG.APB->GPIOCR.R,pin);
           break;
        case PIN_CONFIG_BLOCK:
           CLR_BIT(GPIOE_REG.APB->GPIOCR.R,pin);
           break;
        }
        break;
    case PORTF:
        if(GPIO_TGetPortLockState(PORTF) == BLOCK)return;
        switch(copy_tPinConfigState){
        case PIN_CONFIG_ALLOW:
           SET_BIT(GPIOF_REG.APB->GPIOCR.R,pin);
           break;
        case PIN_CONFIG_BLOCK:
           CLR_BIT(GPIOF_REG.APB->GPIOCR.R,pin);
           break;
        }
        break;
    }
}

/*Func: GPIO_VoidPinToggle
 * Return: void
 * Parameters: GPIO_PINS copy_tPins
 * documentation: Function used for toggle pin data
 * */
void GPIO_VoidPinToggle(GPIO_PINS copy_tPins){
    u8 pin  = copy_tPins % 10;
    GPIO_PORTS port = (GPIO_PORTS)(copy_tPins / 10);
    u8 gpioDataIndex = 1;
    u8 i;
    for(i=0;i<pin;i++){
        gpioDataIndex = gpioDataIndex * 2;
    }
    switch(port){
    case PORTA:
        TOG_BIT(GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTB:
        TOG_BIT(GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTC:
        TOG_BIT(GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTD:
        TOG_BIT(GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTE:
        TOG_BIT(GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    case PORTF:
        TOG_BIT(GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA,pin);
        break;
    }
}

/*Func: GPIO_VoidPortData
 * Return: void
 * Parameters: GPIO_PORTS copy_tPorts,u8 copy_u8Data
 * documentation: Function used for configure port data as whole
 * */
void GPIO_VoidPortData(GPIO_PORTS copy_tPorts,u8 copy_u8Data){
    switch(copy_tPorts){
    case PORTA:
        GPIOA_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    case PORTB:
        GPIOB_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    case PORTC:
        GPIOC_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    case PORTD:
        GPIOD_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    case PORTE:
        GPIOE_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    case PORTF:
        GPIOF_REG.APB->GPIODATA[ALL_PINS].B.DATA = copy_u8Data;
        break;
    }
}

/*Func: GPIO_VoidPortDataMasked
 * Return: void
 * Parameters: GPIO_PORTS copy_tPorts,u8 copy_u8Data,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size
 * documentation: Function used for output will be on the port and masked according to the mask
 * */
void GPIO_VoidPortDataMasked(GPIO_PORTS copy_tPorts,u8 copy_u8Data,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size){
    u8 gpioDataIndex = 0;
    u8 i;
    for(i=0;i<copy_u8Size;i++){
        gpioDataIndex |= copy_tPinOpen[i];
    }
    switch(copy_tPorts){
    case PORTA:
        GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    case PORTB:
        GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    case PORTC:
        GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    case PORTD:
        GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    case PORTE:
        GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    case PORTF:
        GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA = copy_u8Data;
        break;
    }
}

/*Func: GPIO_U8PortRead
 * Return: u8 => Data read from the port
 * Parameters: GPIO_PORTS copy_tPorts
 * documentation: Function used for reading the data on the port
 * */
u8 GPIO_U8PortRead(GPIO_PORTS copy_tPorts){
    u8 value = 0;
    switch(copy_tPorts){
    case PORTA:
        value = GPIOA_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    case PORTB:
        value = GPIOB_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    case PORTC:
        value = GPIOC_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    case PORTD:
        value = GPIOD_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    case PORTE:
        value = GPIOE_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    case PORTF:
        value = GPIOF_REG.APB->GPIODATA[ALL_PINS].B.DATA;
        break;
    }
    return value;
}

/*Func: GPIO_U8PortReadMasked
 * Return: u8 => Data read from the port after masked
 * Parameters: GPIO_PORTS copy_tPorts,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size
 * documentation: Function used for output will be on the port and masked according to the mask
 * */
u8 GPIO_U8PortReadMasked(GPIO_PORTS copy_tPorts,GPIODATA_PIN_OPEN* copy_tPinOpen,u8 copy_u8Size){
    u8 gpioDataIndex = 0;
    u8 i;
    for(i=0;i<copy_u8Size;i++){
        gpioDataIndex |= copy_tPinOpen[i];
    }
    u8 value = 0;
    switch(copy_tPorts){
    case PORTA:
        value = GPIOA_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    case PORTB:
        value = GPIOB_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    case PORTC:
        value = GPIOC_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    case PORTD:
        value = GPIOD_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    case PORTE:
        value = GPIOE_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    case PORTF:
        value = GPIOF_REG.APB->GPIODATA[gpioDataIndex].B.DATA;
        break;
    }
    return value;
}
