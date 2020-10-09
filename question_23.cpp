/*
 * 如果一个链表中包含环，如何找出环的入口节点？ 
 * 例如下面的链表中环的入口节点是3.
 * 1 --> 2 --> 3 --> 4 --> 5 --> 6
 *             ↑                 |
 *             |-----------------|
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

#define LIST_COUNT 10

using namespace std;

ListNode* MeetingNode(ListNode *head)
{
    if (head == nullptr)
        return nullptr;
    
    ListNode *pSlow = head->m_pNext;
    ListNode *pFast = pSlow;

    while (pSlow != nullptr && pFast != nullptr)
    {
        pSlow = pSlow->m_pNext;
        
        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;
        else
            return nullptr;
        
        cout << "pSlow: " << pSlow->value << "pFast: " << pFast->value << endl;
        if (pSlow == pFast)
            return pFast;
    }

    cout << "test" << endl;
    return nullptr;
}

ListNode* MeetingNode2(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode *node = head;

    ListNode *pSlow = head->m_pNext;
    if (pSlow == nullptr)
        return nullptr;

    ListNode *pFast = pSlow->m_pNext;
    while (pSlow != nullptr && pFast != nullptr)
    {
        if (pSlow == pFast)
            return pFast;

        pSlow = pSlow->m_pNext;
        
        pFast = pFast->m_pNext;
        if (pFast != nullptr)
            pFast = pFast->m_pNext;
    }

    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* head, int &entryIndex)
{
    ListNode *meetingNode = MeetingNode(head);
    if (meetingNode == nullptr)
    {
        cout << "There is not meeting node." << endl;
        return nullptr;
    }

    // 得到环中节点的数目
    int nodesLoop = 1;
    ListNode *pNode = meetingNode;
    while (pNode->m_pNext != meetingNode)
    {
        pNode = pNode->m_pNext;
        nodesLoop++;
    }

    // 移动pAhead，次数为环中节点的数目
    ListNode *pAhead = head;
    for (int i = 0; i < nodesLoop; i++)
        pAhead = pAhead->m_pNext;
    
    entryIndex = 1;
    ListNode *pBehind = head;
    while (pAhead != pBehind)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
        entryIndex++;
    }

    return pBehind;
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

    // 形成闭环
    ListNode *lastNode = head;
    while (lastNode->m_pNext != NULL)
        lastNode = lastNode->m_pNext;

    ListNode *midNode = head;
    for (int i = 0; i < (LIST_COUNT >> 1); i++)
        midNode = midNode->m_pNext;

    lastNode->m_pNext = midNode;

    // do something
    int entryIndex = 0;
    ListNode *entryNode = EntryNodeOfLoop(head, entryIndex);
    if (entryNode != nullptr)
        cout << "The entry node is " << entryIndex << " th node, value is " << entryNode->value << endl;

    // 断开闭环
    lastNode->m_pNext = nullptr;
    DeleteList(&head);
    return 0;
}
