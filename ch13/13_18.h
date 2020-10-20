#ifndef CH_13_18_H
#define CH_13_18_H
#include <iostream>
#include <string>
using std::string;

class Employee
{
public:
    Employee(){ id = ini_id++; };
    Employee(const string& s){ id = ini_id++; }
    // cannot define a copy constructor cause employee can't copy in real world
    Employee(const Employee&) = delete;

private:
    string name;
    size_t id;
    static size_t ini_id;
};

size_t Employee::ini_id = 0;
#endif