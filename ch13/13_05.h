#include <string>
using std::string;

class hasPtr
{
private:
    std::string *ps;
    int i;
public:
    hasPtr(const string &s = string()) : ps(new string(s)), i(0) { }

    // allocate a new dynamic string
    hasPtr(const hasPtr &p) : ps(new string(*p.ps)), i(p.i) {}
    ~hasPtr() = default;
};

hasPtr::~hasPtr()
{
}
