/*
41.
如何得到一个数据流中的中位数？如果从数据流中读取奇数个数值，
那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中
读出偶数个数值，那么中位数就是所有数值排序之后的中间两个数的
平均值。
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

/*
push_heap():将容器内的数据组织为最小堆或最大堆。
pop_heap():将容器最前面的数据与最后的数据交换，并将新的最值置于容器最前面。
*/

template<typename T> class DynamicArray
{
private:
    // 最小堆中的数值都比最大堆中的数字大
    vector<T> min;//最小堆(首元素最小)
    vector<T> max;//最大堆(首元素最大)
public:
    void Insert(T num)
    {
        if (((min.size() + max.size()) & 0x1) == 0) //偶数
        {
            if (max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<T>());

                num = max[0];

                pop_heap(max.begin(), max.end(), less<T>());
                max.pop_back();
            }
            min.push_back(num);// 将最大堆中最大的数放到最小堆中
            push_heap(min.begin(), min.end(), greater<T>());// ‘>‘，将min中的数据组织为最小堆
        }
        else // 奇数
        {
            if (min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<T>());

                num = min[0];

                pop_heap(min.begin(), min.end(), greater<T>());
                min.pop_back();
            }
            max.push_back(num);// 将最小堆中最小的数放到最大堆中
            push_heap(max.begin(), max.end(), less<T>());// '<'，将max中的数据组织为最大堆
        }
    }

    T GetMedian()
    {
        int size = min.size() + max.size();
        if (size == 0)
        {
            logic_error ex("No numbers are available");
            throw exception(ex);
        }
        
        T median = 0;
        if ((size & 0x1) == 1)// 奇数
        {
            median = min[0];
        }
        else
        {
            median = (min[0] + max[0]) >> 1;
        }
        return median;
    }
};

int main()
{
    DynamicArray<int> array;
    
    for (int i = 0; i < 5; i++)
    {
        array.Insert(i);
    }

    cout << "the median is " << array.GetMedian() << endl;

    return 0;
}
