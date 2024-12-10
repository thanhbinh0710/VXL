/*
 * UART.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ADMIN
 */

#include "string.h"
#include "UART.h"

void HandleReset(ADC_HandleTypeDef	hadc1, UART_HandleTypeDef huart2){
	if (commandFlag == 1){
		commandFlag = 0;
		if (command[0] == 'R' && command[1] == 'S' && command[2] == 'T'){
			HAL_ADC_Start(&hadc1);
			ADCvalue = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);

			HAL_UART_Transmit(&huart2,(uint8_t*)str, sprintf(str, "\r\n"), 1000);
			Ustatus = ADC;
			setTimer(1, 3000);

		}
	}
}

void HandleADC(UART_HandleTypeDef huart2){
	HAL_UART_Transmit(&huart2, (uint8_t*)str,sprintf(str,"!ADC=%ld\r\n", ADCvalue), 1000);
	Ustatus = OK;
}

void HandleOK(UART_HandleTypeDef huart2){
	if (commandFlag == 1){
		commandFlag = 0;
		if (command[0] == 'O' && command[1] == 'K'){
			HAL_UART_Transmit(&huart2, (uint8_t*)str, sprintf(str,"\r\n"), 1000);
			Ustatus = Reset;
			clearTimer(1);
		}
	}
	if (timer_flag[1] == 1){
		Ustatus = ADC;
		setTimer(1,3000);
	}
}

void UART_fsm(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2){
	switch (Ustatus){
	case Reset:
		HandleReset(hadc1, huart2);
		break;
	case ADC:
		HandleADC(huart2);
		break;
	case OK:
		HandleOK(huart2);
		break;
	default:
		break;
	}
}

