#ifndef QUERY_H
#define QUERY_H

#include "TextQuery.h"
#include "WordQuery.h"
#include <string>
#include <memory>
// Query类对外提供接口，同时隐藏了Query_base的继承体系
// 存储各类Query_base对象

class Query{
    // 两端都有可能有对象，所以重载成非成员函数
    friend Query operator ~ (const Query &);
    friend Query operator | (const Query &, const Query &);
    friend Query operator & (const Query &, const Query &);

public:
    Query(const std::string &);
    // 接口函数，调用对应的Query_base操作
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }

    std::string rep() const
    {
        return q->rep();
    }

private:
    Query(std::shared_ptr<Query_base> Query) : q(Query) { }
    std::shared_ptr<Query_base> q;
};

// 内联函数定义应该都放在头文件中
inline Query::Query(const std::string &s) : q(new WordQuery(s))
{

}

#endif