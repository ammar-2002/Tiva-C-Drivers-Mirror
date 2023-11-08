/********************************************************
 * AUTHOR    : AMMAR WAEL
 * MICRO     : TM4C123GH6PM (TIVA C)
 * LAYER     : MCAL
 * DRIVER    : SYS_TICK_Driver
 * FILE      : SYS_TICK_Interface.h
 * VERSION   : 1.0
 * CREATED   : October 25, 2023
 *
 * DESCRIPTION:
 * This is the interface header file for the SYS_TICK_Driver.
 * It provides high-level abstractions and function prototypes for
 * configuring and using the System Tick Timer on the TM4C123GH6PM
 * (TIVA C) microcontroller.
 *
 * DISCLAIMER:
 * This software is provided "as is" without warranty of any kind,
 * either express or implied, including but not limited to the implied
 * warranties of merchantability and fitness for a particular purpose.
 * The author and OpenAI shall not be held liable for any direct,
 * indirect, incidental, special, exemplary, or consequential damages.
 *
 ********************************************************
 ********************************************************/


#ifndef MCAL_SYS_TICK_SYS_TICK_INTERFACE_H_
#define MCAL_SYS_TICK_SYS_TICK_INTERFACE_H_

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"


/***************************************************************
****************************** APIs ****************************
****************************************************************/

/**
 * Initializes the system tick timer.
 */
void SYS_TICK_VoidInit();

/**
 * Sets the preload value for the system tick timer.
 *
 * @param copy_u32PreLoadValue: The preload value to set.
 */
void SYS_TICK_VoidSetPreLoad(u32 copy_u32PreLoadValue);

/**
 * Delays the program execution for a specified number of seconds using the system tick timer.
 *
 * @param copy_u8Seconds: The number of seconds to delay.
 */
void SYS_TICK_VoidDelaySeconds(u8 copy_u8Seconds);

/**
 * Delays the program execution for a specified number of milliseconds using the system tick timer.
 *
 * @param copy_u32MiliSeconds: The number of milliseconds to delay.
 */
void SYS_TICK_VoidDelayMiliSeconds(u32 copy_u32MiliSeconds);

/**
 * Sets the time cycle for the system tick timer. This function changes the timer's
 * interrupt period to the specified number of seconds.
 *
 * @param copy_u8Seconds: The new time cycle in seconds.
 */
void SYS_TICK_VoidSetTimeCycle(u8 copy_u8Seconds);

/**
 * Sets a callback function to be executed when the system tick timer interrupt occurs.
 *
 * @param func: A pointer to the callback function.
 */
void SYS_TICK_VoidSetCallback(void(*func)(void));

/**
 * Sets a callback function with one argument to be executed when the system tick timer interrupt occurs.
 *
 * @param func: A pointer to the callback function.
 * @param copy_u8Argument: The argument to be passed to the callback function.
 */
void SYS_TICK_VoidSetCallbackWithOneArgument(void(*func)(u8), u8 copy_u8Argument);

/**
 * Retrieves the elapsed time in milliseconds since the system tick timer started.
 *
 * @return The elapsed time in milliseconds.
 */
u32 SYS_TICK_U32GetElapsedTimeInMiliSeconds();

/**
 * Retrieves the remaining time in milliseconds until the next system tick timer interrupt.
 *
 * @return The remaining time in milliseconds.
 */
u32 SYS_TICK_U32GetRemainingTimeInMiliSeconds();

/**
 * Reads a flag associated with the system tick timer. This flag can be used to check if the timer
 * has triggered an interrupt.
 *
 * @return The flag value (e.g., 1 for interrupt occurred, 0 for no interrupt).
 */
u8 SYS_TICK_U8ReadFlag();


#endif /* MCAL_SYS_TICK_SYS_TICK_INTERFACE_H_ */
