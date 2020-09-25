#include "7_11.h"

using std::cout;
using std::cin;

int main()
{
    Sales_data item;
    print(cout, item) << '\n';
    Sales_data item1("123");
    print(cout, item1) << '\n';
    Sales_data item2("123", 4, 5);
    print(cout, item2) << '\n';
    Sales_data item3(cin);
    print(cout, item3) << '\n';
    return 0;
}