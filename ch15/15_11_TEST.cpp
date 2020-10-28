#include "15_11.h"

#include <iostream>
#include <string>

void print_debug(const Quote& q);
double print_total (std::ostream& os, const Quote& item, size_t n);

int main()
{
    Quote q("aaa", 10.60);
    Bulk_quote bq("bbb", 111, 10, 0.3);

    /** 
     *  @note  Not dynamic binding!
     *  The codes below are not dynamic binding. The compiler has known what the
     *  r refering to at compile time. As a result, the virtual function debug of
     *  the subobject is called.
     */
    Quote &r = q;
    r.debug();
	std::cout << "\n";
    r = bq;
    r.debug();
	std::cout << "\n";

    std::cout << "====================\n";

    /** 
     *  @note  dynamic binding!
     *  The below will happen dynamic binding. The reason might be that while  print_debug
     *  compiling the compiler compile it independly from the rest codes. The compiler has
     *  no idea what the paramter q refering to. Thus compiler will leave the decision to
     *  run time. That is, dynamic binding.
     *
     *  Once dynamic binding happens, the corresponding virtual function in derived class will
     *  be called rather than that of the subobject inside the derived object.
     *
     *  Anyway, the reference is essentially an address being passed.
     *
     */
    
    print_debug(q); // r, which is a reference to q, has bound to bq
    std::cout << "\n";
    Quote q2("aaa", 10.60);
    print_debug(q2);
	std::cout << "\n";
    print_debug(bq);
	std::cout << "\n";

    return 0;
}

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);

    os << "ISBN:" << item.isbn()
       << "# sold: " << n << " total due: " << ret << std::endl;

    return ret;
}

void print_debug(const Quote &q)
{
    q.debug();
}