#include "15_30.h"

#include <vector>
#include <memory>
using std::vector;

using std::shared_ptr;
using std::make_shared;

int main()
{
    Basket bst;
    bst.add_item(Quote("001", 1));
    bst.add_item(Quote("002", 2));
    // overloaded
    bst.add_item(Bulk_quote("003", 3, 10, 0.1));
    std::cout << "======================\n";
    bst.total_receipt(std::cout);
    // 1 * 20 + 2 * 20 + 3 * 20 * 0.9 = 114
    std::cout << "======================\n";
    return 0;
}