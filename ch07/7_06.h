#ifndef CH7_06_H
#define CH7_06_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
    // const成员函数，说明this是一个指向常量的指针
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    string isbn() const { return bookNo; };
    Sales_data& combine(const Sales_data&);
};

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// 输入交易信息，返回引用
istream &read(istream &s, Sales_data &item)
{
    double price = 0;
    s >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return s;
}

// 不负责换行。执行输出任务的函数尽量减少对格式的控制
ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs); // 返回*this
    return sum;
}

#endif