#include "dig_into_vfptr_test1.h"
#include "dig_into_vfptr_test2.h"

int main()
{
    /**
     *  @note if show is not a virtual function, then print two lines "A show!
     *  beacause pointer p is a A type, and the function array, which
     *  A's vfptr points to, has no member
     */
    B b;
    C c;
    A *p = nullptr;
    p = &b;
    p->show();
    p = &c;
    p->show();

    /**
     *  @note if show is a virtual function in base class
     *  then polymorphism occured
     */
    B_B b_b;
    C_C c_c;
    A_A *q = nullptr;
    q = &b_b;
    q->show();
    q = &c_c;
    q->show();

    /**
     *  @note compare class with non-virtual and virtual function
     *  the rusult is 1 and 8, the remnant is a vfptr pointer
     */
    printf("size of A without virtual: %d\n", sizeof(A));
    printf("size of A_A with virtual: %d\n", sizeof(A_A));

    /**
     *  @note transform address of B into an int pointer
     *  vfptr starts from address 0
     *  then *ptr denotes the address of the first virtual function in the vfptr
     *  then we can call the function pointer explicitly
     */
    using PFun = void (*)(); // PFun is a function pointer, equal to typedef void(*PFun)();
    // cast to a two-dimension pointer that points to the function pointer
    // but why one-dimension pointer array segmentaton fault?
    // PFun *vfptr = reinterpret_cast<PFun *>(&b_b);
    PFun **vfptr = reinterpret_cast<PFun **>(&b_b);
    vfptr[0][0](); // B show
    vfptr[0][1](); // B show2

    using FPointer = void(*)();
    FPointer **table = reinterpret_cast<FPointer **>(&c_c);
    table[0][0]();

    return 0;
}