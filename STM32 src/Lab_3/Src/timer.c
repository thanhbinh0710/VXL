/*
 * timer.c
 *
 *  Created on: Oct 17, 2024
 *      Author: ADMIN
 */
#include "timer.h"
int timer0_counter = 0;
int timer1_counter = 0;
int timer2_counter = 0;
int timer3_counter = 0;
int timer4_counter = 0;
int timer0_flag = 0;
int timer1_flag = 0;
int timer2_flag = 0;
int timer3_flag = 0;
int timer4_flag = 0;

void setTimer0 (int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}
void setTimer1 (int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}
void setTimer2 (int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}
void setTimer3 (int duration){
	timer3_counter = duration;
	timer3_flag = 0;
}
void setTimer4 (int duration){
	timer4_counter = duration;
	timer4_flag = 0;
}

void timerRun(){
	if (timer0_counter > 0){
		timer0_counter--;
		if (timer0_counter <= 0) timer0_flag = 1;
	}
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0) timer1_flag = 1;
	}
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <= 0) timer2_flag = 1;
	}
	if (timer3_counter > 0){
		timer3_counter--;
		if (timer3_counter <= 0) timer3_flag = 1;
	}
	if (timer4_counter > 0){
		timer4_counter--;
		if (timer4_counter <= 0) timer4_flag = 1;
	}
}

int endTimer0(){
	if (timer0_flag == 1){
		timer0_flag = 0;
		return 1;
	}else return 0;
}

int endTimer1(){
	if (timer1_flag == 1){
		timer1_flag = 0;
		return 1;
	}else return 0;
}

int endTimer2(){
	if (timer2_flag == 1){
		timer2_flag = 0;
		return 1;
	}else return 0;
}

int endTimer3(){
	if (timer3_flag == 1){
		timer3_flag = 0;
		return 1;
	}else return 0;
}

int endTimer4(){
	if (timer4_flag == 1){
		timer4_flag = 0;
		return 1;
	}else return 0;
}

void clearTimer0(){
	timer0_counter = 0;
	timer0_flag = 0;
}

void clearTimer1(){
	timer1_counter = 0;
	timer1_flag = 0;
}

void clearTimer2(){
	timer2_counter = 0;
	timer2_flag = 0;
}

void clearTimer3(){
	timer3_counter = 0;
	timer3_flag = 0;
}

void clearTimer4(){
	timer4_counter = 0;
	timer4_flag = 0;
}






















