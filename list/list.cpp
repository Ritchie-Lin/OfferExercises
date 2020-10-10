#include "list.h"
#include <iostream>


/**
 * 初始化链表
 * @param head 指向链表头节点指针的指针
 * @param value 头节点的值
 * @version 1.0
 * @author Ritchie.Lin
 */
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

/**
 * 向链表尾部添加节点
 * @param head 指向链表头节点的指针
 * @param value 新添加节点的值
 * @version 1.0
 * @author Ritchie.Lin
 */
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

/**
 * 打印链表各节点的值
 * @param head 指向链表头节点的指针
 * @version 1.0
 * @author Ritchie.Lin
 */
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

/**
 * 打印链表各节点的值和另外指针的指向
 * @param head 指向链表头节点的指针
 * @version 1.0
 * @author Ritchie.Lin
 */
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

/**
 * 删除链表，释放资源
 * @param head 指向链表头节点指针的指针
 * @version 1.0
 * @author Ritchie.Lin
 */
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
