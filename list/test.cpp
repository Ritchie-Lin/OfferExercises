#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "list.h"

using namespace std;

int main()
{
    ListNode *head = nullptr;

    if (!InitList(&head, 0) || head == nullptr)
    {
        cout << "init list fail" << endl;
        return -1;
    }

    AddNodeToList(head, 1);
    AddNodeToList(head, 2);
    AddNodeToList(head, 3);
    AddNodeToList(head, 4);

    PrintfList(head);
    
    DeleteList(&head);

    return 0;
}
