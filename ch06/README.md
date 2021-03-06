#### Chapter 6 函数
1. 名字有作用域，对象有生命周期

2. static：使得局部变量的**生命周期**贯穿函数调用以及之后的时间，直到程序终止才销毁。如果静态局部变量没有显式初始值，则它默认初始化的局部静态变量为0。

3. 建议在头文件.h中声明变量和函数，而定义在具体的.cpp源文件中
声明作用在编译阶段，定义作用在链接阶段
定义和声明分开是工程开发的规范，有更多的好处


4. 源文件->预处理->编译->汇编->链接->装入->可执行文件

编译阶段只执行语法检查，所以如果某个函数只有声明没有定义编译阶段不会报错，在链接阶段才会报错。

g++ -E test.cc可以查看预处理之后的待编译源码

gcc -c test.cc 会生成test.o

命令 nm -C test.o可以查看对象文件中的各种定义

链接多个对象文件，直接**g++ a.o b.o**即可

5. 函数中引用传递，引用形参是对应实参的别名，且使用引用参数可以使函数返回多个值

6. 使用引用可以避免不必要的拷贝，当函数无需修改引用形参的值时最好使用常量引用

7. 顶层const作形参需要注意的点

顶层const作为形参时，即可以传入const对象，也可以传入非const对象

而当用实参初始化形参时会忽略掉该顶层const
```C++
void fcn(const int i){}; // fcn可以读取const和非const对象，但是不能改变i
void fcn(int i); // 错误，重复定义，因为上面函数顶层const被忽略了和该函数完全相同
```

8. 如果不改变对象值，则参数尽量使用常量引用

9. **常量引用可以绑定非常量和常量，而普通引用不能绑定到常量上**

10. 指针标准库函数:begin()和end()
>尽管能计算得到尾后指针，但容易出错，因此C++标准库为指针提供了名为begin和end的函数（end返回的时尾元素的下一位置）
>如int \*beg = begin(a)， int \*last = end(b)

采用数组作为函数参数时，尽量使用标准库规范：传递指向数组首元素和尾后元素的指针，这样可以安全地访问到数组
```C++
void print(const int *beg, const int *last)
{
    // 输出[begin, end)的所有元素
    while(begin != end)
        cout << *beg++ << endl;
}
int a[5] = {1, 2, 3, 4};
print(begin(a), end(a));
```

11. main函数地参数一般是通过命令行传入
```C++
// 第一个参数argc代表数组中字符串的数量，第二个argv每个元素代表命令行提供的字符串
int main(int argc, char *argv[]) {……}
// 或者
int main(int argc, char **argv) {……}
```
举例：（prog是一个可执行文件)

如命令行指令：prog -d -o ofile data0 

则argc应该等于5，argv是一个数组，其中各值如下（以空格分割）

argv[0] = "prog";

argv[1] = "-d";

argv[2] = "-o";

argv[3] = "ofile";

argv[4] = "data0";

argv[5] = 0;

用处：比如在读取文件的时候，可以允许从命令行键入文件的path

12. 如果函数的参数数量是可变的，可以用initializer_list或者vector可变作为参数

13. 设计函数返回时，应该保证在任意一条控制流下，函数都能正常返回值

14. 返回也可以返回引用类型，返回非引用类型会发生拷贝，返回引用类型则不会（但是需要注意，**永远不能在函数中返回局部变量/常量的引用**！）

所以一般返回引用时，会返回传入参数的引用

15. 函数可以返回花括号包围的值的列表

```C++
vector<string> process()
{
    return {"function", "okay"}
}
```

16. cstdlib中两个常量：EXIT_FAILURE和EXIT_SUCCESS作为主函数返回状态

标准库定义该两个常量是为了使得返回值和机器无关，不同机器上0，1，2等main返回值代表不同的意思

17. 重载函数：为操作非常相似的函数进行重载

重载函数名和参数类型不能完全相同（这里尤其注意顶层const作为形参）

18. C++函数默认参数，必须放在函数参数列表的最后（**局部**变量不能作为默认实参）

19. 为什么引入inline函数？

因为一些简单的小操作封装成函数有利于重复利用以及修改

但是调用函数比调用等价的表达式要慢，因为函数调用需要保存寄存器如PC以及一些标志寄存器，并在返回时恢复（类似于保存断点，返回现场）；并且可能需要拷贝实参

使用内联函数则编译器会将**inline函数内的函数体直接插入到调用处**，避免了上述费时操作

注意，编译器会自动优化程序，使得某一些函数优化成内联函数。并且inline只是一个建议，并不是说声明了inline最终就是内联的，要看编译器如何优化

那么，省略了调用，代价是什么呢？代价就是会造成程序长度变大，所以如果inline太多会使得程序运行时占用的内存空间非常大，因为到inline的地方就是直接代码段插入，多次调用会使得程序膨胀，所以只建议用于小函数

20. constexpr什么用?

constexpr可以用来修饰object，也可以用来修饰函数

const强调变量不能被修改，是运行时常量

constexpr object是编译期常量，而constexpr function不一定，编译器会看情况而定

[const和constexpr的区别](https://www.zhihu.com/question/35614219)

```C++
constexpr int foo(int i)
{
    return i + 5;
}
int main()
{
    // 如果这里声明为constexpr int i = 10，那么以下都正确
    // 因为编译器确保i在编译期不会被改变
    int i = 10; 
    std::array<int, foo(5)> arr; // OK
    
    foo(i); // Call is Ok
    
    // But...
    std::array<int, foo(i)> arr1; // Error
    return 0;
}
```

21. 一般而言，inline函数和constexpr函数的**定义**放在头文件内

22. assert预处理头文件：cassert

```C++
assert(expression)
```
assert宏常用于检查不能发生的条件。

assert行为以来一个叫NDEBUG的预处理变量的状态。

如果定义了NDEBUG，则assert什么也不做。

在程序中#define NDEBUG

或者在命令行中gcc -D NDEBUG main.cc

23. 除了用assert，也可以用NDEBUG来编写自己的条件调试代码

```C++

void print(const int ia[], size_t size)
{
    #ifndef NDEBUG
        // __func__是编译器定义的一个内置宏，用来存放函数名字
        // 相同类型的还有__FILE__，__LINE__等
        cerr << __func__ << "array size is" << size << endl;
    #endif
}
```

24. 函数指针，函数式编程

函数指针：一般该指针由括号括起来
bool (\*pf) (const string &, const string&);
// pf指向一个函数，该函数参数是两个const string的引用

bool lengthCompare(const string &, const string &);
pf = lengthCompare; //使用时直接将函数名赋值给函数指针即可

25. **对C++函数返回的理解**（**极其重要！**）

* 返回值
返回一个值和初始化一个变量或者形参的方式完全一样：返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。（对类也同样生效）

```C++
string make(const string& s)
{
    return s;
}

string s = "asda";
string t = make(s);
```

中间执行的过程：调用make时，生成一个临时的string变量temp，然后temp再用来初始化t

等价于：string temp(s); string t(temp);

因此，如果一个函数有返回值，调用完没有被赋值给对应对象，则其实一直是中间的temp对象在工作生效。不好好理解这个很可能编程时出现问题（见练习7.27，7.28)。

* 返回引用
返回引用，则该引用仅仅是它所引对象的一个别名，中间不会生成拷贝对象。

函数传参时也是同理。
