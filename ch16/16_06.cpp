#include <iostream>
#include <string>

namespace ch16
{
	// the same as std::begin
	template <typename T, unsigned size>
	// reference to an array
	T* begin(T (&arr)[size])
	{
		return arr;
	}

	// the same as std::end, [)
	template <typename T, unsigned size>
	T* end(T (&arr)[size])
	{
		return arr + size;
	}
}

template <typename T>
void print(T &arr)
{
	std::cout << *ch16::begin(arr) << " " << *(ch16::end(arr) - 1) << '\n';
}

int main()
{
	std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1 };

	// template function in template function
	print(s); print(c); print(i);
	// std::cout << *ch16::begin(s) << " " << *(ch16::end(s) - 1) << '\n';

	// std::cout << *ch16::begin(c) << " " << *(ch16::end(c) - 1) << '\n';

	// std::cout << *ch16::begin(i) << " " << *(ch16::end(i) - 1) << '\n';

	return 0;
}