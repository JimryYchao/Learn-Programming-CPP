## Microsoft C++ 补充说明


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