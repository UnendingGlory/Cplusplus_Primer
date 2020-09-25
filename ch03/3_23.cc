#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main()
{
    vector<int> a(10, 10);
    for(vector<int>::iterator i = a.begin(); i != a.end(); ++i)
    {
        *i = (*i) * 2;
        cout << *i << '\n';
    }
    return 0;
}