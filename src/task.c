#include "DiordnaRTOSConfig.h"
#include "../task.h"
#include "../DataStructure"
#include <string.h>

#ifndef __MAX_PRIORITY__
#define __MAX_PRIORITY__ 7
#endif

typedef struct TaskControlBlock
{
	unsigned char* name;
	unsigned int TID;
	unsigned int priority;
	TaskState state;
	TaskFunctionCode functionCode;
	unsigned int* Stack;
	unsigned int stackWordSize;
}TaskControlBlock;

static List ReadTasks[MAX_PRIORITY];
static List BlockedTasks;
static List SuspendedTasks;
static TaskControlBlock* CurrentTask;



void TaskCreate(const unsigned char* name, unsigned int TID, unsigned int priority, unsigned int stackWordSize, TaskFunctionCode functionCode)
{
	TaskControlBlock* newTask;

	newTask = (TaskControlBlock*)malloc(sizeof(TaskControlBlock));

	newTask->name = calloc(strlen(name)+1,sizeof(char));
	strcpy(newTask->name,name);
	newTask->TID = TID;
	newTask->state = Ready;
	newTask->functionCode = functionCode;
	newTask->stack = calloc(stackWordSize,sizeof(unsigned));
	newTask->stackWordSize = stackWordSize;
}

