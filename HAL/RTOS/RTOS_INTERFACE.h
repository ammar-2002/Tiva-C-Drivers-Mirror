/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : HAL
 * DRIVER  : RTOS_Driver
 * FILE    : INTERFACE File
 * VERSION : 1.0
 * CREATED : October 29, 2023
 ********************************************************
 * DESCRIPTION:
 * This file contains the public interface for the Real-Time Operating System (RTOS) driver
 * in the HAL (Hardware Abstraction Layer) of the TIVA C microcontroller. It provides functions
 * to create tasks, delete tasks, suspend tasks, resume tasks, and start the RTOS.
 ********************************************************/

#ifndef HAL_RTOS_RTOS_INTERFACE_H_
#define HAL_RTOS_RTOS_INTERFACE_H_

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
 *********************** Type Definitions *********************
 ****************************************************************/

/**
 * @enum FUNC_STATE_t
 * @brief Enum for function execution state.
 * Possible values are NOT_OK and OK.
 */

typedef enum {
    NOT_OK, /**< Represents an unsuccessful function execution. */
    OK     /**< Represents a successful function execution. */
} FUNC_STATE_t;

/**
 * @enum Error_t
 * @brief Enum for error types.
 * Possible error types include NO_ERROR, NO_TASK_SEND, MAX_TASK_REACHED,
 * NO_TASK_FOUND, TASK_ID_OUT_OF_LIMIT, ALREADY_SUSPENDED, and ALREADY_RUNNING.
 */

typedef enum {
    NO_ERROR,             /**< No error occurred. */
    NO_TASK_SEND,         /**< No task provided to the function. */
    MAX_TASK_REACHED,     /**< Maximum number of tasks reached. */
    NO_TASK_FOUND,        /**< Task not found. */
    TASK_ID_OUT_OF_LIMIT, /**< Task ID is out of limit. */
    ALREADY_SUSPENDED,    /**< Task is already suspended. */
    ALREADY_RUNNING       /**< Task is already running. */
} Error_t;

/**
 * @struct RTOS_FUNC_RETURN_t
 * @brief Struct for returning the state, task ID, and error of RTOS functions.
 * State can be either NOT_OK or OK. Task_ID holds the task identifier, and
 * Error indicates any error that occurred during the function's execution.
 */

typedef struct {
    FUNC_STATE_t State; /**< Function execution state (NOT_OK or OK). */
    s32 Task_ID;        /**< Task identifier. */
    Error_t Error;      /**< Error status. */
} RTOS_FUNC_RETURN_t;

/**
 * @enum TASK_PRIORITY_t
 * @brief Enum for task priorities.
 * Available priority levels include SHOW_STOPPER, CRITICAL, MAJOR, NORMAL, and MINOR.
 */

typedef enum {
    SHOW_STOPPER, /**< Highest priority level for critical tasks. */
    CRITICAL,    /**< High priority level for critical tasks. */
    MAJOR,       /**< Major priority level. */
    NORMAL,      /**< Normal priority level. */
    MINOR        /**< Minor priority level for non-critical tasks. */
} TASK_PRIORITY_t;

/***************************************************************
 ****************************** APIs ****************************
 ****************************************************************/

/**
 * Function to create a task in the RTOS.
 *
 * @param Task_Handler: Pointer to the task function.
 * @param copy_u8periodicity: Task execution periodicity in system ticks.
 * @param copy_tPriority: Priority level of the task.
 * @return RTOS_FUNC_RETURN_t: Struct indicating the function execution state, task ID, and error status.
 */

RTOS_FUNC_RETURN_t RTOS_tCreateTask(void(*Task_Handler)(void), u8 copy_u8periodicity, TASK_PRIORITY_t copy_tPriority);

/**
 * Function to delete a task in the RTOS.
 *
 * @param copy_u8TaskID: Task identifier to be deleted.
 * @return RTOS_FUNC_RETURN_t: Struct indicating the function execution state, task ID, and error status.
 */

RTOS_FUNC_RETURN_t RTOS_tDeleteTask(u8 copy_u8TaskID);

/**
 * Function to suspend a task in the RTOS.
 *
 * @param copy_u8TaskID: Task identifier to be suspended.
 * @return RTOS_FUNC_RETURN_t: Struct indicating the function execution state, task ID, and error status.
 */

RTOS_FUNC_RETURN_t RTOS_tSuspendTask(u8 copy_u8TaskID);

/**
 * Function to resume a suspended task in the RTOS.
 *
 * @param copy_u8TaskID: Task identifier to be resumed.
 * @return RTOS_FUNC_RETURN_t: Struct indicating the function execution state, task ID, and error status.
 */

RTOS_FUNC_RETURN_t RTOS_tResumeTask(u8 copy_u8TaskID);

/**
 * Function to start the RTOS scheduler.
 */

void RTOS_tStartOS(void);

#endif /* HAL_RTOS_RTOS_INTERFACE_H_ */
