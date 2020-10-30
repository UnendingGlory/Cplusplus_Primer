#ifndef WORD_QUERY_H
#define WORD_QUERY_H
#include "Query_base.h"

class WordQuery : public Query_base{
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) { }

    // WordQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery &t) const
    {
        return t.Query(query_word);
    }

    std::string  rep() const
    {
        return query_word;
    }

    std::string query_word; // 要查找的单词

};

#endif