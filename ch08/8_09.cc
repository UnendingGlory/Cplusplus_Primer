#include <iostream>
#include <string>
#include <sstream>
using std::istream;
using std::string;
using std::cout;

istream &read(istream &is)
{
    string buf;
    while(is >> buf)
    {
        cout << buf << '\n';
    }
    is.clear();
    return is;
}

int main()
{
    // 可以用String初始化一个sstream对象
    std::istringstream strStream("My name is Wilson.");
    read(strStream);
    return 0;
}