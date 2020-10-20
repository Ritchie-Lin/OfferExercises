/*
40.
输入n个整数，找出其中最小的k个数。例如，输入4，5，1，
6，2，7，3，8这8个数字，则最小的4个数字是1，2，3，4。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <time.h>
#include <unistd.h>
#include "util/util.h"
#include <set>
#include <vector>

using namespace std;

typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();

    if (k < 1 || k > data.size())
        return;
    
    vector<int>::const_iterator iter = data.begin();
    for (; iter != data.end(); iter++)
    {
        if (leastNumbers.size() < k)
        {
            leastNumbers.insert(*iter);
        }
        else
        {
            setIterator iterGreatest = leastNumbers.begin();
            if (*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    }
}

int RandomInRange(int start, int end)
{
    if (end > start)
    {
        srand(time(NULL));
        return start + rand() % (end - start);
    }
    return start;
}

void Swap(int& num1, int& num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int Partitation(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
        return -1;
    
    int index = RandomInRange(start, end);
    cout << "random index: " << index << ", value: " << data[index] << endl;
    Swap(data[index], data[end]);

    int smallIndex = start;
    for (int i = start; i < end; i++)
    {
        if (data[i] < data[end])
        {
            if (i != smallIndex)
                Swap(data[i], data[smallIndex]);
            smallIndex++;
        }
    }

    Swap(data[smallIndex], data[end]);
    return smallIndex;
}

void GetLastNumbers(int input[], int length, int output[], int k)
{
    if (input == nullptr || length <= 0 || output == nullptr || k >= length || k <= 0)
        return;
    
    int startIndex = 0;
    int endIndex = length - 1;
    int targetIndex = k - 1;
    int partIndex = Partitation(input, length, startIndex, endIndex);

    while(partIndex != targetIndex)
    {
        if (partIndex > targetIndex)
        {
            endIndex = partIndex - 1;
            partIndex = Partitation(input, length, startIndex, endIndex);
        }
        else
        {
            startIndex = partIndex + 1;
            partIndex = Partitation(input, length, startIndex, endIndex);
        }
    }

    for (int i = 0; i < k; i++)
        output[i] = input[i];
    
    return;
}

int main()
{
    int input[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int length = sizeof(input)/sizeof(int);
    int k = 4;

#if 0
    int output[k] = {0};

    GetLastNumbers(input, length, output, k);

    cout << "solution No.1, output: " << TransferNumToStr(output, k) << endl;
#endif

    vector<int> vInput(input, input + length);
    intSet leastNumbers;
    GetLeastNumbers(vInput, leastNumbers, k);

    cout << "begin: " << *(leastNumbers.begin()) << ", end: " << *(leastNumbers.end()) << endl;

    cout << "solution No.2, output: ";
    for (setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); iter++)
        cout << *iter << " ";

    cout << endl;


    return 0;
}
