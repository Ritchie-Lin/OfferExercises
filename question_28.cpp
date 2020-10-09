/**
 * 请实现一个函数，用来判断一个二叉树是不是对称的，如果一颗二叉树
 * 和它的镜像一样，那么它是对称的。
 */ 

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "binaryTree/BinaryTree.h"

using namespace std;

bool isSymmetrical(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if (pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    
    if (pRoot1->m_value != pRoot2->m_value)
        return false;

    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)
        && isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}

bool isSymmetrical(BinaryTreeNode *pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}


int main()
{
    int data[] = {8, 6, 6, 5, 7, 7, 3};
    BinaryTreeNode *pTree = nullptr;
    int len = sizeof(data)/sizeof(int);

    CreateBinaryTree(pTree, data, len);

    // 层序遍历
    vector<vector<int> > levelRet;
    levelRet = levelOrderWithLevel(pTree);
    for (int i = 0; i < levelRet.size(); i++)
    {
        for (int j = 0; j < levelRet[i].size(); j++)
        {
            cout << levelRet[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Is tree Symmetrical? " << boolalpha <<isSymmetrical(pTree) << endl;

    return 0;
}
