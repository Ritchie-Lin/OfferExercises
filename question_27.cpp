/**
 * 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
 */ 

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include "binaryTree/BinaryTree.h"

using namespace std;

void MirrorRecursively(BinaryTreeNode *pNode)
{
    if (pNode == nullptr)
        return;
    
    if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
        return;
    
    BinaryTreeNode *pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    //if (pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    
    //if (pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

void MirrorRecursivelyLoop(BinaryTreeNode *pTree)
{
    if (pTree == nullptr)
        return;
    
    queue<BinaryTreeNode*> que;
    que.push(pTree);
    while (!que.empty())
    {
        BinaryTreeNode *pNode = que.front();
        que.pop();
        BinaryTreeNode *pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if (pNode->m_pLeft)
            que.push(pNode->m_pLeft);

        if (pNode->m_pRight)
            que.push(pNode->m_pRight);
    }
}
int main()
{
    int data[] = {1,2,3,4,5,6};
    BinaryTreeNode *pTree = nullptr;
    int len = sizeof(data)/sizeof(int);

    CreateBinaryTree(pTree, data, len);
    cout << "层序遍历：" << endl;
    vector<vector<int> > ret;
    ret = levelOrderWithLevel(pTree);
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "镜像之后（递归）：" << endl;
    MirrorRecursively(pTree);
    ret = levelOrderWithLevel(pTree);
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "镜像之后（循环）：" << endl;
    MirrorRecursivelyLoop(pTree);
    ret = levelOrderWithLevel(pTree);
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
        {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

    releaseBinaryTree(pTree);

    return 0;
}
