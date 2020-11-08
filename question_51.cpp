/*
51.
在数组中的两个数字，如果前一个数字大于后面的数字，则两个数字
组成一个逆序对。输入一个数组，求出这数组中的逆序对的总数。例如，
在数组{7，5，6，4}中，一共存在5个逆序对，分别是(7,6),(7,5),
(7,4)，(6,4)，(5,4)
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int InversePairsCore(int* data, int* copy, int start, int end)
{
    if (start == end)
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end-start)/2;

    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);

    // i 初始化为前半段最后一个数字的下标
    int i = start + length;
    
    // j 初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end;
    int count = 0;
    while (i >= start && j >= start + length + 1)
    {
        if (data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else
        {
            copy[indexCopy--] = data[i--];
        }
    }

    for (;i >= start; i--)
        copy[indexCopy--] = data[i];
    
    for (;j >= start + length + 1; i--)
        copy[indexCopy--] = data[j];
    
    return left + right + count;
}

int InversePairs(int* data, int length)
{
    if (data == nullptr || length <= 0)
        return 0;

    int* copy = new int[length];
    for (int i = 0; i < length; i++)
        copy[i] = data[i];

    int count = InversePairsCore(data, copy, 0, length - 1);
    delete[] copy;

    return count;
}

int main(int argc, char* argv[])
{
    cout << "hallo world" << endl;
    return 0;
}
