/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : HAL
 * DRIVER  : RTOS_Driver
 * FILE    : PRIVATE File
 * VERSION : 1.0
 * CREATED : October 29, 2023
 ********************************************************
 * DESCRIPTION:
 * This file contains private definitions and structures used
 * by the Real-Time Operating System (RTOS) driver in the HAL layer.
 * It defines task-related enumerations, structures, and constants.
 ********************************************************/

#ifndef HAL_RTOS_RTOS_PRIVATE_H_
#define HAL_RTOS_RTOS_PRIVATE_H_

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/
#include "STD_TYPES.h"

/***************************************************************
 *********************** Type Definitions **********************
 ****************************************************************/

/**
 * @enum TASK_STATE_t
 * @brief Enum for task states.
 */
typedef enum{
    SUSPENDED,   /**< Represents a task in the SUSPENDED state. */
    RUNNING,     /**< Represents a task in the RUNNING state. */
    EXECUTING    /**< Represents a task in the EXECUTING state. */
} TASK_STATE_t;

/**
 * @enum TASK_EXIST_t
 * @brief Enum for task existence.
 */
typedef enum{
    NOT_EXIST, /**< Represents a task that does not exist. */
    EXIST      /**< Represents a task that exists. */
} TASK_EXIST_t;

/**
 * @enum TASK_FOUND_t
 * @brief Enum for task found status.
 */
typedef enum{
    FOUND,     /**< Represents a found task. */
    NOT_FOUND  /**< Represents a task not found. */
} TASK_FOUND_t;

/**
 * @struct TASK_t
 * @brief Struct representing a task.
 */
typedef struct{
    u16 Task_ID;                 /**< Task ID. */
    void (*Task_Handler)(void);  /**< Task handler function pointer. */
    u8 periodicity;              /**< Task periodicity. */
    TASK_STATE_t tState;         /**< Task state. */
    TASK_EXIST_t tExistState;    /**< Task existence state. */
    TASK_PRIORITY_t tPriority;   /**< Task priority. */
    u8 time;                     /**< Task time. */
}TASK_t;

/***************************************************************
 *************************** Defines ****************************
 ****************************************************************/

#define FINISHED        0

#define CYCLE_TIME      1

#define ID_INDEX        1
#define PRIORITY_INDEX  0

#endif /* HAL_RTOS_RTOS_PRIVATE_H_ */
