/************************************/
/*		File: Task.h				*/
/*		Author: Deived William		*/
/*		Date: 15/03/2017			*/
/************************************/	





#ifndef TASK_H_
#define TASK_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "ArrayList.h"



typedef enum TaskState
{ 
	Deleted = 0,
	Blocked,
	Running,
	Ready,
	Suspended
}TaskState;


typedef void(*TaskFunction)(void* parameters);




#ifdef __cplusplus
}
#endif

#endif