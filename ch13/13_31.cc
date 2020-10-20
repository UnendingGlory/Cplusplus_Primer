#include "13_31.h"
#include <vector>
#include <algorithm>

int main()
{
    // no call swap, direct copy constructor
    HasPtr s{"s"}, a{"a"}, c{"c"};
    // no call swap, direct copy constructor
    std::vector<HasPtr> vec{s, a, c};

    // call swap of HasPtr 4 times
    std::sort(vec.begin(), vec.end());

    // for(const auto &elem : vec) elem.show();

    return 0;
}