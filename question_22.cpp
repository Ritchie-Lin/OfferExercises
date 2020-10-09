/*
 * 输入一个链表，输出该链表倒数第K个节点，为了符合大多数人的习惯，
 * 本题从1开始计数，即链表的尾节点是倒数第1个节点，例如，一个链表
 * 有6个节点，从头节点开始，它们的值依次是1，2，3，4，5，6，这个
 * 链表的倒数第3个节点是值为4的节点。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

#define LIST_COUNT 6
#define K_LAST_NUMBER 3

using namespace std;

ListNode* FindKthToTail(ListNode *pListHead, unsigned int k)
{
    if (pListHead == nullptr || k == 0)
    {
        cout << "invalid input !" << endl;
        return nullptr;
    }

    ListNode *pAhead = pListHead;
    ListNode *pBehind = nullptr;

    // 使指针相隔k个节点
    for (int i = 0; i < k - 1; i++)
    {
        pAhead = pAhead->m_pNext;
        if (pAhead == nullptr)
        {
            cout << "out of range !" << endl;
            return nullptr;
        }
    }
    pBehind = pListHead;

    // 找到末节点
    while(pAhead->m_pNext != nullptr)
    {
        pAhead = pAhead->m_pNext;
        pBehind = pBehind->m_pNext;
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

    // do something
    ListNode *temp = FindKthToTail(head, K_LAST_NUMBER);
    if (temp != nullptr)
        cout << K_LAST_NUMBER << "th last number is: " << temp->value << endl;

    DeleteList(&head);
    return 0;
}
