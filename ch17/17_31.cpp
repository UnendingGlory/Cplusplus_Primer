#include <iostream>
#include <random>
#include <vector>
#include <string>

int main()
{
	std::default_random_engine e;
	// 均值为4，标准差为1.5
	std::normal_distribution<> n(4, 1.5);
	std::vector<unsigned> vals(9);
	for(size_t i = 0; i != 200; ++i)
	{
		// 将每个随机数舍入到最接近的整数
		unsigned v = lround(n(e));
		if(v < vals.size())
			++vals[v];
	}
	std::cout << std::string(10, '=') << '\n';
	for(size_t j = 0; j != vals.size(); ++j)
		std::cout << j << ": " << std::string(vals[j], '*') << std::endl;
	std::cout << std::string(10, '=') << '\n';
 	return 0;
}