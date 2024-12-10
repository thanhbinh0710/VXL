/*
 * parser.c
 *
 *  Created on: Dec 1, 2024
 *      Author: ADMIN
 */

#include "parser.h"

void reset(){
	commandIndex = 0;
}

void add(char c){
	if (commandIndex < MAX_BUFFER - 1){
		command[commandIndex++] = c;
	}
}

void final(){
	command[commandIndex] = '\0';
	commandFlag = 1;
}

void parser_fsm(){
	char curr = temp;
	switch (Pstatus){
	case STR_INIT:
		if (curr == '!'){
			Pstatus = END;
			reset();
		}
		break;
	case END:
		if (curr == '#'){
			final();
			Pstatus = STR_INIT;
		}else if (curr == '!'){
			reset();
		}else{
			add(curr);
		}
		break;
	default:
		break;
	}
}
