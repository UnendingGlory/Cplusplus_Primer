#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include "TextQuery.h"
using std::vector; using std::string;
using std::shared_ptr; using std::map;
using std::set;

class QueryResult
{
public:
    using ResultIter = set<TextQuery::lineNo>::iterator;
    friend std::ostream& print(std::ostream &, const QueryResult&);
    // string for words.
    QueryResult(const string &s, shared_ptr<set<TextQuery::lineNo>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) { };

public:
    ResultIter begin() const { return lines->begin(); }
    ResultIter end() const { return lines->end(); }
    shared_ptr<vector<string>> get_file()
    {
        return std::make_shared<vector<string>>(file);
    }

private:
    string sought;
    // Occurred lineNo
    shared_ptr<set<TextQuery::lineNo>> lines;
    // input file
    shared_ptr<vector<string>> file;
};

#endif