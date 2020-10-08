#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::string str;
    std::deque<std::string> dq;
    while(std::cin >> str) dq.emplace_back(str);
    for(auto i = dq.cbegin(); i != dq.cend(); ++i)
        std::cout << *i;
    std::cout << '\n';
    return 0;
}