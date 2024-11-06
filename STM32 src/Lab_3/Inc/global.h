/*
 * global.h
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "timer.h"
#include "input_reading.h"

#define NORMAL		1
#define RED_LED		2
#define YELLOW_LED	3
#define	GREEN_LED	4
#define RED1_MODIFY		12
#define YELLOW1_MODIFY	13
#define GREEN1_MODIFY	14
#define RED2_MODIFY		15
#define YELLOW2_MODIFY	16
#define GREEN2_MODIFY	17
#define DELAY			18

extern int countdown1;
extern int countdown2;
extern int status1;
extern int lastState1;
extern int status2;
extern int lastState2;
extern int status3;
extern int return_flag1;
extern int return_flag2;

extern int mode;
extern int time_input;

extern int red1_duration;
extern int yellow1_duration;
extern int green1_duration;

extern int red2_duration;
extern int yellow2_duration;
extern int green2_duration;

extern int * led1;
extern int * led2;

void systemINIT();
#endif /*INC_GLOBAL_H_*/

