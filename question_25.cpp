/*
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点
 * 依然是递增排序的。
 * 例：
 * 1 --> 3 --> 5 --> 7
 * 2 --> 4 --> 6 --> 8 --> 10
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

#define LIST_1_COUNT 4
#define LIST_2_COUNT 5 

using namespace std;

ListNode* CreateList(int startNum, int nodeCnt)
{
    ListNode *head = nullptr;

    if (!InitList(&head, startNum) || head == nullptr)
    {
        cout << "init list fail !" << endl;
        return nullptr;
    }

    for (int i = 1; i < nodeCnt; i++)
        AddNodeToList(head, (i << 1) + startNum);

    return head;
}
/* e.g:
 * list one: 1 --> 3 --> 5 --> 7
 * list two: 2 --> 4 --> 6 --> 8 --> 10
 */
ListNode* MergeLists(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;
    
    ListNode *pMergeHead = nullptr;

    if (pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pMergeHead->m_pNext = MergeLists(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergeHead = pHead2;
        pMergeHead->m_pNext = MergeLists(pHead1, pHead2->m_pNext);
    }

    return pMergeHead; 
}
/* e.g:
 * list one: 1 --> 3 --> 5 --> 7
 * list two: 2 --> 4 --> 6 --> 8 --> 10
 */
ListNode* MergeListsNonRcs(ListNode *pHead1, ListNode *pHead2)
{
    if (pHead1 == nullptr)
        return pHead2;
    else if (pHead2 == nullptr)
        return pHead1;
    
    ListNode *pMergeHead = nullptr;
    if (pHead1->value < pHead2->value)
    {
        pMergeHead = pHead1;
        pHead1 = pHead1->m_pNext;
    }
    else
    {
        pMergeHead = pHead2;
        pHead2 = pHead2->m_pNext;
    }
    ListNode *pTemp = pMergeHead;
    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        if (pHead1->value < pHead2->value)
        {
            pTemp->m_pNext = pHead1;
            pTemp = pHead1;
            pHead1 = pHead1->m_pNext;
        }
        else
        {
            pTemp->m_pNext = pHead2;
            pTemp = pHead2;
            pHead2 = pHead2->m_pNext;
        }
    }

    if (pHead1 == nullptr)
    {
        pTemp->m_pNext = pHead2;
    }
    else if (pHead2 == nullptr)
    {
        pTemp->m_pNext = pHead1;
    }

    return pMergeHead;
}

int main()
{
    ListNode *head1 = CreateList(1, LIST_1_COUNT);
    if (head1 == nullptr)
        return -1;
    cout << "List One:" << endl;
    PrintfList(head1);

    ListNode *head2 = CreateList(2, LIST_2_COUNT);
    if (head2 == nullptr)
        return -1;
    cout << "List Two:" << endl;
    PrintfList(head2);

    // do something
    ListNode *pMergeHead = MergeListsNonRcs(head1, head2);
    if (pMergeHead != nullptr)
    {
        cout << "=================" << endl << "After merge:" << endl;
        PrintfList(pMergeHead);
        DeleteList(&pMergeHead);
    }

    //DeleteList(&head1);
    //DeleteList(&head2);
    return 0;
}
