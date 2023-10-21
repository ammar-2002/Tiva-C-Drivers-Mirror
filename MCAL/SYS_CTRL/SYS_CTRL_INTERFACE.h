/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : MCAL
DRIVER  : SYS_CTRL_Driver
File    : INTERFACE File
Version : 1.0
CREATED : September 17, 2023
**********************************************************
*********************************************************/

#ifndef MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_
#define MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_

typedef enum {GPIOA=0,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF}PERIPHERAL_t;
typedef enum {GPIOA_CLOCK=64,GPIOB_CLOCK,GPIOC_CLOCK,GPIOD_CLOCK,GPIOE_CLOCK,GPIOF_CLOCK}PERIPHERAL_CLOCK_t;

void SYS_CTRL_VoidClockInit(void);
void SYS_CTRL_VoidEnablePeripheral(PERIPHERAL_t copy_tPeripheral);
void SYS_CTRL_VoidDisablePeripheral(PERIPHERAL_t copy_tPeripheral);
void SYS_CTRL_VoidEnableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral);
void SYS_CTRL_VoidDisableClockForPeripheral(PERIPHERAL_CLOCK_t copy_tPeripheral);

#endif /* MCAL_SYS_CTRL_SYS_CTRL_INTERFACE_H_ */
