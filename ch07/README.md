#### Chapter 7 类
1. 在类中，成员函数使用this的额外参数来访问调用它的那个对象

this是一个常量指针，调用它的对象的**常量指针**

定义类似如：A* const this，A为某个类，所以this不能绑定到其他对象上

2. 类中在参数列表后的const关键字：修改隐式this指针类型

使得this指针指向的是常量对象，即在该函数体下this指针指向的内容不能改变

声明如：const A* const this

这样使用const的成员函数被称为常量成员函数

当一个成员调用另一个成员时，this指针会在其中隐式地传递

3. 编译器分两步处理类：首先编译成员的声明，然后再编译成员函数体

因此，成员函数体可以随意使用类中的其他成员而无须在意这些成员的出现顺序

4. 定义在类外的函数，前面需要包含类名

编译器一旦看到这个函数名，就能理解剩余的代码是位于类的作用域内的，因此定义在类外的函数也可以随意使用本类内的成员

5. 返回this指针一般和返回类型是引用相结合

6. IO类属于不能被拷贝的类型，因此如果参数是istream,ostream，则一定要加引用
7. 构造函数不能被声明成const的，当我们创建类的一个const对象时，直到构造函数完成初始化过程，对象才能真正取得其“常量”属性

8. C++11中，如果需要默认的行为，那么可以在参数列表后协商=default来要求编译器生成构造函数，如
```C++
struct Sales_data()
{
    Sales_data() = default; // 要求编译器生成默认构造函数
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(p*n){}
}
```

9. 构造函数初始化列表：负责为新创建的对象的一个或几个数据成员赋初值

如上一条中的第二个构造参数

如果成员是const，引用，或者属于某种未提供默认构造函数的类类型，我们必须通过构造函数初始值列表为这些成员提供初值

并且最好令构造函数初始值的顺序与成员声明的顺序保持一致

```C++
// 例子
class ConstRef
{
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
};
ConstRef::ConstRef(int ii)
{
    i = ii; // 正确
    ci = ii; // 错误，不能给const赋值
    ri = ii; //错误，ri是引用，还没有绑定对象
}
// 正确，使用参数列表初始化
ConstRef::ConstRef(int ii):i(ii), ci(ii), ri(ii){}
```

10. struct默认访问权限是public，而class默认访问权限是private

11. 友元：允许其他类或者函数访问自身的非公有成员

一般来说，最好在类定义开始或者结束前的位置集中声明友元
而定义一般放在外部

注意：友元不存在传递性。

12. 可变数据成员mutable，一个可变数据成员永远不会是const，即使它是const对象的成员

可变数据成员即使在const函数中也可以改变。

13.如果一个类想把一组重载函数声明成友元，它需要对这组函数中地每一个分别声明

14. 友元地作用只是影响访问权限，自身并非普通意义上的声明。

15. 委托构造函数：可以在某个构造函数中调用其他的构造函数，使得可以使用其他构造函数的一些功能，而不用再自己写一大堆🆒

example:
```C++
class SalesData
{
    public:
        SalesData(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnt), revenue(cnt*price){}
        // 委托上一个构造函数帮自己完成某些初始化
        SalesData(std:istream &is):SalesData("", 0, 0) {read(is, *this)}
};
```

16. 类内构造函数explicit：防止函数传入的对象进行了隐式转换

比如：如果一个函数的参数是string类型的，则istream类型对象传入会被自动转换
如果又想重载一个stream类型的函数，则会产生二义性问题。
这个时候将其声明为explicit类型即可。


17. 构造函数可以被声明为constexpr类型，用于生成constexpr对象

18. 类中的static

静态成员变量：类的静态成员存在于所有对象之外，相当的全局成员，只有一个静态成员且被所有的类对象共享

一般静态成员不在类的内部初始化。

不过constexpr类型声明的静态成员可以在类内初始化。

声明：static constexpr int xxx = 3;

静态成员函数：与静态成员相同，不与任何对象绑定在一起，所以不包含this指针，因此，静态成员函数不能声明成const的，并且我们也不能在static函数体内使用this指针

访问静态成员直接 **类名::成员名**即可

在类的外部定义静态成员时，不需要重复static关键字

19. 聚合类：只有公有成员，没有构造函数的类。可以直接用花括号的初始值列表初始化
