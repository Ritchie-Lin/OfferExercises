#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int testCase[] = {1,1,1,0,1};

    int *pPrev = &testCase[0];

    int len = sizeof(testCase)/sizeof(int);
    int *pLast = &testCase[len - 1];

    cout << "prev: " << *pPrev << ", last: " << *pLast << ", len: " << len << endl;

    int prevIndex = 0;
    int lastIndex = len - 1;
    int midIndex = (lastIndex - prevIndex) >> 1;
    while (pLast != (pPrev+1))
    {
        if (testCase[midIndex] >= *pPrev)
        {
            pPrev = &testCase[midIndex];
            prevIndex = midIndex;
            midIndex = prevIndex + ((lastIndex - prevIndex) >> 1);
        }

        if (testCase[midIndex] <= *pLast)
        {
            pLast = &testCase[midIndex];
            lastIndex = midIndex;
            midIndex = prevIndex + ((lastIndex - prevIndex) >> 1);
        }
    }

    cout << "the smallest number is " << *pLast << endl;
    return 0;
}
