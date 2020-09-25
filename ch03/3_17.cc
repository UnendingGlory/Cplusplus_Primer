#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;

int main()
{
    for(string s; cin >> s;)
    {
        for(auto &i : s)
            i = toupper(i);
        cout << s << '\n';
    }
    return 0;
}