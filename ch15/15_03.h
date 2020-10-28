#ifndef CH_15_03_H
#define CH_15_03_H
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

#endif