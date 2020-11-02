#include <iostream>

void try_rvalue(int &&i) {}

template <typename T>
void try_rvalue_template(T&& i) {}

int main()
{
	int i = 1;
	// illegal
	// try_rvalue(i);

	// legal
	try_rvalue_template(i);
	return 0;
}