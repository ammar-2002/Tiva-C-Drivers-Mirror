/********************************************************
 * AUTHOR  : AMMAR WAEL
 * MICRO   : TM4C123GH6PM (TIVA C)
 * LAYER   : MCAL
 * DRIVER  : GPIO_Driver
 * FILE    : PRIVATE File
 * VERSION : 1.0
 * CREATED : September 29, 2023
 *
 * DESCRIPTION:
 * This is the private implementation file for the GPIO driver.
 * It contains the low-level functions and data structures used internally by the driver.
 * Users should not modify or include this file directly in their applications.
 *
 ********************************************************
 ********************************************************/

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

/***************************************************************
*************************** Includes ***************************
****************************************************************/

#include "STD_TYPES.h"

/***************************************************************
********************** Type Definitions ************************
****************************************************************/

// Register No. 1
typedef struct {
    u32 DATA:8;
    u32 reserved:24;
}GPIODATA_st;

typedef union{
    GPIODATA_st B;
    u32 R;
}GPIODATA_t;

// Register No. 2
typedef struct {
    u32 DIR:8;
    u32 reserved:24;
}GPIODIR_st;

typedef union{
    GPIODIR_st B;
    u32 R;
}GPIODIR_t;

// Register No. 3
typedef struct {
    u32 IS:8;
    u32 reserved:24;
}GPIOIS_st;

typedef union{
    GPIOIS_st B;
    u32 R;
}GPIOIS_t;

// Register No. 4
typedef struct {
    u32 IBE:8;
    u32 reserved:24;
}GPIOIBE_st;

typedef union{
    GPIOIBE_st B;
    u32 R;
}GPIOIBE_t;

// Register No. 5
typedef struct {
    u32 IEV:8;
    u32 reserved:24;
}GPIOIEV_st;

typedef union{
    GPIOIEV_st B;
    u32 R;
}GPIOIEV_t;

// Register No. 6
typedef struct {
    u32 IME:8;
    u32 reserved:24;
}GPIOIM_st;

typedef union{
    GPIOIM_st B;
    u32 R;
}GPIOIM_t;

// Register No. 7
typedef struct {
    u32 RIS:8;
    u32 reserved:24;
}GPIORIS_st;

typedef union{
    GPIORIS_st B;
    u32 R;
}GPIORIS_t;

// Register No. 8
typedef struct {
    u32 MIS:8;
    u32 reserved:24;
}GPIOMIS_st;

typedef union{
    GPIOMIS_st B;
    u32 R;
}GPIOMIS_t;

// Register No. 9
typedef struct {
    u32 IC:8;
    u32 reserved:24;
}GPIOICR_st;

typedef union{
    GPIOICR_st B;
    u32 R;
}GPIOICR_t;

// Register No. 10
typedef struct {
    u32 AFSEL:8;
    u32 reserved:24;
}GPIOAFSEL_st;

typedef union{
    GPIOAFSEL_st B;
    u32 R;
}GPIOAFSEL_t;

// Register No. 11
typedef struct {
    u32 DRV2:8;
    u32 reserved:24;
}GPIODR2R_st;

typedef union{
    GPIODR2R_st B;
    u32 R;
}GPIODR2R_t;

// Register No. 12
typedef struct {
    u32 DRV4:8;
    u32 reserved:24;
}GPIODR4R_st;

typedef union{
    GPIODR4R_st B;
    u32 R;
}GPIODR4R_t;

// Register No. 13
typedef struct {
    u32 DRV8:8;
    u32 reserved:24;
}GPIODR8R_st;

typedef union{
    GPIODR8R_st B;
    u32 R;
}GPIODR8R_t;

// Register No. 14
typedef struct {
    u32 ODE:8;
    u32 reserved:24;
}GPIOODR_st;

typedef union{
    GPIOODR_st B;
    u32 R;
}GPIOODR_t;

// Register No. 15
typedef struct {
    u32 PUE:8;
    u32 reserved:24;
}GPIOPUR_st;

typedef union{
    GPIOPUR_st B;
    u32 R;
}GPIOPUR_t;

// Register No. 16
typedef struct {
    u32 PDE:8;
    u32 reserved:24;
}GPIOPDR_st;

typedef union{
    GPIOPDR_st B;
    u32 R;
}GPIOPDR_t;

// Register No. 17
typedef struct {
    u32 SRL:8;
    u32 reserved:24;
}GPIOSLR_st;

