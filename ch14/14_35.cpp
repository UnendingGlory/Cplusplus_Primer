#include "14_35.h"
#include <vector>
#include <algorithm>
using std::vector;

int main()
{
    PrintString printer;
    string s = "Hello world";
    printer(s); // 函数调用运算符，在cout中打印s，后面接一个空格
    // 在cerr中都要弄s，后面跟一个换行
    PrintString erros(std::cerr, '\n');
    vector<string> vec{"Hello", "little", "baby"};
    // 用构造函数声明一个对象，再调用函数调用运算符
    std::for_each(vec.begin(), vec.end(), PrintString(std::cerr, '\n'));
    return 0;
}