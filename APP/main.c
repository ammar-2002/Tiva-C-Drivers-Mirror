#include "LCD_INTERFACE.h"
#include "KEY_PAD_INTERFACE.h"

#define MAX_SIZE                    16
#define MAX_DECIMAL_DISPLAY_NUMBER  8

typedef enum {SUCCESS,FLOATING_POINT,DIVIDE_BY_ZERO,UN_CORRECT_EQUATION}CALCULATOR_ERROR;
CALCULATOR_ERROR Calculator(u8*,f32*);

int main(){
    LCD_VoidInit();
    LCD_VoidSendCommand(CLEAR_DISPLAY);
    KEY_PAD_VoidInit();
    u8 Equation[MAX_SIZE];
    u8 length = 0;
    u8 value_shown = 0;
    while(1){
        u8 value = KEY_PAD_U8Read();
        if(value != 0){
            if(value_shown){
                LCD_VoidSendCommand(CLEAR_DISPLAY);
                value_shown = 0;
            }
            if(value == '='){
                f32 result = 0;
                CALCULATOR_ERROR error;
                Equation[length] = 0;
                error = Calculator(Equation,&result);
                length = 0;
                switch(error){
                case SUCCESS:
                    LCD_VoidSendCommand(CLEAR_DISPLAY);
                    LCD_VoidSendString(Equation);
                    LCD_VoidSendCommand(GO_TO_SECOND_LINE);
                    LCD_VoidSendFloatOnTheLeft(result, MAX_DECIMAL_DISPLAY_NUMBER, MAX_DECIMAL_DISPLAY);
                    break;
                case DIVIDE_BY_ZERO:
                    LCD_VoidSendCommand(CLEAR_DISPLAY);
                    LCD_VoidSendString((u8*)"Can't divide");
                    LCD_VoidSendCommand(GO_TO_SECOND_LINE);
                    LCD_VoidSendString((u8*)"by zero");
                    break;
                case UN_CORRECT_EQUATION:
                    LCD_VoidSendCommand(CLEAR_DISPLAY);
                    LCD_VoidSendString((u8*)"Incorrect format");
                    LCD_VoidSendCommand(GO_TO_SECOND_LINE);
                    LCD_VoidSendString(Equation);
                    break;
                case FLOATING_POINT:
                    LCD_VoidSendCommand(CLEAR_DISPLAY);
                    LCD_VoidSendString((u8*)"Floating point");
                    LCD_VoidSendCommand(GO_TO_SECOND_LINE);
                    LCD_VoidSendString((u8*)"aren't available");
                    break;
                }
                Equation[0] = 0;
                length = 0;
                value_shown = 1;
            }else if(value == '.'){
                LCD_VoidSendCommand(CLEAR_DISPLAY);
                length = 0;
                Equation[0] = 0;
            }else{
                if(length < MAX_SIZE - 1){
                    LCD_VoidSendChar(value);
                    Equation[length] = value;
                    length++;
                }
            }
        }
    }
}

CALCULATOR_ERROR Calculator(u8* copy_ptrEquation, f32* copy_ptrResult){
    f32 numbers[MAX_SIZE];
    u8 signs[MAX_SIZE];
    u8 i = 0;
    u8 numbers_index = 0;
    u8 signs_index = 0;
    f32 num = 0;
    u8 enter_num_field = 0;
    u8 enter_sign_field = 0;
    while(copy_ptrEquation[i]){
        if(copy_ptrEquation[i] >= '0' && copy_ptrEquation[i] <= '9'){
            enter_sign_field = 0;
            enter_num_field = 1;
            num = num*10;
            num = num + (copy_ptrEquation[i] - '0');
        }else if(copy_ptrEquation[i] == '.'){
            return FLOATING_POINT;
        }else{
            if(enter_sign_field == 1 || i == 0){
                return UN_CORRECT_EQUATION;
            }else{
                if(enter_num_field == 1){
                    numbers[numbers_index] = num;
                    numbers_index++;
                    enter_num_field = 0;
                    num = 0;
                }
                signs[signs_index] = copy_ptrEquation[i];
                signs_index++;
                enter_sign_field = 1;
            }
        }
        i++;
    }
    if(enter_num_field){
        numbers[numbers_index] = num;
        numbers_index++;
        enter_num_field = 0;
    }
    if(numbers_index == signs_index + 1){
        u8 multiply_finished = 0;
        while(signs_index > 0){
            i=0;
            if(!multiply_finished){
                while(1){
                    if(signs[i]== '*'){
                        u8 temp = i;
                        while(temp < signs_index){
                            signs[temp] = signs[temp+1];
                            temp++;
                        }
                        numbers[i] = numbers[i] * numbers[i+1];
                        temp = i+1;
                        while(temp < numbers_index-1){
                            numbers[temp] = numbers[temp+1];
                            temp++;
                        }
                        signs_index--;
                        numbers_index--;
                        break;
                    }else if(signs[i] == '/'){
                        u8 temp = i;
                        while(temp < signs_index){
                            signs[temp] = signs[temp+1];
                            temp++;
                        }
                        if(numbers[i] == 0|| numbers[i+1] == 0){
                            return DIVIDE_BY_ZERO;
                        }
                        numbers[i] = numbers[i] / (f32)numbers[i+1];
                        temp = i+1;
                        while(temp < numbers_index-1){
                            numbers[temp] = numbers[temp+1];
                            temp++;
                        }
                        signs_index--;
                        numbers_index--;
                        break;
                    }
                    if(i > signs_index){
                        multiply_finished=1;
                        break;
                    }
                    i++;
                }
            }else{
                while(1){
                    if(signs[i]== '+'){
                        u8 temp = i;
                        while(temp < signs_index){
                            signs[temp] = signs[temp+1];
                            temp++;
                        }
                        numbers[i] = numbers[i] + numbers[i+1];
                        temp = i+1;
                        while(temp < numbers_index-1){
                            numbers[temp] = numbers[temp+1];
                            temp++;
                        }
                        signs_index--;
                        numbers_index--;
                        break;
                    }else if(signs[i] == '-'){
                        u8 temp = i;
                        while(temp < signs_index){
                            signs[temp] = signs[temp+1];
                            temp++;
                        }
                        numbers[i] = numbers[i] - numbers[i+1];
                        temp = i+1;
                        while(temp < numbers_index-1){
                            numbers[temp] = numbers[temp+1];
                            temp++;
                        }
                        signs_index--;
                        numbers_index--;
                        break;
                    }
                    i++;
                }
            }
        }
        *copy_ptrResult = numbers[0];
        return SUCCESS;
    }else{
        return UN_CORRECT_EQUATION;
    }
}
