#include "15_11.h"
#include <iostream>

void Quote::debug() const
{
    std::cout << this->bookNo << " " << this->price;
}

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

void Bulk_quote::debug() const
{
    // 直接调用基类的debug函数
    Quote::debug();
    std::cout << " " << this->min_qty << " " << this->discount;
}
