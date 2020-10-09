#ifndef __LIST_H__
#define __LIST_H__

typedef struct node
{
    int value;
    struct node *m_pNext;
    struct node *m_Sibling;
} ListNode;

bool InitList(ListNode **head, int value);
ListNode* AddNodeToList(ListNode *head, int value);
bool PrintfList(ListNode *head);
bool PrintfListWithSibling(ListNode *head);
bool DeleteList(ListNode **head);



#endif
