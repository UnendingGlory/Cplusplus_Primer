#include "15_28.h"

#include <vector>
using std::vector;

int main()
{
    vector<Quote> vec;
    vec.emplace_back(Quote("001", 1));
    vec.emplace_back(Quote("002", 2));
    // 只会emplace_back Bulk_quote中的Quote部分
    vec.emplace_back(Bulk_quote("003", 3, 10, 0.1));
    std::cout << "======================\n";
    double sum = 0;
    for(auto &p : vec)
        sum += p.net_price(20);
    // 1 * 20 + 2 * 20 + 3 * 20 = 120
    // 因为Bulk_quote变成了Quote
    std::cout << sum << '\n';
    std::cout << "======================\n";
    return 0;
}