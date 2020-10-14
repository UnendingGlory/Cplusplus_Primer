// Write a program to concatenate two string literals,
// putting the rusult in a dynamic array of char
// Write a program to concatenate two library strings

#include <iostream>
#include <string>
#include <string.h>

using std::string; using std::cout;

int main()
{
    // string_lt is null now
    char *string_lt = new char[strlen("hello ""world") + 1];
    strcat(string_lt, "hello");
    strcat(string_lt, "world");
    cout << string_lt << '\n';
    delete []string_lt; // don't forget to delete
    string str1("hello"), str2("world");
    cout << str1 + str2 << '\n';
    return 0;
}