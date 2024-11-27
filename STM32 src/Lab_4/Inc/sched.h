/*
 * sched.h
 *
 *  Created on: Nov 20, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHED_H_
#define INC_SCHED_H_

#include "global.h"
#include <stdlib.h>

#define SCH_MAX_TASKS 30

typedef struct Task_Control {
	void (*Task_ptr)();
	uint32_t TaskID;
	uint32_t Delay;
	uint32_t Period;
	struct Task_Control* nextTask;
}Task_Control;

typedef struct {
	Task_Control* head;
	//Task_Control* tail;
	uint32_t size;
}Task_List;

typedef enum {
	NO_ERROR = 0,
	ERROR_SCH_TOO_MANY_TASKS = 1,
	ERROR_SCH_CANNOT_DELETE_TASK = 2
}ERROR_CODE;

typedef enum {
	RETURN_NORMAL = 0,
	RETURN_ERROR = 1
}RETURN_CODE;

//=== Scheduler_System ===
void SCH_INIT();
void SCH_Update();
void SCH_Dispatcher();

//=== Task_Management ===
unsigned char SCH_Add_Task(
		void (*Func_ptr)(),
		unsigned int DELAY,
		unsigned int PERIOD
);
RETURN_CODE SCH_Delete_Task(const unsigned char TaskID);

//=== Status_Report ===
void SCH_Report_Status();
void SCH_Go_To_Sleep();

#ifdef WATCHDOG
void Watchdog_Refresh();
unsigned char Is_Watchdog_Reset();
void Watchdog_Counting();
void Reset_Watchdog_Counting();
#endif /*WATCHDOG*/

#endif /* INC_SCHED_H_ */
