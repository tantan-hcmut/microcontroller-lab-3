/*
 * button.c
 *
 *  Created on: 30 thg 10, 2025
 *      Author: HP-PC
 */

#include "button.h"

uint8_t debounceButton1[NO_OF_BUTTONS] = {1,1,1};
uint8_t debounceButton2[NO_OF_BUTTONS] = {1,1,1};
uint8_t debounceButton3[NO_OF_BUTTONS] = {1,1,1};

uint8_t buttonBuffer[NO_OF_BUTTONS] = {1,1,1};

uint16_t counterforButtonPressed1s[NO_OF_BUTTONS] = {0};
uint8_t flagforButtonPressed1s[NO_OF_BUTTONS] = {0};
uint8_t tempState1 = 0, tempState2 = 0;
uint8_t increase_freq = 0;
uint16_t modify_led_counter = 0;

void button_reading(void){
	for(int i = 0; i < NO_OF_BUTTONS; i++){
		debounceButton1[i] = debounceButton2[i];
		debounceButton2[i] = debounceButton3[i];
		updateButtonState(i);

		if(debounceButton3[i] == debounceButton1[i]){
			buttonBuffer[i] = debounceButton1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
				if(counterforButtonPressed1s[i] < DURATION_FOR_AUTO_INCREASING){
					counterforButtonPressed1s [i ]++;
				}
				else{
					flagforButtonPressed1s[i] = 1;
				}
			}
			else {
				flagforButtonPressed1s[i] = 0;
				counterforButtonPressed1s[i] = 0;
			}
		}
	}
}

void updateButtonState(uint8_t idx){
	switch (idx){
		case 0: {
			debounceButton3[idx] = HAL_GPIO_ReadPin(BUTTON0_GPIO_Port, BUTTON0_Pin);
			break ;
		}
		case 1: {
			debounceButton3[idx] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
			break ;
		}
		case 2: {
			debounceButton3[idx] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
			break ;
		}
		default: {
			break ;
		}
	}
}

unsigned char is_button_press (uint8_t idx){
	if(idx > NO_OF_BUTTONS) return 0;
	return (buttonBuffer[idx] == BUTTON_IS_PRESSED);
}

unsigned char is_button_press1s (uint8_t idx){
	if(idx > NO_OF_BUTTONS) return 0;
	return (flagforButtonPressed1s[idx] == 1);
}


void increase_led_counter(uint16_t * modified_led){
	if(is_button_press(1)) tempState1 = 1;
	if(tempState1 && !is_button_press(1)){
		modify_led_counter = (modify_led_counter + 1) % 100;
		tempState1 = 0;
	}

	if(is_button_press1s(1)){
		increase_freq = (increase_freq + 1) % 5;
		if(!increase_freq){
			modify_led_counter = (modify_led_counter + 1) % 100;
		}
	}

	if(is_button_press(2)) tempState2 = 1;
	if(tempState2 && !is_button_press(2)){
		*modified_led = modify_led_counter;
		tempState2 = 0;
	}
}
