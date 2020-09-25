#ifndef CH7_05_H
#define CH7_05_H

#include <string>
using std::string;

class Person
{
    string name;
    string address;
    string get_name() const{ return name; }
    string get_address() const{ return address; }
};

#endif