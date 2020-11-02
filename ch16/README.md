#### Chapter 16 模板与泛型编程
1. 用关键字typename比用class更直观，因为我们可以用内置（非类）类型来作为模板类型实参。

typename可以指定成类型名。但是，有一些人仍然使用class

2. 绑定到指针或者引用非类型参数的实参必须具有静态的生存期。

不能用一个费static局部变量或者动态对象作为指针或引用非类型模板参数的实参。

3. 当我们定义一个模板时，编译器并不生成代码。只有当我们实例化出模板的一个特定版本时，编译器才会生成代码。

这导致大多数编译错误在实例化期间才报错。

4. 模板的头文件通常既包括声明也包括定义。

5. 函数模板和类模板。

6. 可以将变量定义成数组的引用。
```C++
void print(int (&arr)[10])
{
    for(auto elem : arr) cout << elem << endl;
}
```

7. C++程序员更喜欢使用！=而不喜欢<，因为！=在标准库提供的所有容器上都有效，<只在顺序等容器上有用。

8. 一个类模板的每个实例都会形成一个独立的类，这些类之间没有任何关联。

时刻记住类模板的名字不是一个类型名。类模板用来实例化类型，而一个实例化的类型总是包含模板参数的。

9. 定义在类模板内的成员函数被隐式声明为内联函数。

**在类模板内部可以直接使用模板名而不提供实参**  🦆

在类外定义函数成员时，模板实参和模板形参相同且必须说明作用域
```C++
template <typename T> class Blob{...}
template <typename T>
ret-type Blob<T>::member-name(param-list);
```

10. 当一个类包含一个友元声明时。

如果一个类模板包含一个非模板友元，则友元被授权可以访问所有的模板实例。

如果友元自身是模板，则类可以授权给所有友元模板实例，也可以将相同参数类型的实例声明为友元。

为了让所有实例成为友元，友元声明中必须使用与类模板本身不同的模板参数。

```C++
template <typename T> class Pal; // 将模板的一个特定实例声明成友元的前置工作

class C{
    friend class Pal<C>;
    
    template <typename T> friend class Pal2; // Pal2的所有实例都是C的友元
};

template <typename T> class C2{

    friend class Pal<T>; // C2的每个实例将参数相同的Pal声明为友元
    
    template <typename X> friend class Pal2; // Pal2所有实例都是C2的友元

}
```

11. 可以令模板自己的类型参数成为友元

```C++
template <typename Type> class Bar{
    friend Type;
}
```

作用，如果我们用一个类Data去实例化Bar，则Data是Bar的友元

同时也允许和内置类型兼容，以便能用内置类型来实例化Bar这样的类。

12. 在模板外部，无法使用一个typedef引用一个模板，即typedef Blob<T> StrBlob;

这种写法是错误的，因为模板不是一个类型，在参数为T的模板内部可以这么写，实例化的时候会真正定义一个类型。

```C++
template <typename Type> class Bar{
    typedef T value_type;
}
```

但是**使用using可以。**

```C++
template <typename T> using twin = pair<T, T>;
twin<string> authors; // authors是一个pair<string, string>
``` 

13. 模板的静态类成员。每个实例都有且相同实例的对象共享自己的static成员。

初始化静态类成员也要在类外部定义，且声明模板参数。

```C++
template <typename T>
size_t Foo<T>::ctr = 0;
```

14. 生命中的模板参数名字不必和定义中的相同。

但是一个给定模板的每个声明和定义必须有相同数量和种类。

15. 显式使用typename

假如有这样一行代码
```C++
template <typename T>
void foo(){
    T::iterator * iter;
}
```

在类外部访问类中的名称时，可以使用类作用域操作符，T::iterator：静态数据成员、静态成员函数和嵌套类型

如果是静态类型成员，则代表相乘；如果是嵌套类型，代表T中一个类型iterator

消除歧义的方法：指定其是一个类型，增加前缀typename

