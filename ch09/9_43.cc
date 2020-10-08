#include <iostream>
#include <string>

using std::string; using std::cout;

void replace_with(string &s, string const &oldVal, string const &newVal)
{
    for(auto cur = s.begin(); cur <= s.end() - oldVal.size(); )
    {
        if(oldVal == string{cur, cur + oldVal.size()})
        {
            cur = s.erase(cur, cur + oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size(); // 因为newVal刚插入，所以直接跳过
        }
        else ++cur;
    }
}

// 下标版本
void replace_with_v2(string &s, string const &oldVal, string const &newVal)
{
    for(size_t i = 0; i <= s.size() - oldVal.size(); )
    {
        // 这里可以进行一个剪枝操作，先判断第一个字符是否相等加快速度
        if(s[0] == oldVal[0] && s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += oldVal.size();
        }
        else ++i;
    }
}


int main()
{
    string s = "thoththrutho";
    replace_with(s, "tho", "though");
    cout << s << '\n';
    replace_with_v2(s, "thru", "through");
    cout << s << '\n';
    return 0;
}