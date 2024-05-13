#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode
{
    int val;
    struct ListNode* next;
}LSN;

//struct ListNode* partition(struct ListNode* head, int x) {
//    if (head == NULL)
//    {
//        return NULL;
//    }
//
//    LSN* GreatHead = NULL;
//    LSN* LessHead = NULL;
//    LSN* pcur = head;
//    LSN* tail = NULL;
//
//    if (head->val < x)
//    {
//
//        while ((pcur->next)->val < x && pcur->next)
//        {
//            pcur = pcur->next;
//        }
//
//        if (pcur->next == NULL)
//        {
//            return LessHead;
//        }
//
//        tail = pcur;
//        GreatHead = pcur->next;
//        LSN* GreatTail = GreatHead;
//        pcur = GreatHead->next;
//        while (pcur)
//        {
//            if (pcur->val >= x)
//            {
//                GreatTail->next = pcur;
//
//                while (pcur && pcur->val >= x)
//                {
//                    pcur = pcur->next;
//                }
//                GreatTail = pcur;
//                if(!pcur)
//                {
//                    tail->next = GreatHead;
//                    return head;
//                }
//            }
//            
//            else
//            {
//                tail->next = pcur;
//                tail = pcur;
//                
//                while (pcur && pcur->val < x)
//                {
//                    pcur = pcur->next;
//                }
//                if(pcur)
//                    tail = pcur;
//            }
//        }
//
//        tail->next = GreatHead;
//        GreatTail->next = NULL;
//        return head;
//    }
//
//
//
//    else
//    {
//        GreatHead = head;
//
//        while (pcur->next && (pcur->next)->val >= x)
//        {
//            pcur = pcur->next;
//        }
//
//        if (pcur->next == NULL)
//        {
//            return GreatHead;
//        }
//
//        LessHead = pcur->next;
//        LSN* LessTail = NULL;
//        tail = pcur;
//        pcur = pcur->next;
//
//        while (pcur)
//        {
//            if (pcur->val < x)
//            {
//                pcur = pcur->next;
//                while (pcur && pcur->val < x)
//                {
//                    pcur = pcur->next;
//                }
//                LessTail = pcur;
//            }
//            else
//            {
//                tail->next = pcur;
//                tail = pcur;
//                pcur = pcur->next;
//                while (pcur && pcur->val >= x)
//                {
//                    pcur = pcur->next;
//                }
//                if(pcur)
//                    tail = pcur;
//            }
//        }
//
//        tail->next = NULL;
//        return LessHead;
//    }
//
//}
struct ListNode* partition(struct ListNode* head, int x)
{
    if (!head)
    {
        return NULL;
    }


    LSN* LessHead = NULL;
    LSN* LessTail = NULL;
    LSN* GreatHead = NULL;
    LSN* GreatTail = NULL;
    LSN* pcur = head;

    //Find head
    if (head->val < x)
    {
        LessHead = LessTail = head;

        while (pcur->next &&(pcur->next)->val < x)
        {
            pcur = pcur->next;
        }

        if (pcur->next == NULL)
        {
            return LessHead;
        }

        LessTail = pcur;
        pcur = pcur->next;
        GreatHead = GreatTail = pcur;
        while (pcur)
        {
            if (pcur->val >= x)
            {
                GreatTail = pcur;
                pcur = pcur->next;
                while (pcur->next && (pcur->next)->val >= x)
                {
                    GreatTail = pcur;
                    pcur = pcur->next;
                }
                if (pcur->next == NULL)
                {
                    LessTail->next = GreatHead;
                    GreatTail = pcur;
                    return LessTail;
                }
                
            }
            else
            {
                LessTail = pcur;
                pcur = pcur->next;
                while (pcur->next && (pcur->next)->val < x)
                {
                    LessTail = pcur;
                    pcur = pcur->next;
                }
                if (pcur->next == NULL)
                {
                    if ((pcur->next)->val >= x)
                    {
                        GreatTail = pcur->next;
                        LessTail = pcur;
                        LessTail->next = GreatHead;
                        return LessHead;
                    }
                }

            }
        }

        LessTail->next = GreatHead;
        GreatTail->next = NULL;
        return LessHead;

    }
    else
    {
        GreatHead = head;
    }





    return LessHead;
}

int main()
{
    LSN p1 = { 1, NULL };
    LSN p2 = { 4, NULL };
    LSN p3 = { 3, NULL };
    LSN p4 = { 2, NULL };
    LSN p5 = { 5, NULL };
    LSN p6 = { 2, NULL };
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    p4.next = &p5;
    p5.next = &p6;

    LSN* ret = partition(&p1, 3);

    LSN* head = &p1;
    while (head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }

    int c = 0;

    return 0;
}