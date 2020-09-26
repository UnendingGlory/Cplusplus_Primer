#include "7_23.h"
using std::cout;

int main()
{
    Screen myScreen(5, 5, 'X');
    // 修改第4行第0列的'X'为'#'
    // 由于返回类型是引用，这么调用才真正修改了myscreen对象
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}