#include <iostream>
#include <string>

template <typename Arr>
void print(Arr const &arr)
{
	for(auto elem : arr)
		std::cout << elem << " ";
	std::cout << '\n';
}

int main()
{
	std::string s[] = { "ssss", "aaa", "ssssss" };
    char c[] = { 'a', 'b', 'c', 'd' };
    int  i[] = { 1 };
    print(i);
    print(c);
    print(s);
	return 0;
}