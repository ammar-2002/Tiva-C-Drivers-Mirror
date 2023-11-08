/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : HAL
 * DRIVER  : RTOS_Driver
 * File    : CONFIG File
 * Version : 1.0
 * CREATED : October 29, 2023
 ********************************************************
 ********************************************************/

#ifndef HAL_RTOS_RTOS_CONFIG_H_
#define HAL_RTOS_RTOS_CONFIG_H_

/*
 * RTOS_Driver Configuration File
 *
 * This file contains user-configurable settings for the RTOS_Driver, which is responsible for managing tasks
 * in a Real-Time Operating System (RTOS) on the TM4C123GH6PM (TIVA C) microcontroller.
 *
 * Version: 1.0
 * Created: October 29, 2023
 *
 * Configuration Options:
 * - MAX_NUMBER_TASKS: Set the maximum number of tasks that the RTOS can handle.
 */

/* Maximum Number of Tasks
 * - Adjust this value to set the maximum number of tasks that the RTOS can manage.
 * - Ensure it is an integer value.
 */
#define MAX_NUMBER_TASKS 20

#endif /* HAL_RTOS_RTOS_CONFIG_H_ */
