/*
35.
请实现函数ListNode* Clone(ListNode* pHead),复制一个链表，在这个链表中，
每个节点除了有一个m_pNext指针指向下一个节点，还有一个m_pSibling指针指向链表
中的任意节点或者nullptr。
如：
|-----------↓
A --> B --> C --> D --> E
      |_________________↑
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

using namespace std;

/**
 * function: 复制原始链表的任意节点N并创建新节点N', 再把N'连接到N的后面
 */
void CloneNodes(ListNode* pHead)
{
    ListNode* pNode = pHead;

    while (pNode != nullptr)
    {
        ListNode* pCloned = new ListNode();
        pCloned->value = pNode->value;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_Sibling = nullptr;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}

/**
 * function: 设置复制出来的节点m_pSibling.
 */
void ConnectSiblingNodes(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ListNode* pCloned = pNode->m_pNext;
        if (pNode->m_Sibling != nullptr)
        {
            pCloned->m_Sibling = pNode->m_Sibling->m_pNext;
        }
        pNode = pCloned->m_pNext;
    }
}

/**
 * function: 将得到的链表奇偶数位置上的节点分开，组成两个链表，偶数位上的位clone list
 */
ListNode* ReconnectNodes(ListNode* pHead)
{
    ListNode* pNode = pHead;
    ListNode* pClonedHead = nullptr;
    ListNode* pClonedNode = nullptr;

    if (pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }

    while (pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    return pClonedHead;
}

int main()
{
    ListNode *pHead = nullptr;

    if (!InitList(&pHead, 0) || pHead == nullptr)
    {
        cout << "init list fail" << endl;
        return -1;
    }

    ListNode* pNode_1 = AddNodeToList(pHead, 1);
    ListNode* pNode_2 = AddNodeToList(pHead, 2);
    ListNode* pNode_3 = AddNodeToList(pHead, 3);
    ListNode* pNode_4 = AddNodeToList(pHead, 4);

    pHead->m_Sibling = pNode_2;
    pNode_3->m_Sibling = pNode_1;
    pNode_2->m_Sibling = pNode_4;

    cout << "orignal list(" << pHead << "):" << endl;
    PrintfListWithSibling(pHead);

    /*clone*/
    ListNode* pClonedHead = nullptr;
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    pClonedHead = ReconnectNodes(pHead);

    if (pClonedHead != nullptr)
    {
        cout << "clone list(" << pClonedHead << "):" << endl;
        PrintfListWithSibling(pClonedHead);
    }
    
    DeleteList(&pHead);

    return 0;
}
