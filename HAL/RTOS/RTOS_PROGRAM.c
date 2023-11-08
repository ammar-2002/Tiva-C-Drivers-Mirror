/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : HAL
 * DRIVER  : RTOS_Driver
 * File    : PROGRAM File
 * Version : 1.0
 * CREATED : October 29, 2023
 *
 * DESCRIPTION:
 * This file contains the application program for the Real-Time Operating System (RTOS)
 * driver designed for the TM4C123GH6PM (TIVA C) microcontroller. The program includes
 * initialization of required peripherals, task management, and the scheduler. It also
 * defines the interface for creating, deleting, suspending, and resuming tasks.
 *
 ********************************************************
 ********************************************************/

/***************************************************************
 *************************** Includes ***************************
 ****************************************************************/
#include "STD_TYPES.h"
#include "SYS_TICK_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "RTOS_INTERFACE.h"
#include "RTOS_PRIVATE.h"
#include "RTOS_CONFIG.h"

/***************************************************************
 **************************** Globals ***************************
 ****************************************************************/
TASK_t SystemTasks[MAX_NUMBER_TASKS] = {0};
u8 NUMBER_OF_TASKS = 0;

/***************************************************************
 ****************************** APIs ****************************
 ****************************************************************/

/**
 * Function to create a new task in the RTOS.
 *
 * @param Task_Handler: A function pointer to the task handler.
 * @param copy_u8periodicity: The task's periodicity in system ticks.
 * @param copy_tPriority: The priority of the task.
 * @return RTOS_FUNC_RETURN_t: The return type indicating the success of the operation.
 */
RTOS_FUNC_RETURN_t RTOS_tCreateTask(void (*Task_Handler)(void), u8 copy_u8periodicity, TASK_PRIORITY_t copy_tPriority) {
    RTOS_FUNC_RETURN_t return_type;
    TASK_t create_task;
    TASK_FOUND_t empty_task_found;
    u8 i,index;
    return_type.Task_ID = -1;
    return_type.State = NOT_OK;
    return_type.Error = NO_TASK_SEND;
    if(Task_Handler == 0)return return_type;
    return_type.Error = MAX_TASK_REACHED;
    empty_task_found = NOT_FOUND;
    for(i = 0;i < NUMBER_OF_TASKS;i++){
        if(SystemTasks[i].tExistState == NOT_EXIST){
            index = i;
            empty_task_found = FOUND;
            break;
        }
    }
    if(NUMBER_OF_TASKS == MAX_NUMBER_TASKS && empty_task_found == NOT_FOUND)return return_type;
    if(empty_task_found == FOUND){
        return_type.Task_ID = index;
    }else{
        return_type.Task_ID = NUMBER_OF_TASKS;
        create_task.Task_ID = NUMBER_OF_TASKS;
        NUMBER_OF_TASKS++;
    }
    return_type.State = OK;
    create_task.Task_Handler = Task_Handler;
    create_task.time = copy_u8periodicity;
    create_task.periodicity = copy_u8periodicity;
    create_task.tState = RUNNING;
    create_task.tExistState = EXIST;
    create_task.tPriority = copy_tPriority;
    SystemTasks[create_task.Task_ID] = create_task;
    return_type.Error = NO_ERROR;
    return return_type;
}

/**
 * Function to delete a task from the RTOS.
 *
 * @param copy_u8TaskID: The ID of the task to delete.
 * @return RTOS_FUNC_RETURN_t: The return type indicating the success of the operation.
 */
RTOS_FUNC_RETURN_t RTOS_tDeleteTask(u8 copy_u8TaskID) {
    RTOS_FUNC_RETURN_t return_type;
    return_type.Task_ID = -1;
    return_type.State = NOT_OK;
    return_type.Error = TASK_ID_OUT_OF_LIMIT;
    if(copy_u8TaskID > MAX_NUMBER_TASKS)return return_type;
    return_type.Error = NO_TASK_FOUND;
    if(SystemTasks[copy_u8TaskID].tExistState == NOT_EXIST)return return_type;
    SystemTasks[copy_u8TaskID].tExistState = NOT_EXIST;
    return_type.Error = NO_ERROR;
    return_type.Task_ID = copy_u8TaskID;
    return_type.State = OK;
    return return_type;
}

