/*
49.丑数
我们把只包含因子2，3和5的数称为丑数（Ugly Number）。求按从小到大
的顺序的第1500个丑数。例如6，8都是丑数，但14不是，因为它包含因子7.
习惯上我们把1当作第一个丑数。

*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int Min(int num1, int num2, int num3)
{
    int min = (num1 < num2)?num1:num2;
    return (min<num3)?min:num3;
}


int GetUglyNumber(int index)
{
    if (index <= 0)
        return 0;
    
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while (nextUglyIndex < index)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        pUglyNumbers[nextUglyIndex] = min;

        while (*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
        {
            pMultiply2++;
        }

        while (*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
        {
            pMultiply3++;
        }

        while (*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
        {
            pMultiply5++;
        }

        nextUglyIndex++;
    }
    
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "INVALID INPUT!!" << endl << "Run it like: ./a.out <number>" << endl;
        return 0;
    }

    int N = atoi(argv[1]);
    cout << "The " << N << "th ugly number is " << GetUglyNumber(N) << "." << endl;
    return 0;
}
