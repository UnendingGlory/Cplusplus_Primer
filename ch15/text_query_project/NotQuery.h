#ifndef NOT_QUERY_H
#define NOT_QUERY_H
#include <Query_base.h>
#include <Query.h>

// 没有公有成员，都通过Query接口
class NotQuery : public Query_base{
    friend Query operator~(const Query &) ;
    NotQuery(const Query &q) : query(q) { }

    // NotQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery &t) const;

    std::string  rep() const
    {
        return "~(" + query.rep() + ")";
    }

    Query query;
};

// 即是NotQuery友元又是Query友元
inline Query operator~(const Query &operand)
{
    // 隐式调用Query的构造函数
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

#endif