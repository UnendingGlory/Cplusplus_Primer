#include <iostream>
#include <string>
using std::string; using std::cout;

void pre_and_suffix(string &s, string const &prefix, string const &suffix)
{
    // 传的是迭代器，应该保持迭代器一致
    s.insert(s.begin(), prefix.cbegin(), prefix.cend());
    s.append(suffix);
}

void pre_and_suffix_v2(string &s, string const &prefix, string const &suffix)
{
    // 传的是下标，直接传字符串
    s.insert(0, prefix);
    s.insert(s.size(), suffix);
}

int main()
{
    string s{"Wilson"};
    pre_and_suffix(s, "Mr.", "III");
    cout << s << '\n';
    pre_and_suffix_v2(s, "Mr.", "III");
    cout << s << '\n';
    return 0;
}