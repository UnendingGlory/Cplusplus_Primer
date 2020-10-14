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

也可以忽略参数列表和返回类型，则参数列表未空，返回值由函数内部return指定。

与普通函数不同的是，labmda函数不能有默认参数。

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

inserter是一种迭代器适配器。

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

![反向迭代器](../assets/ch10.png)

15. 迭代器分类
* input iterator

可以读取序列中的元素, 支持比较运算符,递增运算符,解引用运算符

如istream_iterator就是一种input iterator

find()和accumulate()要求input iterator

* output iterator

只写而不读元素,支持递增运算符,解引用运算符(但是只能出现在赋值运算符左侧)

ostream_iterator就是一种output iterator

copy()第三个参数是output iterator

* forward iterator

可以读写元素,但是只能朝一个方向移动。

前向迭代器支持所有input和output iterater的操作

forward_list的迭代器就是forward iterator

* bidirectional iterator

可以正向/反向读写序列中的元素，支持递减运算符

* random-access iterator

支持在常量时间内访问序列中任意序列的能力，支持双向迭代器所有功能且支持下标

sort()要求random-access iterator

array, deque, string, vector上的迭代器都是random-access iterator
