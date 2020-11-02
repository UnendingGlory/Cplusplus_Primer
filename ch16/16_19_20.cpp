#include <iostream>
#include <vector>

using std::vector;

// 接受一个容器的引用并打印容器中的元素
template <typename Container>
std::ostream& print_container(const Container& t, std::ostream &os)
{
	// size_type是一个类型成员
	for(typename Container::size_type i = 0; i != t.size(); ++i)
		os << t[i] << ' ';
	return os;
}

// 使用迭代器进行循环
template <typename Container>
std::ostream& print_container2(const Container& t, std::ostream &os)
{
	// iterator
	for(auto i = t.cbegin(); i != t.cend(); ++i)
		os << *i << ' ';
	return os;
}

int main()
{
	vector<int> vec{1, 2, 4, 7, 9, 10};
	print_container(vec, std::cout) << '\n';
	print_container2(vec, std::cout) << '\n';
	return 0;
}
