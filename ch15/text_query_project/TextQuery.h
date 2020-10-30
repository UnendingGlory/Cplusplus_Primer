#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

using std::vector; using std::string;
using std::shared_ptr; using std::map;
using std::set;

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
    shared_ptr<vector<string>> file;
    // mapping from the word and the line number set
    map<string, shared_ptr<set<lineNo>>> wm;
};

#endif