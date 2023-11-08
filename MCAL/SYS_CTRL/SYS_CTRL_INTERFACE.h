/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : SYS_CTRL_Driver
 * FILE    : SYS_CTRL_Interface.h
 * VERSION : 1.0
 * CREATED : September 17, 2023
 *
 * DESCRIPTION:
 * This file contains the interface for the SYS_CTRL_Driver,
 * which is responsible for configuring and controlling the system clock
 * and peripheral clocks on the TM4C123GH6PM (TIVA C) microcontroller.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_
#define MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_

/***************************************************************
*********************** Type definitions ***********************
****************************************************************/

/* Enum for peripheral to be enabled */
typedef enum {
    GPIOA, /**< Represents GPIO Port A. */
    GPIOB, /**< Represents GPIO Port B. */
    GPIOC, /**< Represents GPIO Port C. */
    GPIOD, /**< Represents GPIO Port D. */
    GPIOE, /**< Represents GPIO Port E. */
    GPIOF  /**< Represents GPIO Port F. */
} PERIPHERAL_t;

/* Enum for peripheral to enable the clock for */
typedef enum {
    GPIOA_CLOCK = 64, /**< Represents the clock enable for GPIO Port A. */
    GPIOB_CLOCK,     /**< Represents the clock enable for GPIO Port B. */
    GPIOC_CLOCK,     /**< Represents the clock enable for GPIO Port C. */
    GPIOD_CLOCK,     /**< Represents the clock enable for GPIO Port D. */
    GPIOE_CLOCK,     /**< Represents the clock enable for GPIO Port E. */
    GPIOF_CLOCK      /**< Represents the clock enable for GPIO Port F. */
} PERIPHERAL_CLOCK_t;


/***************************************************************
****************************** APIs ****************************
****************************************************************/

/**
 * Initialize the system clock according to the chosen configuration in the CONFIG file.
 */
void SYS_CTRL_VoidClockInit(void);

/**
 * Enable a specific peripheral.
 *
 * @param copy_tPeripheral: The peripheral to enable.
 */
void SYS_CTRL_VoidEnablePeripheral(PERIPHERAL_t copy_tPeripheral);

/**
 * Disable a specific peripheral.
 *
 * @param copy_tPeripheral: The peripheral to disable.
 */
void SYS_CTRL_VoidDisablePeripheral(PERIPHERAL_t copy_tPeripheral);

/**
 * Enable the clock to a peripheral.
 *
 * @param copy_tPeripheral: The peripheral for which to enable the clock.
 */
void SYS_CTRL_VoidEnableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral);

/**
 * Disable the clock to a peripheral.
 *
 * @param copy_tPeripheral: The peripheral for which to disable the clock.
 */
void SYS_CTRL_VoidDisableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral);

#endif /* MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_ */
