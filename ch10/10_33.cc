#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cin; using std::cout;

// ./10_33 "10_33_input.txt" "10_33_odd.txt" "10_33_even.txt"
int main(int argc, char **argv)
{
    if(argc != 4) return -1;

    std::ifstream ifs(argv[1]);
    std::ofstream odd_ofs(argv[2]), even_ofs(argv[3]);

    // don't forget to bind
    std::istream_iterator<int> in(ifs), eof;
    std::ostream_iterator<int> odd(odd_ofs, " "), even(even_ofs, "\n");

    // odd number & 0x01 = 1
    // even number & 0x01 = 0
    std::for_each(in, eof, [&odd, &even](const int i)
    {
        *(i & 0x01 ? odd : even)++ = i;
    });
    
    return 0;
}