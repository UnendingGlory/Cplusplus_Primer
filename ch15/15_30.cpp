#include "15_30.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); 
        iter = items.upper_bound(*iter)) // isbn相同的不打印
    {
        // items的函数都跟其比较函数compare有关
        // *iter是一个shared_ptr, 计算每个isbn相同的item数量
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale : " << sum << '\n';
    return sum;
}