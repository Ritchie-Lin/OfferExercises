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

