#include "13_49_String.h"
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

// 移动构造函数，先偷再设空
// 这些假设都是建立在类里有指针，这些都是对临时对象而言
String::String(String &&s) noexcept : elements(s.elements), end(s.end)
{
    s.elements = s.end = nullptr;
    std::cout << "move constructor called\n";
}

// 移动拷贝构造
String& String::operator=(String && s) noexcept
{
    // 防止自拷贝
    if(this != &s)
    {
        free();
        elements = s.elements;
        end = s.end;
        s.elements = s.end = nullptr;
    }
    std::cout << "move assginment operator called\n";
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