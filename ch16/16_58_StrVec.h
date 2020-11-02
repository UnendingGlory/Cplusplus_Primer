// 为你的StrVec类添加一个构造函数，接受一个initializer_list<string>参数
#ifndef CH16_STRVEC_H
#define CH16_STRVEC_H
#include <memory>
#include <string>
#include <utility>
#include <iostream>
using std::allocator; using std::string;
using std::pair;

// 实现一个针对string类型的vector
class StrVec{
	friend std::ostream& operator << (std::ostream&, const StrVec &);
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

	// 模拟标准库定义一个emplace_back函数
	// 为了保持实参中的信息，必须将empalce_back的函数参数定义为模板类型参数的右值引用
	// 搭配引用折叠 + std::forward保持实参类型信息
	// 最终到达的效果: 使得emplace_back(10, 'c')和emplace_back(string1 + string2)等都可行
	template <class ...Args>
	void emplace_back(Args&&...);

public:
    StrVec(StrVec &&) noexcept; // 移动构造函数
    StrVec& operator=(StrVec &&) noexcept; // 移动赋值运算符

private:
    // alloc用来分配元素
    allocator<string> alloc;
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

// 模板定义必须放在头文件中，这样才能实例化
template <class ...Args>
void StrVec::emplace_back(Args&&... args)
{
	chk_n_alloc();
	alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif