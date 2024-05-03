#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//Check whether capacity is enough and add the capacity
void CapacityCheck(SL* ps)
{
	int NewCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	if (ps->size >= ps->capacity)
	{
		SLDataType* PsRet = (SLDataType*)realloc(ps->arr, 2 * NewCapacity * sizeof(SLDataType));
		if (PsRet == NULL)//If realloc failed.
		{
			perror("realloc fail!!!");
			exit(1);
		}

		ps->arr = PsRet;
		ps->capacity = NewCapacity;
	}
}

void SLPrintInt(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}


//Implements a method or interface defined in the sequence table
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}


//Push
void SLPushBack(SL* ps, SLDataType x)
{

	//if (ps == NULL)//Also , assert(ps != NULL)
	//{
	//	printf("ps == NULL,return");
	//	return;
	//}
	assert(ps);


	//If there's not enough space
	CapacityCheck(ps);

	//If there's enough space
	ps->arr[ps->size] = x;
	ps->size++;
}
void SLPushFront(SL* ps, SLDataType x)
{
	//Determine whether the pointer is NULL
	assert(ps);

	//If there's no enough space
	CapacityCheck(ps);

	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[0] = x;
	ps->size++;
	//Inserts at a specified position
}

//Inserts at a specified position
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);

	if (pos < 0 || pos > ps->size)
	{
		printf("Please enter right positin that you wanna insert.");
		return;
	}


	CapacityCheck(ps);

	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}

	ps->arr[pos] = x;
	ps->size++;
}


//Pop
void SLPopBack(SL* ps)
{
	assert(ps);
	
	if (ps->size == 0)
	{
		printf("No data");
		return;
	}

	//ps->arr[--ps->size] = 0;
	ps->size--;

}
void SLPopFront(SL* ps)
{
	assert(ps);
	if (ps->size == 0)
	{
		printf("No data");
		return;
	}

	for (int i = 1; i < ps->size; i++)
	{
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}

//Pop at a specified position:
void SLErase(SL* ps, int pos)
{
	assert(ps);

	if (pos < 0 || pos >= ps->size)
	{
		printf("Please enter a number greater than 0 and less than %d", ps->size);
		return;
	}

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;

}

