/************************************/
/*		File: ArrayList.h		    */
/*		Author: Deived William		*/
/*		Date: 15/03/2018			*/
/************************************/




#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_


#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>


typedef enum OpState
{
	SUCCESS = 0,
	FAILURE
}OpState;

typedef struct Node
{
	void* data;
	struct Node* next;
	struct Node* previous;
	unsigned int index;
}*ptrNode;

typedef ptrNode* DoubleListHead;

typedef struct ArrayList
{
	DoubleListHead listHead;
	DoubleListHead listEnd;
	unsigned int size;
	OpState(*add)(struct ArrayList*, void*, bool(*compare)(void*,void*));
	OpState(*remove)(struct ArrayList*, unsigned int);
	void*(*get)(struct ArrayList*, unsigned int);
	OpState(*destroy)(struct ArrayList*);
	bool(*isEmpty)(struct ArrayList*);
}ArrayList;


ArrayList* newArrayList(void);
void destroyArrayList(ArrayList* list);


#ifdef __cplusplus
}
#endif

#endif