#include "15_15.h"
#include <iostream>

// 计算并打印销售给定数量的某种书籍所得费用
double print_total(std::ostream &os, const Quote &item, size_t n)
{
    // 根据item形参的对象类型调用基类的net_price或者派生类的net_price
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold : " << n << " total due: "
        << ret << std::endl;
    return ret;
}

int main()
{
    // isbn
    Quote basic("0001", 1.0);
    // >=10本打9折
    Bulk_quote bulk("0002", 2.0, 10, 0.1);

    print_total(std::cout, basic, 20);
    // 一个2块打九折，20 * 2 * 0.9 = 36
    print_total(std::cout, bulk, 20);

    // 尝试定义抽象类的对象
    // 报错：cannot declare variable ‘d’ to be of abstract type ‘Disc_quote’
    // Disc_quote d;
    return 0;
}