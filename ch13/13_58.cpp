#include <vector>
#include <iostream>
#include <algorithm>

using std::vector; using std::sort;

class Foo {
public:
    Foo sorted() &&; // 作用于可改变的右值
    Foo sorted() const &; // 作用于任何类型的Foo
private:
    vector<int> data;
};

// 本对象为右值，因此可以对原址排序
Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl; // debug
    return *this;
}

// 本对象是一个const或是一个左值，哪种情况我们都不能对
// 原址排序，只能排序副本
Foo Foo::sorted() const & {
//    Foo ret(*this); // 拷贝一个副本
//    sort(ret.data.begin(), ret.data.end()); // 排序副本
//    return ret; // 返回副本

    std::cout << "const &" << std::endl; // debug

    // Exercise 13.56: reursion and stackoverflow
    // cause ret is a lvalue
    // Foo ret(*this);
    // ret.sorted();
    // return ret;

    // Exercise 13.57
    // right, it will call the rvalue version
    return Foo(*this).sorted();
}

int main()
{
    Foo().sorted(); // rvalue, call "&&"
    Foo f;
    f.sorted(); // lvalue, call "const &"
}