#ifndef __LIST_H__
#define __LIST_H__

struct ListNode
{
    int value;
    ListNode *m_pNext;
    ListNode *m_Sibling;
} ;

bool InitList(ListNode **head, int value);
ListNode* AddNodeToList(ListNode *head, int value);
bool PrintfList(ListNode *head);
bool PrintfListWithSibling(ListNode *head);
bool DeleteList(ListNode **head);



#endif
