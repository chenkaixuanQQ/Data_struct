#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


typedef struct ListNode
{
    int val;
    struct ListNode* next;
}LSN;
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    if (pHead1 == NULL)
    {
        return pHead2;
    }
    else if (pHead2 == NULL)
    {
        return pHead1;
    }

    LSN* NewHead = NULL;
    if (pHead1->val <= pHead2->val)//Determine new head
    {
        NewHead = pHead1;
    }
    else
    {
        NewHead = pHead2;
    }


    LSN* LS1 = pHead1;
    LSN* LS2 = pHead2;
    LSN* prev = pHead2;



    while (LS1 && LS2)
    {
        LSN* LS1_next = LS1->next;
        LSN* LS2_next = LS2->next;

        if (LS2->val >= LS1->val)
        {
            prev = LS1;
            LS1 = LS1_next;
        }
        else
        {
            int swat = LS1->val;
            LS1->val = LS2->val;
            LS2->val = swat;
            LS2->next = LS1_next;
            LS1->next = LS2;

            LS1 = LS2;
            LS2 = LS2_next;
        }


    }

    if (LS2 == NULL)
    {
        return NewHead;
    }

    prev->next = LS2;
    return NewHead;

}


int main()
{
    LSN p1 = { 1 , NULL};
    LSN p2 = { 3 , NULL};
    LSN p3 = { 5 , NULL};
    LSN p4 = { 2 , NULL};
    LSN p5 = { 4 , NULL};
    LSN p6 = { 6 , NULL};

    p1.next = &p2;
    p2.next = &p3;
    p4.next = &p5;
    p5.next = &p6;


    LSN* ret = Merge(&p1, &p4);
    int c = 0;
    return 0;
}
