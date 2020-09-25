#include <iostream>
#include <string>

int main()
{
    std::string str1, str2, str3;
    std::cin >> str1 >> str2 >> str3;

    decltype(str1) temp = str1;

    str1 += str2 + str3;
    std::cout << str1 << '\n';

    temp += ' ' + str2 + ' ' + str3;
    std::cout << temp << '\n';
    return 0;
}