#include <iostream>

using std::string;
using std::cout;

// 6_25 -d -o ofile data0
int main(int argc, char **argv)
{
    string str = "";
    for(unsigned i = 0; i < argc; ++i)
    {
        str += string(argv[i]);
        if(i < argc - 1) str += " ";
    }
    cout << str << '\n';
    return 0;
}