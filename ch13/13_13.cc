// cleared

#include <iostream>
#include <vector>
using std::cout;

struct X
{
    X() {cout << "X()" << '\n'; }
    X(const X&) { cout << "X(const X&)" << '\n'; }
    X& operator=(const X &p)
    {
        cout << "assign operator" << '\n'; 
        //return p;
    }
    ~X(){ cout << "~X" << '\n'; }   
};

void f(const X &rx, X x) // copy 1
{
    std::vector<X> vec;
    vec.reserve(2);
    // push_back declare a temporary object, calls the copy constructor
    vec.push_back(rx); // copy 2
    // emplace_back also calls the copy constructor
    // instead of creating a temporary object as push_back do,
    // emplace_back directly calls the copy constructor at the end of the container
    vec.emplace_back(x); // copy 3
}

int main()
{
    // may bypass the copy-assignment constructor
    // constructor
    X *px = new X;
    f(*px, *px);
    delete px;
    return 0;
}