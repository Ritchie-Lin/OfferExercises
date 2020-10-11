#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <vector>

using namespace std;

struct BinaryTreeNode
{
    int m_value;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pLeft;
};

void CreateBinaryTree(BinaryTreeNode* &tree, const int *data, int length);
void PreOrderTraverse(BinaryTreeNode* tree);//前序遍历
void InOrderTraverse(BinaryTreeNode* tree);//中序遍历
void PostOrderTraverse(BinaryTreeNode* tree);//后序遍历
vector<int> levelOrder(BinaryTreeNode* tree);//层序遍历
vector<vector<int> > levelOrderWithLevel(BinaryTreeNode* tree);//层序遍历，按层输出
void PrintFromTopToBottomWithLevel(BinaryTreeNode* pTreeRoot);
void releaseBinaryTree(BinaryTreeNode* &tree);//销毁二叉树

#endif