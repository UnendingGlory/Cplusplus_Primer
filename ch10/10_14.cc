#include <iostream>

auto f1 = [](int a, int b)->int{ return a + b; };

// use capture list
auto add(int a)
{
    auto f2 = [a](int b)->int{ return a + b; };
    return f2(a);
}

int main()
{
    std::cout << f1(1, 2) << '\n';
    std::cout << add(2) << '\n';
    return 0;
}