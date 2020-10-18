#### Chapter 12 动态内存
1. static对象在第一次使用前分配，在程序结束时销毁。

除了自动和static对象外，C++支持动态分配，动态分配的对象只有当显式地被释放时，这些对象才会销毁。

2. 静态内存用来保存局部static对象，类static数据成员以及定义在任何函数以外的变量。

栈内存用来保存定义在函数内的非static对象。分配在静态或者栈内存中的对象由编译器自动创建和销毁。

堆内存用来保存动态对象。动态对象的生存期由程序来控制，也就是说我们的代码必须显式地销毁它们。

3. shared_ptr允许多个指针指向同一个对象；unique_ptr则“独占”所指向的对象

weak_ptr的伴随类，是一种弱引用

4. 解引用一个智能指针返回它指向的对象。

```C++
shared_ptr<string> p1;

// p1->empty()判断p1是否为空。如果p1指向一个空string，解引用p1并将一个新值赋值string
if(p1 && p1->empty()) *p1 = "hi";
```

5. shared_ptr和unique_ptr支持的操作：p.get() 返回p中保存的指针。要小心使用，若智能指针释放了对象，返回的指针指向的对象就消失了

6. shared_ptr独有的操作：
* p.unique()：判断是否只有一个指针
* p.use_count()：返回与p共享对象的指针数量

7. 最安全的分配和使用动态内存的方法：标准库函数make_shared()✍，头文件：memory

此函数在动态内存中分配一个对象并初始化它，初始化的对象与指针的类型必须相同。

```C++
// 指向一个值为42的int的shared_ptr
shared_ptr<int> p3 = make_shared<int>(42);
// 通常用auto定义一个对象来保存make_shared的结果
// p6指向一个动态分配的空vecotr<string>
auto p6 = make_shared<vector<string>>()
```
8. 每个shared_ptr都有一个关联计数器称为引用计数，一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象。

释放操作是调用shared_ptr类的析构函数完成的，析构函数释放对象获得的资源。

9. 程序使用动态内存出于以下三种原因：
* 程序不知道自己需要使用多少对象
* 程序不知道对象的准确类型
* **程序需要在多个对象间共享数据** 📆

容器类是出于第一种原因而使用动态内存的类型例子

10. 一个const对象不能调用非const成员

11. 显式分配动态内存的一个基本问题是可能有多个指针指向相同的内存。

在delete内存之后重置指针的方法只对这个指针有效，对其他任何指针是无效的。

所以这也是为什么推荐使用智能指针而不是显式分配的指针。

12. 智能指针类型定义了一个名为get的函数，返回一个内置指针。

但需要注意，使用get返回的指针的代码不能delete该指针。

13. 智能指针使用规范
* 不使用相同的内置指针值初始化多个智能指针
* 不delete get()返回的指针
* 不用一个指针的get()初始化或reset另一个智能指针
* 如果使用 get()返回的指针，记住最后一个对应的智能指针销毁后，该指针就无效了
* 如果使用智能指针管理某个资源，而不是new分配的内存，记得传递一个删除器
```C++
#include <iostream>
#include <memory>
// 定义一个C和C++都使用的网络库
struct destination;              // 表示在连接什么
struct connection;               // 打开连接所需要的信息
connection connect(destination*); // 打开连接
void disconnect(connection);     // 关闭给定的连接
void f(destination &d /* 其他参数 */)
{
    // 获得一个连接，记得使用完后关闭
    connection c = connect(&d);
    // 使用连接
    // 如果在f退出前忘记调用disconnect，就再也无法关闭c了
}
// 如果connection有析构函数，就可以在f结束时用析构函数自动关闭
// 但是由于网络库兼容C，所以没有析构函数
// 所以可以自己手写一个end_connection函数并用智能指针管理
void end_connection(connection *p) {disconnect(*p);}
// 使用智能指针可以正确关闭的版本
void f(destination &d /* 其他参数 */)
{
    connection c = connect(&d);
    // shared_ptr传入一个deleter
    std::shared_ptr<connection> p(&c, end_connection);
    // 当f退出时（即使时由于异常而退出，connection也可以正确关闭）
}
```

14. 一个unique_ptr拥有它所指向的对象。

与shared_ptr不同，某一时刻只能有一个unique_ptr指向一个给定对象。

当一个unique_ptr被销毁，它所指向的对象也会被销毁。

定义unique_ptr时，使用直接初始化，没有make_shared()那样的标准库函数。
```C++
unique_ptr<double> p1;
unique_ptr<int> p2(new int(42));
```

15. 由于一个unique_ptr拥有它所指向的对象，因此unique_ptr不支持普通的拷贝或者赋值操作。在做这些操作前要调用ptr.release()释放掉控制权。

16. 在创建一个unique_ptr时，就可以指定一个deleter，没写则默认调用delete

17. new可以分配并初始化一个动态数组，delete调用析函数构并释放内存空间
所以没有默认构造函数和析构函数的类不能够使用new和delete🔑

而allocator类允许将分配和初始化分离
```C++
int *pia = new int[10]; // 10个未初始化的int
delete []pia;

int *pia2 = new int[10](); // 10个初始值为0的int
string *psa = new string[10]; // 10个空string

// 新标准中允许花括号初始化
int *pia3 = new int[10] {0, 1, 2, 3, 4, 5};
```

18. 使用标准库的allocator类，将内存分配和对象构造分离开来

allocator是一个模板，当一个allocator对象分配内存时，会根据给定的对象类型来确定恰当的内存大小和对齐位置
```C++
allocator<string> alloc; // 可以分配string的allocator对象
auto const p =  alloc.allocate(n); // 分配n个未初始化的string
alloc.deallocate(p, n); //释放从p地址开始的n个string的内存
```

allocate分配的内存时未构造的。我们需要按需再内存中构造对象。
* a.construct(p, args) 调用构造函数
* a.destroy(p) 调用析构函数，注意，必须对每个构造的元素调用destroy来摧毁
```C++
while(q != p)
    alloc.destroy(--q);
```
