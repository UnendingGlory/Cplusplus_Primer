#include "14_23.h"

void StrVec::push_back(const string &s)
{
    chk_n_alloc(); // 确保有空间容纳新元素
    // 在first_free指向的元素中构造s的副本
    alloc.construct(first_free++, s);
}

// 返回的first成员指向内存开始的地方，second成员返回最后一个构造元素之后的位置
pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e)
{
    // 分配e - b大小的空间
    auto data = alloc.allocate(e - b);

    // uinitialized_copy：从迭代器b和e指出的输入范围中拷贝元素
    // 到迭代器data指定的未构造的原始内存中
    return {data, std::uninitialized_copy(b, e, data)};
}

// 对于allocator类，首先destroy元素，然后释放空间
void StrVec::free()
{
    // 空指针值默认为0，不能deallocate空指针
    if(elements)
    {
        // 逆序销毁元素
        for(auto p = first_free; p != elements; )
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

string& StrVec::operator[](size_t ind)
{
    return elements[ind];
}

// 传入一个多类型参数
StrVec::StrVec(std::initializer_list<string> s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::~StrVec()
{
    free();
}

// 拷贝赋值运算符，和拷贝构造不一样的是多了一个free的过程
StrVec& StrVec::operator=(const StrVec &rhs)
{
    // 使得两者大小一样并拷贝
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    // 释放自己原有的
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

// 移动构造函数，接管s中的资源
StrVec::StrVec(StrVec &&s) noexcept
    :elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // 接管完成后指针赋值为空
    s.elements = s.first_free = s.cap = nullptr;
}

// 移动赋值运算符
StrVec& StrVec::operator=(StrVec &&s) noexcept
{
    // 直接检测自赋值
    if(this != &s)
    {
        // 先释放我们自己的
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        // 接管后指针为空
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

// 每次重新分配内存都会使StrVec的容量加倍
// 如果StrVec为空，则分配一个元素的空间
void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;

    // 分配新内存
    auto newdata = alloc.allocate(newcapacity);

    // 将数据从旧内存"移动"到新内存    
    auto dest = newdata; // 新数组的下一个空闲位置
    auto elem = elements; // 旧数组的下一个位置
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    // 移动完元素，释放旧内存空间
    free();
    elements = newdata;
    first_free = dest;
    cap = newdata + newcapacity;
}

StrVec &StrVec::operator=(std::initializer_list<string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}