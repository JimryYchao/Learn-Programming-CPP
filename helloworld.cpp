#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>
#include <cassert>
#include <bitset>
using namespace std;

template <typename T>
auto Show(T t)
{
    // if (std::is_pointer_v<T>) // Show(a) results in compiler error for return *t. Show(b) results in compiler error for return t.
    if constexpr (std::is_pointer_v<T>) // This statement goes away for Show(a)
        return *t;
    else
        return t;
}

int main()
{

    for (int a = 1, b = 10; a < b; a++, b--, cout << a * b << '\n')
    {
        int v = a*b;
    };
}
