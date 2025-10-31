/*
 * fsm_mode.c
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */

#include "fsm_mode.h"
#include "software_timer.h"
#include "button.h"
#include "led_display.h"
#include "fsm_traffic.h"

int tempState = 0;
mode_style mode;

void fsm_mode_run(){
	switch(mode){
		case NORMAL_MODE:
			fsm_traffic_run();
			if(is_button_press(0)){
				tempState = 1;
			}
			if(tempState && !is_button_press(0)){
				tempState = 0;
				modify_led_counter = time_red;
				mode = SET_RED_MODE;
				turnOffAllLed();
			}
			break;
		case SET_RED_MODE:
			blinkRed();

			setLed7SEG(0, modify_led_counter / 10);
			setLed7SEG(1, modify_led_counter % 10);
			setLed7SEG(2, 0);
			setLed7SEG(3, 2);

			increase_led_counter(&time_red);

			if(is_button_press(0)){
				tempState = 1;
			}
			if(tempState && !is_button_press(0)){
				tempState = 0;
				modify_led_counter = time_yellow;
				mode = SET_YELLOW_MODE;
				turnOffAllLed();
			}
			break;
		case SET_YELLOW_MODE:
			blinkYellow();

			setLed7SEG(0, modify_led_counter / 10);
			setLed7SEG(1, modify_led_counter % 10);
			setLed7SEG(2, 0);
			setLed7SEG(3, 3);

			increase_led_counter(&time_yellow);

			if(is_button_press(0)){
				tempState = 1;
			}
			if(tempState && !is_button_press(0)){
				tempState = 0;
				modify_led_counter = time_green;
				mode = SET_GREEN_MODE;
				turnOffAllLed();
			}
			break;
		case SET_GREEN_MODE:
			blinkGreen();

			setLed7SEG(0, modify_led_counter / 10);
			setLed7SEG(1, modify_led_counter % 10);
			setLed7SEG(2, 0);
			setLed7SEG(3, 4);

			increase_led_counter(&time_green);

			if(is_button_press(0)){
				tempState = 1;
			}
			if(tempState && !is_button_press(0)){
				tempState = 0;
				mode = NORMAL_MODE;
				traffic_init();
			}
			break;
		default:
			break;
	}
}


