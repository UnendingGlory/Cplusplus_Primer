#include "7_06.h"
using std::cin;
using std::cout;

/* input : 123 4 5
 *         234 5 6
 * output: 123 4 20
 *         234 5 30
 */
int main()
{
    Sales_data data1, data2;
    // 返回左值引用的好处，可以无限调用自己
    read(read(cin, data1), data2);

    // 每一个输出后接一个换行
    print(cout, data1) << '\n';
    print(cout, data2) << '\n';
    return 0;
}