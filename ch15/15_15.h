#ifndef CH_15_15_H
#define CH_15_15_H

#include <string>
using std::string;

class Quote
{
private:
    std::string bookNo;
protected:
    // 允许派生类访问
    double price = 0.0;
public:
    Quote() = default;
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price){}
    string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法（对于每一本书来说）
    virtual double net_price(std::size_t n) const
    {
        // n为销售额
        return n * price;
    }

    // 析构函数动态绑定
    virtual ~Quote() = default;
};

// 用于保存折扣值和购买量的类，只是一个接口类
// 派生类可以用这些数据实现不同的价格策略
class Disc_quote : public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) {} ;

    double net_price(std::size_t) const = 0;

protected:
    size_t quantity = 0; // 折扣购买量
    double discount = 0.0; // 折扣力度
};

class Bulk_quote : public Disc_quote{
public:
    Bulk_quote() = default;
    // 调用基类的构造函数
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Disc_quote(book, p, qty, disc) { } ;
    // 覆盖基类的函数版本以实现大量购买的折扣政策
    double net_price(size_t) const override final;
};

#endif