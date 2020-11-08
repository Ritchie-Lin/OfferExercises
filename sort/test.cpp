#include <iostream>
#include "sort.h"
#include "../util/util.h"

using namespace std;

int main()
{
    int data[] = {3, 4, 7, 9, 5, 1, 8};
    int len = sizeof(data)/sizeof(int);
    int *temp = new int[len];

    cout << "before sort:" << endl;
    cout << TransferNumToStr(data, len) << endl;

    MergeSort(data, 0, len - 1, temp);
    cout << "after sort" << endl;
    cout << TransferNumToStr(data, len) << endl;

/*
    MinHeapAddNumber(data, 5, 1);
    cout << "after add num:" << endl;
    cout << TransferNumToStr(data, 6) << endl;
*/

/*
    QuickSort(data, len, 0, len - 1);
    cout << "after sort:" << endl;
    cout << TransferNumToStr(data, len) << endl;

    int data2[] = {5, 3, 4, 8, 2, 7, 1, 9};
    int len2 = sizeof(data2)/sizeof(int);
    PrimaryQuickSort(data2, len2, 0, len2 - 1);
    cout << "after sort:" << endl;
    cout << TransferNumToStr(data2, len2) << endl;
*/
    delete[] temp;
    return 0;
}