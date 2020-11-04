#### Chapter 17 标准库特殊设施
1. tuple 头文件: #include <tuple>

tuple的成员数目是固定的，但是**类型可以不相同！！！** 😮

```C++
tuple <string, vector<double>, int, list<int>>;

tuple<size_t, size_t, size_t> threeD{1, 2, 3};
```

类似make_pair，有make_tuple函数

```C++
auto item = make_tuple("0001", 3, 20.0);
```

由于tuple中有多个元素，所以访问tuple需要额外的操作。

标准库提供了一个叫做get的函数模板。参数即第几个对象。返回的是成员的引用。

```C++
auto book = get<0>(item);
auto cnt = get<1>(item);
```

tuple一般用于：希望将一些数据组合成单一对象，但又不想麻烦地定义一个新的数据结构。

对于tuple，也可以使用==和！=，但是数量必须相同，且每对成员的比较是合法有意义的

2. bitset 头文件：bitset

使位运算的使用更加容易，并且能够处理超过最长整型类型大小的位集合。

能够使用各种整形数据类型（以及string或者string的字串等）来进行初始化。且可以不受整形长度限制。

函数用法set, reset, flip等函数用时自查。可见习题17_11_12_13.cpp

```C++
bitset<64> bitvec(32); // 10000 不足的高位补0
bitset<32> bitstr("11111110111");
```

可以访问到其中的某一位，使用下标访问即可。注意0是最低位

```C++
bitstr[0]; // 1
bitstr[1]; // 1
bitstr[2]; // 1
bitstr[3]; // 0
```

3. C++ 正则表达式库(regular expression)  头文件 regex

* regex: 正则表达式类
* regex_match 将一个字符序列与一个正则表达式匹配
* regex_search 寻找第一个与正则表达式匹配的子序列
* regex_replace 使用给定格式替换一个正则表达式
* sregex_iterator 迭代器适配器，调用regex_search来遍历一个string中所有匹配的子串
* smatch 容器类 保存在string中的搜索结果

> 默认regex使用的语言是ECMAScript
> [[:alpha:]]] 匹配任意字母，^代表非，+表示一个或多个，\*表示零个或多个
> [^c]* 任意多个非c的字母,  [[:alpha:]]\*表示多个字母

不用sregex_iterator迭代器只要找到一个匹配子串就会停止查找

还有sregex_token_iterator等等...

用时自查。

4. 随机数

程序通常需要一个随机数源。在新标准出现之前，C和C++依赖于一个简单的C库函数rand来生成随机数。该函数生成均匀分布的伪随机数，每个随机数的范围在0和一个系统最大值之间。

然而rand函数局限非常多，没法生成非均匀的数，或者随机浮点数

C++通过随机数引擎和随机数分布类来解决这些问题。 头文件：random

C++程序不应该使用看库函数rand，而应该使用default_random_engine类和恰当的分布对象。

```C++
std::uniform_int_distribution<unsigned> u(0, 9);
std::default_random_engine e;
```

注意：一个给定的随机数发生器会一直生成相同的随机数序列。一个函数如果定义了局部的随机数发生器，应该将其随机数引擎和分布对象定义为static的。（或者给随机数引擎提供不同的种子）

```C++
// 注意，这种方式只适合生成种子间隔为秒级或者更长的应用
default_random_engine e(time(0));
```

其他随机数引擎、随机数分布类等复杂特性用时自查。

5. IO格式化输出与输入

可以控制进制、浮点数精度、对齐格式、补白、浮点数计数法等

endl不是普通值，而是一个操作：它输出一个换行符并刷新缓冲区（因为刷新缓冲区所以一般会比较慢）

6. 标准库同时还提供了一组底层操作，支持未格式化IO。这些操作允许我们将一个流当作一个无解释的字节序列来处理。

7. 意外的是，无参的get版本返回一个int值，应该用int而不是char来记录该值

```C++
int ch;
while( (ch = cin.get()) != EOF)
    cout.put(ch);
```

8. C++支持流中的随机访问，使其可以跳过一些行。

IO输入输出在处理文件时格外有用，用时自查。