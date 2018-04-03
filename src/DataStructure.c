#include <stdlib.h>
#include <sidio.h>
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
		dataStruct->beginning = (HeadDataStructure)malloc(sizeof(ptrNode));
		datastruct->end = (HeadDataStructure)malloc(sizeof(ptrNode));

		if(dataStruct->beginning == NULL || dataStruct->end == NULL)
		{
			free(dataStruct);
			dataStruct = NULL;
		}

	}

	return dataStruct;
}

RESPONSE DataStructureInsertTop(ptrDataStructure dataStruct, void* info)
{

}
RESPONSE DataStructureInsertBottom(ptrDataStructure dataStruct, void* info)
{

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