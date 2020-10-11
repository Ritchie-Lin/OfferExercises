/*
38.
输入一个字符串，打印该字符串中字符的所有排列顺序。例如，
输入字符串abc，则打印出由字符a,b,c所能排列出来的所有字符
串abc,acb,bac,bca,cab和cba.
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

void Permutation(char* pStr, char* pBegin)
{
    if (*pBegin == '\0')
    {
        cout << pStr << endl;
    }
    else
    {
        for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr, pBegin+1);

            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void Permutation(char* pStr)
{
    if (pStr == nullptr)
        return;
    
    Permutation(pStr, pStr);
}

int main()
{
    char str[] = "abc";

    Permutation(str);

    return 0;
}
