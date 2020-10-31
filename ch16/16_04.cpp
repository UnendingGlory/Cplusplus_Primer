#include <iostream>
#include <vector>
#include <string>
#include <list>

namespace ch16
{
	template <typename Iterator, typename Value_type>
	Iterator find(Iterator first, Iterator last, Value_type value)
	{
		for(; first != last && *first != value; ++first);
		// if not found, first == last
		return first;
	}
}

int main()
{
	std::vector<int> vec{10, 3, 4, 5, 11};
	std::cout << *ch16::find(vec.begin(), vec.end(),  4) << '\n';

	std::list<std::string> lst{"this", "is", "a", "road""map"};
	std::cout << *ch16::find(lst.begin(), lst.end(),  "roadmap") << '\n';
	return 0;
}