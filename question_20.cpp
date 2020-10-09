/*
 * 请实现一个函数用于判断字符串是否表示数值(包括整数和小数)，
 * 例如，字符串"+100", "5e2", "-123", "3.1416"及"-1E-16"
 * 都表示数值，但是"12e", "1a3.14", "1.2.3", "+-5"及"12e+5.4"
 * 都不是数值。
 *
 * 解题关键：
 * 表示数值的字符串遵循A[.[B]][e|EC]或者.B[e|EC]
 * 其中,
 * A为数值整数部分，是以'+'或'-'开头的0~9的数位串
 * B为数值小数部分，是0~9的数位串，但是不能有'+'或'-'
 * C为数值指数部分，是以'+'或'-'开头的0~9的数位串
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

/*
 * 寻找连续的数位串(只含0~9)
 */
bool scanIntagerString(char **str)
{
    if (*str == NULL || (*str)[0] == '\0')
        return false;

    char *org = *str;
    while((*str)[0] != '\0' && ((*str)[0] >= '0' && (*str)[0] <= '9'))
        (*str)++;

    return (*str - org);
}

/*
 * 判断字符串是不是带符号数位串
 */
bool scanSignIntagerString(char **str)
{
    if ((*str)[0] == '+' || (*str)[0] == '-')
        (*str)++;
    
    return scanIntagerString(str);
}

/*
 * 判断字符串是否表示数值
 */
bool checkIfNumberString(char *str)
{
    if (str == NULL || str[0] == '\0')
        return false;

    // 判断整数部分
    bool isNumStr = scanSignIntagerString(&str);
    if (*str == '.')
    {
        str++;
        // 判断小数部分
        isNumStr = scanIntagerString(&str) || isNumStr;
    }

    if (*str == 'e' || *str == 'E')
    {
        str++;
        // 判断指数部分
        isNumStr = isNumStr && scanSignIntagerString(&str);
    }

    cout << "isNumStr: " << isNumStr << ",*str: " << *str << endl;
    return isNumStr && (*str == '\0');
}


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "invalid input!" << endl;
        cout << "please input like: question_20 [string]" << endl;
        return -1;
    }

    int len = strlen(argv[1]);
    char *str = new char[len+1];

    memset(str, 0, len + 1);
    strncpy(str, argv[1], len);

    cout << "Is \"" << str  << "\" a number string? " << checkIfNumberString(str) << endl;

    delete[] str;
    return 0;
}
