/*
 * fsm_traffic.h
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */

#ifndef INC_FSM_TRAFFIC_H_
#define INC_FSM_TRAFFIC_H_

#include "main.h"

void traffic_init();
void fsm_traffic_run();

typedef enum {RED, GREEN, YELLOW} color_state;

#endif /* INC_FSM_TRAFFIC_H_ */
