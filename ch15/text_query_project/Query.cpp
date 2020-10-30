#include <Query.h>
#include <WordQuery.h>
#include <iostream>

std::ostream & operator <<(std::ostream &os, const Query &query)
{
    // Query::rep通过base指针对rep()进行了虚调用
    return os << query.rep();
}