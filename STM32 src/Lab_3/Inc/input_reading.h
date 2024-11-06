/*
 * input_reading.h
 *
 *  Created on: Oct 17, 2024
 *      Author: ADMIN
 */
# ifndef INC_INPUT_READING_H_
# define INC_INPUT_READING_H_
#include "main.h"

#define NO_OF_BUTTONS 3
#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED		GPIO_PIN_RESET
#define BUTTON_IS_RELEASED		GPIO_PIN_SET
#define BUTTON_FLAG_SET			1
#define BUTTON_FLAG_RESET		0
#define CONTROL		0
#define SET_TIMER	1
#define SET_VALUE	2

void setButton();
void readButton(void);
unsigned char Press_button(unsigned char index);
unsigned char Press_button1s(unsigned char index);

# endif /* INC_INPUT_READING_H_ */

