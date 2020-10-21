#ifndef CH5_TEXTQUERY_H
#define CH5_TEXTQUERY_H

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>

#include "13_42_StrVec.h"

using std::vector; using std::map;
using std::istringstream; using std::string;
using std::set; using std::shared_ptr;

class QueryResult;
class TextQuery
{
public:
    using lineNo = vector<string>::size_type;
    TextQuery() = default;
    TextQuery(const std::string path);
    TextQuery(std::ifstream &inf);
    /**
     * @brief query the results, occurred times, line number and string.
     *        but this raises some problems.
     *        cause the "QueryResults" class need to copy the results.
     *        One of the solutions is to return a pointer or iterator of the 
     *        "TextQuery" class, but what if TextQuery destroied before QueryR?
     *        So the existence period of two classes should be synchronized 
     *        The best way is to use shared_ptr
     */ 
    QueryResult Query(const string &sought) const;

private:
    // store each line
    shared_ptr<StrVec> file;
    // mapping from the word and the line number set
    map<string, shared_ptr<set<lineNo>>> wm;
};

class QueryResult
{
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
    // string for words.
    QueryResult(const string &s, shared_ptr<set<TextQuery::lineNo>> p, shared_ptr<StrVec> f):
        sought(s), lines(p), file(f) { };

private:
    string sought;
    // Occurred lineNo
    shared_ptr<set<TextQuery::lineNo>> lines;
    // input file
    shared_ptr<StrVec> file;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif