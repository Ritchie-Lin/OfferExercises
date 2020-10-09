#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTreeNode *pTree = nullptr;
    int data[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(data)/sizeof(int);

    CreateBinaryTree(pTree, data, len);

    cout << "前序遍历：" << endl;
    PreOrderTraverse(pTree);
    cout << endl;

    cout << "中序遍历：" << endl;
    InOrderTraverse(pTree);
    cout << endl;

    cout << "后序遍历：" << endl;
    PostOrderTraverse(pTree);
    cout << endl;

    cout << "层序遍历：" << endl;
    vector<int> ret;
    ret = levelOrder(pTree);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;

    cout << "层序遍历(按层输出)：" << endl;
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
    cout << endl;

    releaseBinaryTree(pTree);

    return 0;
}
