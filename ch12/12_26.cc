#include <iostream>
#include <memory>
#include <string>

void input_reverse_output_string(int n)
{
    std::allocator<std::string> alloc;
    // n个string大小的空间
    auto const p = alloc.allocate(n);
    std::string s;
    auto q = p;
    // q每次后移一位，构造下一个string
    while(q != p + n && std::cin >> s)
        alloc.construct(q++, s);
    
    while(q != p)
    {
        std::cout << *(--q) << " ";
        // 要一个个destroy，只是销毁了元素，并没有销毁给p分配的内存
        alloc.destroy(q);
    }
    std::cout << '\n';

    alloc.deallocate(p, n);
}

int main()
{
    input_reverse_output_string(6);
    return 0;
}