/*
34.
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从数的根节点开始往下一直到叶节点所经过的节点形成一条路径。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "binaryTree/BinaryTree.h"

using namespace std;

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int currentSum)
{
    currentSum += pRoot->m_value;
    path.push_back(pRoot->m_value);

    // 如果是叶节点，并且路径上节点值的和等于输入的值，
    // 则打印出这条路径。
    bool isLeaf = pRoot->m_pLeft==nullptr && pRoot->m_pRight==nullptr;
    if (currentSum == expectedSum && isLeaf)
    {
        cout << "A path is found:" << endl;
        vector<int>::iterator iter = path.begin();
        for (; iter != path.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
    
    // 如果不是叶节点，则遍历它的子节点。
    if (pRoot->m_pLeft != nullptr)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    
    if (pRoot->m_pRight != nullptr)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);

    // 在返回父节点之前，在路径上删除当前节点。
    path.pop_back();
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if (pRoot == nullptr)
    {
        cout << "invalid input, return !" << endl;
        return;
    }

    vector<int> path;
    int currentSum = 0;
    FindPath(pRoot, expectedSum, path, currentSum);
}

int main()
{
    int data[] = {10, 5, 12, 4, 7};
    const static int expectedSum = 22;
    BinaryTreeNode* pTree;

    CreateBinaryTree(pTree, data, sizeof(data)/sizeof(int));

    FindPath(pTree, expectedSum);

    releaseBinaryTree(pTree);


    return 0;
}
