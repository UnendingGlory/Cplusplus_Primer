#include <iostream>
#include <stdexcept>
using std::cin; using std::cout;

int main()
{
    int a, b;
    cin >> a >> b;
    // 除数为0时输出Floating point exception
    // cout << a / b << '\n';

    try
    {
        if(b == 0) throw std::runtime_error("Divisor is zero.");
        cout << a / b << '\n';
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}