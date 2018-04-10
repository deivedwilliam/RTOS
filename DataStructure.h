/****************************************/
/*			File: DataStructure.h		*/
/*			Author: Deived William		*/
/*				Date: 03/04/2018		*/
/****************************************/


#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#include <stdbool.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define newList() 						newDataStructure()
#define newQueue()						newDataStructure()
#define newStack()						newDataStructure()
#define Stack_Pop(dataStruct)			DataStructureRemoveBottom(dataStruct)
#define Stack_Push(dataStruct, info)	DataStructureInsertBottom(dataStruct, info)
#define Queue_Insert(dataStruct, info)	DataStructureInsertTop(dataStruct, info)
#define Queue_Remove(dataStruct)		DataStructureRemoveBottom(dataStruct)

#define toCircularChained(dataStruct)
#define toChained(dataStruct)




typedef enum 
{
	SUCCESS,
	ALOCATION_FAIL,
	NCREATE_DATASTRUCTURE
}RESPONSE;

typedef struct Node
{
	struct Node* next;
	struct Node* previous;
	void* info;
	unsigned index;	
}*ptrNode;

typedef ptrNode* HeadDataStructure;

#define foreach(dataStruct, ptr) \
   for(ptrNode scrool = *(dataStruct->beginning); scrool != NULL?ptr = scrool->info:0,scrool != NULL; scrool = scrool->next) 

typedef struct DataStructure
{
	HeadDataStructure beginning;
	HeadDataStructure end;
	unsigned size;
	ptrNode lastNodeAccessed;
	unsigned lastIndexAccessed;
}*ptrDataStructure;

typedef ptrDataStructure Queue;
typedef ptrDataStructure Stack;
typedef ptrDataStructure List;

ptrDataStructure newDataStructure(void);
RESPONSE DataStructureInsertTop(ptrDataStructure dataStruct, void* info);
RESPONSE DataStructureInsertBottom(ptrDataStructure dataStruct, void* info);
RESPONSE DataStructureInsert(ptrDataStructure dataStruct, void* info, bool(*compare)(void*,void*));
RESPONSE DataStructureInsertIndex(ptrDataStructure dataStruct, void* info, unsigned index);
void* DataStructureRemoveTop(ptrDataStructure dataStruct);
void* DataStructureRemoveBottom(ptrDataStructure dataStruct);
void* DataStructureRemoveIndex(ptrDataStructure dataStruct, unsigned index);
void* DataStructureRemove(ptrDataStructure dataStruct, bool(*compare)(void*,void*));

#ifdef __cplusplus
}
#endif


#endif
