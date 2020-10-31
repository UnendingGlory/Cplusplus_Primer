#include <iostream>
#include <string>

template <typename Arr, size_t size>
constexpr size_t get_size(const Arr (&arr)[size])
{
	return size;
}

int main()
{
	std::string s[] = { "sss" };
    std::cout << get_size(s) << std::endl;

    char c[] = "s";
    std::cout << get_size(c) << std::endl;
    // the output is 2, as '\0' is added at the end of the array
}