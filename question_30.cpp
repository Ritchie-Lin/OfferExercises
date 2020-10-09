#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include "mystack/StackWithMin.h"

using namespace std;

void Test(const char* testName, StackWithMin stack, int expected)
{
    if (testName != nullptr)
        cout << testName << " begins: " << endl;
    
    if (stack.min() == expected)
        cout << "Passed." << endl;
    else
        cout << "Fail!" << endl;
}


int main()
{
    StackWithMin stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);
    return 0;
}
