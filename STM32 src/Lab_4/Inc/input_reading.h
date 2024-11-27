/*
 * input_reading.h
 *
 *  Created on: Nov 21, 2024
 *      Author: ADMIN
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#define NO_OF_BUTTONS 1
#define KEY_HOLD_TIMEOUT	500
#define DURATION_FOR_AUTO_INCREASING	100
#define DOUBLE_PRESS_TIMEOUT	24
#define BUTTON_HOLD_TIMEOUT	24
#define AUTO_REPEAT_RATE	100

#define BUTTON_IS_PRESSED	GPIO_PIN_RESET
#define BUTTON_IS_RELEASED	GPIO_PIN_SET

#define BUTTON_FLAG_SET	1
#define BUTTON_FLAG_RESET	0

#define CONTROL	0
#define	SET_TIMER	1
#define SET_VALUE	2

void setButton();
void readButton(void);
unsigned char Press_button(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
