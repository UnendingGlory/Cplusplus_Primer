#ifndef CH7_15_H
#define CH7_15_H

#include <string>
using std::string;

class Person
{
    Person() = default;
    Person(const string name, const string address):name(name), address(address);

    string get_name() const{ return name; }
    string get_address() const{ return address; }

private:
    string name;
    string address;

};

#endif