/************************************/
/*		File: ArrayList.h		    */
/*		Author: Deived William		*/
/*		Date: 15/03/2017			*/
/************************************/




#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_


#ifdef __cplusplus
extern "C"{
#endif



typedef enum OpState
{
	SUCCESS = 0;
	FAILURE
}OpState;

typedef struct List
{
	void* data;
	struct List* next;
	struct List* previous;
	unsigned int id;
}List;

typedef struct ArrayList
{
	List* beginning;
	List* end;
	unsigned int size;
	OpState(*add)(struct ArrayList*, void*, unsigned int);
	OpState(*remove)(struct ArrayList*, unsigned int);
	OpState(*destroyList)(struct ArrayList*);
	bool(*isEmpty)(struct ArrayList*);
}ArrayList;


ArrayList* newArrayList(void);


#ifdef __cplusplus
}
#endif

#endif