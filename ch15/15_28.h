// define the Quote and Bulk_quote copy-control members
#ifndef CH_15_28_H
#define CH_15_28_H

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
    Quote() { std::cout << "Quote : default constructing\n"; };
    Quote(const string &book, double sales_price) : bookNo(book), price(sales_price){
        std::cout << "Quote : constructor taking 2 parameters\n";
    }

    // copy constructor
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price){
        std::cout << "Quote : copy constructing\n";
    }

    // move constructor
    Quote(Quote && q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)){
        std::cout << "Quote : move constructing\n";
    }

    // copy =
    Quote& operator=(const Quote &rhs)
    {
        // tackle self-assgin
        if(this != &rhs)
        {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote : copy-assignment operator\n";
        return *this;
    }

    // move =
    Quote& opertor(Quote &&rhs)
    {
        if(this != &rhs)
        {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "Quote : move-assignment operator\n";
        return *this;
    }

    // destructing
    virtual ~Quote() { std::cout << "Quote : destructing\n"; };

    // the caller of the function is a lvalue
    virtual Quote* clone() const & { return new Quote(*this); }
    // the caller of the function is a rvalue
    virtual Quote* clone() const && { return new Quote(std::move(*this)); }

    string isbn() const { return bookNo; }
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写并使用不同的折扣计算算法（对于每一本书来说）
    virtual double net_price(std::size_t n) const
    {
        // n为销售额
        return n * price;
    }
};

class Bulk_quote : public Quote{
public:
    Bulk_quote() { std::cout << "Bulk_quote : default constructing\n"; }

    // 调用基类的构造函数
    Bulk_quote(const string &book, double p, size_t qty, double disc)
        : Quote(book, p), min_qty(qty), discount(disc){ 
            std::cout << "Bulk_quote : constructor taking 2 parameters\n";
        }

    // copy constructor
    Bulk_quote(const Bulk_quote &rhs) : Quote(rhs), min_qty(rhs.min_qty), discount(rhs.discount)
    {
        std::cout << "Bulk_quote : copy constructing\n";
    }
    
    // move constructor
    Bulk_quote(Bulk_quote &&rhs) : 
        Quote(std::move(rhs)), min_qty(std::move(rhs.min_qty)), discount(std::move(rhs.discount))
    {
        std::cout << "Bulk_quote : move constructing\n";
    }
    
    // copy-assignment
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        // called the copy-assignment operator explicitly
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        std::cout << "Bulk_quote : copy-assignment operator\n";
        return *this;
    }

    // move-assignment
    Bulk_quote &operator=(Bulk_quote &&rhs)
    {
        // called the copy-assignment operator explicitly
        if(this != &rhs)
        {
            Quote::operator=(std::move(rhs));
            min_qty = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
            std::cout << "Bulk_quote : move-assignment operator\n";
        }
        return *this;
    }

    ~Bulk_quote() { std::cout << "Bulk_quote : destructing\n"; }

    // the caller of the function is a lvalue
    virtual Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    // the caller of the function is a rvalue
    virtual Bulk_quote* clone() const && { return new Bulk_quote(std::move(*this)); }

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

double print_total(std::ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " #sold: " << n << 
        " total due: " << ret << '\n';
    return ret;
}

#endif