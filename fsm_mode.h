/*
 * fsm_mode.h
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */

#ifndef INC_FSM_MODE_H_
#define INC_FSM_MODE_H_

#include "main.h"

typedef enum {NORMAL_MODE, SET_RED_MODE, SET_YELLOW_MODE, SET_GREEN_MODE} mode_style;

extern mode_style mode;
extern uint16_t time_red;
extern uint16_t time_yellow;
extern uint16_t time_green;
extern uint16_t modify_led_counter;

void fsm_mode_run();

#endif /* INC_FSM_MODE_H_ */
