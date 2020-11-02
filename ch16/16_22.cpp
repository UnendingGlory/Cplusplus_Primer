#include <memory>
#include "16_21.h"

int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);

	int *ip = new int;
	DebugDelete()(ip);

	// unique_ptr is also a template
	// point its deleter, generate an object, calls its () operator
	std::unique_ptr<int, DebugDelete> pp(new int, DebugDelete());

	// away from scope, calls destructor of unique_ptr
	return 0;
}