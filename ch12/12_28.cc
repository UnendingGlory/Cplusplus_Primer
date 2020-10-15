// Write a version without class and shared_ptr;
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>

using std::cout; using std::cin;
using std::ifstream; using std::string;
using std::set; using std::map;
using std::vector;

int main()
{
    ifstream ifs("speak_now_lyrics.txt");
    string str;
    // save the file content
    vector<string> file;
    using lineNo = vector<string>::size_type;
    // save map for each word and its line number
    map<string, set<lineNo>> mapping;
    lineNo line = 0;
    while (std::getline(ifs, str))
    {
        ++line;
        file.emplace_back(str);
        string word;
        std::istringstream iss(str);
        while (iss >> word)
        {
            auto it = mapping.find(word);
            // do not use second to insert
            if(it == mapping.end()) mapping[word] = set<lineNo>();
            mapping[word].insert(line);
        }
    }
    
    // Query begin
    while (true)
    {
        cout << "enter a word to look for, or q to quit : ";
        string s;
        if(!(cin >> s) || s == "q") break;
        auto it =  mapping.find(s);
        auto size = it->second.size();
        cout << s << " occurs " << size << " " << (size <= 1 ? "time" : "times") << '\n';
        if(it != mapping.cend())
        {
            for(auto num : it->second)
            {
                cout << "\t(line " << num << ") ";
                // cause we increse lineNo before
                cout << file[num - 1] << '\n';
            }
        }
    }
    return 0;
}