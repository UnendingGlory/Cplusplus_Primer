#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H
#include "Query.h"

// BinaryQuery也是一个抽象基类，保存操作两个运算符对象的查询类型所需的数据

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s) : 
        lhs(l), rhs(r), opSym(s) { }

    // 抽象类：BinaryQuery不定义eval
    // 继承了Query_base的eval虚函数，因此BinaryQuery也是一个抽象基类
    std::string rep() const
    {
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }

    Query lhs, rhs; // 左侧和右侧对象
    std::string opSym; // 运算符名字
};


#endif