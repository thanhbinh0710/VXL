/*
 * global.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ADMIN
 */
#include "global.h"
parserStatus Pstatus = STR_INIT;
uartStatus Ustatus = Reset;

uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER] = {0};
uint8_t bufferIndex = 0;
uint8_t bufferFlag = 0;

uint8_t commandFlag = 0;
uint8_t command[MAX_BUFFER] = {0};
uint8_t commandIndex = 0;

char str[50] = {0};
uint32_t ADCvalue = 0;


