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

```C++
array<int> 
array<int, 42> // 42个int元素
```

8. 如果创建一个容器为另一个容器的拷贝，则两个容器类型必须匹配

如果用迭代器范围来拷贝，则不需要

如vector<int> vec(S.begin(), S.end()), S为set<int>类型

9. 顺序容器中还有很多使用的操作函数

c1.swap(c2)：使用交换函数，比从c2向c1拷贝元素快得多

seq.assign(b, e)

将seq中的容器替换为迭代器b和e所表示的范围中的元素

10. 将元素插入到vecot，string，deque的任何位置都是合法的，但是可能很耗时

insert返回插入的元素的位置

vector和string的insert和earse不仅有迭代器版本，还有下标类型版本

11. emplace_back()，emplace(), emplace_front()会在容器管理的内存空间中直接创建对象

而调用push_back()则会创建一个临时对象, 所以emplace_back效率较高

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