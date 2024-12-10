/*
 * global.h
 *
 *  Created on: Dec 1, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
//------Status cmd-------
typedef enum{
	STR_INIT = 0,
	END = 1
}parserStatus;

//-----Status UART-------
typedef enum{
	Reset = 10,
	ADC = 0,
	OK
}uartStatus;

#define MAX_BUFFER 30
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER];
extern uint8_t bufferIndex;
extern uint8_t bufferFlag;

extern uint8_t command[MAX_BUFFER];
extern uint8_t commandIndex;
extern uint8_t commandFlag;

extern char str[50];
extern uint32_t ADCvalue;

extern parserStatus Pstatus;
extern uartStatus Ustatus;


#endif /* INC_GLOBAL_H_ */
