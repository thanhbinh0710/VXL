/*
 * fsm_modify.c
 *
 *  Created on: Oct 24, 2024
 *      Author: ADMIN
 */
#include "fsm_modify.h"
void toggleLEDs(int mode) {
    switch (mode) {
        case 2: toggleRed1(); toggleRed2(); break;
        case 3: toggleYellow1(); toggleYellow2(); break;
        case 4: toggleGreen1(); toggleGreen2(); break;
        case 5: toggleRed1(); toggleRed2(); break; // RED2_MODIFY
        case 6: toggleYellow1(); toggleYellow2(); break; // YELLOW2_MODIFY
        case 7: toggleGreen1(); toggleGreen2(); break; // GREEN2_MODIFY
    }
}

void fsm_modify(){
	switch(status3){
	case RED1_MODIFY:
		//set mode to display
		mode = 2;
		if(endTimer1()) {
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)) {
			clearLed();
			red1_duration = time_input * 100;
			time_input = 1;
			status3 = YELLOW1_MODIFY;
		}
		if(Press_button(SET_TIMER)) {
			time_input = (time_input + 1) % 100;
			if(time_input == 0) time_input = 1;
		}
		if(Press_button(CONTROL)){
			clearLed();
			time_input = 1;
			status3 = YELLOW1_MODIFY;
		}
		break;
	case YELLOW1_MODIFY:
		mode = 3;
		if(endTimer1()) {
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)){
			clearLed();
			yellow1_duration = time_input * 100;
			time_input = 1;
			status3 = GREEN1_MODIFY;
		}
		if(Press_button(SET_TIMER)) {
			time_input = (time_input + 1) % 100;
			if(time_input == 0) time_input = 1;
		}
		if(Press_button(CONTROL)){
			clearLed();
			time_input = 1;
			status3 = GREEN1_MODIFY;
		}
		break;
	case GREEN1_MODIFY:
		mode = 4;
		if(endTimer1()) {
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)) {
			clearLed();
			green1_duration = time_input * 100;
			time_input = 1;
			status3 = RED2_MODIFY;
		}
		if(Press_button(SET_TIMER)) {
			time_input = (time_input + 1) % 100;
			if(time_input == 0) time_input = 1;
		}
		if(Press_button(CONTROL)) {
			clearLed();
			time_input = 1;
			status3 = RED2_MODIFY;
		}
		break;
	case RED2_MODIFY:
		mode = 5;
		if(endTimer1()) {
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)) {
			clearLed();
			red2_duration = time_input * 100;
			time_input = 1;
			status3 = YELLOW2_MODIFY;
		}
		if(Press_button(SET_TIMER)) {
			time_input = (time_input + 1) % 100;
			if(time_input == 0) time_input = 1;
		}
		if(Press_button(CONTROL)) {
			clearLed();
			time_input = 1;
			status3 = YELLOW2_MODIFY;
		}
		break;
	case YELLOW2_MODIFY:
		mode = 6;
		if(endTimer1()) {
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)){
			clearLed();
			yellow2_duration = time_input * 100;
			time_input = 1;
			status3 = GREEN2_MODIFY;
		}
		if(Press_button(SET_TIMER)) {
			time_input = (time_input + 1) % 100;
			if(time_input == 0) time_input = 1;
		}
		if(Press_button(CONTROL)) {
			clearLed();
			time_input = 1;
			status3 = GREEN2_MODIFY;
		}
		break;
	case GREEN2_MODIFY:
		mode = 7;
		if (endTimer1()){
			setTimer1(100);
			toggleLEDs(mode);
		}
		if(Press_button(SET_VALUE)) {
		    clearLed();
		    green2_duration = time_input * 100;
		    time_input = 1;
		    return_flag1 = return_flag2 = 1;
		    status3 = DELAY;
		    led1 = &countdown1;
		    led2 = &countdown2;
		 }

		 if(Press_button(SET_TIMER)) {
		     time_input = (time_input % 99) + 1;
		 }

		 if(Press_button(CONTROL)) {
		    clearLed();
		    time_input = 1;
		    return_flag1 = return_flag2 = 1;
		    status3 = DELAY;
		    led1 = &countdown1;
		    led2 = &countdown2;
		  }
		  break;
	case DELAY:
		break;
	default:
		break;
	}
}


