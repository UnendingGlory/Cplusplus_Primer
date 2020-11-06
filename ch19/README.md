#### Chapter 19 特殊工具与技术

1. 控制内存分配，如果想自己管理内存，则可以重载new和delete运算符

(注意，相比较关键字而言，这两个说是运算符更准确一点）

2. **运行时类型识别（run-time type identification, RTTI)**

C++中RTTI主要由两个运算符实现：
* typeid 运算符，用于返回表达式的类型
* dynamic_cast 运算符，用于将基类的指针或者引用安全地转成派生类地指针或引用

3. dynamic_cast 运算符

> dynamic_cast<type*> (e)
> dynamic_cast<type&> (e)
> dynamic_cast<type&&> (e)

其中，type必须是一个类类型，并且通常情况下该类型应该含有虚函数。

第一种形式中， e必须是一个指针。

第二种形式中，e必须是一个左值。

第三种形式中，e不能是左值。

一般e是type的派生类的对应类型

4. typeid运算符
> typeid(e)

typeid操作的结果是一个常量对象的引用，该对象的类型是type_info或者type_info的公有派生类型。

type_info 类，定义：
> t1 == t2 如果t1和t2表示同一种类型，返回true
> t1 != t2 如果t1和t2表示不同类型，返回true
> t.name() 返回一个C风格字符串，表示类型名字的可打印形式

5. 枚举类型enum

使得我们可以将一组整型常量组织在一起。

* 限定作用域的枚举类型：
```C++
    enum class peppers {red, yellow, green};
    peppers p = peppers::red;
```

* 不限作用域的枚举类型成员:
```C++
    enum color {red, yellow, green};
    peppers p = red;
```

可以提前声明enum对象的类型，默认为int
enum intValues : unsigned long long;

6. 成员函数指针

使用成员函数指针时，必须通过.\*或者->\*运算符作用于指向成员函数的指针

```C++
char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
pmf2 = &Screen::get;

Screen *pScreen = &myScreen;
char c1 = (pScreen->*pmf2)(0, 0); // 调用
```

7. 成员函数作为可调用对象
不能直接调用成员函数指针，必须使用.\*或者->\*调用成员指针

```C++
auto fp = &string::empty;
find_if(svec.begin(), svec.end(), fp); // wrong
```
显然上面没有传入一个可调用的对象。

另一种解决方法时使用标准库模板function（有点神奇）

```C++
function<bool (const string&)> fcn = &string::empty;
find_if(svec.begin(), svec.end(), fcn)；
```

8. union：一种节省空间的**类**

一个union可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。

当我们给union的某个成员赋值后，该union的其他成员就变成未定义的状态了。

```C++
union token{
    char cval;
    int ival;
    double dval;
};

token first_token = {'a'};
token last_token;
last_token.cval = 'z';

// 对于匿名union，可以直接访问其数据成员
union{
    char cval;
    int ival;
    double dval;
};
cval = 'c';
```

9. volatile
常用于直接处理硬件的程序，他们的值由程序直接控制之外的过程控制。

例如，程序可能包含一个**由系统时钟定时更新的变量**。当对象的值可能在程序的控制或者检测之外被改变时，应该将对象声明为volatile。

10. 链接指示: extern "C"
C++程序有时候需要调用其他语言编写的函数，最常见的是调用C语言编写的函数。

和其他所有名字一样，其他语言中的名字也必须提前声明。

C++使用链接指示指出任意非C++函数所用的语言。

```C++
// 可能出现在C++头文件cstring中的链接提示
// 单语句链接指示
extern "C"
size_t strlen(const char *);
// 复合语句链接指示
extern "C"{
    int strcmp(const char *, const char *);
    char *strcat(char *, const char*);
}
```