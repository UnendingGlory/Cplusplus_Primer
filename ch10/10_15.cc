#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::string; using std::vector;

int biggies(vector<string> &words, vector<string>::size_type sz)
{
    std::stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
        { return a.size() < b.size(); });
    auto wc = std::find_if(words.begin(), words.end(),
        [sz](const string &a)
        { return a.size() >= sz; });
    
    // count numbers of the elements whose size is bigger than sz
    auto ans = std::count_if(words.begin(), words.end(),
        [sz](const string &a)
        { return a.size() >= sz; });

    return ans;
}