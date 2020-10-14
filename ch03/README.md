### Chapter 3 字符串，向量和数组
1. 有符号数和无符号数一起操作，则有符号数会自动转换为无符号数

2. string类型取下标，其实属接受的输入参数是string::size_type类型，而不是常用的int类型，只不过int类型会转换成该类型
3. 用emplace_back()代替push_back()
4. vector类型的下标是vector<type>::size_type类型，所以取下标操作其实是对应类型的size_type
5. 迭代器和！=适用于所有容器类型
6. cbegin()和cend()代表const begin和const end，不能通过该迭代器修改对应信息
7. 使用数组下标时，通常使用size_t类型，**基本所有下标都是无符号整数类型（除了map）**