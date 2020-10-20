#ifndef CH_13_30_H
#define CH_13_30_H

#include <iostream>
#include <string>

using std::string;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use){ ++*use; }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
    void show() const { std::cout << *ps << '\n'; }

public:
    friend void swap(HasPtr &, HasPtr &);

private:
    string *ps;
    int i;
    size_t *use; // 记录多少个对象共享*ps的动态空间指针
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "call swap\n";
}

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