/********************************************************
AUTHOR  : AMMAR WAEL
MICRO   : TM4C123GH6PM (TIVA C)
LAYER   : HAL
DRIVER  : LCD_Driver
File    : PROGRAM File
Version : 1.0
CREATED : October 19, 2023
**********************************************************
*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "SYS_CTRL_INTERFACE.h"
#include "LCD_INTERFACE.h"
#include "LCD_PRIVATE.h"
#include "LCD_CONFIG.h"

void delay_ms(u8 x);

#if LCD_MODE == _4_BIT_MODE
GPIODATA_PIN_OPEN PinMask[LCD_4_BIT_MODE_DATA_PINS] = {PIN_MASK_DATA_4,PIN_MASK_DATA_5,PIN_MASK_DATA_6,PIN_MASK_DATA_7};
#endif



void LCD_VoidInit(){
    SYS_CTRL_VoidClockInit();
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOD_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOD);
    SYS_CTRL_VoidEnableClockForPeripheral(GPIOC_CLOCK);
    SYS_CTRL_VoidEnablePeripheral(GPIOC);
    GPIO_VoidPinState(LCD_RS_PIN, PIN_ENABLE);
    GPIO_VoidPinState(LCD_EN_PIN, PIN_ENABLE);
    GPIO_VoidPinState(LCD_RW_PIN, PIN_ENABLE);
    GPIO_VoidPinDirection(LCD_RS_PIN, OUTPUT);
    GPIO_VoidPinDirection(LCD_EN_PIN, OUTPUT);
    GPIO_VoidPinDirection(LCD_RW_PIN, OUTPUT);
    GPIO_VoidPinData(LCD_RW_PIN,LOW);
    #if LCD_MODE == _8_BIT_MODE
    PORT_MODE(LCD_DATA_PORT,OUTPUT);
    LCD_VoidSendCommand(_8_BIT_MODE_2_LINE);                            /* THIS COMMAND ACTIVATE 8 BIT MODE ********************/
    #elif LCD_MODE == _4_BIT_MODE
    GPIO_VoidPinState(LCD_DATA_PIN_4, PIN_ENABLE);
    GPIO_VoidPinState(LCD_DATA_PIN_5, PIN_ENABLE);
    GPIO_VoidPinState(LCD_DATA_PIN_6, PIN_ENABLE);
    GPIO_VoidPinState(LCD_DATA_PIN_7, PIN_ENABLE);
    GPIO_VoidPinDirection(LCD_DATA_PIN_4, OUTPUT);
    GPIO_VoidPinDirection(LCD_DATA_PIN_5, OUTPUT);
    GPIO_VoidPinDirection(LCD_DATA_PIN_6, OUTPUT);
    GPIO_VoidPinDirection(LCD_DATA_PIN_7, OUTPUT);
    LCD_VoidSendCommand(_4_BIT_MODE_FIRST_INITIALIZATION);
    LCD_VoidSendCommand(_4_BIT_MODE_SECOND_INITIALIZATION);
    LCD_VoidSendCommand(_4_BIT_MODE_2_LINE);                            /* THIS COMMAND ACTIVATE 4 BIT MODE ********************/
    #endif
    LCD_VoidSendCommand(DISPLAY_ON_CURSOR_OFF_CURSOR_BLINK_OFF);          /* THIS COMMAND TO TURN ON DISPLAY AND TURN OFF CURSOR */
    LCD_VoidSendCommand(CLEAR_DISPLAY);                                 /* THIS COMMAND TO CLEAR LCD ***************************/
    LCD_VoidSendCommand(ENTRY_MODE_SET_WITH_ADRESS_INCREMENT_NO_SHIFT); /* THIS COMMAND TO MOVE CURSOR FROM LEFT TO WRITE ******/
    LCD_VoidSendCommand(RETURN_HOME);                                   /* THIS COMMAND TO RETURN HOME *************************/
}

void LCD_VoidSendCommand(LDC_COMMAND_t copy_tCommand){
    #if LCD_MODE == _8_BIT_MODE
    GPIO_VoidPinData(LCD_RS_PIN,LOW);
    GPIO_VoidPortData(LCD_DATA_PORT, copy_tCommand);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    #elif LCD_MODE == _4_BIT_MODE
    GPIO_VoidPinData(LCD_RS_PIN,LOW);
    GPIO_VoidPortDataMasked(LCD_DATA_PORT, copy_tCommand , PinMask, 4);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    GPIO_VoidPortDataMasked(LCD_DATA_PORT, copy_tCommand << 4, PinMask, 4);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    #endif
}

