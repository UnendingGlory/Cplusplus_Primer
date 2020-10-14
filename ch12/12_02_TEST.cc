#include "12_02.h"
#include <iostream>

int main()
{
    const StrBlob test({"Hello", "dear", "Bob"});
    StrBlob t({"Hello", "dear", "Alice"});

    std::cout << test.size() << t.size() << '\n';
    std::cout << test.front() << "" << test.back() << '\n';
    t.back() = "Chalice";
    std::cout << t.front() << "" << t.back() << '\n';
    
    return 0;
}
