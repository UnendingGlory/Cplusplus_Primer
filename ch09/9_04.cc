#include <iostream>
#include <vector>

using std::vector;

/* 
 * 使用const_iterator
 */

bool find_x(vector<int>::const_iterator start, vector<int>::const_iterator end, int x)
{
    while(start != end)
    {
        if(*start == x) return true;
        ++start;
    }
    return false;
}

/*
 * 没有找到则返回末尾指针，正确处理未找到给定值的情况
 */
auto find_y(vector<int>::const_iterator start, vector<int>::const_iterator end, int y)
{
    while(start != end)
    {
        if(*start == y) return start;
        ++start;
    }
    return end;
}