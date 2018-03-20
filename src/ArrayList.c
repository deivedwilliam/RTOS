#include "../ArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool isEmptyList(ArrayList* list);
static OpState addList(ArrayList* list, void* data, bool(*compare)(void*,void*));
static OpState removeList(ArrayList* list, unsigned int index);
static OpState destroyList(ArrayList* list);
static void* getElement(ArrayList* list, unsigned int index);


ArrayList* newArrayList(void)
{
	ArrayList* list = NULL;

	list = (ArrayList*)malloc(sizeof(ArrayList));

	if(list != NULL)
	{
		list->listHead = (DoubleListHead)malloc(sizeof(ptrNode));
		list->listEnd = (DoubleListHead)malloc(sizeof(ptrNode));
		if(list->listHead != NULL && list->listEnd != NULL)
		{
			*list->listHead = NULL;
			*list->listEnd = NULL;
		}

		list->size = 0;
		list->add = addList;
		list->remove = removeList;
		list->destroy = destroyList;
		list->isEmpty = isEmptyList;
		list->get = getElement;
	}

	return list;
}

static bool isEmptyList(ArrayList* list)
{
	return list == NULL||(*list->listHead == NULL);
}

static OpState destroyList(ArrayList* list)
{
	ptrNode auxNode;

	if(list == NULL)
		return FAILURE;

	while(list != NULL)
	{
		auxNode = *list->listHead;
		*list->listHead = (*list->listHead)->next;
		free(auxNode);
	}

	return SUCCESS;
}

static OpState addList(ArrayList* list, void* data, bool(*compare)(void*,void*))
{
	ptrNode newNode;
	ptrNode scroll;
	ptrNode auxPrevious;

	if(list == NULL)
		return FAILURE;

	newNode = (ptrNode)malloc(sizeof(struct Node));
	if(newNode == NULL)
		return FAILURE;

	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->index = list->size;

	if(*list->listHead == NULL)
	{
		*list->listHead = newNode;
		*list->listEnd = newNode;
	}
	else
	{
		scroll = *list->listHead;

		while(scroll != NULL && compare(data,scroll))
		{
			auxPrevious = scroll; 
			scroll = scroll->next;
		}

		if(scroll == *list->listHead)
		{
			newNode->next = *list->listHead;
			(*list->listHead)->previous = newNode;
			*list->listHead = newNode;
		}
		else
		{
			newNode->next = auxPrevious->next;
			newNode->previous = auxPrevious;
			auxPrevious->next = newNode;

			if(scroll != NULL)
				scroll->previous = newNode;
			else
			{
				*list->listEnd = newNode;
			}

		}
	}
	list->size++;

	return SUCCESS;

}
static void* getElement(ArrayList* list, unsigned int index)
{
	ptrNode scroll;

	if(list == NULL || *list->listHead == NULL)
		return NULL;


	scroll = *list->listHead;

	while(scroll != NULL && index != scroll->index)
	{
		scroll =  scroll->next;
	}

	return scroll;
}

static OpState removeList(ArrayList* list, unsigned int index)
{


}