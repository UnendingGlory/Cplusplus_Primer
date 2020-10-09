#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::vector; using std::string;
using std::istringstream;
using std::cout;

int main()
{
    vector<string> vec;
    string str{"fox jumps over quick red slow the turtle"};
    istringstream is(str);
    string word;
    
    while(is >> word) vec.emplace_back(word);

    // sort by the size of the word
    std::sort(vec.begin(), vec.end(), 
        [&](const string &s1, const string &s2){ return s1.size() < s2.size(); });

    for(const auto &i : vec) cout << i << ' ';    
    cout << '\n';

    // ensure that the relative sequence in the original string is preserved
    std::stable_sort(vec.begin(), vec.end(),
        [&](const string &s1, const string &s2){ return s1.size() < s2.size(); });

    for(const auto &i : vec) cout << i << ' ';
    cout << '\n';

    return 0;
}