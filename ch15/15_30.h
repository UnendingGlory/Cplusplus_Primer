#ifndef CH_15_30_H
#define CH_15_30_H

#include "15_28.h"
#include <set>
#include <memory>

class Basket{
public:
    // 使用合成的默认构造函数和拷贝控制成员
    // 避免用户显式调用std::make_shared
    // 用户只用传入Quote对象即可，其余由我们完成
    void add_item(const Quote &sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    void add_item(const Quote &&sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    // 负责将购物篮内容逐项打印成清单，然后返回购物篮中所有物品的价格
    double total_receipt(std::ostream&) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset保存多个报价，从小到大排序，用compare函数来初始化该set的比较函数
    // shared_ptr没有定义 <
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};


#endif