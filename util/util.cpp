#include <iostream>
#include <time.h>
#include <exception>
#include "util.h"

using namespace std;

/**
 * 将整型数组转化为string类型的字串
 * @param nums 整型数组
 * @param length 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
string TransferNumToStr(const int* nums, int nLength)
{
    if (nums == nullptr || nLength <= 0)
        return string("");

    string numStr = string("{");

    for (int i = 0; i < nLength; i++)
    {
        numStr.append(to_string(nums[i]));
        numStr.append(", ");
    }
    
    numStr.erase(numStr.length()-2, 2);// delete the last ", "
    numStr.append("}");

    return numStr;
}

static int RandomInrange(int start, int end)
{
    if (end > start)
    {
        srand(time(NULL));
        return start + (rand() % (end-start));
    }
    return  start;
}

static void Swap(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

/**
 * 将数组中大的数组移到左边，小的数字移到右边
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @param start 起始下标
 * @param end 终止下标
 * @version 1.0
 * @author Ritchie.Lin
 */
int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        throw "invalid parameters";
    }

    int index = RandomInrange(start, end);
    Swap(data[index], data[end]);

    int small = start - 1;
    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            small++;
            if (small != index)
                Swap(data[index], data[small]);
        }
    }

    small++;
    Swap(data[small], data[end]);

    return small;
}

/**
 * 快速排序法
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @param start 起始下标
 * @param end 终止下标
 * @version 1.0
 * @author Ritchie.Lin
 */
void QuickSort(int data[], int length, int start, int end)
{
    if (start == end)
        return;
    
    int index =  Partition(data, length, start, end);
    if (index > start)
        QuickSort(data, length, start, index-1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}