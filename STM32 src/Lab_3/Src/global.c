/*
 * global.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */
#include "global.h"
int status1 = NORMAL;
int lastState1 = NORMAL;
int status2 = NORMAL;
int lastState2 = NORMAL;
int status3 = DELAY;

int red1_duration = 500;
int yellow1_duration = 200;
int green1_duration = 300;

int red2_duration = 500;
int yellow2_duration = 200;
int green2_duration = 300;

int time_input = 1;
int mode = 1;

int countdown1 = 0;
int countdown2 = 0;

int return_flag1 = 0;
int return_flag2 = 0;

void systemINIT(){
	setButton();
	GPIOB->ODR = 0xffff;
	setTimer0(10);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);

	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, SET);
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, RESET);
}

