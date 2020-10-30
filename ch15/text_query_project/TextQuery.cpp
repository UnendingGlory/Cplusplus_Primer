#include <TextQuery.h>
#include <fstream>
#include <sstream>

using std::ifstream;

TextQuery::TextQuery(ifstream& is) : file(new vector<string>)
{
    string text;
    while(getline(is, text))
    {
        file->emplace_back(text);
        // current line number
        int n = file->size() - 1;
        std::istringstream line(text);
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