[参考链接](http://feihu.me/blog/2014/the-origin-and-usage-of-typename/)

```C++
template <typename T>
void foo(){
    typename T::iterator * iter;
    using size_type = typename vector<T>::size_type;
}
```

16. 模板也可以提供默认模板实参，若不实例化则使用默认实参实例化

```C++
template <class T = int> class number
{}

number<> aaa; // 调用默认类型
```

```C++
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
    if(f(v1, v2)) return -1;
    if(f(v2, v1)) return 1;
}

compare(0, 42); // 默认函数实参
compare(item, item2, compareIsbn);  // 自己的实参
```

17. 无论何时使用类模板，都必须在模板名后加上尖括号。函数模板则不需要。

当然，如果类型无法自动推断，则函数模板也需要加尖括号显式给出类型。

```C++
template <typename T1, typename T2>
T1 sum(T2, T3);

// T1是显式指定的,T2和T3是从函数实参类型推断而来的
auto val3 = sum<long, long>(i, lng);
```

如上面16中的 number<> aaa;

18. 当模板被使用时才会被实例化，意味着相同参数的实例可能出现在多个对象文件中。

当两个或多个独立编译的源文件使用了相同的模板并提供了相同的模板参数时，每个文件中就都会有该模板的一个实例。

在大系统中，这种额外开销可能非常严重。我们可以通过**extern**关键字显式实例化一个模板来避免这种开销。🕵️‍

```C++
extern template class Blob<string>;
extern template int compare (const int&, const int&);
```

对于一个给定的实例化版本，可能有多个extern声明，但必须只有一个定义。

当然，必须要将定义所在的.o和extern声明所在的.o链接到一起。

19. shared_ptr和unique_ptr：

通过在编译时绑定删除器，unique_ptr避免了间接调用删除器的运行时开销。

通过在运行时绑定删除器，shared_ptr使用户重载删除器更方便。(见P600)

20. 算术类型转换、派生类向基类的转换、以及用户在类中定义的转换，都不能应用于函数模板参数

如果函数模板参数是一个简单的引用，则不能用数组类型实例化。

如果函数参数类型不是模板参数，则可以对实参进行正常的类型转换。

21. 尾置返回类型

尾置返回类型允许我们在参数列表之后声明返回类型，这在模板编程中十分有用。

```C++
template <typename It>
decltype(*beg) fcn(It beg, It end)
{
    return *beg;
}
```
以上定义错误，因为在编译器遇到函数的参数列表之前，beg都是不存在的，更别提解引用beg了，正确的打开方式是使用auto+尾置返回类型推断（解引用会返回一个左值）
```C++
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg)
{
    return *beg;
}
```

更一般更通用的写法：使用标准库的类型转换模板类，如remove_reference可以褪掉引用得到实际的类型。
```C++
template <typename It>
auto fcn(It beg, It end) ->
    typename remove_reference<decltype(*beg)>::type
    {
        return *beg;
    }
```

22. 普通的函数中，不能将一个左值绑定到参数类型为右值的参数上🚴‍

但是在模板函数中可以。当我们在模板中将左值引用传递给一个右值引用函数参数时，编译器推断类型为一个左值引用类型。（右值引用+引用折叠）

但这会带来困惑：
```C++
template <typename T> void f3(T&& val)
{
    T t = val; 
    // 如果函数参数传入一个左值int，int & &&被折叠为int &，则T是int &，即引用t绑定到val上
    // 如果是一个右值int，int&& &&被折叠为int，则T是普通的int，则发生拷贝
}
```

实际上，右值引用在模板中通常用于两种情况，模板转发其实参或模板被重载。

23. 从一个左值static_cast到一个右值引用是允许的。（当然，使用std::move代替是最好也最容易的方式）

24. 完美转发：std::forward<T>(t)

forward模板可以在转发过程中保持实参的原始类型，前提是对应的模板参数类型是右值引用T&&。

25. 函数模板重载

函数模板可以被另一个模板或者一个非模板函数重载，同样必须有不同数量或类型参数。

调用时，如果有多个模板/非模板函数匹配，则选择最合适（特例）的那一个

26. 可变参数模板：用...表示

initializer_list只能针对相同类型的可变参数，而可变参数包可以针对不同类型的参数。

```C++
// Args表示0个或多个模板类型参数
// rest表示0个或多个模板类型参数
template <typename T, typename ... Args>
void foo(const T& t, const Args& ...rest>
```

如果想要知道包中有多少个元素，可以使用 **sizeof...** 运算符

可变参数模板函数通常是递归的，一步一步处理每一个实参
```C++
// 非可变版本
template <typename T>
ostream& print(ostream &os, const T& t)
{
	return os << t;
}

// 可变函数参数通常是递归的，一步一步处理每一个实参
template <typename T, typename ...Args>
ostream& print(ostream &os, const T& t, const Args ...rest)
{
    os << t << ", ";
    return print(os, rest...); // 递归调用打印其他实参
}
```

当定义可变参数版本的print时，非可变版本的声明必须在作用域中。**否则，可变参数版本会无限递归。**

对于参数包，也可以对其扩展（在上面进行同一操作）
```C++
template <typename ... Args>
ostream &errorMsg(ostream &os, const Args& ... rest)
{
    return print(os, debug_rep(rest)...);
}
```

27. 一般会组合使用可变参数模板和forward机制来编写函数，如c11的emplace_back和make_shared
```C++
// 模拟标准库定义一个emplace_back函数
// 为了保持实参中的信息，必须将empalce_back的函数参数定义为模板类型参数的右值引用
// 搭配引用折叠 + std::forward保持实参类型信息
// 最终到达的效果: 使得emplace_back(10, 'c')和emplace_back(string1 + string2)等都可行
template <class ...Args>
void emplace_back(Args&&...);
    
    
template <class ...Args>
void StrVec::emplace_back(Args&&...)
{
    check_n_alloc();
    alloc.allocate(first_free++, std::forward<Args>(args)...);
}
```

28. 模板特例化作用：当我们不希望将模板定义于某些特定类型时，模板特例化很有作用。 

29. 标准库算法都是函数模板，标准库容器都是类模板