#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SLN;


//Linked list print:
void SLPrint_Int(SLN phead);

//Add :
void SLPushBack(SLN* phead, SLDataType x);
void SLPushFront(SLN* phead, SLDataType x);
void SLPopBack(SLN* phead);
