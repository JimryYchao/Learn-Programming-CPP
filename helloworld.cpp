#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>
#include <cassert>
#include <bitset>
#include <initializer_list>
using namespace std;

class Base
{
public:
    virtual void Foo() = 0;
    virtual ~Base() = 0;
};

int main()
{
}

class S
{
public:
    void foo() {}
    void foo(int, ...) {}   // 可变参数区分
    void foo(int, float) {} // 参数数目区分

    // 参数类别区分
    // void foo(int) {}
    void foo(long) {}
    void foo(int &) {} // 调用 int a; foo(a) 无法区分 foo(int) 与 foo(int&)
    void foo(const int &) {}
    __inline void foo(volatile int &) {}
    __forceinline void foo(int &&) {} // 调用 foo(10) 无法区分 foo(int) 与 foo(int&&)
    void foo(const int &&) {}
    void foo(volatile int &&) {}

    // cv 限定区分
    void foo(int) const {}
    void foo(int) volatile {}

    // ref 限定区分
    // 仅通过引用限定进行区分的重载需要全部都具有引用限定或都不具有
    void foo(float) & {}
    void foo(float) && {}
    void foo(float) const & {}
    void foo(float) const && {}
    void foo(float) volatile & {}
    void foo(float) volatile && {}

    // 可以通过编译，但无法通过函数决策
    void foo(auto) {}
    template <typename T>
    auto foo(T t) { return t; } // 与 auto foo(auto) 无法区分
    template <typename T>
    auto foo(T t) -> decltype(t) { return t; }
    template <typename T>
    decltype(auto) foo(T t) { return t; }
};
