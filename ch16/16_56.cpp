#include <iostream>
#include "16_48_Debug_rep.h"
using std::ostream;

// 最后只剩一个元素的时候编译器选择该非可变参的函数终止递归
template <typename T>
ostream& print(ostream &os, const T& t)
{
	return os << t;
}

// 可变函数参数通常是递归的，一步一步处理每一个实参
template <typename T, typename ...Args>
ostream& print(ostream &os, const T& t, const Args ...rest)
{
	os << t << ", ";
	return print(os, rest...); // 递归调用打印其他实参
}

template <typename ... Args>
ostream &errorMsg(ostream &os, const Args& ... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	int i = 0; double d = 3.14; std::string s = "how now brown cow";
	errorMsg(std::cerr, i, d, s) << '\n';
	return 0;
}