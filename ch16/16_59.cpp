#include "16_58_StrVec.h"
#include <string>

int main()
{
	StrVec svec;
	svec.emplace_back(10, 'c');
	std::cout << svec << '\n';
	std::string s{"asda"};
	svec.emplace_back(s);
	std::cout << svec << '\n';
	return 0;
}