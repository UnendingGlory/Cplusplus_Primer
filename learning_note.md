### Chapter 1 概述
1. C++文件后缀不仅有cpp，还有cc； C； cxx等
2. 文件重定向命令：Windows下  **xxx.exe**  <input_file> output_file 
>linux下也相同，xxx <input_file> output_file


3. 缓冲区 buffer，IO设备通常将输入输出数据保存在一个缓冲区中
 
4. 多行注释规范书写
```C++
/*
 *
 *
 */
```

5. 预处理名字由预处理器提供而非编译器管理，调用时直接使用即可，由编译器管理的使用时才需要std::或者xxx::来声明

#include，#define都是预处理定义

在编译前，预处理阶段处理这些预处理定义
一些内置宏：

![981bd902a7af1cfc62ee9075e48c9e1e.png](./assets/ch01.png)


---
### Chapter 2 变量和基本类型
1. 注意**内存对齐**问题（408知识点）

2. C++11标准下，可以用列表花括号初始化一切，包括变量
3. extern关键字，只是声明一个外部的全局变量，并没有定义（理解还不是很深）
一般将所有全局变量和全局函数都放在一个*.cpp文件中，然后用同一个同名的*.h包含所有函数和变量声明
4. C++静态语言，所以在编译阶段就检查所有类型，编译器必须知道每一个实体对象类型
python为动态解释性语言，所以不需要声明类型
5. 命名规范
* 变量名一般用小写字母
* 用户定义的类名一般以大写字母开头
* 单词间应该有明显区分，下划线分隔或者驼峰命名

6. 引用即起别名，是一种左值引用，必须初始化（绑定在实际的对象上）

7. void * 指针
8. 顶层const：即指针本身是一个常量如  **int \* const p1 = i;**
底层const：指针所指向的对象是一个常量如 **const int \* p2 = i;**

9. decltype()只分析表达式类型，不会执行实际的计算 
decltype((i)) d ，双层括号声明了引用，如果i是int型，则d为int &
decltype(i) d，单层括号则d为int类型

```C++
// 较有技术想象力的模板加法实现
template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b){
    return a + b;
}

// lambda表达式

auto add4 = [](int a, int b)->int
{
    return a + b;
};

```

10. 头文件保护符：用来防止某一些文件重复定义
![5fe219a7cbe2a2832aed54aa7d14af16.png](./assets/ch02.png)
11. constexpr函数 指能用于常量表达式赋值的函数，被隐式地指定为inline函数

---
### Chapter 3 字符串，向量和数组
1. 有符号数和无符号数一起操作，则有符号数会自动转换为无符号数

2. string类型取下标，其实属接受的输入参数是string::size_type类型，而不是常用的int类型，只不过int类型会转换成该类型
3. 用emplace_back()代替push_back()
4. vector类型的下标是vector<type>::size_type类型，所以取下标操作其实是对应类型的size_type
5. 迭代器和！=适用于所有容器类型
6. cbegin()和cend()代表const begin和const end，不能通过该迭代器修改对应信息
7. 使用数组下标时，通常使用size_t类型，**基本所有下标都是无符号整数类型（除了map）**

---
### Chapter 4 表达式
1. 关于左值和右值
* 以常量对象为代表的某些左值实际上不能作为赋值语句的左侧运算对象。
* 当一个对象被用作右值的时候，用的是对象的内容。当一个对象被用作左值的时候，用的是对象的身份（在内存中的位置）
* 在需要右值的时候可以用左值来代替，但不能把右值当作左值使用
* 解引用，string和vector下标运算符等得到的结果均为左值
* 如果表达式的结果是左值，则decltype将得到一个引用类型，如int \*p; decltype(\*p); decltype(a[0])等
* 普通的算术表达式是右值
2. 递增运算符优先级高于解引用运算符
3. 箭头运算符作用域一个指针类型的运算对象，结果是一个左值。而点运算符得到的类型取决于城院所属对象
4. 位运算符和1，0以及移位运算符相结合的活学活用
5. sizeof()运算符返回一个size_t类型
6. 显示强制类型转换（应该尽量避免使用）
格式：
```C++
cast-name<type>(expression);
```
tpye为要转换的目标类型，如果type是引用类型则目标是左值。9
而cast-name可选以下四种:

* static_cast：只要不包含底层const，则都可以使用明确定义的static_cast
* dynamic_cast：
* const_cast： 只能改变对象的底层const，转换成的type必须是指针或者引用
* reinterpret_cast： 不会用

