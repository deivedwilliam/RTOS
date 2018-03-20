#include "../task.h"
#include "../ArrayList.h"



typedef struct TaskControlBlock
{
	unsigned char* name;
	unsigned int PID;
	unsigned int priority;
	TaskState state;
	TaskFunctionCode functionCode;
}TaskControlBlock;


void TaskCreate(const unsigned char* name, 
				unsigned int PID, 
				unsigned int priority,
				TaskFunctionCode functionCode);

