#define _CRT_SECURE_NO_WARNINGS 1
#include "Linked_table.h"

SLN SLNInitial()
{
	SLN* p1 = (SLN*)malloc(sizeof(SLN));
	assert(p1);
	p1->data = 0;
	p1->next = NULL;
	return *p1;
}
void SLPrint_Int(SLN phead)
{
	SLN* pcur = &phead;
	assert(pcur);
	while (pcur->next)
	{
		printf("%d->", pcur->next->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

void SLPushBack(SLN* phead, SLDataType x)
{
	assert(phead);

	SLN* NewNode = (SLN*)malloc(sizeof(SLN));
	assert(NewNode);
	NewNode->data = x;
	NewNode->next = NULL;

	SLN* phead_cpy = phead;
	while (phead_cpy->next != NULL)
	{
		phead_cpy = phead_cpy->next;
	}

	(*phead_cpy).next = NewNode;
}
void SLPushFront(SLN* phead, SLDataType x)
{
	assert(phead);
	SLN* NewNode = (SLN*)malloc(sizeof(SLDataType));
	assert(NewNode);
	NewNode->data = x;
	SLN* p_cpy = phead->next;
	phead->next = NewNode;
	NewNode->next = p_cpy;
}
void SLPopBack(SLN* phead)
{
	assert(phead->next);

	SLN* phead_cpy = phead;
	SLN* prev = NULL;

	while (phead_cpy->next)
	{
		prev = phead_cpy;
		phead_cpy = phead_cpy->next;
	}
	free(phead_cpy);
	phead_cpy = NULL;
	prev->next = NULL;
}
void SLPopFront(SLN* phead)
{
	assert(phead->next);
	SLN* phead_cpy = phead->next;
	phead->next = phead_cpy->next;
	free(phead_cpy);
	phead_cpy = NULL;
}
SLN* SLFind(SLN* phead,SLDataType x)
{
	assert(phead->next);
	SLN* pcur = phead->next;
	assert(pcur);
	while(pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;

}
void SLInsertFront(SLN* phead, SLN* pos, SLDataType x)
{
	assert(phead);
	assert(pos);

	SLN* NewNode = (SLN*)malloc(sizeof(SLDataType));
	assert(NewNode);
	NewNode->data = x;
	NewNode->next = NULL;

	SLN* pcur = phead;

	if (pcur == pos)
	{
		SLPushFront(phead, x);
		return;
	}

	while (pcur->next != pos && pcur)
	{
		pcur = pcur->next;
	}
	if (pcur == NULL)
	{
		printf("The specified location does not exist!");
		return;
	}

	pcur->next = NewNode;
	NewNode->next = pos;

}
void SLInsertFront_PLUS(SLN* pos, SLDataType x)
{
	assert(pos);
	SLN* NewNode = (SLN*)malloc(sizeof(SLN));
	assert(NewNode);
	NewNode->data = pos->data;
	NewNode->next = pos->next;
	pos->next = NewNode;
	pos->data = x;


}
void SLPop(SLN* phead,SLN* pos)
{
	assert(pos);
	assert(phead);
	assert(phead->next);
	SLN* NewNode = phead;

	while (NewNode->next != pos && NewNode)
	{
		NewNode = NewNode->next;
	}

	if (NewNode == NULL)
	{
		printf("The specified location does not exist");
		return;
	}

	NewNode->next = pos->next;
	free(pos);
	pos = NULL;
}
void SLDestroy(SLN* phead)
{
	assert(phead);
	SLN* pcur = phead;
	SLN* Next = pcur->next;
	while (Next)
	{
		pcur = Next;
		Next = Next->next;
		free(pcur);
		pcur = NULL;
	}
	free(pcur);
	phead->next = NULL;
	pcur = NULL;
}