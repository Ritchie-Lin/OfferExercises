/*
50.
在字符串中找出第一个只出现一次的字符。例如输入"abaccdeff",则输出‘b’。
*/
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

char FirstNotRepeatingChar(char* pString)
{
    if (pString == nullptr)
        return '\0';
    
    const int tableSize = 256;
    unsigned int hashTable[tableSize] = {0};

    char* pHashKey = pString;
    while (*pHashKey != '\0')
    {
        hashTable[*(pHashKey++)]++;
    }
    
    pHashKey = pString;
    while (*pHashKey != '\0')
    {
        if (hashTable[*pHashKey] == 1)
            return *pHashKey;
        
        pHashKey++;
    }
    return '\0';
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "INVALID INPUT!!" << endl << "Run it like: ./a.out <string>" << endl;
        return 0;
    }

    cout << "The First not repeating char is '" << FirstNotRepeatingChar(argv[1]) << "'." << endl;

    return 0;
}
