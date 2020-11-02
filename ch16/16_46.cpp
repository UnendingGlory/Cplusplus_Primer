#include <iostream>
// 进行非常规类型转换的标准库模板类
#include <type_traits>
#include <string>

namespace ch16
{
	// 标准库move函数定义
	template <typename T>
	typename std::remove_reference<T>::type&& move(T &&t)
	{
		return static_cast<typename std::remove_reference<T>::type&&> (t);
	}
}

int main()
{
	std::string s1("hi"), s2;
	s2 = ch16::move(std::string("bye"));
	s2 = ch16::move(s1); // 正确，但要保证赋值后，s1最好不能再被使用
	return 0;
}