/**
 * Function to suspend a task in the RTOS.
 *
 * @param copy_u8TaskID: The ID of the task to suspend.
 * @return RTOS_FUNC_RETURN_t: The return type indicating the success of the operation.
 */
RTOS_FUNC_RETURN_t RTOS_tSuspendTask(u8 copy_u8TaskID) {
    RTOS_FUNC_RETURN_t return_type;
    return_type.Task_ID = -1;
    return_type.State = NOT_OK;
    return_type.Error = TASK_ID_OUT_OF_LIMIT;
    if(copy_u8TaskID > MAX_NUMBER_TASKS)return return_type;
    return_type.Error = NO_TASK_FOUND;
    if(SystemTasks[copy_u8TaskID].tExistState == NOT_EXIST)return return_type;
    return_type.Error = ALREADY_SUSPENDED;
    if(SystemTasks[copy_u8TaskID].tState == SUSPENDED)return return_type;
    SystemTasks[copy_u8TaskID].tState = SUSPENDED;
    return_type.Error = NO_ERROR;
    return_type.Task_ID = copy_u8TaskID;
    return_type.State = OK;
    return return_type;
}

/**
 * Function to resume a suspended task in the RTOS.
 *
 * @param copy_u8TaskID: The ID of the task to resume.
 * @return RTOS_FUNC_RETURN_t: The return type indicating the success of the operation.
 */
RTOS_FUNC_RETURN_t RTOS_tResumeTask(u8 copy_u8TaskID) {
    RTOS_FUNC_RETURN_t return_type;
    return_type.Task_ID = -1;
    return_type.State = NOT_OK;
    return_type.Error = TASK_ID_OUT_OF_LIMIT;
    if(copy_u8TaskID > MAX_NUMBER_TASKS)return return_type;
    return_type.Error = NO_TASK_FOUND;
    if(SystemTasks[copy_u8TaskID].tExistState == NOT_EXIST)return return_type;
    return_type.Error = ALREADY_RUNNING;
    if(SystemTasks[copy_u8TaskID].tState == RUNNING)return return_type;
    SystemTasks[copy_u8TaskID].tState = RUNNING;
    return_type.Error = NO_ERROR;
    return_type.Task_ID = copy_u8TaskID;
    return_type.State = OK;
    return return_type;
}

/**
 * Function to initiate the scheduler.
 */
void scheduler(void) {
    u8 counter = 0;
    u8 counter2= 0;
    u8 top = 0;
    u8 id_high_priority;
    u8 task_order = 0;
    u8 counter2_priority_reset = 0;
    u8 arr[MAX_NUMBER_TASKS][2] = {0};
    for(;counter<NUMBER_OF_TASKS;counter++){

        if(SystemTasks[counter].tExistState == NOT_EXIST || SystemTasks[counter].tState == EXECUTING)continue;
        if(SystemTasks[counter].tState == RUNNING){
            if(SystemTasks[counter].time >= CYCLE_TIME)SystemTasks[counter].time = SystemTasks[counter].time - CYCLE_TIME;
            else SystemTasks[counter].time = 0;
        }
        if(SystemTasks[counter].time == FINISHED){
            SystemTasks[counter].tState = EXECUTING;
            arr[top][PRIORITY_INDEX] = (u8)SystemTasks[counter].tPriority;
            arr[top][ID_INDEX] = (u8)SystemTasks[counter].Task_ID;
            top++;
        }
    }
    if(top > 0){
        counter = 0;
        for(;counter < top;counter++){
            counter2 = 0;
            id_high_priority = 255;
            for(;counter2 < top;counter2++){
                if(id_high_priority > arr[counter2][PRIORITY_INDEX]){
                    task_order = arr[counter2][ID_INDEX];
                    id_high_priority = arr[counter2][PRIORITY_INDEX];
                    counter2_priority_reset = counter2;
                }
            }
            arr[counter2_priority_reset][PRIORITY_INDEX] = 255;
            (*SystemTasks[task_order].Task_Handler)();
            SystemTasks[task_order].time = SystemTasks[task_order].periodicity;
            SystemTasks[task_order].tState = RUNNING;
        }
    }
}

/**
 * Function to start the RTOS and initiate the system tick timer.
 */
void RTOS_tStartOS(void) {
    SYS_TICK_VoidInit();
    SYS_TICK_VoidSetCallback(scheduler);
    SYS_TICK_VoidSetTimeCycle(CYCLE_TIME);
}
