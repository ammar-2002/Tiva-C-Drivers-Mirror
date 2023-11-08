/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : SYS_CTRL_Driver
 * FILE    : SYS_CTRL_Program.c
 * VERSION : 1.0
 * CREATED : September 17, 2023
 *
 * DESCRIPTION:
 * This file contains the program code for the SYS_CTRL_Driver,
 * responsible for configuring and controlling the system clock
 * and peripheral clocks on the TM4C123GH6PM (TIVA C) microcontroller.
 *
 ********************************************************
 ********************************************************/

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYS_CTRL_INTERFACE.h"
#include "SYS_CTRL_PRIVATE.h"
#include "SYS_CTRL_CONFIG.h"

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/*Func: SYS_CTRL_VoidClockInit
 * Return: void
 * Parameters: void
 * documentation: Initialize the system clock according to the chosen configuration in the CONFIG file
 * */
void SYS_CTRL_VoidClockInit(void){
    #if RCC_SYSCLK == RCC_MOSC
        SYS_CTRL_REG->RCC.B.XTAL = 0x15;                            /*Select 16MHz source clock*/
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.OSCSRC = RCC_MOSC;                      /*Select MOSC as system clock*/
            SYS_CTRL_REG->RCC.B.BYPASS = ENABLE;                        /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_64
            SYS_CTRL_REG->RCC2.B.USERCC2 = ENABLE;
            SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_MOSC;                    /*Select MOSC as system clock*/
            SYS_CTRL_REG->RCC2.B.BYPASS2 = ENABLE;                      /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #elif RCC_SYSCLK == RCC_PIOSC
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.OSCSRC = RCC_PIOSC;                     /*Select PIOSC as system clock*/
            SYS_CTRL_REG->RCC.B.BYPASS = ENABLE;                        /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_64
            SYS_CTRL_REG->RCC2.B.USERCC2 = ENABLE;
            SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_PIOSC;                   /*Select PIOSC as system clock*/
            SYS_CTRL_REG->RCC2.B.BYPASS2 = ENABLE;                      /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #elif RCC_SYSCLK == RCC_PIOSC_DIVIDED_BY_4
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.OSCSRC = RCC_PIOSC_DIVIDED_BY_4;        /*Select PIOSC divided by 4 as system clock*/
            SYS_CTRL_REG->RCC.B.BYPASS = ENABLE;                        /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_64
            SYS_CTRL_REG->RCC2.B.USERCC2 = ENABLE;
            SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_PIOSC_DIVIDED_BY_4;      /*Select PIOSC divided by 4 as system clock*/
            SYS_CTRL_REG->RCC2.B.BYPASS2 = ENABLE;                      /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #elif RCC_SYSCLK == RCC_LFIOSC
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.OSCSRC = RCC_LFIOSC;                    /*Select LFIOSC as system clock*/
            SYS_CTRL_REG->RCC.B.BYPASS = ENABLE;                        /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_64
            SYS_CTRL_REG->RCC2.B.USERCC2 = ENABLE;
            SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_LFIOSC;                  /*Select LFIOSC as system clock*/
            SYS_CTRL_REG->RCC2.B.BYPASS2 = ENABLE;                      /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #elif RCC_SYSCLK == RCC_EXTERNAL_OSC_32KHZ
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.OSCSRC = RCC_EXTERNAL_OSC_32KHZ;        /*Select external 32KHz OSC as system clock*/
            SYS_CTRL_REG->RCC.B.BYPASS = ENABLE;                        /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_64
            SYS_CTRL_REG->RCC2.B.USERCC2 = ENABLE;
            SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_EXTERNAL_OSC_32KHZ;      /*Select external 32KHz OSC as system clock*/
            SYS_CTRL_REG->RCC2.B.BYPASS2 = ENABLE;                      /*To enable OSC source for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #elif RCC_SYSCLK == RCC_PLL
        #if SYSDIV_VALUE < SYSDIV_BY_17
            SYS_CTRL_REG->RCC.B.PWRDN = DISABLE;
            #if PLL_CLOCK_MODE == PLL_CLOCK_MOSC
                SYS_CTRL_REG->RCC.B.OSCSRC = RCC_MOSC;                      /*Select MOSC for PLL*/
            #elif PLL_CLOCK_MODE == PLL_CLOCK_PIOSC
                SYS_CTRL_REG->RCC.B.OSCSRC = RCC_PIOSC;                     /*Select PIOSC for PLL*/
            #endif
            SYS_CTRL_REG->RCC.B.BYPASS = DISABLE;                           /*To enable PLL for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC.B.SYSDIV = SYSDIV_VALUE;
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #elif SYSDIV_VALUE <= SYSDIV_BY_63_5
            SYS_CTRL_REG->RCC2.B.PWRDN2 = DISABLE;
            #if PLL_CLOCK_MODE == PLL_CLOCK_MOSC
                SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_MOSC;                    /*Select MOSC for PLL*/
            #elif PLL_CLOCK_MODE == PLL_CLOCK_PIOSC
                SYS_CTRL_REG->RCC2.B.OSCSRC2 = RCC_PIOSC;                   /*Select PIOSC for PLL*/
            #endif
            SYS_CTRL_REG->RCC.B.BYPASS = DISABLE;                           /*To enable PLL for the output clock*/
            #if SYSDIV_STATE == SYSDIV_ON
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_ON;
                SYS_CTRL_REG->RCC2.B.SYSDIV2 = (SYSDIV_VALUE % 64);
                SYS_CTRL_REG->RCC2.B.SYSDIV2LSB = 0x1 & (~(u8)(SYSDIV_VALUE / 64));
            #elif SYSDIV_STATE == SYSDIV_OFF
                SYS_CTRL_REG->RCC.B.USESYSDIV = SYSDIV_OFF;
            #endif
        #else
            #error "Clock divisor specified is not valid for this source"
        #endif
    #else
        #error "Wrong clock source"
    #endif
}

