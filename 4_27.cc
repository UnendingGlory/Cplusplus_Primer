#include <iostream>
using std::cout;

int main()
{
    unsigned long u11 = 3, u12 = 7;
    // 011 & 111 = 011 = 3D
    cout << (u11 & u12) << '\n';

    // 011 | 111 = 111 = 7D
    cout << (u11 | u12) << '\n';

    // 1
    cout << (u11 && u12) << '\n';

    // 1
    cout << (u11 || u12) << '\n';
    return 0;
}