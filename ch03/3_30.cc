#include <iostream>

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for(size_t ix = 0; ix < array_size; ++ix)
    {
        ia[ix] = ix;
        // colored print, background color: default, foreground color:blue
        printf("\033[1;;34m%d\n\033[0m", ia[ix]);
    }
    return 0;
}