#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string str, temp = "", max_str;
    int max_cnt = 0, cnt;
    while(cin >> str && str != "#")
    {
        if(str == temp)
        {
            ++cnt;
            if(cnt > max_cnt)
            {
                max_cnt = cnt;
                max_str = str;
            }
        }
        else cnt = 1, temp = str;
    }
    cout << max_str << " " << max_cnt << '\n';
    return 0;
}