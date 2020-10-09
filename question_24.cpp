/*
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表头节点。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

#define LIST_COUNT 8

using namespace std;

ListNode* ReverseList(ListNode *pHead)
{
    ListNode *pReverseHead = nullptr;
    ListNode *pNode = pHead;
    ListNode *pPrev = nullptr;
    ListNode *pNext = nullptr;
    while (pNode != nullptr)//如果pHead为nullptr，那么立即退出循环
    {
        pNext = pNode->m_pNext;

        if (pNext == nullptr)
            pReverseHead = pNode;

        pNode->m_pNext = pPrev;

        pPrev = pNode;
        pNode = pNext;
    }

    return pReverseHead;
}

int main()
{
    ListNode *head = nullptr;

    if (!InitList(&head, 1) || head == nullptr)
    {
        cout << "init list fail !" << endl;
        return -1;
    }

    for (int i = 0; i < LIST_COUNT-1; i++)
        AddNodeToList(head, i+2);

    PrintfList(head);

    // do something
    ListNode *pReverseHead = ReverseList(head);
    cout << "=======================" << endl;
    cout << "After reverse:" << endl;
    PrintfList(pReverseHead);
    cout << "Reverse Head: " << pReverseHead->value << endl;

    DeleteList(&head);
    return 0;
}
