/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : NVIC_Driver
 * FILE    : NVIC_Program.c
 * VERSION : 1.0
 * CREATED : October 24, 2023
 *
 * DESCRIPTION:
 * This file contains the implementation of the NVIC (Nested Vector Interrupt Controller) driver
 * for the TM4C123GH6PM (TIVA C) microcontroller. It provides functions for enabling/disabling
 * interrupts, as well as setting the priority level of each interrupt source.
 *
 ********************************************************
 ********************************************************/

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "NVIC_INTERFACE.h"
#include "NVIC_PRIVATE.h"
#include "NVIC_CONFIG.h"

/***************************************************************
 ****************************** APIs ****************************
 ****************************************************************/

/**
 * Function to enable a specific interrupt source.
 *
 * @param copy_tInterruptType: The type of interrupt to be enabled.
 */
void NVIC_VoidEnableInterrupt(INTERRUPT_TYPE copy_tInterruptType){
    SET_BIT(NVIC_REG->EN0[(u32)copy_tInterruptType/NVIC_REGISTER_DIVISIBLE],copy_tInterruptType%NVIC_REGISTER_DIVISIBLE);
}

/**
 * Function to disable a specific interrupt source.
 *
 * @param copy_tInterruptType: The type of interrupt to be disabled.
 */
void NVIC_VoidDisableInterrupt(INTERRUPT_TYPE copy_tInterruptType){
    SET_BIT(NVIC_REG->DIS[(u32)copy_tInterruptType/NVIC_REGISTER_DIVISIBLE],copy_tInterruptType%NVIC_REGISTER_DIVISIBLE);
}

/**
 * Function to set the priority level of a specific interrupt source.
 *
 * @param copy_tInteruptType: The type of interrupt to set its priority.
 * @param copy_tInteruptLevel: The priority level to be set for the interrupt.
 */
void NVIC_VoidSetPriority(INTERRUPT_TYPE copy_tInteruptType, PRIORITY_LEVEL copy_tInteruptLevel){
    switch(copy_tInteruptType % NVIC_PRI_REGISTER_DIVISIBLE){
    case INTA_TYPE:
        NVIC_REG->PRI[copy_tInteruptType / NVIC_PRI_REGISTER_DIVISIBLE].B.INTA = copy_tInteruptLevel;
        break;
    case INTB_TYPE:
        NVIC_REG->PRI[copy_tInteruptType / NVIC_PRI_REGISTER_DIVISIBLE].B.INTB = copy_tInteruptLevel;
        break;
    case INTC_TYPE:
        NVIC_REG->PRI[copy_tInteruptType / NVIC_PRI_REGISTER_DIVISIBLE].B.INTC = copy_tInteruptLevel;
        break;
    case INTD_TYPE:
        NVIC_REG->PRI[copy_tInteruptType / NVIC_PRI_REGISTER_DIVISIBLE].B.INTD = copy_tInteruptLevel;
        break;
    }
}