#### Chapter 5 语句
1. C++异常处理
try……catch语句
```C++
try
{
    program-statements
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
```
exception类不可以赋初值
而throw其他异常类（在头文件stdexcept），如runtime_error等，必须赋初值，一般是一个字符串

```C++
throw runtime_error("Data must be a digit")
```

---
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

20. constexpr什么用? 感觉还是很难理解
constexpr声明的函数是一种内联函数
const修饰的可以被常量表达式初始化，也可以被编译器不能计算出值的表达式初始化

而constexpr修饰的函数，一定要用常量表达式初始化或者作为返回值，一定可以用于指定数组的大小

const强调变量不能被修改，而constexpr直接声明常量

![e1b4e281fe44a837f60888ff18df7b55.png](./assets/ch06.png)
（没看懂==，后面复习的时候再理解）

constexpr是真正的常量，在编译器和运行期都是常量
但是const只是编译器常量

21. 一般而言，inline函数和constexpr函数的**定义**放在头文件内

22. assert预处理头文件：cassert

```C++
assert(expression)
```
assert宏常用于检查不能发生的条件。
assert行为以来一个叫NDEBUG的预处理变量的状态。
如果定义了NDEBUG，则assert什么也不做。
在程序中#define NDEBUG
或者在命令行中cc -D NDEBUG main.cc

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

---

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

静态成员函数：与静态成员相同，不与任何对象绑定在一起，所以不包含this指针，因此，静态成员函数不能声明成const的，并且我们也不能在static函数体内使用thi指针

访问静态成员直接 **类名::成员名**即可

在类的外部定义静态成员时，不需要重复static关键字

19. 聚合类：只有公有成员，没有构造函数的类。可以直接用花括号的初始值列表初始化

---
#### Chapter 8 IO库
1. IO类：iostream, fstream（针对文件），sstream（针对字符串）
在这些类中，iostream分为istream，ostream
fstream分为ifstream，ofstream
sstream分为istringstream，ostringstream

2. IO类型不能拷贝或者赋值
因此如果函数返回IO类型对象，一般会返回引用

3. endl操纵符会显式刷新缓冲区（少用）并输出一个回车
flush会刷新缓冲区，但不加任何字符

4. 如果有一个函数接收一个ostream &参数，我们在调用这个函数时，可以传递给它一个ofstream对象，对istream和ifstream也是类似的

5. sstream头文件，string流，可以从string等读取数据，就像string是个IO流一样
istringstream，可以读一个字符串形成一个istringstream对象
ostringstream，可以存一个字符串
\>>和<<箭头的方向就是流的方向

---
#### Chapter 9 顺序容器
1. 顺序容器：vector, deque, list, forward_list, array, string

2. 只有连续内存空间的容器才能用下标访问

3. forward_list是前向链表，所以迭代器不支持递减

4. 元素范围: [begin, end)

5. 迭代器：begin()，end()，rbegin(), rend(), cbegin(), cend()， crbegin(), crend()
    vector<int>::const_iterator 代表常量迭代器
    不过需要注意的是，以c开头的函数都是被重载过的。
    一个是const成员，返回const_iterator类型。
    一个是非const成员，返回iterator类型。
    
6. 可以在不了解容器中元素类型的情况下使用它。
如果需要元素类型，可以使用容器的value_type
如果需要元素类型的一个引用，可以使用referenece或者const_reference

7. 只有顺序容器（不包括array）的构造函数才接受大小参数。
因为array的大小是类型的一部分且声明后就固定不变，如
array<int> 
array<int, 42> // 42个int元素


8. 如果创建一个容器为另一个容器的拷贝，则两个容器类型必须匹配
如果用迭代器范围来拷贝，则不需要
如vector<int> vec(S.begin(), S.end()) 
S为set<int>类型

9. 顺序容器中还有很多使用的操作函数
c1.swap(c2)：使用交换函数，比从c2向c1拷贝元素快得多
seq.assign(b, e)
将seq中的容器替换为迭代器b和e所表示的范围中的元素

10. 将元素插入到vecot，string，deque的任何位置都是合法的，但是可能很耗时
insert返回插入的元素的位置

vector和string的insert和earse不仅有迭代器版本，还有下标类型版本

11. emplace_back()，emplace(), emplace_front()会在容器管理的内存空间中直接创建对象
而调用push_back()则会创建一个临时对象
所以emplace_back效率较高

12. 所有的顺序容器都有front()和back()，forward_list（单向链表)不支持back()

