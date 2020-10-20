#ifndef CH_13_27_H
#define CH_13_27_H
#include <iostream>
#include <string>

using std::string;

/** 
 * 在行为类似指针的类中定义自己的计数器的时候，需要注意以下几点
 * 1. 除了初始化对象外，每个构造函数需要创建一个引用计数
 * 2. 拷贝构造函数不分配新的计数器，而是直接拷贝计数器且拷贝构造函数要递增计数器
 * 3. 析构函数时要递减，如果计数为0，则释放之
 * 4. 拷贝赋值运算符递增左侧对象的计数器，递减右侧对象的计数器 a = b
 * 5. 需要注意的是计数器不能作为直接成员，因为这样会带来问题
 * HasPtr p1("Hello");
 * HasPtr p2(p1);
 * HasPtr p3(p1);
 * 如果将每个计数器作为直接成员，那么在定义p3的时候如何使用呢？
 * 如果递增p1的计数器，那如何递增p2的计数器？
 * 其中的一个解决办法是将计数器保存在动态内存中，创建一个对象时将计数器指向对应内存空间即可
 */

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use){ ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use; // 记录多少个对象共享*ps的动态空间指针
};

// 如果这是最后一个析构的对象，则删除对应的两段内存
HasPtr::~HasPtr()
{
    if(--(*use) == 0)
    {
        delete ps;
        delete(use);
    }
}

// 递增右侧的引用计数，递减左侧的引用计数，并且左侧拷贝右侧对象
HasPtr& HasPtr::operator=(const HasPtr& p)
{
    ++(*p.use);
    // 如果变为了0要做和析构函数相同的操作
    if(--(*use) == 0)
    {
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return *this;
}

#endif