/*Func: SYS_CTRL_VoidEnablePeripheral
 * Return: void
 * Parameters: PERIPHERAL_t copy_tPeripheral
 * documentation: Function for enabling specific peripheral
 * */
void SYS_CTRL_VoidEnablePeripheral(PERIPHERAL_t copy_tPeripheral){
    switch(copy_tPeripheral / SYS_CTRL_RCC_PERIPHERAL_DIVIDER){
    case SYS_CTRL_GPIO_RCC_REGISTER:
        SET_BIT(SYS_CTRL_REG->RCGCGPIO.R,copy_tPeripheral%32);
        break;
    }
}

/*Func: SYS_CTRL_VoidDisablePeripheral
 * Return: void
 * Parameters: PERIPHERAL_t copy_tPeripheral
 * documentation: Function for disabling specific peripheral
 * */
void SYS_CTRL_VoidDisablePeripheral(PERIPHERAL_t copy_tPeripheral){
    switch(copy_tPeripheral / SYS_CTRL_RCC_PERIPHERAL_DIVIDER){
    case SYS_CTRL_GPIO_RCC_REGISTER:
        CLR_BIT(SYS_CTRL_REG->RCGCGPIO.R,copy_tPeripheral%32);
        break;
    }
}

/*Func: SYS_CTRL_VoidEnableClockForPeripheral
 * Return: void
 * Parameters: PERIPHERAL_CLOCK_t copy_tPeripheral
 * documentation: Function for enable the clock to peripheral
 * */
void SYS_CTRL_VoidEnableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral){
    switch(copy_tPeripheral / SYS_CTRL_RCC_PERIPHERAL_DIVIDER){
    case SYS_CTRL_RCGC2_REGISTER:
        SET_BIT(SYS_CTRL_REG->RCGC2.R,copy_tPeripheral%32);
        break;
    }
}

/*Func: SYS_CTRL_VoidDisableClockForPeripheral
 * Return: void
 * Parameters: PERIPHERAL_CLOCK_t copy_tPeripheral
 * documentation: Function for disable the clock to peripheral
 * */
void SYS_CTRL_VoidDisableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral){
    switch(copy_tPeripheral / SYS_CTRL_RCC_PERIPHERAL_DIVIDER){
    case SYS_CTRL_RCGC2_REGISTER:
        CLR_BIT(SYS_CTRL_REG->RCGC2.R,copy_tPeripheral%32);
        break;
    }
}
