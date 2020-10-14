#### Chapter 11 关联容器

1. 向map中insert或者emplace时，新值不会覆盖旧值，已经存在该键，则什么都不做

用下标访问时，新值才会覆盖旧值

而multimap则不一样，由于multimap同值的键不唯一，因此插入操作总是会有效。

2. 对于有序容器，map,multimap,set以及multiset，关键字必须定义元素比较的方法

更详细地说，是要定义一个严格弱序地比较方法

可以在类内部提供，也可以显式地提供一个谓词函数

```C++
// 显式地提供一个函数
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);
```

3. 通常不对关联容器使用泛型算法。关键字是const这一特性意味着不能将关联容器传递给修改或者重排元素的算法。

一般会使用关联容器自己专用的算法。

4. insert和emplace的返回值：返回一个pair

其中，pair的first成员是一个迭代器，指向具有给定关键字的元素。

second成员是一个bool值，指出元素是插入成功还是已经存在于容器中。

5. 关联容器的删除操作

* c.earse(k)： 从c中删除**每个**关键字为k的元素。返回一个size_type值，指出删除的元素的数量🌑
* c.earse(p)：从c中删除迭代器p指定的元素。返回一个指向p之后元素的迭代器。
* c.erase(b, e)：删除迭代器对b和e所表示范围中的元素。返回e。

6. 对一个map进行下标操作，如果关键字不在容器中，则会添加一个具有此关键字的元素到map中

对一个map进行下标操作，得到的是mapped_type对象（即map的值）

但当解引用一个map迭代器时，会得到一个value_type对象（即一个键值对）

7. multiset和multimap中，如果有多个元素具有给定关键字，则这些元素在容器中会相邻存储。

8. 无序的关联容器不是使用比较远算符来组织元素，而是使用一个hash function和关键字类型的==运算符

关键字类型的元素没有明显的序的情况下，无序容器是非常有用的。

使用无序容器通常更为简单（通常也会有更好的性能）。🚘

9. 无序容器在存储上组织为一组桶，每个桶可以保存多个元素。（bucket）

当一个桶保存多个元素的时候，需要顺序搜索这些元素来查找到我们想要的那一个。

计算一个函数的哈希值和在桶中搜索通常都是很快的操作。

但是，如果一个桶中保存了很多元素，bane查找一个特定元素就要大量比较操作。（就像处理哈希冲突中的**拉链**法）

10. 无序容器对于自定义类型的要求

默认情况下，无序容器使用关键字类型的==运算符来比较元素。 还使用一个hash<key_type>类型的对象来生成每个元素的hash值。

如果我们对无序容器传自定义类型，则必须提供自己的hash模板版本以及对应的==函数

```C++
size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
}

bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

using SD_multiset = unordered_multiset<Sales_data, decltype(hasher)*, decltype(eqOp)*>

// 参数是桶大小、哈希函数指针和相等性判断运算符指针
SD_multiset bookstore(42, hasher, eqOp);
```

如果类自身定义了==运算符，可以只重载哈希函数。