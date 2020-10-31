#include <iostream>
#include <vector>
#include "../ch07/7_41.h"
using std::cout;

template <typename T>
int compare(const T &lhs, const T &rhs)
{
	if(lhs < rhs) return 1;
	if(rhs < lhs) return -1;
	return 0;
}

int main()
{
	cout << compare(1, 0) << '\n';
	// vector重载了<运算符，所以可以作用于该函数模板
	std::vector<int> a{0, 1, 2}, b{0, 1, 3};
	cout << compare(a, b) << '\n';
	// error: no match for operator <
	// Sales_data s("001", 100, 10), t("002", 50, 5);
	// cout << compare(s, t) << '\n';
	return 0;
}