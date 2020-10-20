#include <iostream>

class numbered
{
public:
    numbered() {isbn = start++; }
    numbered(const numbered &) { isbn = start++; }
    size_t get_isbn()const { return isbn; }
private:
    size_t isbn;
    static size_t start;
};

size_t numbered::start = 10;

// a const object can not call nonConst, so get_isbn must be const
void f(const numbered& s)
{
    std::cout << s.get_isbn() << '\n';
}

int main()
{
    // numbered has a copy constructor, so call the copy constructor
    // instead of calling the synthesized copy-assignment operator
    // 10, 11, 12
    numbered a, b = a, c = b;

    // const &, so 10, 11, 12
    f(a), f(b), f(c);
    // thus, print three numbers increasing one by one
    return 0;
}