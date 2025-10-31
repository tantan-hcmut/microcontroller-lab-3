/*
 * software_timer.h
 *
 *  Created on: 30 thg 10, 2025
 *      Author: HP-PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void set_timer_1(int duration);
void set_timer_2(int duration);
void set_timer_3(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
