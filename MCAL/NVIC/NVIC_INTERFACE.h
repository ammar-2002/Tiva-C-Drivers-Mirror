/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : NVIC_Driver
 * FILE    : NVIC_Interface.h
 * VERSION : 1.0
 * CREATED : October 24, 2023
 *
 * DESCRIPTION:
 * This file contains the public interface for the NVIC (Nested Vector Interrupt Controller)
 * driver used in the TM4C123GH6PM (TIVA C) microcontroller. It defines various enumerations
 * for group mode, interrupt types, and priority levels. Additionally, it provides functions
 * to enable or disable interrupts and set priority levels.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
 ********************** Type Definitions ************************
 ****************************************************************/

/**
 * @enum INTERRUPT_TYPE
 * @brief Enum for interrupt types.
 */
typedef enum {
    GPIO_PORTA_INT = 0,  /**< Represents GPIO Port A Interrupt. */
    GPIO_PORTB_INT = 1,  /**< Represents GPIO Port B Interrupt. */
    GPIO_PORTC_INT = 2,  /**< Represents GPIO Port C Interrupt. */
    GPIO_PORTD_INT = 3,  /**< Represents GPIO Port D Interrupt. */
    // ... (other interrupt types)
    UART6_INT = 62,      /**< Represents UART6 Interrupt. */
    UART7_INT = 63,      /**< Represents UART7 Interrupt. */
} INTERRUPT_TYPE;

/**
 * @enum PRIORITY_LEVEL
 * @brief Enum for priority levels.
 */
typedef enum {
    LEVEL_0, /**< Represents Priority Level 0. */
    LEVEL_1, /**< Represents Priority Level 1. */
    LEVEL_2, /**< Represents Priority Level 2. */
    LEVEL_3, /**< Represents Priority Level 3. */
    LEVEL_4, /**< Represents Priority Level 4. */
    LEVEL_5, /**< Represents Priority Level 5. */
    LEVEL_6, /**< Represents Priority Level 6. */
    LEVEL_7  /**< Represents Priority Level 7. */
} PRIORITY_LEVEL;

/***************************************************************
 ****************************** APIs ****************************
 ****************************************************************/

/**
 * Function to enable a specific interrupt source.
 *
 * @param copy_tInterruptType: The type of interrupt to be enabled.
 */
void NVIC_VoidEnableInterrupt(INTERRUPT_TYPE copy_tInterruptType);

/**
 * Function to disable a specific interrupt source.
 *
 * @param copy_tInterruptType: The type of interrupt to be disabled.
 */
void NVIC_VoidDisableInterrupt(INTERRUPT_TYPE copy_tInterruptType);

/**
 * Function to set the priority level of a specific interrupt source.
 *
 * @param copy_tInteruptType: The type of interrupt for which the priority will be set.
 * @param copy_tInteruptLevel: The desired priority level (LEVEL_0 to LEVEL_7).
 */
void NVIC_VoidSetPriority(INTERRUPT_TYPE copy_tInteruptType, PRIORITY_LEVEL copy_tInteruptLevel);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
