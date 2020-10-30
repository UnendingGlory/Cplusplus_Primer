#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "TextQuery.h"
#include "QueryResult.h"
#include <string>

// 没有公有成员，都通过Query接口
class Query_base
{
    friend class Query;
private:
    // eval返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery &) const = 0;
    // rep是表示查询的一个string
    virtual std::string rep() const = 0;

protected:
    using line_no = TextQuery::lineNo;
    virtual ~Query_base() = default;
};

#endif