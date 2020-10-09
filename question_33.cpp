/*
33.
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字
互不相同。如：{5,6,7,9,11,10,8}是以下二叉搜索树的后序遍历结果。
而{7,4,6,5}，则由于没有哪颗二叉搜索树的后序遍历结果是这个序列，
所以返回false。
        8
      __|__
     |     |
     6     10
   __|_   _|__  
  |    | |    |
  5    7 9    11
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "util/util.h"

using namespace std;

bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == nullptr || length <= 0)
    {
        cout << "invalid input" << endl;
        return false;
    }

    int root = sequence[length - 1];

    // 在二叉搜索树中左子树节点的值小于根节点的值
    int i = 0;
    for (; i < length - 1; i++)
    {
        if (sequence[i] > root)
            break;
    }

    // 在二叉搜索树中右子树节点的值大于根节点的值
    for (int j = i; j < length - 1; j++)
    {
        if (sequence[j] < root)
            return false;
    }

    // 判断左子树是不是二叉搜索树
    bool left = true;
    if (i > 0)
        left = VerifySquenceOfBST(sequence, i);

    // 判断右子树是不是二叉搜索树
    bool right = true;
    if (i < length - 1)
        right = VerifySquenceOfBST(sequence + i, length - i - 1);

    return (left && right);
}

int main()
{
    int data1[] = {5, 7, 6, 9, 11, 10, 8};
    int len1 = sizeof(data1)/sizeof(int);
    int data2[] = {7, 4, 6, 5};
    int len2 = sizeof(data2)/sizeof(int);

    cout << TransferNumToStr(data1, len1) << string(VerifySquenceOfBST(data1, len1)?" is":" isn't") << " sequence of BST." << endl;
    cout << TransferNumToStr(data2, len2) << string(VerifySquenceOfBST(data2, len2)?" is":" isn't") << " sequence of BST." << endl;

    return 0;
}
