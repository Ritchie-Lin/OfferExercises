#include <iostream>
#include "util.h"

using namespace std;

int main()
{
    int data[] = {1,2,3,4,5};
    int len = sizeof(data)/sizeof(int);

    cout << TransferNumToStr(data, len) << endl;

    return 0;
}