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
SLN SLNInitial();
//Add :
void SLPushBack(SLN* phead, SLDataType x);
void SLPushFront(SLN* phead, SLDataType x);
void SLInsertFront(SLN* phead,SLN* pos, SLDataType x);
void SLInsertFront_PLUS(SLN* pos, SLDataType x);
//Pop:
void SLPopBack(SLN* phead);
void SLPopFront(SLN* phead);
void SLPop(SLN* phead, SLN* pos);
//Find:
SLN* SLFind(SLN* phead,SLDataType x);

//Destroy
void SLDestroy(SLN* phead);