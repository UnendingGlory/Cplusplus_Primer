#include <iostream>
using std::cout; using std::endl;

class Copyable{
public:
    Copyable(){}
    Copyable(const Copyable &o)
    {
        cout << "Copied" << endl;
    }
};

Copyable ReturnRvalue()
{
    return Copyable(); // 返回一个临时对象，返回的过程中应该会调用一次拷贝构造
}

void AcceptVal(Copyable a) 
{ // 传参的时候会生成临时对象，调用一次拷贝构造

}

void AcceptRef(const Copyable& a) 
{ // 常量左值引用可以绑定右值，不会调用拷贝构造

}

int main() 
{
    cout << "pass by value: " << endl;
    AcceptVal(ReturnRvalue()); // 应该调用两次拷贝构造函数
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnRvalue()); // 左值引用减少一次拷贝，应该只调用一次拷贝构造函数
}

// 结果是一次拷贝构造都没有调用，因为编译器开启了RVO，即return value optimization
// 可以在编译的时候加上-fno-elide-constructors选项(关闭返回值优化)
// g++ 13_rvalue_test.cpp -o 13_rvalue_test -fno-elide-constructors
// 关闭后发现结果如预期一样