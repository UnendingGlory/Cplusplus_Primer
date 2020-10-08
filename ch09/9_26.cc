#include <iostream>
#include <vector>
#include <list>
#include <array>

using std::cout; using std::vector;
using std::list; using std::array;

/*
 * 注意erase后迭代器还是指向原来的位置
 * 但是原本容器结构已经发生了变化，指向了删掉元素下一个位置
 */

int main()
{
    array<int, 11> ia{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(ia.begin(), ia.end());
    list<int> lst(ia.begin(), ia.end());
    auto it = vec.begin();
    while(it != vec.end())
    {
        if(*it % 2)
            it = vec.erase(it);
        else ++it;
    }
    auto iter = lst.begin();
    while(iter != lst.end())
    {
        if(*iter % 2 == 0)
            iter = lst.erase(iter);
        else ++iter; 
    }
    for(const auto &i : vec) cout << i << " ";
    cout << '\n';
    for(const auto &i : lst) cout << i << " ";
    cout << '\n';
    return 0;
}