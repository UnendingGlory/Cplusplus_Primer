#include <iostream>
#include <random>

int main()
{
	// 在(0, 9)之间的均匀分布的随机数生成器
	std::uniform_int_distribution<unsigned> u(0, 9);

	std::default_random_engine e;
	for(size_t i = 0; i < 10; ++i)
	{
		std::cout << u(e) << std::endl;
	}
	return 0;
}