#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    // iterator is for type int, and is bound to the standard cin
    std::istream_iterator<int> in_iter(std::cin), end;
    std::vector<int>vec (in_iter, end);
    std::sort(vec.begin(), vec.end());
    // seperate by a blankspace
    std::ostream_iterator<int> out_iter(std::cout, " ");
    // copy the data to the out_iter
    std::copy(vec.begin(), vec.end(), out_iter);
    return 0;
}