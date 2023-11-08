/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : GPIO_Driver
 * FILE    : INTERFACE File
 * VERSION : 1.0
 * CREATED : September 29, 2023
 *
 * DESCRIPTION:
 * This is the interface file for the GPIO (General-Purpose Input/Output) driver.
 * It provides a set of functions to configure and control GPIO pins and ports.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
*********************** Type Definitions ***********************
****************************************************************/

/**
 * @enum GPIODATA_PIN_OPEN
 * @brief Enum for open pins for modification.
 */
typedef enum {
    PIN_0 = 1,     /**< Represents Pin 0. */
    PIN_1 = 2,     /**< Represents Pin 1. */
    PIN_2 = 4,     /**< Represents Pin 2. */
    PIN_3 = 8,     /**< Represents Pin 3. */
    PIN_4 = 16,    /**< Represents Pin 4. */
    PIN_5 = 32,    /**< Represents Pin 5. */
    PIN_6 = 64,    /**< Represents Pin 6. */
    PIN_7 = 128,   /**< Represents Pin 7. */
    ALL_PINS = 255 /**< Represents All Pins. */
} GPIODATA_PIN_OPEN;

/**
 * @enum GPIO_PINS
 * @brief Enum for available pins.
 */
typedef enum {
    PA0 = 10, /**< Represents Pin PA0. */
    PA1 = 11, /**< Represents Pin PA1. */
    PA2 = 12, /**< Represents Pin PA2. */
    PA3 = 13, /**< Represents Pin PA3. */
    PA4 = 14, /**< Represents Pin PA4. */
    PA5 = 15, /**< Represents Pin PA5. */
    PA6 = 16, /**< Represents Pin PA6. */
    PA7 = 17, /**< Represents Pin PA7. */
    PB0 = 20, /**< Represents Pin PB0. */
    PB1 = 21, /**< Represents Pin PB1. */
    PB2 = 22, /**< Represents Pin PB2. */
    PB3 = 23, /**< Represents Pin PB3. */
    PB4 = 24, /**< Represents Pin PB4. */
    PB5 = 25, /**< Represents Pin PB5. */
    PB6 = 26, /**< Represents Pin PB6. */
    PB7 = 27, /**< Represents Pin PB7. */
    PC0 = 30, /**< Represents Pin PC0. */
    PC1 = 31, /**< Represents Pin PC1. */
    PC2 = 32, /**< Represents Pin PC2. */
    PC3 = 33, /**< Represents Pin PC3. */
    PC4 = 34, /**< Represents Pin PC4. */
    PC5 = 35, /**< Represents Pin PC5. */
    PC6 = 36, /**< Represents Pin PC6. */
    PC7 = 37, /**< Represents Pin PC7. */
    PD0 = 40, /**< Represents Pin PD0. */
    PD1 = 41, /**< Represents Pin PD1. */
    PD2 = 42, /**< Represents Pin PD2. */
    PD3 = 43, /**< Represents Pin PD3. */
    PD4 = 44, /**< Represents Pin PD4. */
    PD5 = 45, /**< Represents Pin PD5. */
    PD6 = 46, /**< Represents Pin PD6. */
    PD7 = 47, /**< Represents Pin PD7. */
    PE0 = 50, /**< Represents Pin PE0. */
    PE1 = 51, /**< Represents Pin PE1. */
    PE2 = 52, /**< Represents Pin PE2. */
    PE3 = 53, /**< Represents Pin PE3. */
    PE4 = 54, /**< Represents Pin PE4. */
    PE5 = 55, /**< Represents Pin PE5. */
    PE6 = 56, /**< Represents Pin PE6. */
    PE7 = 57, /**< Represents Pin PE7. */
    PF0 = 60, /**< Represents Pin PF0. */
    PF1 = 61, /**< Represents Pin PF1. */
    PF2 = 62, /**< Represents Pin PF2. */
    PF3 = 63, /**< Represents Pin PF3. */
    PF4 = 64, /**< Represents Pin PF4. */
    PF5 = 65, /**< Represents Pin PF5. */
    PF6 = 66, /**< Represents Pin PF6. */
    PF7 = 67, /**< Represents Pin PF7. */
} GPIO_PINS;

/**
 * @enum DATA_OUTPUT
 * @brief Enum for pins data.
 */
typedef enum {
    HIGH = 1, /**< Represents High (1). */
    LOW = 0   /**< Represents Low (0). */
} DATA_OUTPUT;

/**
 * @enum PIN_DIRECTION
 * @brief Enum for pins direction.
 */
typedef enum {
    INPUT = 0,  /**< Represents Input Direction. */
    OUTPUT = 1, /**< Represents Output Direction. */
} PIN_DIRECTION;

/**
 * @enum PIN_INPUT_MODE
 * @brief Enum for resistor type for input pins.
 */
typedef enum {
    PULL_UP = 1,   /**< Represents Pull-Up Resistor. */
    PULL_DOWN = 0, /**< Represents Pull-Down Resistor. */
} PIN_INPUT_MODE;

/**
 * @enum PORT_LOCK
 * @brief Enum for port lock state.
 */
typedef enum {
    ALLOW = 0, /**< Represents Port Lock State: Allowed. */
    BLOCK = 1, /**< Represents Port Lock State: Blocked. */
} PORT_LOCK;

/**
 * @enum PIN_CONFIG_STATE
 * @brief Enum for pins configuration state.
 */
