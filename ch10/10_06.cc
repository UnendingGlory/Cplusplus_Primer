#include <iostream>
#include <iterator>
#include <vector>

using std::vector;
using std::back_inserter;

int main()
{
    // vector is empty now
    vector<int> vec;
    // reserve 5 elements
    vec.reserve(5);

    // @warning
    // dangerous operation, because vec's capacity is only 5
    // std::fill_n(vec.begin(), 10, 0);
    // for(const auto &i : vec) std::cout << i << " ";

    // The right operation is to use back_inster.
    std::fill_n(back_inserter(vec), 10, 0);
    for(const auto &i : vec) std::cout << i << " ";
    std::cout << '\n';
    return 0;
}