/*
43.
数字以0123456789 10 11 12 13 14 15...的格式序列化到一个字符序列中。
在这序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写
一个函数，求任意第n位对应的数字。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

/**
 * 计算n位数有多少个数字
 * @param n 位数
 * @version 1.0
 * @author Ritchie.Lin
 */
int countOfIntegers(int n)
{
    if (n == 1)
        return 10;
    
    int count = (int)pow(10, n - 1);
    return 9 * count;
}

/**
 * n位数中最小的数
 * @param n 位数
 * @version 1.0
 * @author Ritchie.Lin
 */
int beginNumber(int n)
{
    if (n == 1)
        return 0;
    
    return pow(10, n - 1);
}

/**
 * 找出某个位置上的数字
 * @param index 索引
 * @param n 位数
 * @version 1.0
 * @author Ritchie.Lin
 */
int digitAtIndex(int index, int n)
{
    // 先确定index位所在的数字
    int number = beginNumber(n) + index/n;
    
    // 再确定在这数字内的offset
    int indexFromRight = n - index % n;
    for (int i = 1; i < indexFromRight; i++)
        number/= 10;

    return number%10;
}


int digitAtIndex(int index)
{
    if (index < 0)
        return -1;
    
    int digits = 1;
    while(true)
    {
        int numbers = countOfIntegers(digits);

        // numbers * digits 表示数字的总位数
        if (index < numbers * digits)
            return digitAtIndex(index, digits);
        
        index -= digits*numbers;
        digits++;
    }
    return -1;
}

int main()
{
    int N = 19;

    cout << "The number in " << N << " is " << digitAtIndex(N) << endl;

    return 0;
}
