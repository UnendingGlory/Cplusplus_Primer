#include "14_07.h"
#include <iostream>
#include <algorithm>

std::pair<char *, char *> String::alloc_n_copy (const char* b, const char* e)
{
    auto str = alloc.allocate(e - b);
    return {str, std::uninitialized_copy(b, e, str)};
}


void String::range_initializer(const char *b, const char *e)
{
    auto data = alloc_n_copy(b, e);
    elements = data.first;
    end = data.second;
}

String::String(const char *s)
{
    // const_cast将const类型转换为非const
    char *sl = const_cast<char *>(s);
    while(*sl) ++sl;
    range_initializer(s, sl);
}

void String::free()
{
    if(elements)
    {
        // 左闭右开，lambda中捕捉到的是指针指向的元素
        std::for_each(elements, end, [this](char &c)
        {
            alloc.destroy(&c);
        });
        // destroy后别忘了deallocate
        alloc.deallocate(elements, end - elements);
    }
}

String& String::operator=(const String &s)
{
    auto newStr = alloc_n_copy(s.elements, s.end);
    free();
    elements = newStr.first;
    end = newStr.second;
    std::cout << "copy-assignment\n";
    return *this;
}

String::String(const String &s)
{
    range_initializer(s.elements, s.end);
    std::cout << "Copy Constructor\n";
}

String::~String()
{
    free();
}

// 重载输出运算符里不应该输出换行
std::ostream& operator<<(std::ostream &os, const String &s)
{
    auto start = s.c_str();
    size_t len = s.size();
    while(len--) os << *start++;
    return os;
}