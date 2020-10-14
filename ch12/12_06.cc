#include <iostream>
#include <memory>
#include <vector>

using std::vector;
using Ptr = vector<int>*;

Ptr make_vector()
{
    Ptr p = new vector<int>();
    return p;
}

Ptr input(Ptr vec)
{
    for(int i; std::cout << "Please Enter:\n", std::cin >> i; vec->push_back(i));
    return vec;
}

std::ostream& print(Ptr vec)
{
    for(auto i : *vec) std::cout << i << " ";
    return std::cout;
}

int main()
{
    auto vec = input(make_vector());
    print(vec) << '\n';
    return 0;
}