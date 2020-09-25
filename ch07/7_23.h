#ifndef CH7_23_H
#define CH7_23_H

#include <string>
#include <iostream>
using std::ostream;

class Screen
{
    public:
        using pos = std::string::size_type;

        Screen() = default;
        // 用c填满contents
        Screen(pos ht, pos wd, char c):height(ht), width(wd), 
            contents(ht * wd, c) {}

        char get() const
        {
            ++acc_str; // 追踪get成员函数被调用了多少次
            return contents[cursor];
        }

        char get(pos , pos)const;

        Screen &set(char);
        Screen &set(pos, pos, char);
        Screen &move(pos r, pos c);
        Screen &display(ostream &os){ do_display(os); return *this;}
        const Screen &display(ostream &os)const
        {
            do_display(os);
            return *this;
        }

    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        mutable size_t acc_str;
        std::string contents;
        void do_display(ostream &os)const {os << contents;}
};

inline char Screen::get(pos lr, pos c)const
{
    pos row = lr * width;
    return contents[row + c];
}

// 设定指定位置的新值
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

// 最好只在类外部的地方说明inline，设置光标当前所在新值
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

// 设置某一个位置为新值
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

#endif