/*
32.对于二叉树：
        8
      __|__
     |     |
     6     10
   __|_   _|__  
  |    | |    |
  5    7 9    11

<1>不分行从上到下打印二叉树。
从上到下打印二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
示例树打印为：8 6 10 5 7 9 11

<2>分行从上到下按层打印二叉树。
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
示例树打印为：
8
6 10
5 7 9 11

<3>之字形打印二叉树
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，以此类推。
示例树打印顺序为：
8
10 6
5 7 9 11
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <deque>
#include <stack>
#include "binaryTree/BinaryTree.h"

using namespace std;

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if (pTreeRoot == nullptr)
    {
        cout << "null tree, return!" << endl;
        return;
    }

    deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);

    while (!dequeTreeNode.empty())
    {
        BinaryTreeNode *pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        cout << pNode->m_value << " ";

        if (pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);

        if (pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }

    cout << endl;
    return;
}

void PrintFromTopToBottomWithLevel(BinaryTreeNode* pTreeRoot)
{
    if (pTreeRoot == nullptr)
    {
        cout << "null tree, return!" << endl;
        return;
    }

    deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);
    int toBePrintCount = 1;
    int nextLevelCount = 0;

    while (!dequeTreeNode.empty())
    {
        BinaryTreeNode* pNode = dequeTreeNode.front();
        dequeTreeNode.pop_front();

        cout << pNode->m_value << " ";

        if (pNode->m_pLeft)
        {
            dequeTreeNode.push_back(pNode->m_pLeft);
            nextLevelCount++;
        }

        if (pNode->m_pRight)
        {
            dequeTreeNode.push_back(pNode->m_pRight);
            nextLevelCount++;
        }

        if (--toBePrintCount == 0)
        {
            cout << endl;
            toBePrintCount = nextLevelCount;
            nextLevelCount = 0;
        }
    }

    cout << endl;
    return;
}

void PrintFromTopToBottomDiffOrder(BinaryTreeNode* pTree)
{
    if (pTree == nullptr)
    {
        cout << "null tree, return!" << endl;
        return;
    }

    stack<BinaryTreeNode*> levels[2];
    int current = 0;
    int next = 1;

    levels[current].push(pTree);
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();

        cout << pNode->m_value << " ";

        if (current == 0)// 当前是奇数层，左节点先入栈，右节点后入栈
        {
            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else// 当前是偶数层，右节点先入栈，左节点后入栈
        {
            if (pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);

            if (pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }
        
        if (levels[current].empty())
        {
            cout << endl;
            current = 1 - current;
            next = 1 - next;
        }
    }

    cout << endl;
    return;
}

int main()
{
    BinaryTreeNode *pTree = nullptr;
    const int data[] = {8, 6, 10, 5, 7, 9, 11};
    int len = sizeof(data)/sizeof(int);
    
    CreateBinaryTree(pTree, data, len);

    cout << "层序遍历：" << endl;
    PrintFromTopToBottom(pTree);
    cout << endl;

    cout << "层序遍历(分层)：" << endl;
    PrintFromTopToBottomWithLevel(pTree);

    cout << "之字形层序遍历(分层)：" << endl;
    PrintFromTopToBottomDiffOrder(pTree);

    releaseBinaryTree(pTree);

    return 0;
}