typedef union{
    GPIOSLR_st B;
    u32 R;
}GPIOSLR_t;

// Register No. 18
typedef struct {
    u32 DEN:8;
    u32 reserved:24;
}GPIODEN_st;

typedef union{
    GPIODEN_st B;
    u32 R;
}GPIODEN_t;

// Register No. 19
typedef struct {
    u32 LOCK;
}GPIOLOCK_st;

typedef union{
    GPIOLOCK_st B;
    u32 R;
}GPIOLOCK_t;

// Register No. 20
typedef struct {
    u32 CR:8;
    u32 reserved:24;
}GPIOCR_st;

typedef union{
    GPIOCR_st B;
    u32 R;
}GPIOCR_t;

// Register No. 21
typedef struct {
    u32 GPIOAMSEL:8;
    u32 reserved:24;
}GPIOAMSEL_st;

typedef union{
    GPIOAMSEL_st B;
    u32 R;
}GPIOAMSEL_t;

// Register No. 22
typedef struct {
    u32 PMC0:4;
    u32 PMC1:4;
    u32 PMC2:4;
    u32 PMC3:4;
    u32 PMC4:4;
    u32 PMC5:4;
    u32 PMC6:4;
    u32 PMC7:4;
}GPIOPCTL_st;

typedef union{
    GPIOPCTL_st B;
    u32 R;
}GPIOPCTL_t;

// Register No. 23
typedef struct {
    u32 ADCEN:8;
    u32 reserved:24;
}GPIOADCCTL_st;

typedef union{
    GPIOADCCTL_st B;
    u32 R;
}GPIOADCCTL_t;

// Register No. 24
typedef struct {
    u32 DMAEN:8;
    u32 reserved:24;
}GPIODMACTL_st;

typedef union{
    GPIODMACTL_st B;
    u32 R;
}GPIODMACTL_t;

// Register No. 25
typedef struct {
    u32 PID4:8;
    u32 reserved:24;
}GPIOPeriphID4_st;

typedef union{
    GPIOPeriphID4_st B;
    u32 R;
}GPIOPeriphID4_t;

// Register No. 26
typedef struct {
    u32 PID5:8;
    u32 reserved:24;
}GPIOPeriphID5_st;

typedef union{
    GPIOPeriphID5_st B;
    u32 R;
}GPIOPeriphID5_t;

// Register No. 27
typedef struct {
    u32 PID6:8;
    u32 reserved:24;
}GPIOPeriphID6_st;

typedef union{
    GPIOPeriphID6_st B;
    u32 R;
}GPIOPeriphID6_t;

// Register No. 28
typedef struct {
    u32 PID7:8;
    u32 reserved:24;
}GPIOPeriphID7_st;

typedef union{
    GPIOPeriphID7_st B;
    u32 R;
}GPIOPeriphID7_t;

// Register No. 29
typedef struct {
    u32 PID0:8;
    u32 reserved:24;
}GPIOPeriphID0_st;

typedef union{
    GPIOPeriphID0_st B;
    u32 R;
}GPIOPeriphID0_t;

// Register No. 30
typedef struct {
    u32 PID1:8;
    u32 reserved:24;
}GPIOPeriphID1_st;

typedef union{
    GPIOPeriphID1_st B;
    u32 R;
}GPIOPeriphID1_t;

// Register No. 31
typedef struct {
    u32 PID2:8;
    u32 reserved:24;
}GPIOPeriphID2_st;

typedef union{
    GPIOPeriphID2_st B;
    u32 R;
}GPIOPeriphID2_t;

// Register No. 32
typedef struct {
    u32 PID3:8;
    u32 reserved:24;
}GPIOPeriphID3_st;

typedef union{
    GPIOPeriphID3_st B;
    u32 R;
}GPIOPeriphID3_t;

// Register No. 33
typedef struct {
    u32 CID0:8;
    u32 reserved:24;
}GPIOPCellID0_st;

typedef union{
    GPIOPCellID0_st B;
    u32 R;
}GPIOPCellID0_t;

// Register No. 34
typedef struct {
    u32 CID1:8;
    u32 reserved:24;
}GPIOPCellID1_st;

typedef union{
    GPIOPCellID1_st B;
    u32 R;
}GPIOPCellID1_t;

// Register No. 35
typedef struct {
    u32 CID2:8;
    u32 reserved:24;
}GPIOPCellID2_st;

