#include <iostream>

class numbered
{
public:
    numbered() {isbn = start++; }
    size_t get_isbn() { return isbn; }
private:
    size_t isbn;
    static size_t start;
};

size_t numbered::start = 10;

void f(numbered s)
{
    std::cout << s.get_isbn() << '\n';
}

int main()
{
    // call the synthesized copy-assignment operator
    numbered a, b = a, c = b;
    // call the default copy constructor
    f(a), f(b), f(c);
    // thus, print three identical numbers
    return 0;
}