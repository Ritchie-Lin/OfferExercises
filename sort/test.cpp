#include <iostream>
#include "sort.h"
#include "../util/util.h"

using namespace std;

int main()
{
    int data[] = {5, 3, 4, 8, 2, 7, 1, 9};
    int len = sizeof(data)/sizeof(int);

    QuickSort(data, len, 0, len - 1);
    cout << "after sort:" << endl;
    cout << TransferNumToStr(data, len) << endl;

    int data2[] = {5, 3, 4, 8, 2, 7, 1, 9};
    int len2 = sizeof(data2)/sizeof(int);
    PrimaryQuickSort(data2, len2, 0, len2 - 1);
    cout << "after sort:" << endl;
    cout << TransferNumToStr(data2, len2) << endl;

    return 0;
}