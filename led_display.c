/*
 * led_display.c
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */
#include "led_display.h"
#include "software_timer.h"

#define LED_ON GPIO_PIN_RESET
#define LED_OFF GPIO_PIN_SET

uint8_t digits[10][7] = {
    {0,0,0,0,0,0,1}, // 0
    {1,0,0,1,1,1,1}, // 1
    {0,0,1,0,0,1,0}, // 2
    {0,0,0,0,1,1,0}, // 3
    {1,0,0,1,1,0,0}, // 4
    {0,1,0,0,1,0,0}, // 5
    {0,1,0,0,0,0,0}, // 6
    {0,0,0,1,1,1,1}, // 7
    {0,0,0,0,0,0,0}, // 8
    {0,0,0,0,1,0,0}  // 9
};

void display7SEG(uint8_t number)
{
    if(number > 9) number = 0;
    HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, digits[number][0] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, digits[number][1] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, digits[number][2] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, digits[number][3] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, digits[number][4] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, digits[number][5] ? LED_OFF : LED_ON);
    HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, digits[number][6] ? LED_OFF : LED_ON);
}

int led_buffer[4];

void setLed7SEG(int led_index, int value) {
	if(value < 0 || value > 9) return;
	led_buffer[led_index] = value;
}

void update7SEG(int index) {
    HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, LED_OFF);
    HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, LED_OFF);
    HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, LED_OFF);
    HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, LED_OFF);

    switch(index) {
        case 0:
            display7SEG(led_buffer[0]);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, LED_ON);
            break;
        case 1:
            display7SEG(led_buffer[1]);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, LED_ON);
            break;
        case 2:
            display7SEG(led_buffer[2]);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, LED_ON);
            break;
        case 3:
            display7SEG(led_buffer[3]);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, LED_ON);
            break;
        default:
            break;
    }
}

void setRedA(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_OFF);
}

void setYellowA(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_ON);
}

void setGreenA(void){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_OFF);
}

void setRedB(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_OFF);
}

void setYellowB(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_ON);
}

void setGreenB(void){
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_ON);
	HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_OFF);
}

void turnOffAllLed(){
    HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, LED_OFF);
    HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, LED_OFF);
    HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, LED_OFF);
    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, LED_OFF);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, LED_OFF);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, LED_OFF);
}

void blinkRed(void){
    if(timer2_flag){
        timer2_flag = 0;
        HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
        HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);

        set_timer_2(500);
    }
}

void blinkYellow(void){
    if(timer2_flag){
        timer2_flag = 0;
        HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
        HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);

        set_timer_2(500);
    }
}

void blinkGreen(void){
    if(timer2_flag){
        timer2_flag = 0;
        HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
        HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);

        set_timer_2(500);
    }
}
