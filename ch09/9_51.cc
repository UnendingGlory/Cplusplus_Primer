#include <iostream>
#include <string>

using std::string;

class Date
{
    private:
        unsigned year, month, day;
    public:
        Date() = default;
        Date(const string& date);
};

Date::Date(const string& date)
{
    
}