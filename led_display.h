/*
 * led_display.h
 *
 *  Created on: 31 thg 10, 2025
 *      Author: HP-PC
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

void setLed7SEG(int index, int value);
void update7SEG(int index);

void setRedA();
void setYellowA();
void setGreenA();
void setRedB();
void setYellowB();
void setGreenB();

void blinkRed(void);
void blinkYellow(void);
void blinkGreen(void);

void turnOffAllLed();

#endif /* INC_LED_DISPLAY_H_ */
