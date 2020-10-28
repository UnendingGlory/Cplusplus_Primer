#ifndef VFPTR2_H
#define VFPTR2_H
#include <iostream>

class A_A{
public:
    virtual void show() const { printf("A show!\n"); }
};

class B_B : public A_A{
public:
    void show() const override { printf("B show!\n"); }
    virtual void show2() { printf("B show2!\n"); }
};

class C_C : public A_A{
public:
    void show() const override { printf("C show!\n"); }
};


#endif