/*
44.
输入一个正整数数组，把数组里所有的数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如，输入数组{3,32,321},
则打印出这3个数字能排成的最小数字是321323。
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "util/util.h"

using namespace std;

const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength<<1 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength<<1 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
    //cout << "num1 address: " << strNumber1 << ", *num1: " << (void*)(*(int **)strNumber1)<< endl;
    //cout << "num2 address: " << strNumber2 << ", *num2: " << (void*)(*(int **)strNumber2)<< endl;
    // 拼接数字字符串1
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);

    // 拼接数字字符串2
    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);

    // 字符串比较
    return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length)
{
    if (numbers == nullptr || length <=  0)
        return ;
    
    // 指向字符串的指针
    char **strNumbers = new char**[length];
    for (int i = 0; i < length; i++)
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }
    
    cout << "strNumbers: " << (void *)strNumbers << endl;
    qsort(strNumbers, length, sizeof(char*), compare);

    for (int i = 0; i < length; i++)
        cout << strNumbers[i];
    cout << endl;

    for (int i = 0; i < length; i++)
        delete[] strNumbers[i];
    
    delete[] strNumbers;
}

int main()
{
    int numbers[] = {3,32,321};
    int len = sizeof(numbers)/sizeof(int);

    cout << "sizeof(int*): " << sizeof(int*) << ", long: " << sizeof(long) << endl;

    cout << "The min combine of " << TransferNumToStr(numbers, len) << " is " << endl;
    PrintMinNumber(numbers, len);

    return 0;
}
