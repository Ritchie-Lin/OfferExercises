#include <iostream>
#include "sort.h"
#include "../util/util.h"
#include <unistd.h>
#include <time.h>

/**
 * 分治算法(初级)-将数组中大的数组移到左边，小的数字移到右边
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
 * 分治算法(高级)-将数组中大的数组移到左边，小的数字移到右边
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


static void MinHeapFixup(int data[], int childIndex)
{
    if (data == nullptr)
        return;
    
    int temp = data[childIndex];
    int parIndex = (childIndex - 1) >> 1;// i的父节点索引
    while (parIndex >= 0 && childIndex != 0)
    {
        if (data[parIndex] <= temp)
            break;
        
        data[childIndex] = data[parIndex];
        childIndex = parIndex;
        parIndex = (childIndex - 1) >> 1;
    }
    cout << "par: " << parIndex << ", child: " << childIndex << endl;
    data[childIndex] = temp;
}

void MinHeapAddNumber(int data[], int numIndex, int num)
{
    data[numIndex] = num;
    MinHeapFixup(data, numIndex);
}

/**
 * 取两个子节点中较小的那个作为父节点
 * @param data 整型数组
 * @param parIndex 需填入数据的父节点索引
 * @param length 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
void MinHeapFixdown(int data[], int parIndex, int length)
{
    if (data == nullptr || parIndex >= (length -1))
        return;

    int minChildIdx = (parIndex << 1) + 1;
    int temp = data[parIndex];

    while (minChildIdx < length)
    {
        // 比较左右节点的大小，取较小的那个。
        if (minChildIdx + 1 < length && data[minChildIdx + 1] < data[minChildIdx])
            minChildIdx++;
        
        if (data[minChildIdx] >= temp)
            break;
        
        data[parIndex] = data[minChildIdx];
        parIndex = minChildIdx;
        minChildIdx = (parIndex << 1) + 1;
    }
    //cout << "parent index: " <<parIndex << endl;
    data[parIndex] = temp;
}

/**
 * 将数组组织成堆
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
void MakeMinHeap(int data[], int length)
{
    // 叶节点可以认为是一个合法的堆，所以对于叶节点不需要建堆
    // 所以从最后一个叶节点的父节点开始建堆，该父节点索引是(length>>1)-1
    for (int i = ((length-1) >> 1) - 1; i >= 0; i--)
    {
        MinHeapFixdown(data, i, length);
    }
}
/**
 * 堆排序，先将数组组织成堆，然后进行排序
 * @param data 整型数组
 * @param length 整形数组元素个数
 * @version 1.0
 * @author Ritchie.Lin
 */
void MinHeapSort(int data[], int length)
{
    MakeMinHeap(data, length);
    cout << "min heap: " << endl << TransferNumToStr(data, length) << endl;

    for (int i = length - 1; i >= 1; i--)
    {
        Swap(data[i], data[0]);
        MinHeapFixdown(data, 0, i);
    }
}

void MinHeapDeleteNumber(int data[], int length)
{
    Swap(data[0], data[length - 1]);
    MinHeapFixdown(data, 0, length - 1);
}

/**
 * 合并算法，将两个有序数列a[first...mid]和a[mid+1...last]合并
 * @param data 整型数组
 * @param frist 第一个元素索引
 * @param mid 中间元素索引
 * @param last 最后一个元素索引
 * @param length 整形数组元素个数
 * @param temp 整型数组，用于辅助计算
 * @version 1.0
 * @author Ritchie.Lin
 */
void MergeArry(int data[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    // 两数间，取其小者，直到某个数列被取空。
    while (i <= m && j <= n)
    {
        if (data[i] <= data[j])
        {
            temp[k++] = data[i++];
        }
        else
        {
            temp[k++] = data[j++];
        }        
    }

    while (i <= m)
    {
        temp[k++] = data[i++];
    }
    
    while (j <= n)
    {
        temp[k++] = data[j++];
    }

    for (i = 0; i < k; i++)
        data[first + i] = temp[i];
}

/**
 * 归并排序
 * @param data 整型数组
 * @param frist 第一个元素索引
 * @param last 最后一个元素索引
 * @param temp 整型数组，用于辅助计算
 * @version 1.0
 * @author Ritchie.Lin
 */
void MergeSort(int data[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = first + (last - first)/2;
        MergeSort(data, first, mid, temp);// 左边有序
        MergeSort(data, mid + 1, last, temp);// 右边有序
        MergeArry(data, first, mid, last, temp);// 再将二个有序数列合并
    }
}
