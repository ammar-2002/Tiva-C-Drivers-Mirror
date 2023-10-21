/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : LCD_Driver
File    : PRIVATE File
Version : 1.0
CREATED : October 19, 2023
**********************************************************
*********************************************************/

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define _4_BIT_MODE 4
#define _8_BIT_MODE 8

#define LCD_4_BIT_MODE_DATA_PINS 4

#define LCD_DATA_PORT   PORTC
#define LCD_DATA_PIN_0  PC0
#define LCD_DATA_PIN_1  PC1
#define LCD_DATA_PIN_2  PC2
#define LCD_DATA_PIN_3  PC3
#define LCD_DATA_PIN_4  PC4
#define LCD_DATA_PIN_5  PC5
#define LCD_DATA_PIN_6  PC6
#define LCD_DATA_PIN_7  PC7

#define PIN_MASK_DATA_4 PIN_4
#define PIN_MASK_DATA_5 PIN_5
#define PIN_MASK_DATA_6 PIN_6
#define PIN_MASK_DATA_7 PIN_7

#define LCD_RS_PIN      PD0
#define LCD_RW_PIN      PD1
#define LCD_EN_PIN      PD2

#define LCD_MAX_WIDTH   16

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
