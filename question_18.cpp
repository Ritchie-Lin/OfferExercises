#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list/list.h"

using namespace std;

int main()
{
    ListNode *head = nullptr;
    if (!InitList(&head, 0) || head == nullptr)
    {
        cout << "list init fail." << endl;
        return -1;
    }

    AddNodeToList(head, 1);
    AddNodeToList(head, 2);
    ListNode* targetNode = AddNodeToList(head, 3);
    AddNodeToList(head, 4);

    cout << "show list:" << endl;
    PrintfList(head);

    cout << "targetNode:" << targetNode->value << endl;

    DeleteList(&head);
    return 0;
}
