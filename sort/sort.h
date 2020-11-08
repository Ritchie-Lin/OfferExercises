#ifndef __SORT_H__
#define __SORT_H__

void PrimaryQuickSort(int data[], int len, int low, int high);
void QuickSort(int data[], int length, int start, int end);
void MinHeapAddNumber(int data[], int numIndex, int num);
void MinHeapDeleteNumber(int data[], int length);
void MinHeapSort(int data[], int length);
void MergeSort(int data[], int first, int last, int temp[]);

#endif