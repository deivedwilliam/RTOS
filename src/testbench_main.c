#include "../DataStructure.h"
#include <stdio.h>
#include <stdlib.h>


typedef union Integer
{
	int value;
	unsigned uvalue;

}*Integer;

Integer newInteger(unsigned value)
{
	Integer integer = NULL;

	integer = (Integer)calloc(1,sizeof(union Integer));

	if(integer != NULL)
	{
		integer->value = value;
		return integer;
	}
}



int main(int argc, char const *argv[])
{
	List myList;
	Integer ipt;

	myList = newList();

	DataStructureInsertTop(myList,newInteger(10));
	DataStructureInsertTop(myList,newInteger(1));
	DataStructureInsertTop(myList,newInteger(18));

	foreach(myList,ipt)
	{
	   //if(ipt != NULL)
			printf("%i\n",((Integer)ipt)->value);
	}
	


	return 0;
}