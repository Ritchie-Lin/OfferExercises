/*
31.
输入两个整数序列，第一个序列表示栈的入栈顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列{1，2，3，4，5}是某个栈的压栈序列，序列
{4，5，3，2，1}是该压栈序列对应的一个弹出序列，但{4，3，5，1，2}就不可能是该压栈
序列的弹出序列。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include "util/util.h"

using namespace std;

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;

    if (pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        stack<int> stackData;
        while (pNextPop - pPop < nLength)
        {
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                if (pNextPush - pPush == nLength)// 防止越界访问
                    break;
                
                stackData.push(*pNextPush);
                pNextPush++;
            }

            if (stackData.top() != *pNextPop)
                break;
            
            stackData.pop();
            pNextPop++;
        }
        
        if (stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }

    return bPossible;
}

int main()
{
    int pushData[] = {1, 2, 3, 4, 5};
    int popData1[] = {4, 5, 3, 2, 1};
    int popData2[] = {4, 5, 3, 1, 2};

    int len = sizeof(pushData)/sizeof(int);
    cout << TransferNumToStr(popData1, len) << string(IsPopOrder(pushData, popData1, len)?" is":" isn't") << " the pop order of " << TransferNumToStr(pushData, len) << endl;
    cout << TransferNumToStr(popData2, len) << string(IsPopOrder(pushData, popData2, len)?" is":" isn't") << " the pop order of " << TransferNumToStr(pushData, len) << endl;

    return 0;
}
