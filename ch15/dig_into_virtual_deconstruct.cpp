#include <string>
#include <iostream>
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
    virtual ~Quote() { std::cout << "Quote deconstructor is called\n"; };
};

class Bulk_quote : public Quote{
public:
    Bulk_quote() = default;
    // 调用基类的构造函数
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc) { } ;
    // 覆盖基类的函数版本以实现大量购买的折扣政策
    double net_price(size_t) const override;
    virtual ~Bulk_quote() { std::cout << "Bulk quote deconstructor is called\n"; }
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

int main()
{
    // 调用Quote的析构函数
    Quote *itemP= new Quote;
    delete itemP;

    // 先调用Bulk quote的析构函数，再调用其基类的析构函数
    // 基类的析构函数用来析构继承来的基类部分
    itemP = new Bulk_quote;
    delete itemP;
    return 0;
}