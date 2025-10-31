/*
 * software_timer.c
 *
 *  Created on: 30 thg 10, 2025
 *      Author: HP-PC
 */

#include "software_timer.h"

#define TIMER_CYCLE_1 10 //10ms
#define TIMER_CYCLE_2 10 //10ms
#define TIMER_CYCLE_3 10 //10ms

//Timer1 su dung de quet hien thi 4 led 7 doan
int timer1_mul = 0;
int timer1_counter = 0;
int timer1_flag = 0;

//Timer2 dung de blinkled moi 0,5s
int timer2_mul = 0;
int timer2_counter = 0;
int timer2_flag = 0;

//Timer3 dung de cai dat may trang thai traffic light
int timer3_mul = 0;
int timer3_counter = 0;
int timer3_flag = 0;

void set_timer_1(int duration) {
	timer1_mul = duration / TIMER_CYCLE_1;
	timer1_counter = timer1_mul;
	timer1_flag = 0;
}

void set_timer_2(int duration) {
	timer2_mul = duration / TIMER_CYCLE_2;
	timer2_counter = timer2_mul;
	timer2_flag = 0;
}

void set_timer_3(int duration) {
	timer3_mul = duration / TIMER_CYCLE_3;
	timer3_counter = timer3_mul;
	timer3_flag = 0;
}

void timer_run(){
	if(timer1_counter > 0) {
		timer1_counter--;
		if(timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if(timer2_counter > 0) {
		timer2_counter--;
		if(timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}

	if(timer3_counter > 0) {
		timer3_counter--;
		if(timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}
}
