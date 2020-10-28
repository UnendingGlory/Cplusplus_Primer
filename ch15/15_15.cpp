#include "15_15.h"
#include <iostream>

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}
