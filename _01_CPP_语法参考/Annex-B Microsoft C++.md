## 特定于 Microsoft C++ 的补充说明


---
### 词法补充

#### Keywords

| keyword                   | description |
| :------------------------ | :---------- |
| `__alignof`              |
| `__asm`                  |
| `__assume`               |
| `__based`                |
| `__cdecl`                |
| `__declspec`             |
| `__event`                 |
| `__except`               |
| `__fastcall`             |
| `__finally`              |
| `__forceinline`          |
| `__hook`                 |
| `__if_exists`             |
| `__if_not_exists`         |
| `__inline`               |
| `__int16`                |
| `__int32`                |
| `__int64`                |
| `__int8`                 |
| `__interface`             |
| `__leave`                |
| `__m128`                  |
| `__m128d`                 |
| `__m128i`                 |
| `__m64`                   |
| `__multiple_inheritance` |
| `__ptr32`                |
| `__ptr64`                |
| `__raise`                 |
| `__restrict`             |
| `__single_inheritance`   |
| `__sptr`                 |
| `__stdcall`              |
| `__super`                 |
| `__thiscall`              |
| `__unaligned`            |
| `__unhook`               |
| `__uptr`                 |
| `__uuidof`               |
| `__vectorcall`           |
| `__virtual_inheritance`  |
| `__w64`                  |
| `__wchar_t`               |


>---
#### `__declspec` 扩展属性中的上下文关键字

| keyword               | description |
| :-------------------- | :---------- |
| `align`               |
| `allocate`            |
| `allocator`           |
| `appdomain`           |
| `code_seg`            |
| `deprecated`          |
| `dllexport`           |
| `dllimport`           |
| `jitintrinsic`        |
| `naked`               |
| `noalias`             |
| `noinline`            |
| `noreturn`            |
| `no_sanitize_address` |
| `nothrow`             |
| `novtable`            |
| `process`             |
| `property`            |
| `restrict`            |
| `safebuffers`         |
| `selectany`           |
| `spectre`             |
| `thread`              |
| `uuid`                |

>---
#### C++/CLI 和 C++/CX 关键字

| keyword             | description |
| :------------------ | :---------- |
| `__abstract`       |
| `__box`            |
| `__delegate`       |
| `__gcf`             |
| `__nogc`           |
| `__pin`            |
| `__property`       |
| `__sealed`         |
| `__try_cast`       |
| `__value`          |
| `__noop`            |
| `__identifier`      |
| `abstract`         |
| `array`            |
| `delegate`         |
| `event`            |
| `gcnew`            |
| `generic`          |
| `interface class`  |
| `interface struct` |
| `interior_ptr`     |
| `literal`          |
| `new`              |
| `property`         |
| `sealed`           |
| `value class`      |
| `value struct`     |
| `as_friend`         |
| `enum class`        |
| `enum struct`       |
| `finally`           |
| `for each in`       |
| `initonly`          |
| `ref class`         |
| `ref struct`        |
| `safecast`          |
| `typeid`            |


---
### Main

支持的 `main` 签名有：

```c++
int main();   
int main(int argc, char *argv[]);
int wmain();
int wmain(int argc, wchar_t *argv[]);
```

以可以是无返回值的：

```c++
void main();
void main(int argc, char *argv[]);
void wmain();
void wmain(int argc, wchar_t *argv[]);
```

>---
#### envp 命令行参数

支持 `envp` 命令行参数，以允许 Microsoft 特定扩展访问环境变量。`envp` 参数是表示用户环境中设置的变量的字符串数组。

```c++
int main(int argc, char* argv[], char* envp[]);
int wmain(int argc, wchar_t* argv[], wchar_t* envp[]);
```

传递给 `main` 和 `wmain` 的环境块是当前环境的 “冻结” 副本。 如果随后通过调用 `putenv` 或 `_wputenv` 来更改环境，则当前环境（由 `getenv` 或 `_wgetenv` 以及 `_environ` 或 `_wenviron` 变量返回）将发生更改。

```c++
// argument_definitions.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>

using namespace std;
int main( int argc, char *argv[], char *envp[] )
{
    bool numberLines = false;    // Default is no line numbers.

    // If /n is passed to the .exe, display numbered listing
    // of environment variables.
    if ( (argc == 2) && _stricmp( argv[1], "/n" ) == 0 )
         numberLines = true;

    // Walk through list of strings until a NULL is encountered.
    for ( int i = 0; envp[i] != NULL; ++i )
    {
        if ( numberLines )
            cout << i << ": "; // Prefix with numbers if /n specified
        cout << envp[i] << "\n";
    }
}
```

---
### 内置类型

特定于 Microsoft：`char` 类型的变量将提升到 `int`；

特定于 Microsoft：`wchar_t` 是原生类型。`__wchar_t` 类型是本机 `wchar_t` 类型的 Microsoft 专用同义词。

特定于 Microsoft：`long double` 和 `double` 的表示形式完全相同。

特定于 Microsoft：整数类型包括特定宽度的 `__int8`、`__int16`、`__int32` 和 `__int64` 类型。`__int8` 与 `char` 同义，`__int16` 与 `short` 同义，`__int32` 与 `int` 同义，`__int64` 与 `long long` 同义。

Microsoft 专用：`__ptr32` 表示 32 位系统中的本机指针，而 `__ptr64` 表示 64 位系统中的本机指针。在 32 位系统中，`__ptr64` 截断为 32 位。在 64 位系统中，`__ptr32` 强制转换为 64 位。

