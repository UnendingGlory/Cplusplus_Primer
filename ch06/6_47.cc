#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::vector;
/*
 * 如果define了NDEBUG则什么也不输出
 * 可以这样define，也可以在编译时加-D参数
 * g++ -D NDEBUG 6_47.cc -o 6_47
 */
// #define NDEBUG

// print vector by recursion
void recur(const vector<int> &s, decltype(s.size()) index)
{
    if(index == s.size()) return;
    // 自己的编译调试代码，如果没有定义NDEBUG，则输出相关信息
    #ifndef NDEBUG
        cout << __FILE__ << " " << __func__ << " " << __TIME__ << " "\
            <<s[index] << '\n';
    #endif
    recur(s, index + 1);
}

int main()
{
    vector<int> test{1, 2, 3, 4};
    recur(test, 0);
    return 0;
}