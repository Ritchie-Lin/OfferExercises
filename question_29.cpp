/**
 *  29.顺时针打印矩阵
 *  输入一个矩阵，按照从外到里以顺时针的顺序依此打印出每一个数字。 
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

// 打印一个数字
void printNumber(int number)
{
    cout << number << " ";
}

// 打印一圈
void PrintMatrixInCircle(int **numbers, int columns, int rows, int start)
{
    int endX = columns - start - 1;
    int endY = rows - start - 1;

    // 从左到右打印一行
    for (int i = start; i <= endX; i++)
    {
        int number = numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一列
    if (start < endY)
    {
        for (int i = start + 1; i <= endY; i ++)
        {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }

    // 从右到左打印一行
    if (start < endX && start < endY)
    {
        for (int i = endX - 1; i >= start; i--)
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从上到下打印一行
    if (start < endX && start < endY - 1)
    {
        for (int i = endY - 1; i >= start + 1; i--)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void PrintMatrixClockwisely(int **numbers, int columns, int rows)
{
    if (numbers == nullptr || columns < 1 || rows < 1)
    {
        cout << "invalid input !" << endl;
        return;
    }

    int start = 0;

    while(columns > (start<<1) && rows > (start<<1))
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        start++;
    }
    cout << endl;
}

int main()
{
    int numbers[][4] = 
    {{ 1, 2, 3, 4},
     { 5, 6, 7, 8},
     { 9,10,11,12},
     {13,14,15,16},
     {17,18,19,20}
    };
    int columns = sizeof(numbers[0])/sizeof(int);
    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int** theNumbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        theNumbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            theNumbers[i][j] = i * columns + j + 1;
        }
    }

    printNumber(theNumbers[0][0]);
    cout << "columns: " << columns << ", rows: " << rows << endl;
    PrintMatrixClockwisely(theNumbers, columns, rows);
    return 0;
}
