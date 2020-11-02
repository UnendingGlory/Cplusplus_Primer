#include <iostream>

template <typename T>
int compare(const T& v1, const T& v2)
{
	if(v1 < v2) return 1;
	if(v2 < v1) return -1;
	return 0;
}

int main()
{
	const char *a{"abc"}, *b{"def"};

	// correct
	std::cout << compare(a, b) << "\n";

	// correct
	std::cout << compare<const char*>(a, b) << "\n";
	return 0;
}