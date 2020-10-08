#include <iostream>
#include <string>
#include <vector>

using std::string; using std::vector;

int main()
{
    vector<string> s;
    for(int i = 0; i < 10; ++i)
    {
        s.emplace_back(std::to_string(i * 10));
    }
    int ans = 0;
    for(auto i : s) ans += stoi(i);
    std::cout << ans << '\n';
    return 0;
}