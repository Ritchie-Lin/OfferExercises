#include <iostream>
#include "util.h"

using namespace std;

int main()
{
    int data[] = {1,5,6,2,8,7,3};
    int len = sizeof(data)/sizeof(int);

    cout << "Orignal array:" << endl;
    cout << TransferNumToStr(data, len) << endl;

    QuickSort(data, len, 0, len - 1);

    cout << "After sort:" << endl;
    cout << TransferNumToStr(data, len) << endl;

    return 0;
}