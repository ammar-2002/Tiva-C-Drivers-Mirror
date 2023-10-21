/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : MCAL
DRIVER  : GPIO_Driver
File    : PROGRAM File
Version : 1.0
CREATED : September 29, 2023
**********************************************************
*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"

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
