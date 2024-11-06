/*
 * timer.h
 *
 *  Created on: Oct 17, 2024
 *      Author: ADMIN
 */
#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include "main.h"
#include "input_reading.h"

void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);

void timerRun();

int endTimer0();
int endTimer1();
int endTimer2();
int endTimer3();
int endTimer4();

void clearTimer0();
void clearTimer1();
void clearTimer2();
void clearTimer3();
void clearTimer4();

#endif /*INC_TIMER_H_*/
