#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    std::cout << std::accumulate(v.cbegin(), v.cend(), 0) << '\n';
    std::vector<double> vec{1.1, 2.2, 3.3, 0, 1.0};
    std::cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << '\n';
    
    // @attention
    //
    // the output is 7 rather than 7.6 as expected
    // The reason is std::accumulate is a template function.
    // The third parameter is _Tp __init.(_Tp represents type)
    // So when "0", an integer, is specified here, the compiler deduced
    // _Tp is integer. So actually the compiler
    // add 1 + 2 + 3 + 1, the result is 7.
    // We can pass "0.0" instead of "0" to make it work correctly.

    std::cout << std::accumulate(vec.cbegin(), vec.cend(), 0.0) << '\n';

    return 0;
}