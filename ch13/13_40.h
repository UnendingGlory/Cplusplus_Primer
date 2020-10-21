// 为你的StrVec类添加一个构造函数，接受一个initializer_list<string>参数
#ifndef CH_13_40_H
#define CH_13_40_H
#include <memory>
#include <string>
#include <utility>

using std::allocator; using std::string;
using std::pair;

// 实现一个针对string类型的vector
class StrVec{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){};
    StrVec(const StrVec &); // 拷贝构造函数
    StrVec(std::initializer_list<string>);
    StrVec& operator=(const StrVec &); // 拷贝赋值运算符
    string& operator[](size_t ind); // 重载下标运算符
    ~StrVec(); // 析构函数
    void push_back(const string &); // 拷贝元素
    size_t size() const { return first_free - elements; } // 有效元素个数
    size_t capacity() const { return cap - elements; } // 最大容量
    string* begin() const { return elements; }
    string *end() const { return first_free; } // end是最后一个有效元素的后一位

private:
    // alloc用来分配元素
    static allocator<string> alloc;
    // 保证StrVec至少有容纳一个新元素的空间。
    // 如果没有空间添加新元素，该函数会调用
    // reallocate来分配更多内存
    void chk_n_alloc() { if(size() == capacity()) reallocate(); }
    // 分配内存并拷贝一个给定范围中的元素
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    // 销毁元素并释放内存
    void free();
    // 获得更多内存并拷贝已有元素
    void reallocate();
    string *elements; // 指向数组首元素
    string *first_free; // 指向数组第一个空闲元素的指针
    string *cap; // 指向数组尾后位置的指针(capacity末尾的后一个位置)
};

#endif