/*
 * fsm_traffic.c
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */

#include "fsm_traffic.h"
#include "software_timer.h"
#include "led_display.h"

#define default_time_red 5
#define default_time_green 3
#define default_time_yellow 2

uint16_t time_red = default_time_red;
uint16_t time_green = default_time_green;
uint16_t time_yellow = default_time_yellow;

color_state state_A, state_B;
int time_remaning_A, time_remaning_B;

void traffic_init(){
	state_A = RED;
	state_B = GREEN;

	time_remaning_A = time_red;
	time_remaning_B = time_green;

	setRedA();
	setGreenB();

	set_timer_3(1000);
}

void fsm_traffic_run(){
	setLed7SEG(0, time_remaning_A/10);
	setLed7SEG(1, time_remaning_A%10);
	setLed7SEG(2, time_remaning_B/10);
	setLed7SEG(3, time_remaning_B%10);

	if(timer3_flag == 1){
		timer3_flag = 0;

		if(time_remaning_A > 0) time_remaning_A--;
		if(time_remaning_B > 0) time_remaning_B--;

		if(time_remaning_A == 0){
			switch(state_A){
				case RED:
					state_A = GREEN;
					time_remaning_A = time_green;
					setGreenA();
					break;
				case GREEN:
					state_A = YELLOW;
					time_remaning_A = time_yellow;
					setYellowA();
					break;
				case YELLOW:
					state_A = RED;
					time_remaning_A = time_red;
					setRedA();
					break;
				default:
					break;
			}
		}

		if(time_remaning_B == 0){
			switch(state_B){
				case RED:
					state_B = GREEN;
					time_remaning_B = time_green;
					setGreenB();
					break;
				case GREEN:
					state_B = YELLOW;
					time_remaning_B = time_yellow;
					setYellowB();
					break;
				case YELLOW:
					state_B = RED;
					time_remaning_B = time_red;
					setRedB();
					break;
				default:
					break;
			}
		}
		set_timer_3(1000);
	}
}

