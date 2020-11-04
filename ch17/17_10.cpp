#include <iostream>
#include <bitset>
#include <vector>

using std::bitset; using std::vector;

int main()
{
	vector<int> v = {1, 2, 3, 5, 8, 13, 21};
	bitset<32> bset;
	for(auto i : v)
	{
		bset.set(i); // 置第i位为1
		std::cout << bset << '\n';
	}
	std::bitset<32> bset2 = bset;
    // for (size_t i = 0; i != 32; ++i)
    //     bset2[i] = bset[i];

	std::cout << "================================\n";
    std::cout << bset << std::endl;
    std::cout << bset2 << std::endl;
	return 0;
}