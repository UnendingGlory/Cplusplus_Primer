#include "15_28.h"

#include <vector>
#include <memory>
using std::vector;

using std::shared_ptr;
using std::make_shared;

int main()
{
    vector<shared_ptr<Quote>> vec;
    // 在末尾创建指针
    vec.emplace_back(make_shared<Quote>("001", 1));
    vec.emplace_back(make_shared<Quote>("002", 2));
    // 只会emplace_back Bulk_quote中的Quote部分
    vec.emplace_back(make_shared<Bulk_quote>("003", 3, 10, 0.1));
    std::cout << "======================\n";
    double sum = 0;
    for(auto &p : vec)
        sum += p->net_price(20);
    // 1 * 20 + 2 * 20 + 3 * 20 * 0.9 = 114
    std::cout << sum << '\n';
    std::cout << "======================\n";
    return 0;
}