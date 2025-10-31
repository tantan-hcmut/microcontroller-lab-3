/*
 * button.h
 *
 *  Created on: 30 thg 10, 2025
 *      Author: HP-PC
 */


#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NO_OF_BUTTONS 3

#define BUTTON_IS_PRESSED     GPIO_PIN_RESET
#define BUTTON_IS_RELEASED    GPIO_PIN_SET

#define DURATION_FOR_AUTO_INCREASING 100

void button_reading(void);
void updateButtonState(uint8_t idx);

unsigned char is_button_press(uint8_t idx);
unsigned char is_button_press1s(uint8_t idx);

void increase_led_counter(uint16_t * modified_led);

extern uint8_t debounceButton1[NO_OF_BUTTONS];
extern uint8_t debounceButton2[NO_OF_BUTTONS];
extern uint8_t debounceButton3[NO_OF_BUTTONS];
extern uint8_t buttonBuffer[NO_OF_BUTTONS];

extern uint16_t counterforButtonPressed1s[NO_OF_BUTTONS];
extern uint8_t flagforButtonPressed1s[NO_OF_BUTTONS];

extern uint8_t tempState1, tempState2;
extern uint8_t increase_freq;
extern uint16_t modify_led_counter;


#endif /* INC_BUTTON_H_ */
