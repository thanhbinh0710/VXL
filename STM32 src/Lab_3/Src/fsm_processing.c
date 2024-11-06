/*
 * fsm_processing.c
 *
 *  Created on: Oct 23, 2024
 *      Author: ADMIN
 */

#include "fsm_processing.h"

void handleButtonPress() {
    if(Press_button(0)){
        clearLed();
        lastState1 = status1;
        lastState2 = status2;
        status1 = DELAY;
        status2 = DELAY;
        status3 = RED1_MODIFY;
        clearTimer1();
        clearTimer2();
        clearTimer3();
        clearTimer4();
        setTimer1(100);
        led1 = &time_input;
        led2 = &mode;
    }
}

void runFsm1(){
    switch(status1){
        case NORMAL:
            setRed1();
            status1 = RED_LED;
            lastState1 = status1;
            setTimer1(red1_duration);
            setTimer3(100);
            countdown1 = red1_duration / 100;
            led1 = &countdown1;
            mode = 1;
            break;

        case RED_LED:
            setRed1();
            mode = 1;
            if(endTimer3()){
                setTimer3(100);
                countdown1--;
            }
            if(endTimer1() == 1){
                setTimer1(green1_duration);
                status1 = GREEN_LED;
                setTimer3(100);
                countdown1 = green1_duration / 100;
            }
            handleButtonPress();
            break;
        case GREEN_LED:
            mode = 1;
            setGreen1();
            if(endTimer3()){
                setTimer3(100);
                countdown1--;
            }
            if(endTimer1() == 1){
                setTimer1(yellow1_duration);
                status1 = YELLOW_LED;
                setTimer3(100);
                countdown1 = yellow1_duration / 100;
            }
            handleButtonPress();
            break;
        case YELLOW_LED:
            mode = 1;
            setYellow1();
            if(endTimer3()){
                setTimer3(100);
                countdown1--;
            }
            if(endTimer1() == 1){
                setTimer1(red1_duration);
                status1 = RED_LED;
                setTimer3(100);
                countdown1 = red1_duration / 100;
            }
            handleButtonPress();
            break;
        case DELAY:
            if(lastState1 == RED_LED && return_flag1){
                clearLed();
                status1 = lastState1;
                return_flag1 = 0;
                setTimer3(100);
                setTimer1(red1_duration);
                countdown1 = red1_duration / 100;
            }
            if(lastState1 == GREEN_LED && return_flag1){
                return_flag1 = 0;
                status1 = lastState1;
                clearLed();
                setTimer3(100);
                setTimer1(green1_duration);
                countdown1 = green1_duration / 100;
            }
            if(lastState1 == YELLOW_LED && return_flag1) {
                return_flag1 = 0;
                status1 = lastState1;
                clearLed();
                setTimer3(100);
                setTimer1(yellow1_duration);
                countdown1 = yellow1_duration / 100;
            }
            break;

        default:
            break;
    }
}

void runFsm2(){
    switch(status2){
        case NORMAL:
            setGreen2();
            status2 = GREEN_LED;
            lastState2 = status2;
            setTimer2(green2_duration);
            setTimer4(100);
            countdown2 = green2_duration / 100;
            led2 = &countdown2;
            mode = 1;
            break;

        case RED_LED:
            setRed2();
            mode = 1;
            if(endTimer4()){
                setTimer4(100);
                countdown2--;
            }
            if(endTimer2() == 1){
                setTimer2(green2_duration);
                status2 = GREEN_LED;
                setTimer4(100);
                countdown2 = green2_duration / 100;
            }
            handleButtonPress();
            break;
        case GREEN_LED:
            mode = 1;
            setGreen2();
            if(endTimer4()){
                setTimer4(100);
                countdown2--;
            }
            if(endTimer2() == 1){
                setTimer2(yellow2_duration);
                status2 = YELLOW_LED;
                setTimer4(100);
                countdown2 = yellow2_duration / 100;
            }
            handleButtonPress();
            break;
        case YELLOW_LED:
            mode = 1;
            setYellow2();
            if(endTimer4()){
                setTimer4(100);
                countdown2--;
            }
            if(endTimer2() == 1){
                setTimer2(red2_duration);
                status2 = RED_LED;
                setTimer4(100);
                countdown2 = red2_duration / 100;
            }
            handleButtonPress();
            break;
        case DELAY:
            if(lastState2 == RED_LED && return_flag2){
                clearLed();
                status2 = lastState2;
                return_flag2 = 0;
                setTimer4(100);
                setTimer2(red2_duration);
                countdown2 = red2_duration / 100;
            }
            if(lastState2 == GREEN_LED && return_flag2){
                return_flag2 = 0;
                status2 = lastState2;
                clearLed();
                setTimer4(100);
                setTimer2(green2_duration);
                countdown2 = green2_duration / 100;
            }
            if(lastState2 == YELLOW_LED && return_flag2) {
                return_flag2 = 0;
                status2 = lastState2;
                clearLed();
                setTimer4(100);
                setTimer2(yellow2_duration);
                countdown2 = yellow2_duration / 100;
            }
            break;
        default:
            break;
    }
}


