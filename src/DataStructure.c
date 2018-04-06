#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../DataStructure.h"




ptrDataStructure newDataStructure(void)
{
	ptrDataStructure dataStruct = NULL;

	dataStruct = (ptrDataStructure)malloc(sizeof(struct DataStructure));

	if(dataStruct != NULL)
	{
		dataStruct->size = 0;
		dataStruct->lastNodeAccessed = NULL;
		dataStruct->lastIndexAccessed = 0;
		dataStruct->beginning = (HeadDataStructure)calloc(1,sizeof(ptrNode));
		dataStruct->end = (HeadDataStructure)calloc(1,sizeof(ptrNode));

		if(dataStruct->beginning == NULL || dataStruct->end == NULL)
		{
			free(dataStruct);
			dataStruct = NULL;
		}
		(*(dataStruct->beginning)) = NULL;
		(*(dataStruct->end)) = NULL;

	}

	return dataStruct;
}

RESPONSE DataStructureInsertTop(ptrDataStructure dataStruct, void* info)
{
	ptrNode newNode = NULL;

	if(dataStruct == NULL)
	{
		return NCREATE_DATASTRUCTURE;
	}
	else if(dataStruct->beginning == NULL && dataStruct->end == NULL)
	{
		return NCREATE_DATASTRUCTURE;
	}

	newNode = (ptrNode)malloc(sizeof(struct Node));

	if(newNode == NULL)
		return ALOCATION_FAIL;

	newNode->info = info;
	newNode->index = dataStruct->size;

	newNode->next = *(dataStruct->beginning);
	*(dataStruct->beginning) = newNode;
	if(*(dataStruct->end) == NULL)
		*(dataStruct->end) = newNode;

	dataStruct->size++;

	return SUCCESS;
}



RESPONSE DataStructureInsertBottom(ptrDataStructure dataStruct, void* info)
{
	ptrNode newNode = NULL;

	if(dataStruct == NULL)
	{
		return NCREATE_DATASTRUCTURE;
	}
	else if(dataStruct->beginning == NULL && dataStruct->end == NULL)
	{
		return NCREATE_DATASTRUCTURE;
	}

	newNode = (ptrNode)malloc(sizeof(struct Node));

	if(newNode == NULL)
		return ALOCATION_FAIL;

	newNode->info = info;
	newNode->index = dataStruct->size;
	newNode->next = NULL;

	newNode->previous = (*(dataStruct->end))->next;
	*(dataStruct->end) = newNode;

	return SUCCESS;
}


RESPONSE DataStructureInsert(ptrDataStructure dataStruct, void* info, bool(*compare)(void*,void*))
{

}
RESPONSE DataStructureInsertIndex(ptrDataStructure dataStruct, void* info, unsigned index)
{

}
void* DataStructureRemoveTop(ptrDataStructure dataStruct)
{

}
void* DataStructureRemoveBottom(ptrDataStructure dataStruct)
{

}
void* DataStructureRemoveIndex(ptrDataStructure dataStruct, unsigned index)
{

}
void* DataStructureRemove(ptrDataStructure dataStruct, bool(*compare)(void*,void*))
{

}