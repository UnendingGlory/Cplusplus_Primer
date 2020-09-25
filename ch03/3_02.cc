#include <iostream>
#include <string>

// getline一次读入一行，cin读入到空格或者换行符停止
int main()
{
    std::string str;
    // 读入 my string
    std::getline(std::cin, str);
    // 输出my string
    std::cout << str << '\n';

    // 读入his string
    std::cin >> str;
    // 输出his
    std::cout << str << '\n';
    return 0;
}