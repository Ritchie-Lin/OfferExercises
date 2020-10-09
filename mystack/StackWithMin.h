#ifndef __STACK_WITH_MIN_H__
#define __STACK_WITH_MIN_H__

#include <stack>

class StackWithMin
{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    int top();

    void push(int value);
    void pop();
    
    int min();

    bool empty();
    size_t size();

private:
    std::stack<int> m_data;// 数据栈，存放栈的所有元素
    std::stack<int> m_min;// 辅助栈，存放栈的最小元素
};

#endif