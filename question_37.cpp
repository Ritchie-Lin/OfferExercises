/*
37.
请实现两个函数，分别用来序列化和反序列化二叉树。
如：
        1
      __|__
     |     |
     2     3
   __|_   _|  
  |   |  |   
  4   5  6    
序列化为：
    1,2,4,$,$,5,$,$,3,6,$,$,$
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "binaryTree/BinaryTree.h"

using namespace std;

void Serialize(BinaryTreeNode* pRoot, ostream& stream)
{
    if (pRoot == nullptr)
    {
        stream << "$,";
        return;
    }
    
    stream << pRoot->m_value << ",";
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

bool ReadStream(istream& stream, int* number)
{
    if (stream.eof())
        return false;
    
    char buffer[32] = {0};

    char ch;
    stream >> ch;
    int i = 0;
    while (!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if (i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }
    
    return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if (ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_value = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;
        
        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(data)/sizeof(int);
    BinaryTreeNode* pTree = nullptr;
    CreateBinaryTree(pTree, data, len);

    cout << "printf the tree with level: " << endl; 
    PrintFromTopToBottomWithLevel(pTree);

    Serialize(pTree, cout);
    cout << endl;

    BinaryTreeNode* pTreeDeserilize = nullptr;
    Deserialize(&pTreeDeserilize, cin);
    PrintFromTopToBottomWithLevel(pTreeDeserilize);

    releaseBinaryTree(pTree);

    return 0;
}
