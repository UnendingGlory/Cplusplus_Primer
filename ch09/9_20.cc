#include <string>
#include <iostream>
#include <deque>
#include <list>
using std::cout; using std::deque; using std::list;

int main()
{
    list<int> lst;
    deque<int> dq1, dq2;
    for(int i = 0; i < 10; ++i) lst.emplace_back(i);
    for(const auto &i : lst)
    {
        if(i % 2) dq1.emplace_back(i);
        else dq2.emplace_back(i); 
    }
    for(const auto i : dq1) cout << i << " ";
    cout << "\n";
    for(const auto i : dq2) cout << i << " ";
    cout << "\n";
    return 0;
}