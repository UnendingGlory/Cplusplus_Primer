#include "QueryResult.h"
#include <iostream>

using std::ostream;

// print the query results
ostream& print(ostream &os, const QueryResult& res)
{
    // process the plural
    os << res.sought << " occurs " << res.lines->size() << " " <<
        (res.lines->size() <= 1 ? "time" : "times") << '\n';
    // for each word li lines
    for(auto num : *res.lines)
    {
        os << "\t(line " << num + 1 << ") ";
        os << (*res.file)[num] << '\n'; 
    }
    return os;
}