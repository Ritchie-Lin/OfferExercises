#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "binaryTree/BinaryTree.h"

using namespace std;

bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    if (pRoot2 == nullptr)
        return true;

    if (pRoot1 == nullptr)
        return false;

    if (pRoot1->m_value != pRoot2->m_value)
        return false;
    
    return DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
           DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool HasSubtree(BinaryTreeNode *pRoot1, BinaryTreeNode *pRoot2)
{
    bool result  = false;

    if (pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if (pRoot1->m_value == pRoot2->m_value)
            result = DoesTree1HaveTree2(pRoot1, pRoot2);
        
        if (!result)
            result = HasSubtree(pRoot1->m_pLeft, pRoot2);
        
        if (!result)
            result = HasSubtree(pRoot1->m_pRight, pRoot2);
    }

    return result;
}


int main()
{
    BinaryTreeNode *pTree1 = nullptr;
    int data1[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(data1)/sizeof(int);
    CreateBinaryTree(pTree1, data1, len);
    cout << "前序遍历Tree1：" << endl;
    PreOrderTraverse(pTree1);
    cout << endl;

    BinaryTreeNode *pTree2 = nullptr;
    int data2[] = {3,6,8};
    len = sizeof(data2)/sizeof(int);
    CreateBinaryTree(pTree2, data2, len);
    cout << "前序遍历Tree2：" << endl;
    PreOrderTraverse(pTree2);
    cout << endl;

    cout << "Is tree1 has tree2? " << HasSubtree(pTree1, pTree2) << endl;

    return 0;
}
