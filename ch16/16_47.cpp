#include <iostream>
#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
	f(std::move<T2>(t2), std::forward<T1>(t1));
}

void g(int &&i, int &j)
{
	std::cout << i << " " << j << "\n";
}

int main()
{
	int i = 1, j = 2;
	// flip(F a, int &t1, int &t2)
	// f(t2, t1)
	flip(g, i, j);
	return 0;
}