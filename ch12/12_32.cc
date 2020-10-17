#include "12_32.h"
#include <fstream>

using std::ifstream; using std::string;
using std::ostream;

TextQuery::TextQuery(ifstream& is)
{
    string text;
    while(getline(is, text))
    {
        file.push_back(text);
        // current line number
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            // if not in wm
            auto &lines = wm[word];
            // the first time we met the word
            if(!lines)
                lines.reset(new set<lineNo>); // allocate a new set
            // insert the line no
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::Query(const string& sought) const
{
    // if sought not found, return a static pointer
    static shared_ptr<set<lineNo>> nodata(new set<lineNo>);

    auto loc = wm.find(sought);
    if(loc == wm.end()) return QueryResult(sought, nodata, file);
    // return the second which is a shared_ptr of the pair to QueryResult
    else return QueryResult(sought, loc->second, file);
}

// print the query results
ostream& print(ostream &os, const QueryResult& res)
{
    // process the plural
    os << res.sought << " occurs " << res.lines->size() << " " <<
        (res.lines->size() <= 1 ? "time" : "times") << '\n';
    // for each word li lines
    for(auto num : *res.lines)
    {
        // StrBlobPtr constructor should add const
        // or compiling will fail
        StrBlobPtr p(res.file, num);
        os << "\t(line " << num + 1 << ") ";
        os << p.deref() << '\n'; 
    }
    return os;
}