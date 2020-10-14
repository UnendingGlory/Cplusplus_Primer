#include <iostream>
#include <memory>

using std::shared_ptr; using std::make_shared;

void process(shared_ptr<int> ptr)
{
    std::cout << "inside the process function " << ptr.use_count() << '\n';
}

int main()
{
    shared_ptr<int> p(new int(42));
    shared_ptr<int> q = make_shared<int>(43);

    // 参数传递时拷贝了一份
    process(p);

    // 拷贝的那份销毁了
    std::cout << p.use_count() << '\n';

    // r再和p共享
    auto r = p;
    std::cout << p.use_count() << '\n';
    return 0;
}