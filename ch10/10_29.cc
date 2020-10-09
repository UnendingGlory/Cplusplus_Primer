#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <vector>

int main()
{
    // declare a ifstream object
    std::ifstream in("10_29.txt");
    // bind the object to an istream iterator
    std::istream_iterator<std::string> it(in), eof;

    std::vector<std::string> vec(it, eof);
    for(const auto &i : vec) std::cout << i << ' ';
    std::cout << '\n';
    return 0;
}