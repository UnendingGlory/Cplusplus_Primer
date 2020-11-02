#include <algorithm>
#include <iostream>

int main()
{
	int x = 1;
	long y = 2;
	/**
	 *  @brief
	 *  wrong, the source code is as follows
	 *  template<typename _Tp>
     *  	_GLIBCXX14_CONSTEXPR
     *  		inline const _Tp&
	 *  			max(const _Tp& __a, const _Tp& __b)
	 *  so the first and the second paramter must have the same type
	 */
	// std::cout << std::max(x, y) << "\n";

	// correct, convert y to int implicitly
	std::cout << std::max<int>(x, y) << "\n";
	return 0;
}