typedef union{
    GPIOPCellID2_st B;
    u32 R;
}GPIOPCellID2_t;

// Register No. 36
typedef struct {
    u32 CID3:8;
    u32 reserved:24;
}GPIOPCellID3_st;

typedef union{
    GPIOPCellID3_st B;
    u32 R;
}GPIOPCellID3_t;



typedef struct {
    GPIODATA_t GPIODATA[256];
    GPIODIR_t GPIODIR;
    GPIOIS_t GPIOIS;
    GPIOIBE_t GPIOIBE;
    GPIOIEV_t GPIOIEV;
    GPIOIM_t GPIOIM;
    GPIORIS_t GPIORIS;
    GPIOMIS_t GPIOMIS;
    GPIOICR_t GPIOICR;
    GPIOAFSEL_t GPIOAFSEL;
    u32 reserved1[55];
    GPIODR2R_t GPIODR2R;
    GPIODR4R_t GPIODR4R;
    GPIODR8R_t GPIODR8R;
    GPIOODR_t GPIOODR;
    GPIOPUR_t GPIOPUR;
    GPIOPDR_t GPIOPDR;
    GPIOSLR_t GPIOSLR;
    GPIODEN_t GPIODEN;
    GPIOLOCK_t GPIOLOCK;
    GPIOCR_t GPIOCR;
    GPIOAMSEL_t GPIOAMSEL;
    GPIOPCTL_t GPIOPCTL;
    GPIOADCCTL_t GPIOADCCTL;
    GPIODMACTL_t GPIODMACTL;
    u32 reserved2[678];
    GPIOPeriphID4_t GPIOPeriphID4;
    GPIOPeriphID5_t GPIOPeriphID5;
    GPIOPeriphID6_t GPIOPeriphID6;
    GPIOPeriphID7_t GPIOPeriphID7;
    GPIOPeriphID0_t GPIOPeriphID0;
    GPIOPeriphID1_t GPIOPeriphID1;
    GPIOPeriphID2_t GPIOPeriphID2;
    GPIOPeriphID3_t GPIOPeriphID3;
    GPIOPCellID0_t GPIOPCellID0;
    GPIOPCellID1_t GPIOPCellID1;
    GPIOPCellID2_t GPIOPCellID2;
    GPIOPCellID3_t GPIOPCellID3;
}GPIO_t;

typedef struct{
    GPIO_t* AHB;
    GPIO_t* APB;
}GPIO_BUS_t;

/***************************************************************
*************************** Defines ****************************
****************************************************************/

/*Base address of the GPIO Port with their bus*/
#define GPIOA_AHB_BASE_ADRESS       0x40058000
#define GPIOB_AHB_BASE_ADRESS       0x40059000
#define GPIOC_AHB_BASE_ADRESS       0x4005A000
#define GPIOD_AHB_BASE_ADRESS       0x4005B000
#define GPIOE_AHB_BASE_ADRESS       0x4005C000
#define GPIOF_AHB_BASE_ADRESS       0x4005D000

#define GPIOA_APB_BASE_ADRESS       0x40004000
#define GPIOB_APB_BASE_ADRESS       0x40005000
#define GPIOC_APB_BASE_ADRESS       0x40006000
#define GPIOD_APB_BASE_ADRESS       0x40007000
#define GPIOE_APB_BASE_ADRESS       0x40024000
#define GPIOF_APB_BASE_ADRESS       0x40025000

/*Variable controlling all the GPIO peripheral in the memory*/
GPIO_BUS_t GPIOA_REG = {
    (GPIO_t*)GPIOA_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOA_APB_BASE_ADRESS
};

GPIO_BUS_t GPIOB_REG = {
    (GPIO_t*)GPIOB_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOB_APB_BASE_ADRESS
};

GPIO_BUS_t GPIOC_REG = {
    (GPIO_t*)GPIOC_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOC_APB_BASE_ADRESS
};

GPIO_BUS_t GPIOD_REG = {
    (GPIO_t*)GPIOD_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOD_APB_BASE_ADRESS
};

GPIO_BUS_t GPIOE_REG = {
    (GPIO_t*)GPIOE_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOE_APB_BASE_ADRESS
};

GPIO_BUS_t GPIOF_REG = {
    (GPIO_t*)GPIOF_AHB_BASE_ADRESS,
    (GPIO_t*)GPIOF_APB_BASE_ADRESS
};

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
