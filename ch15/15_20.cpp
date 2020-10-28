// just for 2-D shape
#include <iostream>
#include <string>

class Shape
{
public:
    using Coordinate = std::pair<double, double>; // 点的坐标

    Shape() = default;
    Shape(const std::string& n) : // 名字
        name(n) { }

    virtual double area()       const = 0; // 面积
    virtual double perimeter()  const = 0; // 周长

    virtual ~Shape() = default;
private:
    std::string name;
};

// 长方形继承形状
class Rectangle : public Shape
{
public:
    Rectangle() = default;
    Rectangle(const std::string& n,
              const Coordinate& a,
              const Coordinate& b,
              const Coordinate& c,
              const Coordinate& d) :
        Shape(n), a(a), b(b), c(c), d(d) { }

    ~Rectangle() = default;

protected:
    Coordinate  a;
    Coordinate  b;
    Coordinate  c;
    Coordinate  d;
};

// 正方形继承长方形
class Square : public Rectangle
{
public:
    Square() = default;
    Square(const std::string& n,
           const Coordinate& a,
           const Coordinate& b,
           const Coordinate& c,
           const Coordinate& d) :
        Rectangle(n, a, b, c, d) { }

    ~Square() = default;
};

int main()
{

    return 0;
}