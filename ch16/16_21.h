#ifndef CH_16_21_H
#define CH_16_21_H

#include <iostream>

class DebugDelete
{
public:
	DebugDelete(std::ostream &s = std::cerr) : os(s) { }

	// 重载调用运算符，使其可以作用于任意对象
	// 左侧为类成员，右侧为要删除的指针
	template <typename T>
	void operator()(T *p) const
	{
		os << "deleting unique_ptr\n";
		delete p;
	}
	
private:
	std::ostream &os;
};

#endif