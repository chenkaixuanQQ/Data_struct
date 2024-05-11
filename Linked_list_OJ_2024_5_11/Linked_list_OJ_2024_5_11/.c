#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


//Merge two sorted linked list:

typedef struct ListNode
{
	int val;
	struct ListNode* next;
}LSN;


//Method 1:  Creat a new list
struct ListNode* Merge1(struct ListNode* pHead1, struct ListNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}

	LSN* NewHead = NULL;
	LSN* NewTail = NULL;
	LSN* LS1 = pHead1;
	LSN* LS2 = pHead2;


	//First : Find the new head
	if (LS1->val <= LS2->val)
	{
		NewHead = LS1;
		LS1 = LS1->next;
	}
	else
	{
		NewHead = LS2;
		LS2 = LS2->next;
	}

	NewTail = NewHead;

	//Find the body:
	while (LS1 && LS2)
	{
		if (LS1->val <= LS2->val)
		{
			NewTail->next = LS1;
			LS1 = LS1->next;
			NewTail = NewTail->next;
		}
		else
		{
			NewTail->next = LS2;
			LS2 = LS2->next;
			NewTail = NewTail->next;

		}
	}


	if (LS1)
	{
		NewTail->next = LS1;
		return NewHead;
	}
	NewTail->next = LS2;
	return NewHead;
}

//Method 2:  Straight insertion
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if(pHead2 == NULL)
	{
		return pHead1;
	}


	LSN* NewHead = NULL;
	LSN* LS1 = pHead1;
	LSN* next1 = LS1->next;

	LSN* LS2 = pHead2;
	LSN* next2 = LS2->next;

	LSN* prev = LS1;

	//First : Find the new head
	if (LS1->val <= LS2->val)
	{
		NewHead = LS1;
		LS1 = LS1->next;
	}
	else
	{
		NewHead = LS2;
		NewHead->next = LS1;
		LS2 = next2;
	}

	while (LS1 && LS2)
	{
		next1 = LS1->next;
		next2 = LS2->next;
		if (LS1->val <= LS2->val)
		{
			prev = LS1;
			LS1 = next1;
		}
		else
		{
			//Attention!  Swap numbers and then tail insert, 
			// which is actually equivalent to head insert.

			int swap = LS1->val;
			LS1->val = LS2->val;
			LS2->val = swap;

			//Tail insert:
			LS1->next = LS2;
			LS2->next = next1;

			LS1 = LS2;
			prev = LS2;
			LS2 = next2;
		}
	}


	if (LS1)
	{
		return NewHead;
	}
	prev->next = LS2;
	return NewHead;
}






int main()
{
	LSN P1 = { 1, NULL };
	LSN P2 = { 3, NULL };
	LSN P3 = { 5, NULL };
	LSN L1 = { 2, NULL };
	LSN L2 = { 4, NULL };
	LSN L3 = { 6, NULL };
	P1.next = &P2;
	P2.next = &P3;
	L1.next = &L2;
	L2.next = &L3;


	LSN* ret = Merge(&P1, &L1);

	int c = 0;

	return 0;
}