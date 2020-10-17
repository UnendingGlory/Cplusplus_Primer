#ifndef CH_12_19_H
#define CH_12_19_H

#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <exception>

using std::string; using std::vector;
using std::shared_ptr;

class StrBlobPtr;
class StrBlob
{
// StrBlob指针类
friend class StrBlobPtr;
public:
    using size_type = vector<string>::size_type;

    StrBlob();
    StrBlob(std::initializer_list<string> il1);

    size_type size() const { return data->size(); }
    bool empty() const {return data->empty();}
    void push_back(const string &t) { data->push_back(t); }
    void pop_back();
    string &front() const;
    string &back() const;

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    // 多个StrBlob共享vector
    std::shared_ptr<vector<string>> data;

    // 如果data[i]不合法，则抛出一个异常，msg为异常信息
    void check(size_type i, const string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    // wptr指向StrBlob中的shared_ptr
    StrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz){ }
    string& deref() const;
    StrBlobPtr& incr(); // 前缀递增
    // 重载!=运算符
    bool operator != (const StrBlobPtr p) { return curr != p.curr; }

private:
    // 若检查成功，check返回一个指向vector的shared_ptr
    shared_ptr<vector<string>> check(std::size_t, const string&) const;

    // 保存一个weak_ptr，意味着底层vector可能被销毁
    std::weak_ptr<vector<string>> wptr;

    // 在数组中的当前位置
    std::size_t curr;
};

StrBlob::StrBlob() : data(std::make_shared<vector<string>>()){}
StrBlob::StrBlob(std::initializer_list<string> il1) : 
    data(std::make_shared<vector<string>>(il1)){}

void StrBlob::check(size_type i, const string &msg) const
{
    if(i >= data->size())
        throw std::out_of_range(msg);
}

string& StrBlob::front() const
{
    // 如果vector为空会抛出一个异常
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop on empty StrBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, this->size());
}

// 检查下标是否合法，以及指针指向的vector是否存在
shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string &msg) const
{
    // lock函数检查weak_ptr指向的对象是否存在，存在则返回一个shared_ptr
    auto ret = wptr.lock();
    if(!ret) throw std::runtime_error("unbound StrBlobPtr");
    if(i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}

// 非重载版本，解引用dereference StrBlobPtr
string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p)是对象指向的vector
}

// 指针自增
StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

#endif