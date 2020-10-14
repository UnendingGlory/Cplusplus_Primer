#ifndef CH_12_02_H
#define CH_12_02_H

#include <string>
#include <initializer_list>
#include <vector>
#include <memory>
#include <exception>

using std::string; using std::vector;

class StrBlob
{
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

private:
    // 多个StrBlob共享vector
    std::shared_ptr<vector<string>> data;

    // 如果data[i]不合法，则抛出一个异常，msg为异常信息
    void check(size_type i, const string &msg) const;
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

#endif