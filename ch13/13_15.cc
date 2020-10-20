#include <iostream>

class numbered
{
public:
    numbered() {isbn = start++; }
    numbered(const numbered &) { isbn = start++;}
    size_t get_isbn() const { return isbn; }
private:
    size_t isbn;
    static size_t start;
};

size_t numbered::start = 10;

void f(numbered s)
{
    std::cout << s.get_isbn() << '\n';
}

void f2(const numbered& s)
{
    std::cout << s.get_isbn() << '\n';
}

int main()
{
    // numbered has a copy constructor, so call the copy constructor
    // instead of calling the synthesized copy-assignment operator
    // 10, 11, 12
    numbered a, b = a, c = b;
    f2(a), f2(b), f2(c);

    f(a), f(b), f(c);
    // thus, print three numbers increasing one by one
    return 0;
}