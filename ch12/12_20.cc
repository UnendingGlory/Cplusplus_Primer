#include "12_19.h"
#include <iostream>
#include <fstream>

// output is "It's a beautiful morning." 
int main()
{
    std::ifstream ifs("data.txt");
    StrBlob test;
    string str;
    while(ifs >> str) test.push_back(str);
    // 想使用=号需要重载，这里使用默认拷贝构造函数
    for(StrBlobPtr start(test.begin()), end(test.end()); start != end;
        start.incr())
    {
        std::cout << start.deref() << " ";
    }
    std::cout << '\n';
    return 0;
}