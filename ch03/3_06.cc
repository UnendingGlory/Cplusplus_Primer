#include <iostream>
#include <string>

int main()
{
    std::string str = "This is a string.";
    // 因为要修改，所以要加引用
    for(auto &i : str) i = 'X';
    std::cout << str << '\n';
    return 0;
}