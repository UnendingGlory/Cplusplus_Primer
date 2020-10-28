#ifndef VFPTR1_H
#define VFPTR1_H
#include <iostream>

class A{
public:
    void show() const { printf("A show!\n"); }
};

class B : public A{
public:
    void show() const { printf("B show!\n"); }
};

class C : public A{
public:
    void show() const { printf("C show!\n"); }
};


#endif