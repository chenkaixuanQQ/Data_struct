#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

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