13. 检查下标是否合法可以用at函数，如果传入的下标越界，则会抛一个out_of_range异常

14. erase()函数可以删除指定迭代器位置的数，也可以删除一对范围内的数
但是erase掉后应该将迭代器设置为删除元素之后的元素（即erase的返回值）

15. 由于通过迭代器向容器中添加元素和删除元素的代码可能使迭代器失效，所以必须保证每次改变容器的操作后都正确地重定位迭代器

16. 不要保存end()返回地迭代器，因为容器操作会使得迭代器失效

17. vector的size是容器中实际元素的个数，capacity是实际分配到的内存空间，会动态增长

18. string的substr函数只能使用下标，如果要用迭代器，则可以用传迭代器给一个新的string对象
```C++
string s = "asdasf";
a = string{s.begin(), s.begin() + 2};
```

19. string的各函数如果传的是迭代器，则insert的函数或者earse的范围也都应传迭代器
如果传的是下标，则可以直接传字符串

20. to_string() 将任意类型数据转换为string
stod() stoi() stof() stol等等，将string转换为对double, int, float, long等数据

21. 容器适配器：使得某些事物的行为看起来像另一种事物一样
staclk<int> stk(deq); // 从deq拷贝元素到stk

容器需要有增加和删除元素的能力，因此适配器不能构建在array和forward_list上。

stack适配器只要求push_back, pop_back, back操作，因此可以使用除了array和forward_list以外的任意容器来构造它😎

queue适配器要求back(), front(), push_back(), pop_front()，因此可以构造于list和deque上

priority_queue除了front，push_back()， pop_back()外还需要随机访问能力，因此只能够构造在vector或者deque上，不能基于list

因此适配器规则跟数据结构的特点息息相关🆒

---
#### Chapter 10 泛型
1. 标准库的算法一般传入的是一个迭代器范围

2. 泛型算法运行于迭代器之上，且泛型算法永远不会执行底层容器的操作，因此算法永远不会改变底层容器的大小

3. 只有容器类型运行相关操作时，才能用对应的算法
比如加法算法accumulate，string支持加法，所以可以使用，但const char \*不支持，所以不能使用
又比如比较算法equal，string支持，所以可以判断字符串值是否相等，但const char \*不支持，所以实际上比较的会是字符串的地址而不是字符串值✌

4. 泛型算法本身不检查写操作，所以在使用泛型算法时，要保证容器内部的存储空间是足够的，否则可能发生灾难

```C++
vector<int> vec;
// 灾难：修改vec中10个不存在的元素
fill_n(vec.begin(), 10, 0) 
```

为了解决该问题，引入了inserter插入迭代器（定义在头文件iterator中）
如back_inserter

5. 标准库算法unique
由于标准库算法不能执行容器的操作，所以unique不能真正地使得容器中元素变唯一
unique使得不重复的元素出现在容器的开始部分，返回值是不重复区域的最后一个位置

假如string类型的vector如下。
| fox | jumps | over | quick | red | slow | the | turtle | red | the |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

首先调用sort(a.begin(), a.end())后

| fox | jumps | over | quick | red | red | slow | the | the | turtle |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

再调用unique（a.begin(), a.end()

| fox | jumps | over | quick | red | slow | the | turtle | ??? | ??? |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |

unique函数返回倒数第二个位置的迭代器📕
如果要删除掉重复的元素，则要调用容器的earse
所以完整代码：earse(unique(a.begin(), a.end()), a.end())

6. 标准库算法一般接受函数式的参数，称为谓词(predicate)
谓词函数参数若是一元的，则称为一元谓词，若是二元的，则是二元谓词

7. sort算法不能保证相等大小（这个大小也可以是用户自己定义的谓词函数，比如字符串的长度，如果相同长度的要维持原有顺序则应该用stable_sort）的元素排序后维持原有结果
因此标准库提供了stable_sort算法，保证排序结果是稳定的

8. lambda函数：可以将lambda函数理解为一个未命名的内联函数
适用于只在一两个地方使用的简单操作，经常使用的操作应该定义为一个函数😋
>*[capture list] (param list) -> return type {function body}*