typedef enum {
    PIN_CONFIG_ALLOW = 1, /**< Represents Pin Configuration Allowed. */
    PIN_CONFIG_BLOCK = 0, /**< Represents Pin Configuration Blocked. */
} PIN_CONFIG_STATE;

/**
 * @enum GPIO_PORTS
 * @brief Enum for available ports.
 */
typedef enum {
    PORTA = 1, /**< Represents Port A. */
    PORTB = 2, /**< Represents Port B. */
    PORTC = 3, /**< Represents Port C. */
    PORTD = 4, /**< Represents Port D. */
    PORTE = 5, /**< Represents Port E. */
    PORTF = 6, /**< Represents Port F. */
} GPIO_PORTS;

/**
 * @enum GPIO_PIN_STATE
 * @brief Enum for pins state.
 */
typedef enum {
    PIN_ENABLE,  /**< Represents Pin Enable State. */
    PIN_DISABLE, /**< Represents Pin Disable State. */
} GPIO_PIN_STATE;

/***************************************************************
****************************** APIs ****************************
****************************************************************/

/**
 * Function to set the pin direction as input or output.
 *
 * @param copy_tPins: The pin for which the direction will be set.
 * @param copy_tPinDirection: The desired direction (INPUT or OUTPUT).
 */
void GPIO_VoidPinDirection(GPIO_PINS copy_tPins, PIN_DIRECTION copy_tPinDirection);

/**
 * Function to write data (HIGH or LOW) to a specific pin.
 *
 * @param copy_tPins: The pin for which the data will be written.
 * @param copy_tData: The data to be written (HIGH or LOW).
 */
void GPIO_VoidPinData(GPIO_PINS copy_tPins, DATA_OUTPUT copy_tData);

/**
 * Function to enable or disable a specific pin.
 *
 * @param copy_tPins: The pin to be enabled or disabled.
 * @param copy_tPinState: The desired pin state (PIN_ENABLE or PIN_DISABLE).
 */
void GPIO_VoidPinState(GPIO_PINS copy_tPins, GPIO_PIN_STATE copy_tPinState);

/**
 * Function for setting the port lock state as ALLOW or BLOCK.
 *
 * @param copy_tPorts: The port for which the lock state will be set.
 * @param copy_tPortLockState: The desired port lock state (ALLOW or BLOCK).
 */
void GPIO_VoidPortLockState(GPIO_PORTS copy_tPorts, PORT_LOCK copy_tPortLockState);

/**
 * Function to configure the input mode for a specific pin as PULL-UP or PULL-DOWN.
 *
 * @param copy_tPins: The pin for which the input mode will be configured.
 * @param copy_tPinInputMode: The desired input mode (PULL_UP or PULL_DOWN).
 */
void GPIO_VoidPinInputMode(GPIO_PINS copy_tPins, PIN_INPUT_MODE copy_tPinInputMode);

/**
 * Function to allow or block the pin's configuration.
 *
 * @param copy_tPins: The pin for which the configuration state will be set.
 * @param copy_tPinConfigState: The desired pin configuration state (PIN_CONFIG_ALLOW or PIN_CONFIG_BLOCK).
 */
void GPIO_VoidPinConfig(GPIO_PINS copy_tPins, PIN_CONFIG_STATE copy_tPinConfigState);

/**
 * Function to toggle the data on a specific pin.
 *
 * @param copy_tPins: The pin for which the data will be toggled.
 */
void GPIO_VoidPinToggle(GPIO_PINS copy_tPins);

/**
 * Function to configure the entire port's data.
 *
 * @param copy_tPorts: The port for which the data will be configured.
 * @param copy_u8Data: The data to be written to the entire port.
 */
void GPIO_VoidPortData(GPIO_PORTS copy_tPorts, u8 copy_u8Data);

/**
 * Function to write data to the port, masked according to the mask.
 *
 * @param copy_tPorts: The port for which the data will be written.
 * @param copy_u8Data: The data to be written to the port.
 * @param copy_tPinOpen: Array of pins to be modified.
 * @param copy_u8Size: The number of pins in the array.
 */
void GPIO_VoidPortDataMasked(GPIO_PORTS copy_tPorts, u8 copy_u8Data, GPIODATA_PIN_OPEN* copy_tPinOpen, u8 copy_u8Size);

/**
 * Function to read the data from the specified port.
 *
 * @param copy_tPorts: The port from which the data will be read.
 * @return u8: The data read from the port.
 */
u8 GPIO_U8PortRead(GPIO_PORTS copy_tPorts);

/**
 * Function to read data from the port, masked according to the mask.
 *
 * @param copy_tPorts: The port from which the data will be read.
 * @param copy_tPinOpen: Array of pins to be read.
 * @param copy_u8Size: The number of pins in the array.
 * @return u8: The data read from the port after being masked.
 */
u8 GPIO_U8PortReadMasked(GPIO_PORTS copy_tPorts, GPIODATA_PIN_OPEN* copy_tPinOpen, u8 copy_u8Size);

/**
 * Function to read the data from a specific pin.
 *
 * @param copy_tPins: The pin from which the data will be read.
 * @return u8: The data read from the pin.
 */
u8 GPIO_U8PinRead(GPIO_PINS copy_tPins);

/**
 * Function to get the lock state of the specified port (ALLOW or BLOCK).
 *
 * @param copy_tPorts: The port for which the lock state will be checked.
 * @return PORT_LOCK: The lock state of the port.
 */
PORT_LOCK GPIO_TGetPortLockState(GPIO_PORTS copy_tPorts);

#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
