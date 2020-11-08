/*
46.
给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成“a”,
1翻译为“b”,..., 11翻译为“i”,..., 25翻译为“z”。一个数字
可能有多这个翻译。例如，12258有5种不同的翻译，分别是“bccfi”
,"bczi","mcfi"和“mzi”。请编程实现一个函数，用来计算一个数字
有多少中不同的翻译方法。
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;
int GetTranslationCount(const string& number);

int GetTranslationCount(int number)
{
    if (number < 0)
        return 0;
    
    string numberInString = to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        count = 0;
        if (i < length - 1)
        {
            count = counts[i+1];
        }
        else
        {
            count = 1;
        }

        if (i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i+1] - '0';
            int converted = digit1 * 10 + digit2;
            if (converted >= 10 && converted <= 25)
            {
                if (i < length - 2)
                {
                    count += counts[i+2];
                }
                else
                {  
                    count +=1;
                }
            }
        }
        counts[i] = count;
    }
    count = counts[0];
    delete[] counts;

    return count;
}


int main()
{
    int num = 122;
    cout << "The translation of " << num << " have " <<  GetTranslationCount(num) << "."<< endl;
    return 0;
}
