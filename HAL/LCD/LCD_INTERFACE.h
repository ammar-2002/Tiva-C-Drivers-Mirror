/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : LCD_Driver
File    : INTERFACE File
Version : 1.0
CREATED : October 19, 2023
**********************************************************
*********************************************************/

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#include "STD_TYPES.h"

typedef enum {
    CLEAR_DISPLAY                                   = 0x1,
    RETURN_HOME                                     = 0x2,
    ENTRY_MODE_SET_WITH_ADRESS_DECREMENT_NO_SHIFT   = 0x4,
    ENTRY_MODE_SET_WITH_ADRESS_DECREMENT_WITH_SHIFT = 0x5,
    ENTRY_MODE_SET_WITH_ADRESS_INCREMENT_NO_SHIFT   = 0x6,
    ENTRY_MODE_SET_WITH_ADRESS_INCREMENT_WITH_SHIFT = 0x7,
    DISPLAY_OFF_CURSOR_OFF_CURSOR_BLINK_OFF         = 0x8,
    DISPLAY_OFF_CURSOR_OFF_CURSOR_BLINK_ON          = 0x9,
    DISPLAY_OFF_CURSOR_ON_CURSOR_BLINK_OFF          = 0xA,
    DISPLAY_OFF_CURSOR_ON_CURSOR_BLINK_ON           = 0xB,
    DISPLAY_ON_CURSOR_OFF_CURSOR_BLINK_OFF          = 0xC,
    DISPLAY_ON_CURSOR_OFF_CURSOR_BLINK_ON           = 0xD,
    DISPLAY_ON_CURSOR_ON_CURSOR_BLINK_OFF           = 0xE,
    DISPLAY_ON_CURSOR_ON_CURSOR_BLINK_ON            = 0xF,
    SHIFT_CURSOR_TO_THE_LEFT                        = 0x10,
    SHIFT_CURSOR_TO_THE_RIGHT                       = 0x14,
    SHIFT_DISPLAY_TO_THE_LEFT_CURSOR_FOLLOW         = 0x18,
    SHIFT_DISPLAY_TO_THE_RIGHT_CURSOR_FOLLOW        = 0x1C,
    _4_BIT_MODE_1_LINE_5_8_FONT                     = 0x20,
    _4_BIT_MODE_1_LINE_5_11_FONT                    = 0x24,
    _4_BIT_MODE_2_LINE                              = 0x28,
    _8_BIT_MODE_1_LINE_5_8_FONT                     = 0x30,
    _4_BIT_MODE_SECOND_INITIALIZATION               = 0x32,
    _4_BIT_MODE_FIRST_INITIALIZATION                = 0x33,
    _8_BIT_MODE_1_LINE_5_11_FONT                    = 0x34,
    _8_BIT_MODE_2_LINE                              = 0x38,
    GO_TO_SECOND_LINE                               = 0xC0,
}LDC_COMMAND_t;

typedef enum {
    FORCE_DISPLAY       = 0,
    MAX_DECIMAL_DISPLAY = 1
}DECIMAL_FORMAT_TYPE_t;

void LCD_VoidInit();
void LCD_VoidSendCommand(LDC_COMMAND_t copy_tCommand);
void LCD_VoidSendChar(u8 copy_u8Data);
void LCD_VoidSendString(u8* copy_ptrString);
void LCD_VoidSendNumber(u32 copy_u32Number);
void LCD_VoidSendFloat(f32 copy_f32Number,u8 copy_u8DecimalFormat,DECIMAL_FORMAT_TYPE_t copy_tDecimalFormatType);
void LCD_VoidSendNumberOnTheLeft(u8 copy_u8Number);
void LCD_VoidSendFloatOnTheLeft(f32 copy_f32Number,u8 copy_u8DecimalFormat,DECIMAL_FORMAT_TYPE_t copy_tDecimalFormatType);


#endif /* HAL_LCD_LCD_INTERFACE_H_ */