void LCD_VoidSendChar(u8 copy_u8Data){
    #if LCD_MODE == _8_BIT_MODE
    GPIO_VoidPinData(LCD_RS_PIN,HIGH);
    GPIO_VoidPortData(LCD_DATA_PORT, copy_u8Data);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    #elif LCD_MODE == _4_BIT_MODE
    GPIO_VoidPinData(LCD_RS_PIN,HIGH);
    GPIO_VoidPortDataMasked(LCD_DATA_PORT, copy_u8Data , PinMask, 4);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    GPIO_VoidPinData(LCD_RS_PIN,HIGH);
    GPIO_VoidPortDataMasked(LCD_DATA_PORT, copy_u8Data << 4, PinMask, 4);
    GPIO_VoidPinData(LCD_EN_PIN,HIGH);
    delay_ms(1);
    GPIO_VoidPinData(LCD_EN_PIN,LOW);
    delay_ms(10);
    #endif
}

void LCD_VoidSendString(u8* copy_ptrString){
    u8 i=0;
    while(*(copy_ptrString+i) != '\0'){
        LCD_VoidSendChar(*(copy_ptrString+i));
        i++;
    }
}

void LCD_VoidSendNumber(u32 copy_u32Number){
    if(copy_u32Number == 0){
        LCD_VoidSendChar('0');
    }else{
        u32 rem = 0;
        u8 arr [16];
        s8 i = 0;
        while(copy_u32Number && i < 16){
            rem = copy_u32Number % 10;
            arr[i] = rem + 48;
            i++;
            copy_u32Number = copy_u32Number / 10;
        }
        i--;
        while(i > -1)
        {
            LCD_VoidSendChar(arr[i]);
            i--;
        }
    }
}

void LCD_VoidSendFloat(f32 copy_f32Number,u8 copy_u8DecimalFormat,DECIMAL_FORMAT_TYPE_t copy_tDecimalFormatType){
    f32 n;
    u8 point;
    point = 0;
    n = copy_f32Number;
    if(copy_f32Number < 0){
        LCD_VoidSendChar('-');
        LCD_VoidSendNumber((u32)(-n));
    }else{
        LCD_VoidSendNumber((u32)n);
    }
    LCD_VoidSendChar('.');
    if(copy_f32Number < 0){
        n = -(n - (s32)n);
    }else{
        n = n - (s32)n;
    }
    while(n && point < copy_u8DecimalFormat){
        n = n*10;
        point++;
    }
    LCD_VoidSendNumber((u32)n);
    switch(copy_tDecimalFormatType){
    case FORCE_DISPLAY:
        while(point < copy_u8DecimalFormat)LCD_VoidSendChar('0');
        break;
    case MAX_DECIMAL_DISPLAY:
        break;
    }
}

void LCD_VoidSendNumberOnTheLeft(u8 copy_u8Number){
    u8 n,len;
    len = 0;
    n = copy_u8Number;
    while (n != 0){
        len++;
        n /= 10;
    }
    u8 space_len = LCD_MAX_WIDTH - len;
    while(space_len){
        LCD_VoidSendChar(' ');
        space_len--;
    }
    LCD_VoidSendNumber(copy_u8Number);
}

void LCD_VoidSendFloatOnTheLeft(f32 copy_f32Number,u8 copy_u8DecimalFormat,DECIMAL_FORMAT_TYPE_t copy_tDecimalFormatType){
    f32 n;
    u8 len,point,negative_flag;
    negative_flag = 0;
    point = 0;
    len = 0;
    n = copy_f32Number;
    if(copy_f32Number < 0){
        negative_flag = 1;
    }
    switch(copy_tDecimalFormatType){
    case FORCE_DISPLAY:
        point = copy_u8DecimalFormat;
        len = copy_u8DecimalFormat;
        break;
    case MAX_DECIMAL_DISPLAY:
        while ((s32)n != n && point < copy_u8DecimalFormat){
            len++;
            n *= 10;
            point++;
        }
        break;
    }
    if(negative_flag){
        n = (u32)(-copy_f32Number);
    }else{
        n = (u32)copy_f32Number;
    }
    while (n != 0){
        len++;
        n /= 10;
        n = (u32)n;
    }
    if((u32)copy_f32Number == 0 && len > 0){
        len++;
    }
    if((u32)copy_f32Number == copy_f32Number && len > 0){
        len++;
    }
    if(negative_flag && point == 0 && len > 0){
        len++;
    }
    if((u32)copy_f32Number == 0 && negative_flag && point > 0 && len > 0){
        len++;
    }
    u8 space_len = LCD_MAX_WIDTH - len-1;
    while(space_len){
        LCD_VoidSendChar(' ');
        space_len--;
    }
    if(negative_flag && len > 0){
        LCD_VoidSendChar('-');
        LCD_VoidSendNumber((u32)(-copy_f32Number));
    }else{
        LCD_VoidSendNumber((u32)copy_f32Number);
    }
    LCD_VoidSendChar('.');
    n = copy_f32Number;
    if(negative_flag){
        n = -(n - (s32)n);
    }else{
        n = n - (s32)n;
    }
    while(point){
        n = n*10;
        point--;
    }
    LCD_VoidSendNumber((u32)n);
}


void delay_ms(u8 x){
    u8 j = 0;
    u32 i = 0;
    for(;j<x;j++){
        for(;i < 16000;i++);
    }
}
