#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

bool g_InvalidInput = false;

#define DOUBLE_GAP (0.0000001)
bool myEqual(double num1, double num2)
{
    if (num1 < num2 + DOUBLE_GAP && num1 > num2 - DOUBLE_GAP)
        return true;

    return false;
}

double PowerWithUnsignedExponent(double base, int exponent)
{
    double result = 1.0;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;        
    }

    return result;
}

double Power(double base, int exponent)
{
    g_InvalidInput = false;

    // exponent < 0,求次方需要取倒数，因此base不可为0
    if (myEqual(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent;
    if (exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }
    else
    {
        absExponent = (unsigned int)(exponent);
    }
    
    double result = PowerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
        result = 1/result;

    return result;
}


int main()
{
    cout << "Power(5, 2) = " << Power(5, 2) << endl;
    cout << "Power(5, -3) = " << Power(5, -3) << endl;
    cout << "Power(0, -5) = " << Power(0, -5) << endl;
    
    return 0;
}
