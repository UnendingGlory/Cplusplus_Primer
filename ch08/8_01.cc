#include <iostream>
#include <string>
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
    read(std::cin);
    return 0;
}