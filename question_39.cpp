/*
39.
数组中有一个数字出现的次数超过数组长度的一半，请找出这数字。例如，
输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2
在数组中出现了5次，超过数组长度一半，因此输出2。
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "util/util.h"

using namespace std;

bool g_bInputInvalid = false;
bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if (numbers == nullptr || length <= 0)
        g_bInputInvalid = true;
    
    return g_bInputInvalid;
}

bool CheckMoreThanHalfTime(int* numbers, int length, int number)
{
    int i = 0;
    int time = 0;
    while (i < length)
    {
        if (number == numbers[i])
            time++;
        i++;
    }
    
    if (time < (length >> 1))
    {
        g_bInputInvalid = true;
        return false;
    }

    return true;
}

int MoreThanHalfNum(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;

    int result = numbers[0];
    int time = 0;
    for (int i = 0; i < length; i++)
    {
        if (time == 0)
        {
            result = numbers[i];
            time = 1;
        }
        else if (result == numbers[i])
        {
            time++;
        }
        else
        {
            time--;
        }
    }

    //cout << "result: " << result << endl;

    if (!CheckMoreThanHalfTime(numbers, length, result))
        return 0;

    return result;
}

int MoreThanHalfNumPartition(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;
    
    int startIndex = 0;
    int endIndex = length - 1;
    int midIndex = (length - 1) >> 1;
    int index = Partition(numbers, length, startIndex, endIndex);

    while (index != midIndex)
    {
        if (index > midIndex)
        {
            endIndex = index - 1;
            index = Partition(numbers, length, startIndex, endIndex);
        }
        else
        {
            startIndex = index + 1;
            index = Partition(numbers, length, startIndex, endIndex);
        }
    }

    if (!CheckMoreThanHalfTime(numbers, length, numbers[midIndex]))
        return 0;
    
    return numbers[midIndex];
}

int main()
{
    int data[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int length = sizeof(data)/sizeof(int);

    //int ret = MoreThanHalfNum(data, length);
    int ret = MoreThanHalfNumPartition(data, length);
    if (ret == 0 && g_bInputInvalid)
    {
        cout << "The number can't be found in " << TransferNumToStr(data, length) << endl;
    }
    else
    {
        cout << "The number is " << ret << " in " << TransferNumToStr(data, length) << endl;
    }

    return 0;
}
