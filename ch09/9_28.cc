#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list; using std::cout;
using std::string;

void insert_into_fls(forward_list<string> &fls, string const &s1, 
    string const &s2)
{
    auto prev = fls.before_begin();
    for(auto curr = fls.begin(); curr != fls.end(); prev = curr++)
    {
        if(*curr == s1)
        {
            fls.insert_after(prev, s1);
            return;
        }
    }
    fls.insert_after(prev, s2);
} 

int main()
{
    return 0;
}