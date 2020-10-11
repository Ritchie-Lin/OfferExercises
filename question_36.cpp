/*
36.
输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。
以下为转换的例子：
        10
      __|__
     |     |
     6     14
   __|_   _|__  
  |    | |    |
  4   8 12   16
-->
4 ⇄ 6 ⇄ 8 ⇄ 10 ⇄ 12 ⇄ 14 ⇄ 16
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "binaryTree/BinaryTree.h"
#include "list/list.h"

using namespace std;

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if (pNode == nullptr)
        return;

    BinaryTreeNode *pCurrent = pNode;

    if (pCurrent->m_pLeft != nullptr)
        ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
    
    pCurrent->m_pLeft = *pLastNodeInList;
    if (*pLastNodeInList != nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;
    
    *pLastNodeInList = pCurrent;

    if (pCurrent->m_pRight != nullptr)
        ConvertNode(pCurrent->m_pRight, pLastNodeInList);
}

ListNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode *pLastNodeInList = nullptr;
    ConvertNode(pRootOfTree, &pLastNodeInList);

    BinaryTreeNode *pHeadOfList = pLastNodeInList;
    while (pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;
    
    return (ListNode*)pHeadOfList;
}

int main()
{
    BinaryTreeNode *pTree = nullptr;
    int data[] = {10, 6, 14, 4, 8, 12, 16};
    int len = sizeof(data)/sizeof(int);

    CreateBinaryTree(pTree, data, len);

    cout << "Printf the tree with level: " << endl;
    PrintFromTopToBottomWithLevel(pTree);

    ListNode* pHead = Convert(pTree);

    cout << "Printf the list:" << endl;
    PrintfListWithSibling(pHead);

    // release the list
    DeleteList(&pHead);
    return 0;
}
