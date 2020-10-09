#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using std::vector; using std::string;
using std::istringstream;
using std::cout;

// the library algorithm operates on iterators, not containers
// Thus, an algorithm connot directly add or remove elements

int main()
{
    string str{"the quick red fox jumps over the slow red turtle"};
    vector<string> vec;

    // bind str to an istringstream
    istringstream is(str);
    string word;

    // read words from the istringstream objects, seperated by blankspace
    while(is >> word)
        vec.emplace_back(word);

    // sort and eliminate duplicate elements
    sort(vec.begin(), vec.end());
    for(const auto &i : vec)
        cout << i << ' ';
    cout << '\n';

    auto end_iter = std::unique(vec.begin(), vec.end());
    vec.erase(end_iter, vec.end());

    for(const auto &i : vec)
        cout << i << ' ';
    cout << '\n';
    return 0;
}