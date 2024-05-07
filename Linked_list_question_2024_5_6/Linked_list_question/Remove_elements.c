#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


//Given a list header and an integer VAL
//delete all VAL in the list and return a new header node

typedef struct SLinkedList
{
	int val;
	struct SLinkedList* next;
}SLL;

SLL* RemoveElements(SLL* phead, int val)
{
	//General idea: find value and delete it

	//1.Determine the new head:
	SLL* NewHead = phead;
	SLL* prev = NewHead;
	while (NewHead->val == val)
	{
		if (NewHead == NULL)//If all the value are val
		{
			return NewHead;
		}
		prev = NewHead;
		
		NewHead = NewHead->next;
		
		free(prev);
		prev = NULL;
	}

	SLL* pcur = NewHead;
	SLL* pcur_cpy = NewHead;
	prev = NewHead;

	//Find and delete:
	while (pcur)
	{
		if (pcur->val == val)
		{
			prev->next = pcur->next;
			pcur_cpy = pcur;
			free(pcur_cpy);
			pcur_cpy = NULL;
		}
	}


	return NewHead;
}

