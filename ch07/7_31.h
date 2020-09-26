#ifndef CH7_31_H
#define CH7_31_H

// 前向声明
class Y;

class X
{
    Y *y = nullptr;
};

class Y
{
    X x;
};

#endif