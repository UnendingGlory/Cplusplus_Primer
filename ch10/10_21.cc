#include <iostream>

int main()
{
    int i = 21;
    auto f = [&i]() -> bool{
        int j = i;
        while(i-- > 0);
        return j == 0;
    };
    std::cout << f() << '\n'; 
    return 0;
}