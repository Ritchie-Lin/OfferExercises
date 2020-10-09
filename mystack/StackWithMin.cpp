#include "StackWithMin.h"
#include <assert.h>

int StackWithMin::top()
{
    return m_data.top();
}

void StackWithMin::push(int value)
{
    // 把新元素添加到辅助栈
    m_data.push(value);

    // 当新元素比之前的最小元素小时，把新元素插入辅助栈中
    // 否则把之前最小元素重复插入栈中
    if (m_min.size() == 0|| value < m_min.top())
        m_min.push(value);
    else
        m_min.push(m_min.top());
}

void StackWithMin::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();
    m_min.pop();
}

int StackWithMin::min()
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

bool StackWithMin::empty()
{
    return m_data.empty();
}

size_t StackWithMin::size()
{
    return m_data.size();
}
