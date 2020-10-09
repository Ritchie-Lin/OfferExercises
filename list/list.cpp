#include "list.h"
#include <iostream>

bool InitList(ListNode **head, int value)
{
    *head = new ListNode;
    if (*head != nullptr)
    {
        (*head)->value = value;
        (*head)->m_pNext = nullptr;
        return true;
    }

    return false;
}

ListNode* AddNodeToList(ListNode *head, int value)
{
    if (head == nullptr)
    {
        std::cout << "head is nullptr" << std::endl;
        return nullptr;
    }

    ListNode *newNode = new ListNode;
    newNode->value = value;
    newNode->m_pNext = nullptr;
    if (newNode == nullptr)
    {
        std::cout << "node alloc fail" << std::endl;
        return nullptr;
    }
    
    ListNode *node = head;
    while (node->m_pNext != nullptr)
        node = node->m_pNext;

    node->m_pNext = newNode;

    return newNode;
}

bool PrintfList(ListNode *head)
{
    if (head == nullptr)
    {
        std::cout << "invalid input" << std::endl;
        return false;
    }

    ListNode *node = head;
    int i = 0;
    while (node != nullptr)
    {
        std::cout << "node[" << i << "]" <<" " << node->value << std::endl;
        node = node->m_pNext;
        i++;
    }

    return true;
}

bool PrintfListWithSibling(ListNode *head)
{
    if (head == nullptr)
    {
        std::cout << "invalid input" << std::endl;
        return false;
    }

    ListNode *node = head;
    int i = 0;
    while (node != nullptr)
    {
        std::cout << "node[" << i << "]" <<" " << node->value;
        if (node->m_Sibling)
        {
            std::cout << " --> " << node->m_Sibling->value << std::endl;
        }
        else
        {
            std::cout << std::endl;
        }
        
        node = node->m_pNext;
        i++;
    }

    return true;
}

bool DeleteList(ListNode **head)
{
    if (head == nullptr || *head == nullptr)
    {
        std::cout << "invalid input" << std::endl;
        return false;
    }
    ListNode *node = *head;
    ListNode *nextNode = *head;

    while (node != nullptr)
    {
        nextNode = node->m_pNext;
        node->m_pNext = nullptr;
        delete node;
        node = nextNode;
    }

    *head = nullptr;
    
    return true;
}
