/*
 * sched.c
 *
 *  Created on: Nov 20, 2024
 *      Author: ADMIN
 */

#include "sched.h"
#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Task_List Tlist;
uint32_t Tcounter = 0; //Task_counter
ERROR_CODE errorCode = NO_ERROR;
ERROR_CODE lastError = NO_ERROR;

char str[50];

void SCH_INIT(){
	Tlist.head = NULL;
	Tlist.size = 0;
	Tcounter = 0;
	errorCode = NO_ERROR;
}

void SCH_Update(){
	timestamp += 10;
	if (Tlist.size && Tlist.head->Delay > 0){
		Tlist.head->Delay--;
	}
}

int deleteTask (uint32_t ID){
	if (Tlist.size == 0) return 1;
	Task_Control *curr = Tlist.head;
	Task_Control *prev = NULL;
	while (curr != NULL){
		if (ID == curr->TaskID){
			//found task
			if (prev == NULL){
				//delete 1st task in list
				Tlist.head = curr->nextTask;
			}else{
				prev->nextTask = curr->nextTask;
			}
			if (curr->nextTask != NULL){
				curr->nextTask->Delay += curr->Delay;
			}
			free(curr);
			Tlist.size--;
			return 0;
		}
		prev = curr;
		curr = curr->nextTask;
	}
	return 1;
}

RETURN_CODE SCH_Delete_Task(const unsigned char TaskID){
	RETURN_CODE returnCode;
	if (deleteTask(TaskID)){
		returnCode = ERROR_SCH_CANNOT_DELETE_TASK;
	}else{
		returnCode = NO_ERROR;
	}
	return returnCode;
}

int addTask(Task_Control *task){
	if (Tlist.size >= SCH_MAX_TASKS){
		return 1;
	}
	if (Tlist.size == 0){
		Tlist.head = task;
		Tlist.size++;
		return 0;
	}
	Task_Control *curr = Tlist.head;
	Task_Control *prev = NULL;
	while (curr != NULL && task->Delay >= curr->Delay){
		task->Delay -= curr->Delay;
		prev = curr;
		curr = curr->nextTask;
	}
	task->nextTask = curr;
	if (prev != NULL){
		prev->nextTask = task;
	}else{
		Tlist.head = task;
	}
	if (curr != NULL){
		curr->Delay -= task->Delay;
	}
	Tlist.size++;
	return 0;
}

unsigned char SCH_Add_Task(void (*func_ptr)(), unsigned int DELAY,
		unsigned int PERIOD){
	Task_Control *task = (Task_Control*)malloc(sizeof(Task_Control));
	task->Delay = DELAY;
	task->Period = PERIOD;
	task->TaskID = (++Tcounter)%256;
	task->Task_ptr = func_ptr;
	task->nextTask = NULL;
	addTask(task);
	return task->TaskID;
}

void SCH_Dispatcher(){
	while (Tlist.size != 0 && Tlist.head -> Delay == 0){
		uint32_t timeOut = timestamp;
		sprintf(str, "TaskID: %ld timeout at: %ld ms\r\n", Tlist.head->TaskID,timeOut);
		displayMSG(str);
		(*Tlist.head->Task_ptr)();
		if (Tlist.head->Period) SCH_Add_Task(Tlist.head->Task_ptr, Tlist.head->Period,Tlist.head->Period);
		SCH_Delete_Task(Tlist.head->TaskID);
	}
	SCH_Report_Status();
}

int errorCounter = 0;
void SCH_Report_Status(){
#ifdef REPORT_ERROR
	if (errorCode != lastError){
		lastError = errorCode;
		if (errorCode != NO_ERROR){
			errorCounter = 60000;
			sprintf(str, "Error occurred: %d\r\n", errorCode);
			displayMSG(str);
		}else{
			errorCounter =0;
			sprintf(str, "No error detected.\r\n");
			displayMSG(str);
		}
	}
	if (errorCounter > 0){
		if (--errorCounter == 0){
			errorCode = NO_ERROR;
		}
	}
#endif
}

#ifdef WATCHDOG
IWDG_HandleTypeDef hiwdg;
static uint32_t counter_for_watchdog = 0;
void MX_IWDG_Init(){
	hiwdg.Instance = IWDG;
	hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
	hiwdg.ReadLoad = 4095;
	if (HAL_IWDG_Init(&hiwdg) != HAL_OK) Error_Handler();
}
void Watchdog_Refresh(){
	HAL_IWDG_Refresh(&hiwdg);
}
unsigned char Is_Watchdog_Refresh(){
	if (counter_for_watchdog > 3) return 1;
	else return 0;
}
void Watchdog_Counting(){
	counter_for_watchdog++;
}
void Reset_Watchdog_Counting(){
	counter_for_watchdog = 0;
}
#endif