```c++
#include <cstdlib>
#include <iostream>

int main()
{
    using namespace std;

    int * __ptr32 p32;
    int * __ptr64 p64;

    p32 = (int * __ptr32)malloc(4);
    *p32 = 32;
    cout << *p32 << endl;

    p64 = (int * __ptr64)malloc(4);
    *p64 = 64;
    cout << *p64 << endl;
}
```

---
### 属性

在某些情况下，标准属性与编译器特定的 `__declspec` 参数重叠。在 Microsoft C++ 中，可以使用 `[[deprecated]]` 属性而不使用 `__declspec(deprecated)`。`[[deprecated]]` 属性可由任何符合标准的编译器识别。

对于所有其他 `__declspec` 参数（例如 `dllimport` 和 `dllexport`），到目前为止还没有等效的属性，因此必须继续使用 `__declspec` 语法。属性不影响类型系统，也不会改变程序的含义。编译器会忽略它们无法识别的属性值。

在属性列表的范围内，可以使用单个 `using` 引入器为所有名称指定命名空间：

```c++
void g() {
    [[using rpr: kernel, target(cpu,gpu)]] 
    // equivalent to [[ rpr::kernel, rpr::target(cpu,gpu) ]]
    do task();
}
```

>---
#### MS 特定属性

`[[gsl::suppress(rules)]]` 用于抑制在代码中强制实施准则支持库 (GSL) 规则的检查器发出的警告。使用安装并激活的 CppCoreCheck 代码分析工具编译此代码时，会触发前两个警告。
- C26494（类型规则 5：始终初始化对象。）
- C26485（边界规则 3：没有指针衰减的数组。）
- C26481（边界规则 1：不要使用指针算术。请改用范围。）

```c++
int main()
{
    int arr[10]; // GSL warning C26494 will be fired
    int* p = arr; // GSL warning C26485 will be fired
    [[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
    {
        int* q = p + 1; // GSL warning C26481 suppressed
        p = q--; // GSL warning C26481 suppressed
    }
}
```

`[[msvc::forceinline_calls]]` 放置在语句或块之上或之前。 它会导致内联启发式尝试 `[[msvc::forceinline]]` 该语句或块中的所有调用：

```c++
void f() {
    [[msvc::forceinline_calls]]
    {
        foo();
        bar();
    }
    ...
    [[msvc::forceinline_calls]]
    bar();
    foo();
    // 对 foo 的第一次调用以及对 bar 的两次调用都被视为声明为 __forceinline。 
    // 对 foo 的第二次调用不会被视为 __forceinline。
}
```

`[[msvc::forceinline]]` 当放置在函数声明之前时，`[[msvc::forceinline]]` 与 `__forceinline` 具有相同的含义。

`[[msvc::flatten]]`  与 `[[msvc::forceinline_calls]]` 非常相似，并且可以在相同位置以相同方式使用。 不同之处在于，`[[msvc::flatten]]` 会递归地 `[[msvc::forceinline_calls]]` 其应用范围内的所有调用，直到没有调用为止。 

[[msvc::intrinsic]] 属性告知编译器内联一个元函数，该元函数充当从参数类型到返回类型的命名转换。当该属性出现在函数定义中时，编译器会用简单的强制转换替换对该函数的所有调用。`[[msvc::intrinsic]]` 对其应用到的函数有三个约束：
- 该函数不能具有递归性；它的主体必须只有一个 `return` 语句，该语句带有从参数类型到返回类型的 `static_cast`。
- 该函数只能接受单个参数。
- `/permissive-` 编译器选项是必需的。 

```c++
// 应用于 my_move 函数的 [[msvc::intrinsic]] 属性使编译器将该函数的调用替换为其主体中的内联静态强制转换
template <typename T>
[[msvc::intrinsic]] T&& my_move(T&& t) { return static_cast<T&&>(t); }

void f() {
    int i = 0;
    i = my_move(i);
}  
```

`[[msvc::noinline]]` 当放置在函数声明之前时，与 `declspec(noinline)` 具有相同的含义。

`[[msvc::noinline_calls]]` 的用法与 `[[msvc::forceinline_calls]]` 相同。它可以放置在任何语句或块之前。它不是强制内联该块中的所有调用，而是对应用到的范围禁用内联。

`[[msvc::no_tls_guard]]` 禁止在首次访问 DLL 中的线程局部变量时检查初始化。仅适用于其后面的特定变量。若要全局禁用检查，请使用 `/Zc:tlsGuards-` 编译器选项。

---
### 运算符与表达式

#### safe_cast

`safe_cast` 在 C++/CLI 中用于生成可验证的 MSIL。



---
### 语句

#### __if_exists, __if_not_exists 

```c++
__if_exists ( identifier ) {
statements
};

__if_not_exists ( identifier ) {
statements
};
```

`_if_exists` 语句测试指定的标识符是否存在。如果该标识符存在，则执行指定的语句块。

`__if_not_exists` 语句测试指定的标识符是否存在。如果该标识符不存在，则执行指定的语句块。

只将 `__if_exists` 和 `__if_not_exists` 语句应用于简单类型；将语句应用于类的内部或外部的标识符。不要应用于局部变量。仅在函数的主体中使用，在外部，语句仅能测试完全定义的类型。在测试重载函数时，不能测试特定形式的重载。

`__if_exists` 语句的补集是 `__if_not_exists` 语句

```c++
class C {
public:
    void f(int);
    void f(double);
};

int main() {
    __if_not_exists(::g_bFlag) {
        std::cout << "g_bFlag not exists" << std::endl;
    }
    __if_exists(C::f) {
        std::cout << "C::f exists" << std::endl;
    }
}
// g_bFlag not exists
// C::f exists
```