#define _CRT_SECURE_NO_WARNINGS 1
#include "Linked_table.h"



void SLTest()
{
	SLN p1 = SLNInitial();
	SLPushBack(&p1, 1);
	SLPushBack(&p1, 2);

	SLPushBack(&p1, 3);
	SLPushBack(&p1, 4);
	SLN* slfind = SLFind(&p1, 2);



	//SLInsertFront(&p1, slfind, 999);
	SLInsertFront_PLUS(slfind, 999);
	slfind = SLFind(&p1, 2);

	SLPop(&p1, slfind);

	//SLPushBack(&p1, 5);
	//SLPushBack(&p1, 6);
	//SLPushFront(&p1, 6);
	//SLPushFront(&p1, 1000);
	//SLPopFront(&p1);

	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	//SLPopFront(&p1);
	SLPrint_Int(p1);
	//SLN* slfind = SLFind(&p1, 4);
	//if (slfind)
	//{
	//	printf("Find it!\n");
	//}
	//else
	//{
	//	printf("Not exit!\n");
	//}

	SLDestroy(&p1);

}

int main()
{
	SLTest();


	return 0;
}