#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::cin;
using std::string;

int main()
{
    // ispunc函数，检查字符是否是标点符号
    cout << "Enter a string include punctuation.\n";
    for(string s; getline(cin, s); cout << '\n')
    {
        string str = "";
        for(auto i : s)
            if(!ispunct(i))
                str.push_back(i);
        cout << str;
    }
    return 0;
}