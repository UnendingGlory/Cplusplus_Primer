#ifndef CH_12_27_H
#define CH_12_27_H

// replace vector<string> with StrBlob
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <fstream>
#include <12_19.h>

using std::vector; using std::map;
using std::istringstream; using std::string;
using std::set; using std::shared_ptr;

class QueryResult;
class TextQuery
{
public:
    using lineNo = StrBlob::size_type;
    TextQuery() = default;
    TextQuery(const std::string path);
    TextQuery(std::ifstream &inf);

    QueryResult Query(const string &sought) const;

private:
    // store each line, StrBlob is a shared_ptr vector<string>
    StrBlob file;
    // mapping from the word and the line number set
    map<string, shared_ptr<set<lineNo>>> wm;
};

class QueryResult
{
public:
    using ResultIter = set<TextQuery::lineNo>::iterator;
    friend std::ostream& print(std::ostream &, const QueryResult&);
    // string for words.
    QueryResult(const string &s, shared_ptr<set<TextQuery::lineNo>> p, StrBlob f):
        sought(s), lines(p), file(f) { };

public:
    ResultIter begin() const {return lines->begin(); }
    ResultIter end() const {return lines->end(); }
    shared_ptr<StrBlob> get_file(){return std::make_shared<StrBlob>(file); }

private:
    string sought;
    // Occurred lineNo
    shared_ptr<set<TextQuery::lineNo>> lines;
    // input file
    StrBlob file;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif