#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

// 本身就不能变，用顶层const，默认lhs数目少于rhs
bool is_prefix(vector<int> const& lhs, vector<int> const& rhs)
{
    if(lhs.size() > rhs.size()) return is_prefix(rhs, lhs);
    for(auto i = 0; i < lhs.size(); ++i)
        if(lhs[i] != rhs[i])
            return false;
    return true;
}

int main()
{
    vector<int> a{0, 1, 1, 2}, b{0, 1, 1, 2, 3, 5, 8};
    cout << (is_prefix(a, b) ? "Yes" : "No") << '\n';
    return 0;
}