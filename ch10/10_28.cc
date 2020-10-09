#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using std::vector; using std::list;
using std::cout;

// use inserter iterator to copy the vector

int main()
{
    vector<int> vec{1, 2, 3, 4};
    vector<int> lst1, lst2, lst3;

    // @error
    // because vector can not push front
    // std::copy(vec.cbegin(), vec.cend(), std::front_inserter(lst1));
    // so replace with double direction list
    list<int> lst;

    std::copy(vec.cbegin(), vec.cend(), std::front_inserter(lst));

    std::copy(vec.cbegin(), vec.cend(), std::inserter(lst2, lst2.begin()));

    std::copy(vec.cbegin(), vec.cend(), std::back_inserter(lst3));

    for(auto const &i : lst) cout << i << ' ';
    cout << '\n';

    for(auto const &i : lst2) cout << i << ' ';
    cout << '\n';

    for(auto const &i : lst3) cout << i << ' ';
    cout << '\n';
    return 0;
}