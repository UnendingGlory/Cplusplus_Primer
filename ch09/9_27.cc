#include <iostream>
#include <forward_list>

using std::forward_list; using std::cout;

int main()
{
    forward_list<int> fls{1, 2, 3, 4, 5, 6};
    auto prev = fls.before_begin();
    auto iter = fls.begin();
    while(iter != fls.end())
    {
        if(*iter % 2)
        {
            // 删除并移动iter，别忘了返回
            iter = fls.erase_after(prev);
        }
        else
        {
            prev = iter;
            ++iter;
        }
    }
    for(const auto &i : fls)
        cout << i << " ";
    cout << "\n";
    return 0;
}