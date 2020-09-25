#include <iostream>
#include <string>
using std::string;
using std::cout;

// 返回string对象中某个指定字符第一次出现的位置，同时用引用返回该字符出现次数
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(ret == s.size()) ret = i; // occur first time
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    string::size_type cnt;
    string s = "abcdaallao";
    cout << "The position the chosen character first occured: " 
         << find_char(s, 'a', cnt) << '\n';
    cout << "Occured times: " << cnt << '\n';
    return 0;
}