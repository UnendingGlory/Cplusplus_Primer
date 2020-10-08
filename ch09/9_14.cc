#include <iostream>
#include <vector>
#include <list>
#include <string>

int main()
{
    std::list<const char *> l{"My", "name", "is", "Wilson"};
    std::vector<std::string> vec(l.cbegin(), l.cend());
    for(auto i : vec) std::cout << i << " ";
    std::cout << '\n';
    return 0;
}