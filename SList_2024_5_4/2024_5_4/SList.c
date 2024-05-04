#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//void SListTest()
//{
//	SLN* node1 = (SLN*)malloc(sizeof(SLN));
//	SLN* node2 = (SLN*)malloc(sizeof(SLN));
//	SLN* node3 = (SLN*)malloc(sizeof(SLN));
//	SLN* node4 = (SLN*)malloc(sizeof(SLN));
//	assert(node1);
//	assert(node2);
//	assert(node3);
//	assert(node4);
//	node1->data = 1;
//	node2->data = 2;
//	node3->data = 3;
//	node4->data = 4;
//	
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = NULL;
//
//	SLN* phead = node1;
//	SLPrint_Int(phead);
//}

void SListTest1()
{
	SLN p1 = { 0, NULL };
	SLPushBack(&p1,1);
	SLPushBack(&p1,2);
	SLPushFront(&p1, 1111);
	SLPushBack(&p1,6);
	SLPushBack(&p1,4);
	SLPushFront(&p1, 222);
	
	SLPrint_Int(p1);

	SLPopBack(&p1);
	SLPrint_Int(p1);
	SLPopBack(&p1);
	SLPrint_Int(p1);
	SLPopBack(&p1);
	SLPrint_Int(p1);
	SLPopBack(&p1);
	SLPrint_Int(p1);
	SLPopBack(&p1);
	SLPrint_Int(p1);
	SLPopBack(&p1);
	SLPrint_Int(p1);

}
int main()
{
	SListTest1();


	return 0;
}


