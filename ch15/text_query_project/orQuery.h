#ifndef OR_QUERY_H
#define OR_QUERY_H
#include "BinaryQuery.h"

// BinaryQuery也是一个抽象基类，保存操作两个运算符对象的查询类型所需的数据

class OrQuery : public BinaryQuery
{
    friend Query operator | (const Query &, const Query &);
    OrQuery(const Query &left, const Query &right) : 
        BinaryQuery(left, right, "|") { }

    // 具体的类，AndQuery继承了rep并且定义了其它纯虚函数
    QueryResult eval(const TextQuery&) const;
};

inline Query operator | (const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif