#include <iostream>
#include "sort.h"
#include "../util/util.h"
#include <unistd.h>
#include <time.h>

/**
 * (初级)-将数组中大的数组移到左边，小的数字移到右边
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @param start 起始下标
 * @param end 终止下标
 * @version 1.0
 * @author Ritchie.Lin
 */
static int PrimaryPartition(int data[], int len, int low, int high)
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
        while (i < j && x < data[j])
            j--;

        if (i < j)
        {
            data[i] = data[j];
            i++;
        }
        else
            break;

        // 从右往左查找大于x的数字
        while (i < j && x > data[i])
            i++;

        if (j > i)
        {
            data[j] = data[i];
            j--;
        }
        else
            break;
    }
    data[i] = x;
    return i;
}

/**
 * (初级)-快速排序法
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @param start 起始下标
 * @param end 终止下标
 * @version 1.0
 * @author Ritchie.Lin
 */
void PrimaryQuickSort(int data[], int len, int low, int high)
{
    if (low < high)
    {
        int i = PrimaryPartition(data, len, low, high);
        cout << "After partition, i = " << i << ", "<< TransferNumToStr(data, len) << endl;
        PrimaryQuickSort(data, len, low, i - 1);
        PrimaryQuickSort(data, len, i + 1, high);
    }
}

/**
 * 产生一个start到end间的随机数（不包括end）
 * @param start 起始值
 * @param end 终止值
 * @version 1.0
 * @author Ritchie.Lin
 */
static int RandomInrange(int start, int end)
{
    if (end > start)
    {
        srand(time(NULL));
        return start + (rand() % (end-start));
    }
    return  start;
}

/**
 * 交换两个变量的值
 * @param num1 变量1
 * @param num2 变量2
 * @version 1.0
 * @author Ritchie.Lin
 */
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
    cout << "randome index: " << index << ", ";
    // 将随机下标的值放在数组最后
    Swap(data[index], data[end]);

    // small 表示数值比随机下标的值小的下标
    int small = start - 1;
    for (index = start; index < end; index++)
    {
        if (data[index] < data[end])
        {
            small++;

            // 两个下标相同的话，就不需要交换数值了
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
    cout << "After partition, index = " << index << ", "<< TransferNumToStr(data, length) << endl;
    if (index > start)
        QuickSort(data, length, start, index-1);
    if (index < end)
        QuickSort(data, length, index + 1, end);
}