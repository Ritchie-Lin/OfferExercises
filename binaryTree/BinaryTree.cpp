#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include "BinaryTree.h"

/**
 * 使用数值元素的值创建二叉树
 * @param tree 二叉树根节点
 * @param data 整型数组，用于给二叉树节点赋值
 * @param length 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
void CreateBinaryTree(BinaryTreeNode* &tree, const int *data, int length)
{
    if (data == nullptr || length == 0 || length > 20)
    {
        cout << "invalid input" << endl;
        return;
    }

    BinaryTreeNode *nodes[20] = {nullptr};
    for (int i = 0; i < length; i++)
    {
        nodes[i] = new BinaryTreeNode;
        nodes[i]->m_value = data[i];
        //cout << data[i] << " ";
    }
    //cout << endl;

    // 遍历层
    int tempLen = length;
    //cout << "(0)" << nodes[0]->m_value << endl;
    for (int i = 0; tempLen = tempLen >> 1; i++)
    {
        // 遍历每层节点, (2 << i) >> 1 --> 2^(i -1)
        for (int j = 0; j < ((2 << i)>>1); j++)
        {
            int index = pow(2, i) - 1 + j;
            int leftChildIdx = 2 * index + 1;
            int rightChildIdx = 2 * index + 2;
            if (leftChildIdx < length)
            {
                //cout << "(" << leftChildIdx << ")" << nodes[leftChildIdx]->m_value << " ";
                nodes[index]->m_pLeft = nodes[leftChildIdx];
            }
            else
                goto EXIT_LOOP;
            if (rightChildIdx < length)
            {
                //cout << "(" << rightChildIdx << ")" << nodes[rightChildIdx]->m_value << " ";
                nodes[index]->m_pRight = nodes[rightChildIdx];
            }
            else
                goto EXIT_LOOP;
        }
        //cout << endl;
    }
EXIT_LOOP:
    //cout << endl;
    tree = nodes[0];
    return;
}

/**
 * 前序遍历二叉树
 * @param tree 二叉树根节点
 * @version 1.0
 * @author Ritchie.Lin
 */
void PreOrderTraverse(BinaryTreeNode* tree)
{
    if (tree)
    {
        cout << tree->m_value << " ";
        PreOrderTraverse(tree->m_pLeft);
        PreOrderTraverse(tree->m_pRight);
    }
}

/**
 * 中序遍历二叉树
 * @param tree 二叉树根节点
 * @version 1.0
 * @author Ritchie.Lin
 */
void InOrderTraverse(BinaryTreeNode* tree)
{
    if (tree)
    {
        InOrderTraverse(tree->m_pLeft);
        cout << tree->m_value << " ";
        InOrderTraverse(tree->m_pRight);
    }
}

/**
 * 后序遍历二叉树
 * @param tree 二叉树根节点
 * @version 1.0
 * @author Ritchie.Lin
 */
void PostOrderTraverse(BinaryTreeNode* tree)
{
    if (tree)
    {
        PostOrderTraverse(tree->m_pLeft);
        PostOrderTraverse(tree->m_pRight);
        cout << tree->m_value << " ";
    }
}

/**
 * 销毁二叉树
 * @param tree 二叉树根节点
 * @version 1.0
 * @author Ritchie.Lin
 */
void releaseBinaryTree(BinaryTreeNode* &tree)
{
    if (tree)
    {
        releaseBinaryTree(tree->m_pLeft);
        releaseBinaryTree(tree->m_pRight);
        delete tree;
        tree = nullptr;
    }
}

/**
 * 层序遍历二叉树
 * @param tree 二叉树根节点
 * @return vector数组
 * @version 1.0
 * @author Ritchie.Lin
 */
vector<int> levelOrder(BinaryTreeNode* tree)
{
    vector<int> ret;
    queue<BinaryTreeNode*> queue;
    if (tree)
        queue.push(tree);
    while(!queue.empty())
    {
        BinaryTreeNode* treeNode = queue.front();
        ret.push_back(treeNode->m_value);
        queue.pop();
        if (treeNode->m_pLeft)
            queue.push(treeNode->m_pLeft);
        if (treeNode->m_pRight)
            queue.push(treeNode->m_pRight);
    }
    return ret;
}

/**
 * 层序遍历二叉树，按层输出
 * @param tree 二叉树根节点
 * @return 二维向量，一级为层数，二级为每层节点的值
 * @version 1.0
 * @author Ritchie.Lin
 */
vector<vector<int> > levelOrderWithLevel(BinaryTreeNode* tree)
{
    vector<vector<int> > ret;
    if (tree == nullptr)
        return ret;

    queue<BinaryTreeNode*> queue;
    queue.push(tree);
    while (!queue.empty())
    {
        int nodeCntInQueue = queue.size();
        ret.push_back(vector<int>());       //创建一个向量，并加入另一向量中
        for (int i = 0; i < nodeCntInQueue; i++)
        {
            BinaryTreeNode* tempNode = queue.front();
            queue.pop();
            ret.back().push_back(tempNode->m_value);
            if (tempNode->m_pLeft != nullptr)
                queue.push(tempNode->m_pLeft);
            if (tempNode->m_pRight != nullptr)
                queue.push(tempNode->m_pRight);
        }
    }
    return ret;
}
