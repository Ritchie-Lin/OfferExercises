/*
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

bool isEvenNumber(int num);

void exchNumber(int& number1, int& number2)
{
    int temp;
    temp = number1;
    number1 = number2;
    number2 = temp;
}

// 12 21 23 34 45
int selectNumber(int *number, int count)
{
    if (number == NULL)
    {
        cout << "invalid input!" << endl;
        return -1;
    }

    int j = count-1;
    for (int i = 0; i < j; i++)
    {
        if (isEvenNumber(number[i]))
        {
            for (; j > i && isEvenNumber(number[j]); j--);
            exchNumber(number[i], number[j]);
            j--;
        }
    }

    return 1;
}

void showNumber(int* number, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << number[i] << " ";
    }

    cout << endl;
}

typedef bool (*Func)(int n);

bool isEvenNumber(int n)
{
    return (n & 0x1) == 0;
}

void ReorderOddEven(int *pData, unsigned int length, Func func )
{
    if (pData == nullptr || length == 0)
    {
        cout << "invalid input" << endl;
        return;
    }
    
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // 往前找到偶数
        while (pBegin < pEnd && !func(*pBegin))
            pBegin++;

        // 往后找到奇数
        while (pBegin < pEnd && func(*pEnd))
            pEnd--;

        int temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}

int main(int argv, char *argc[])
{
    int number[] = {12,23,34,12,31,61,78};
    int count = sizeof(number)/sizeof(int);

    cout << "before select:" << endl;
    showNumber(number, count);

    //selectNumber(number, count);
    ReorderOddEven(number, count, isEvenNumber);

    cout << "after select:" << endl;
    showNumber(number, count);

    return 0;
}
