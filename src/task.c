#include "DiordnaRTOSConfig.h"
#include "../task.h"
#include "../ArrayList.h"
#include <string.h>

#ifndef __MAX_PRIORITY__
#define __MAX_PRIORITY__ 7
#endif

typedef struct TaskControlBlock
{
	unsigned char* name;
	unsigned int PID;
	unsigned int priority;
	TaskState state;
	TaskFunctionCode functionCode;
	void* stack;
	unsigned int stackWordSize;
}TaskControlBlock;


static ArrayList[__MAX_PRIORITY__] ReadyTasks;
static ArrayList* BlockedTasks;
static ArrayList* SuspendedTasks;
static TaskControlBlock* CurrentRunningTask;


void TaskCreate(const unsigned char* name, unsigned int PID, unsigned int priority,unsigned int stackSize,TaskFunctionCode functionCode)
{
	TaskControlBlock* newTask;

	newTask = (TaskControlBlock*)malloc(sizeof(TaskControlBlock));

	newTask->name = calloc(strlen(name)+1,sizeof(char));
	strcpy(newTask->name,name);
	newTask->PID = PID;
	newTask->state = Ready;
	newTask->functionCode = functionCode;
	newTask->stack = calloc(stackSize,sizeof(unsigned));
	newTask->stackByteSize = stackSize;

}



