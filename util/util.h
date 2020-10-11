#ifndef __UTIL_H__
#define __UTIL_H__

#include <string>

using namespace std;

string TransferNumToStr(const int* nums, int nLength);
int Partition(int data[], int length, int start, int end);
void QuickSort(int data[], int length, int start, int end);
#endif