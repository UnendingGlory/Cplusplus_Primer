#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int main()
{
    vector<int> a;
    int b;
    while(cin >> b) // 以非整数结尾即可
    {
        a.emplace_back(b);
    }
    for(decltype(a.size()) i = 1; i < a.size(); ++i)
        cout << a[i] + a[i - 1] << '\n';
    for(decltype(a.size()) i = 0, j = a.size() - 1; i <= j; ++i, --j)
        cout << a[i] + a[j] << '\n';
    return 0;
}