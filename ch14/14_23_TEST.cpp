#include "14_23.h"
#include <iostream>

int main()
{
    StrVec svec;
    svec.push_back("aaa");
    svec = {"Hello", "world"};
    for(auto i = svec.begin(); i != svec.end(); ++i)
        std::cout << *i << '\n';
    return 0;
}