#include "14_26.h"
#include <iostream>

int main()
{
    StrVec svec;
    svec.push_back("aaa");
    svec = {"Hello", "world", "asdaf"};
    std::cout << svec[1] << '\n';
    const StrVec cvec = svec;
    if(svec.size() && svec[0].empty())
    {
        svec[0] = "zero";
        // 常量版本返回一个const，我们不能对常量版本的返回值赋值
        // cvec[0] = "zip";
    }
    return 0;
}