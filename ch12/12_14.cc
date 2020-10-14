#include <iostream>
#include <memory>

// 定义一个C和C++都使用的网络库
struct destination;              // 表示在连接什么
struct connection;               // 打开连接所需要的信息
connection connect(destination*); // 打开连接
void disconnect(connection);     // 关闭给定的连接

void f(destination &d /* 其他参数 */)
{
    // 获得一个连接，记得使用完后关闭
    connection c = connect(&d);
    // 使用连接
    // 如果在f退出前忘记调用disconnect，就再也无法关闭c了
}

// 如果connection有析构函数，就可以在f结束时用析构函数自动关闭
// 但是由于网络库兼容C，所以没有析构函数
// 所以可以自己手写一个end_connection函数并用智能指针管理
void end_connection(connection *p) {disconnect(*p);}

// 使用智能指针可以正确关闭的版本
void f(destination &d /* 其他参数 */)
{
    connection c = connect(&d);
    // shared_ptr传入一个deleter
    std::shared_ptr<connection> p(&c, end_connection);
    // 当f退出时（即使时由于异常而退出，connection也可以正确关闭）
}

// lambda函数版本
void f(destination &d)
{
    connection c = connect(&d);
    // 传地址
    std::shared_ptr<connection> p(&c, [](connection *p){ disconnect(*p); }
}