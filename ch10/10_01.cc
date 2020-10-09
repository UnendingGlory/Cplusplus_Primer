#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::cout;

// pass iterator for algorithm

int main()
{
    vector<int> vec{100, 200, 300, 100, 400, 100};
    cout << count(vec.begin(), vec.end(), 100) << '\n';
    list<int> lst{100, 200, 300, 100, 400, 100};
    cout << count(lst.begin(), lst.end(), 100) << '\n';
    return 0;
}

