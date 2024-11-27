/*
 * global.h
 *
 *  Created on: Nov 20, 2024
 *      Author: ADMIN
 */


#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#define REFRESH_RATE 100
#define TIMER_CYCLE 1
#define SHIFT_CYCLE 500
#define BUTTON_SCAN 10
#define BUTTON_THRESHOLD 5

extern uint32_t timestamp;
void displayMSG (char *str);
#endif /* INC_GLOBAL_H_ */
