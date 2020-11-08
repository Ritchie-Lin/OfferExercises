#include <iostream>
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
int UtilPartition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        throw "invalid parameters";
    }

    int index = RandomInrange(start, end);
    // cout << "randome index: " << index << ", ";
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