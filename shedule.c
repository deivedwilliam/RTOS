#include "../shedule.h"
#include "../task.h"


static ArrayList* ReadTasks[MAX_PRIORITY]; 
static TaskControlBlock* CurrentTCB;




void __ISR(_T0_CORE_TIMER)