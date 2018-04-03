#include "../task.h"
#include "../DataStructure"



typedef struct TaskControlBlock
{
	unsigned char* name;
	unsigned int TID;
	unsigned int priority;
	TaskState state;
	TaskFunctionCode functionCode;
	unsigned int* Stack;
}TaskControlBlock;

static List ReadTasks[MAX_PRIORITY];
static List BlockedTasks;
static List SuspendedTasks;
static TaskControlBlock* CurrentTask;

void TaskCreate(const unsigned char* name, 
				unsigned int TID, 
				unsigned int priority,
				unsigned int StackSize,
				TaskFunctionCode functionCode);