* labmda函数参数 
labmda函数必须指定尾置返回来指定返回类型
也可以忽略参数列表和返回类型，则参数列表未空，返回值由函数内部return
指定。与普通函数不同的是，labmda函数不能有默认参数。
```C++
auto f = [] { return 42; };

auto f = [&]() ->int { return 42; };
```
* 捕获列表
捕获列表声明了lambda函数中可以使用的布局变量
如果没有捕获列表，则只能访问参数中的变量
比如对一个string类型的vector排序后，计算满足size >= sz的元素的数目
```C++
void biggies(vector<string> &words, vector<string>::size_type sz
{
    elimDups(words);
    count_if(words.begin(), words.end(),
        [sz](const string &a){ return a.size() >= sz; );
}
```

如果在lambda函数中要改变局部变量的值，可以使用引用捕获[&sz]
要尽量减少捕获的数据量，且可能的话应该避免捕获指针或引用。🔒

* 隐式捕获
捕获可以采用上面的显式捕获，也可以用隐式捕获的方式
\[&]代表采用捕获引用的方式，[=]代表采用捕获值的方式

* 由于参数列表有多个，所以可以混用显式和隐式捕获
```C++
for_each(words.begin(), words.end(),
    [=, &os](const string &s) { os << s << c; } );
// os对象不能被拷贝，所以只能用引用捕获的方式
```

9. for_each(iterator begin, iterator last, callable)
传入两个参数，位迭代器范围，第三个参数可以是一个调用对象参数
会对输入序列中的每个元素都调用该对象

10. 标准库bind函数，将一个可调用对象绑定到某个对象上，并传一个参数列表
auto *newCallable* = std::bind(callable, *arg_list*);

11. using namespace name_space
这种形式说明来自namespace的所有名字都可以在程序中直接使用

12. 插入迭代器，头文件：itetrator 🙏
* back_inserter() 创建一个使用push_back()的迭代器
* front_inserter() 创建一个使用push_front()的迭代器
* inserter()创建一个使用insert的迭代器。此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器的元素之前。即使我们传递给inserter的位置原来指向第一个元素，只要我们在此元素之前插入一个新元素，此元素就不再是容器的首元素了

```C++
list<int> lst = {1, 2, 3, 4};
list<int> lst2, lst3;

// 每次插入到头部，拷贝完成后，lst包含4 3 2 1
copy(lst.cbegin(), lst.cend(), front_inserter(lst2));

// 虽然一开始是首部元素，但是插入一次后就不是了，所以完成后
// lst3包含1 2 3 4
copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())
```

13. 流迭代器
虽然iostream类型不是容器，但是标准库定义了可以用于这些IO类型对象的迭代器
此种迭代器可以作用于所有的iostream类型对象

istream_iterator和ostream_iterator
下面是一个用istream_iterator从标准输入读取数据，放入vector的例子

```C++
istream_iterator<int> in_iter(cin);

// 空迭代器用来代表结尾
istream_iterator<int> eof

while(in_iter != eof)
{
    vec.emplace_back(*in_iter++);
}
```

用流迭代器有什么好处？可以将程序重写成以下形式。
```C++
istream_iterator<int> in_iter(cin), eof;

// 可以直接用流迭代器从输入流来初始化一个vector！
vector<int>(in_iter, eof);

// 也可以在算法中操作流迭代器
cout << accumulate(in_iter, eof, 0) << endl;
```

注意，istream_iterator默认属于InputIterator，只提供了++, \*, !=等操作
如果是sort就不能传流迭代器，因为sort中partition操作要求随机访问，所以需要的是RandomAccessIterator

定义流迭代器的根本目的是为了适配标准算法，用的好根本就不需要显式的输入输出操作👍
见习题10.30（但是这种实现存在的问题就是会占用额外空间，而且慢，并不是很推荐）

@attention 流迭代器只有递增运算符，没有递减运算符

14. 反向迭代器
反向迭代器会反过来处理容器，且反向迭代器只能反着移动
如果我们希望打印一个逗号分割的单词列表"one, two, three"中的最后一个单词
```C++
// 找到倒数第一个逗号的位置
auto rcomma = find(line.crbegin(), line.crend(), ',');

// 该代码输出结果位eerht，错误
cout << string(line.crbegin(), rcomma);
```
反向迭代器会反向处理string，此外不能直接写
```C++
// 错误，反向迭代器只能反向（即向左）移动，而rcomma在crbegin左边
cout << string(rcomma, line.crbegin();
```
正确的处理方式是将rcomma转换为正常的迭代器。
```C++
// 正确，反向迭代器的base()方法即对应的正向迭代器
cout << string(rcomma.base(), line.cend())
```

为了保证正常的左闭右合区间特性，所以rcomma和rcomma.base()必须生成相邻位置而不是相同位置，一般base在rcomma的右边.