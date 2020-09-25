#include <iostream>
#include <string>

int main()
{
    std::string str1, str2;
    std::cin >> str1 >> str2;
    if(str1 == str2) std::cout << str1 << '\n';
    else if(str1 > str2) std::cout << str1 << '\n';
    else std::cout << str2 << '\n';

    std::string::size_type len1 = str1.size(), len2 = str2.size();
    if(len1 > len2) std::cout << str1 << '\n';
    else if(len1 < len2) std::cout << str2 << '\n';
    return 0;
}