#include "DiordnaRTOSConfig.h"
#include "../task.h"
<<<<<<< HEAD
#include "../DataStructure"
=======
#include "../ArrayList.h"
#include <string.h>
>>>>>>> 766482207dbf3e5f032ce3de302d762a9b50aabf

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
<<<<<<< HEAD
	unsigned int* Stack;
=======
	unsigned int stackWordSize;
>>>>>>> 766482207dbf3e5f032ce3de302d762a9b50aabf
}TaskControlBlock;

static List ReadTasks[MAX_PRIORITY];
static List BlockedTasks;
static List SuspendedTasks;
static TaskControlBlock* CurrentTask;

<<<<<<< HEAD

=======


void TaskCreate(const unsigned char* name, unsigned int TID, unsigned int priority,unsigned int stackSize,TaskFunctionCode functionCode)
{
	TaskControlBlock* newTask;

	newTask = (TaskControlBlock*)malloc(sizeof(TaskControlBlock));

	newTask->name = calloc(strlen(name)+1,sizeof(char));
	strcpy(newTask->name,name);
	newTask->TID = TID;
	newTask->state = Ready;
	newTask->functionCode = functionCode;
	newTask->stack = calloc(stackSize,sizeof(unsigned));
	newTask->stackByteSize = stackSize;

}


>>>>>>> 766482207dbf3e5f032ce3de302d762a9b50aabf

