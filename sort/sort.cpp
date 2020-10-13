#include <iostream>
#include "sort.h"
#include "../util/util.h"

static void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

//{5, 3, 4, 8, 2}
int Partition_2(int data[], int len, int low, int high)
{
    if (data == nullptr || len <=0 || low < 0 || high >= len)
    {
        return -1;
    }

    int i = low;
    int j = high;
    int x = data[i];

    while (i < j)
    {
        // 从右往左查找小于x的数字
        while (x < data[j])
            j--;

        data[i] = data[j];
        if (++i >= j)
            break;

        cout << "i:"<< i << ", j:" << j << ", "<< TransferNumToStr(data, len) << endl;

        // 从右往左查找大于x的数字
        while (x > data[i])
            i++;
        
        data[j] = data[i];
        if (--j <= i)
            break;

        cout << "i:"<< i << ", j:" << j << ", "<< TransferNumToStr(data, len) << endl;
    }

    data[i] = x;
    cout << "the reset of partition :" << endl;
    cout << "i:"<< i << ", j:" << j << ", "<< TransferNumToStr(data, len) << endl;
    return i;
}


void QuikeSort_2(int data[], int len, int low, int high)
{

}