#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
    int data[] = {5, 3, 4, 8, 2};
    int len = sizeof(data)/sizeof(int);

    Partition_2(data, len, 0, len - 1);

    return 0;
}