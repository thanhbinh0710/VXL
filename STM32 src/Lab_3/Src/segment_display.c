/*
 * segment_display.c
 *
 *  Created on: Oct 17, 2024
 *      Author: ADMIN
 */
#include "segment_display.h"
#include "global.h"

void display7SEG1 (int num){
	switch (num){
	case 0:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, RESET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, SET);
				break;
		case 1:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, SET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, SET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, SET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, SET);
				break;
		case 2:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, SET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, RESET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, SET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 3:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, SET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 4:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, SET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, SET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 5:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, SET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 6:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, SET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, RESET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 7:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, SET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, SET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, SET);
				break;
		case 8:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, RESET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		case 9:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, RESET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, RESET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, RESET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, RESET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, RESET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, RESET);
				break;
		default:
				HAL_GPIO_WritePin(SEGA1_GPIO_Port, SEGA1_Pin, SET);
				HAL_GPIO_WritePin(SEGB1_GPIO_Port, SEGB1_Pin, SET);
				HAL_GPIO_WritePin(SEGC1_GPIO_Port, SEGC1_Pin, SET);
				HAL_GPIO_WritePin(SEGD1_GPIO_Port, SEGD1_Pin, SET);
				HAL_GPIO_WritePin(SEGE1_GPIO_Port, SEGE1_Pin, SET);
				HAL_GPIO_WritePin(SEGF1_GPIO_Port, SEGF1_Pin, SET);
				HAL_GPIO_WritePin(SEGG1_GPIO_Port, SEGG1_Pin, SET);
				break;
		}
}

void display7SEG2(int num) {
    switch (num){
    case 0:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, SET);
    		break;
    case 1:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, SET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, SET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, SET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, SET);
    		break;
    case 2:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGD2_Pin, SET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, SET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 3:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA1_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, SET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 4:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, SET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, SET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, SET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 5:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, SET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 6:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, SET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 7:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, SET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, SET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, SET);
    		break;
    case 8:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    case 9:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, RESET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, RESET);
    		break;
    default:
    		HAL_GPIO_WritePin(SEGA2_GPIO_Port, SEGA2_Pin, SET);
    		HAL_GPIO_WritePin(SEGB2_GPIO_Port, SEGB2_Pin, SET);
    		HAL_GPIO_WritePin(SEGC2_GPIO_Port, SEGC2_Pin, SET);
    		HAL_GPIO_WritePin(SEGD2_GPIO_Port, SEGD2_Pin, SET);
    		HAL_GPIO_WritePin(SEGE2_GPIO_Port, SEGE2_Pin, SET);
    		HAL_GPIO_WritePin(SEGF2_GPIO_Port, SEGF2_Pin, SET);
    		HAL_GPIO_WritePin(SEGG2_GPIO_Port, SEGG2_Pin, SET);
    		break;
    }
}

int * led1;
int * led2;
int led_index = 0;
void update7SEG(){
	if (endTimer0()){
		setTimer0(10);
		switch(led_index){
		case 0:
			//Turn on count led
			SEG_PORT->ODR = 0xffff;
			display7SEG1(*led1 % 10);
			display7SEG2(*led1 / 10);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			break;
		case 1:
			//Turn on mode led
			SEG_PORT->ODR = 0xffff;
			display7SEG1(*led2 % 10);
			display7SEG2(*led2 / 10);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			break;
		default:
			break;
		}
		led_index = (led_index + 1) % 2;
	}
}



































