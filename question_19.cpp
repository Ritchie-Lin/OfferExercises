/*
 * 19.
 * 请实现一个函数用于匹配包含'.'和'*'的正则表达式，
 * 模式中的字符'.'表示任意一个字符，而字符'*'表示
 * 他前面的字符可以出现人一次(含0次)。在本题中，匹
 * 配是指字符串的所有字符匹配整个模式。例如，字符串
 * "aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和
 * "ab*a"均不匹配。
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

bool matchCore(char *str, char* pattern);

bool match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(char *str, char* pattern)
{
    if (str[0] == '\0' && pattern[0] == '\0')
        return true;
    
    if (str[0] != '\0' && pattern[0] == '\0')
        return false;

    if (pattern[1] == '*')
    {
        // 第一个字符匹配的情况
        if (pattern[0] == str[0] || (pattern[0] == '.' && str[0] != '\0'))
        {
            return matchCore(str + 1, pattern + 2)//转换到下一个状态
                || matchCore(str + 1, pattern) //保持当前状态
                || matchCore(str, pattern + 2); //忽略'*'
        }
        else
        {
            return matchCore(str, pattern + 2);
        }
    }

    if (str[0] == pattern[0] || (pattern[0] == '.' && str[0] != '\0'))
        return matchCore(str + 1, pattern + 1);

    return false;
}

int main()
{
    char str[] = "aaa";
    char pattern[] = "ba*ac*a";

    cout << "str: " + string(str) << endl;
    cout << "pattern: " + string(pattern) << endl;
    cout << "match: " << match(str, pattern) << endl;

    return 0;
}
