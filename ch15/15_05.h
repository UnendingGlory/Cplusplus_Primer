#ifndef CH_15_05_H
#define CH_15_05_H
#include "15_03.h"

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    // 调用基类的构造函数
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) { } ;
    // 覆盖基类的函数版本以实现大量购买的折扣政策
    double net_price(size_t) const override;
private:
    size_t min_qty = 0; // 是用折扣政策的最小购买量min_quantity
    double discount = 0.0; // 以小数代表折扣额
};

double Bulk_quote::net_price(size_t cnt) const
{
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif