#ifndef CH_14_35_H
#define CH_14_35_H

/**
 * @brief 默认情况下类将会把内容写入到cout中，每个string用空格隔开
 */

#include <iostream>
using std::ostream;
using std::cout;

#include <string>
using std::string;

class PrintString{
public:
    PrintString(ostream &o = cout, char c = ' ') : os(o), sep(c) {}
    void operator()(const string &s) const { os << s << sep; }

private:
    ostream &os;
    char sep;
};

#endif