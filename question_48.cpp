#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip> 

using namespace std;

int LongestSubstringWithoutDuplication(const string& str)
{
    int curLength = 0;
    int maxLength = 0;

    // 储存
    int *position = new char[256];
    for (int i = 0; i < 256; i++)
        position[i] = -1;

#ifdef DEBUG
    for (char c = 'a'; c <= 'z'; c++)
        cout << c << setw(3);
    cout << setw(0) << endl;
#endif

    for (int i = 0; i < str.length(); i++)
    {
        int prevIndex = position[str[i]];
        // i - prevIndex > curLength表示当前字符上一次出现的位置在curLength之外
        // 所以该字符与不重复子串中的字符重复，curLength加1.
        if (prevIndex < 0 || i - prevIndex > curLength)
        {
            curLength++;
        }
        else
        {
            if (curLength > maxLength)
                maxLength = curLength;
            
            curLength = i - prevIndex;
        }
        position[str[i]] = i;

#ifdef DEBUG
        for (int j = 0; j < 26; j++)
        {
            if (position[j] == -1)
                cout << "-" << setw(3);
            else
                cout << position[j] << setw(3);
        }

        cout << setw(0) << endl;
#endif
    }

    if (curLength > maxLength)
        maxLength = curLength;
    
    delete[] position;
    return maxLength;
}
int main(int argc, char* argv[])
{
    string str = string("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    int maxLen = LongestSubstringWithoutDuplication(str);
    cout << "The length of longest substring is " << maxLen << endl;

    return 0;
}
