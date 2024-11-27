/*
 * input_reading.c
 *
 *  Created on: Nov 21, 2024
 *      Author: ADMIN
 */

#include "input_reading.h"

int Max_press;
int button_flag[NO_OF_BUTTONS];

//define 4-stages buffer for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer4[NO_OF_BUTTONS];

static uint8_t press1s_flag[NO_OF_BUTTONS];
static uint16_t press1s_counter[NO_OF_BUTTONS];

#define INPUT_PORT GPIOB

void setButton(){
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer3[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer4[i] = BUTTON_IS_RELEASED;
		button_flag[i] = BUTTON_FLAG_RESET;
		press1s_flag[i] = BUTTON_FLAG_RESET;
		press1s_counter[i] = 0;
	}
}

void readButton(void){
	for (unsigned char i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer3[i] = debounceButtonBuffer2[i];
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(BUT_GPIO_Port, BUT_Pin);
		if ((debounceButtonBuffer2[i] == debounceButtonBuffer1[i]) && (debounceButtonBuffer2[i] == debounceButtonBuffer3[i])){
			if (debounceButtonBuffer3[i] != debounceButtonBuffer4[i]){
				debounceButtonBuffer4[i] = debounceButtonBuffer3[i];
				if (debounceButtonBuffer4[i] == BUTTON_IS_PRESSED){
					Max_press = 500;
					button_flag[i] = BUTTON_FLAG_SET;
				}else{
					Max_press--;
					press1s_counter[i] = 0;
					debounceButtonBuffer4[i] = BUTTON_IS_RELEASED;
				}
			}else{
				if (press1s_counter[i] < DURATION_FOR_AUTO_INCREASING){
					press1s_counter[i]++;
				}else press1s_flag[i] = BUTTON_FLAG_SET;
			}
		}
	}
}

unsigned char Press_button(unsigned char index){
	if (index >= NO_OF_BUTTONS) return 0;
	if (button_flag[index] == BUTTON_FLAG_SET){
		button_flag[index] = BUTTON_FLAG_RESET;
		return 1;
	}else return 0;
}










