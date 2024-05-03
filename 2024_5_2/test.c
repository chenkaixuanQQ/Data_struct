#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"


//Test sequence table
void SLTest01()
{
	SL s1;
	SLInit(&s1);
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPushBack(&s1, 4);
	SLPushBack(&s1, 5);
	//SLPushFront(&s1, 0);
	//SLPushFront(&s1, 10);
	//SLPushFront(&s1, 10);
	//SLPrintInt(&s1);
	//SLPop(&s1, 2);
	//SLPrintInt(&s1);
	//SLInsert(&s1, s1.size, 1000);
	//SLPrintInt(&s1);

	SLPrintInt(&s1);


	SLErase(&s1, 0);
	SLErase(&s1, 0);
	SLErase(&s1, 0);
	SLPrintInt(&s1);
}


int main()
{
	SLTest01();

	return 0;
}







