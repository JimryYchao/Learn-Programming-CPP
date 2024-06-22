## C++ 程序构建基块

- [ ] [用户定义文本](#用户定义文本-todo)


---
### 词法元素

#### 字符集

C++ 指定可用于源文件的基本源字符集和通用字符集：

```c++
' ', '\t', '\v', '\f', '\n',
a b c d e f g h i j k l m n o p q r s t u v w x y z
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
0 1 2 3 4 5 6 7 8 9
_ { } [ ] # ( ) < > % : ; . ? * + - / ^ & | ~ ! = , \ " '
```

通用字符名称是形如 `\u hhhh` 或 `\U HHHHHHHH` 表示的 Unicode 码位的字符序列。用于标识标识符、字符串或字符文本。

执行字符集表示编译程序中可显示的字符和字符串。这些字符集包含源文件中允许的所有字符，以及表示 `\a`、`\b`、`\r` 和 `\0` 的控制字符。执行字符集具有特定于区域设置的表示形式。

>---
#### 标记

标记有五种：标识符、关键字、文本、运算符和其他分隔符；空白字符包括有空格 ```' '```、水平制表符 ```'\t'```、换行符 ```'\n'```、回车符 ```'\r'```、换页符 ```'\f'``` 和垂直制表符 ```'\v'```。标记由空白符和其他标记分隔（划分边界），在分析代码时，编译器将忽略空白字符。

标识符为程序中的对象、变量、类型、类型成员、函数、类型定义、宏定义、宏参数参数和标签提供名称，名称在拼写和大小写上必须与任何关键字都不同。标识符的首字符不可以是数字字符。

```cpp
/* 有效标识符 */  // 注释
_Identifier
Identifier
Identifier123
```

`final`、`import`、`module`、`override` 保留关键字由 C++ 编译器使用。

>---
#### Keywords

| keyword | description |
| :------ | :---------- |
`alignas`
`alignof`
`asm`
`auto`
`bool`
`break`
`case`
`catch`
`char`
`char8_t`
`char16_t`
`char32_t`
`class`
`concept`
`const`
`consteval`
`constexpr`
`constinit`
`const_cast`
`continue`
`co_await`
`co_return`
`co_yield`
`decltype`
`default`
`delete`
`do`
`double`
`dynamic_cast`
`else`
`enum`
`explicit`
`export`
`extern`
`false`
`float`
`for`
`friend`
`goto`
`if`
`inline`
`int`
`long`
`mutable`
`namespace`
`new`
`noexcept`
`nullptr`
`operator`
`private`
`protected`
`public`
`register`
`reinterpret_cast`
`requires`
`return`
`short`
`signed`
`sizeof`
`static`
`static_assert`
`static_cast`
`struct`
`switch`
`template`
`this`
`thread_local`
`throw`
`true`
`try`
`typedef`
`typeid`
`typename`
`union`
`unsigned`
`using`
`virtual`
`void`
`volatile`
`wchar_t`
`while`


>---
#### Operators & Punctuation

```cpp
{ } [ ] ( )
<: :> <% %> ; : ...
? :: . .* -> ->* ~
! + - * / % ^ & |
= += -= *= /= %= ^= &= |=
== != < > <= >= <=> && ||
<< >> <<= >>= ++ -- ,
and or xor not bitand bitor compl
and_eq or_eq xor_eq not_eq
```

> 替用标志，保留

```cpp
// Alternative/Primary
    <%           {   
    %>           }    
    <:           [    
    :>           ]    
    %:           #    
    %:%:         ##   
    and          &&    
    or           ||  
    not          !  
    xor          ^     
    bitand       &    
    bitor        | 
    compl        ~     
    not_eq       !=  
    xor_eq       ^= 
    and_eq       &= 
    or_eq        |=  
```

>---
#### Number, Boolean, Pointer Literal

文本是一种直接表示值的程序元素。包含由整数、浮点、布尔、指针、字符、字符串类型的文本以及用户定义的文本。

整数文本可以是二进制、八进制、十进制或十六进制的数字序列：

```cpp
long b = 0b1011'0101;      // b-binary
long o = 013245670;        // 0-octal
long i = 1234567890LL;     // decimal
long long h = 0x1234'5678'90ab'cdfLL;  // x-hexadecimal

unsigned ui = 110u;
unsigned long long uh = 0XFFFFULL; //x-hexadecimal
size_t z = -10010z;
ssize_t uz = 10086uz;
```

浮点文本是十进制或十六进制（`0x` or `0X` 前缀）表示的数字序列。*E* 指数表示法（以 10 为基数）用于十进制；*P* 指数表示法（以 2 为基数）用于十六进制。

```c++
float f = 3.1415F;
double d = 3.1415;
long double ld = 3.1415L;
float16_t f16 = 3.1415f16;
float32_t f32 = 3.1415f32;
float64_t d2 = 3.1415f64;
float128_t f64 = 3.1415f128;
bfloat16_t bf16 = 3.1415bf16;  // BF
// decimal
double e1 = 1.234e-2; 
double e2 = 1.234E2;
// hexadecimal
double p1 = 0x1p-2;	  // == 0.25
double p2 = 0x2.p10;  // == 2048.0
```

布尔文本是关键字 `false` 和 `true`。此类文本的类型为 `bool`。

指针文本是关键字 `nullptr`。它的类型为 `std::nullptr_t`。`nullptr` 用来初始化零值指针。



>---
#### Character, String Literal

字符文本表示一个或多个多字节字符的序列。`wchar_t`、`char16_t`、`char32_t` 字符称为宽字符，`char8_t` 和普通字符为窄字符。序列元素是源字符集的任何成员；它们以实现定义的方式映射到执行字符集的成员。

```c++
// Character literals
auto c0 =   'A';  // char; 普通字符
auto c1 = u8'A';  // char; UTF-8
auto c2 =  L'A';  // wchar_t; 宽字符
auto c3 =  u'A';  // char16_t; UTF-16
auto c4 =  U'A';  // char32_t; UTF-32
auto m0 = 'abcd'; // int, value 0x61626364; 多字节

// 八进制、十六进制转义序列和通用字符序列
char u1 = 'A';          // 'A'
char u2 = '\101';       // octal, 'A'; 1-3 位八进制，最大 \377
char u3 = '\x41';       // hexadecimal, 'A'
char u4 = '\u0041';     // \u UCN 'A'
char u5 = '\U00000041'; // \U UCN 'A'

// 转义字符
'\'' '\"' '\?' '\\' '\a' '\b' '\f' '\n' '\r' '\t' '\v'
```

字符串文本的种类、类型及其关联的字符编码由其编码前缀和字符序列决定。常规字符串文本和 UTF-8 字符串文本称为窄字符串文本。

```c++
auto s0 =   "hello"; // const char*
auto s1 = u8"hello"; // const char8_t* 
auto s2 =  L"hello"; // const wchar_t*
auto s3 =  u"hello"; // const char16_t*, encoded as UTF-16
auto s4 =  U"hello"; // const char32_t*, encoded as UTF-32
const char32_t* s5 = U"😎 = \U0001F60E is B-)";
```

前缀中带有 R 的字符串文本是原始字符串文本。`R"delimiter( char-sequence )delimiter"` 中 `delimiter` 最多包含 16 个字符；`R"((a|b))"` 等价于 `"(a|b)"`。

```c++
auto R0 =   R"("Hello \ world")"; // const char*
auto R1 = u8R"("Hello \ world")"; // const char8_t*
auto R2 =  LR"("Hello \ world")"; // const wchar_t*
auto R3 =  uR"("Hello \ world")"; // const char16_t*, encoded as UTF-16
auto R4 =  UR"("Hello \ world")"; // const char32_t*, encoded as UTF-32
```

`s` 后缀表示映射到 `std::string` 类型的静态值。

```c++
auto S0 =   "hello"s; // std::string
auto S1 = u8"hello"s; // std::u8string in C++20
auto S2 =  L"hello"s; // std::wstring
auto S3 =  u"hello"s; // std::u16string
auto S4 =  U"hello"s; // std::u32string

auto S5 =   R"("Hello \ world")"s; // std::string from a raw const char*
auto S6 = u8R"("Hello \ world")"s; // std::u8string from a raw const char* 
auto S7 =  LR"("Hello \ world")"s; // std::wstring from a raw const wchar_t*
auto S8 =  uR"("Hello \ world")"s; // std::u16string from a raw const char16_t*, encoded as UTF-16
auto S9 =  UR"("Hello \ world")"s; // std::u32string from a raw const char32_t*, encoded as UTF-32
```

相邻字符串文本序列的公共编码前缀要么相同，要么其中一个没有编码前缀；任何其他组合都是格式不正确的。计算字符串文本会生成具有静态存储持续时间的字符串文本对象。

```c++
char str[] = "12" "34";  // "1234"
auto hi = u8"hello" " " "world"s;
auto err = U"hello" " " L"world"; // disagree on prefix
```

>---
#### User Defined Literal

用户定义文本可以是整数、浮点数、字符或字符串用户定义，用户定义文本由一个用户定义后缀标识。用户定义文本被视为对文本运算符或文本运算符模板的调用。

```c++
using namespace std;
long double operator""_w(long double);
string operator""_w(const char16_t *, size_t);
unsigned operator""_w(const char *);
int main()
{
	1.2_w;	  // calls operator ""_w(1.2L)
	u"one"_w; // calls operator ""_w(u"one", 3)
	12_w;	  // calls operator ""_w("12")
	"two"_w; // error: no applicable literal operator
}
```

通过以下形式之一在命名空间范围定义 `operator""` 来实现用户定义文本，这些函数都可定义为 `constexpr`：

```c++
ReturnType operator "" _a(unsigned long long int);   // user-defined INTEGRAL literal
ReturnType operator "" _b(long double);              // user-defined FLOATING literal
ReturnType operator "" _c(char);                     // user-defined CHARACTER literal
ReturnType operator "" _d(wchar_t);                  // user-defined CHARACTER literal
ReturnType operator "" _e(char16_t);                 // user-defined CHARACTER literal
ReturnType operator "" _f(char32_t);                 // user-defined CHARACTER literal
ReturnType operator "" _g(const char*, size_t);      // user-defined STRING literal
ReturnType operator "" _h(const wchar_t*, size_t);   // user-defined STRING literal
ReturnType operator "" _i(const char16_t*, size_t);  // user-defined STRING literal
ReturnType operator "" _g(const char32_t*, size_t);  // user-defined STRING literal
ReturnType operator "" _r(const char*);              // Raw literal operator
template<char...> ReturnType operator "" _t();       // Literal operator template
```

---
### 基本概念
#### 翻译阶段

源文件以及通过预处理指令 `#include` 包含的所有头文件和源文件，去掉任何被条件编译 `#if` 跳过的部分，以及由任何条件支持的指令和编译指示的实现定义行为修改，被称为预处理翻译单元。

源文件不需要全部同时翻译，翻译单元和实例化单元可以单独保存或保存在库中，程序的单独翻译单元通过调用具有外部链接或模块链接的函数、对象等的标识符、或操作数据文件进行通信。翻译单元可以单独翻译，然后链接其他单元以生成可执行程序。

在某些情况下，可能需要在 .cpp 文件中声明全局变量或类。 在这些情况下，你需要一种方法来告知编译器和链接器名称所具有的链接类型。 链接的类型指定对象的名称是仅在一个文件中可见，还是在所有文件中可见。 链接的概念仅适用于全局名称。 链接的概念不适用于在一定范围内声明的名称。 范围是由一组封闭的大括号指定的，例如在函数或类的定义中。

1. 字符映射：源文件中的字符将映射到内部源表示形式。
2. 行拼接：以反斜杠 (`\`) 结束且后跟换行符的所有行将与源文件中从物理行形成逻辑行的下一行联接。
3. 令牌化：源文件分为预处理标记和空白字符。 源文件中的注释将逐一替换为空白字符。 换行符将保留。
4. 预处理：执行预处理指令，扩展宏调用，并执行 `_Pragma` 表达式。`#include` 语句按第 1 ~ 4 阶段递归处理。然后删除所有预处理指令。
5. 字符集映射：所有源字符集成员和转义序列将转换为执行字符集中的等效项。
6. 字符串串联：串联相邻的字符串文字令牌。
7. 翻译：将从语法和语义上分析所有令牌；并将它们转换为对象代码。
8. 实例化单元：检查每个翻译的翻译单元，以生成所需实例化的列表。找到所需模板的定义。
9. 链接：解析所有外部引用以创建可执行程序或动态链接库。

>---
#### 程序启动

程序启动需要入口函数 `main`，动态链接库和静态库没有 `main` 函数。程序进入 `main` 函数之前，没有初始值设定项 `static` 类成员零初始化。

```c++
int main(); // 或
int main(int argc, char *argv[]);
```

`argc` 和 `argv` 的类型由语言定义。`argc` 包含 `argv` 参数的计数，`argv` 至少包含程序名称的 `argv[0]`。`argv[1]` 是第一个命令行参数。 命令行的最后一个参数是 `argv[argc - 1]`，并且 `argv[argc]` 始终为 `NULL`。

```c++
#include <iostream>

using namespace std;
int main( int argc,      // Number of strings in array argv
          char *argv[])   // Array of command-line argument strings
{
    int count;
    // Display each command-line argument.
    cout << "\nCommand-line arguments:\n";
    for( count = 0; count < argc; count++ )
         cout << "  argv[" << count << "]   "
                << argv[count] << "\n";
}
```


>---
#### 程序终止

在 C++ 中，可以通过以下方式退出程序：

- 调用 `exit` 函数，终止程序并执行清理（如调用全局对象析构函数）。
- 调用 `abort` 函数。立即终止程序，跳过 `atexit` 机制。
- 从 `main` 执行 `return` 语句。

```c++
#include <cstdlib>

int main() {
    if (cond1){
        exit(EXIT_SUCCESS);  // or EXIT_FAILURE 
    }else if (cond2) {
        abort();
    }else 
        return 0;
}
```

`atexit` 用于在程序终止之前执行的操作，在此之前不会销毁任何初始化的全局静态对象。

使用 `return` 语句可以从 `main` 指定一个返回值，任何自动变量都将被销毁。 然后，`main` 以返回值作为参数调用 `exit`。直接调用 `exit` 不会销毁自动变量。

> 线程和静态对象的销毁

直接调用 `exit` 时（或在 `main` 的 `return` 语句之后调用它时），将销毁与当前线程关联的线程对象。然后按与初始化相反的顺序销毁静态对象（在调用指定给 `atexit` 的函数（如果有）之后）。 

```c++
#include <cstdio>
class ShowData {
public:
	ShowData(const char* szDev) {
		errno_t err;
		err = fopen_s(&OutputDev, szDev, "w");
	}

	~ShowData() { fclose(OutputDev); }
	void Disp(const char* szData) {
		fputs(szData, OutputDev);
	}
private:
	FILE* OutputDev;
};
//  Define a static object of type ShowData. The output device
//   selected is "CON" -- the standard output device.
ShowData sd1 = "CON";
ShowData sd2 = "CON";

int main() {
	sd1.Disp("hello sd1\n");
	sd2.Disp("hello sd2\n");  // 相反顺序销毁并调用 ~ShowData()
}
// hello sd2  
// hello sd1
```

>---
#### 类型系统

标量类型：包含定义范围的单个值的类型。标量包括算术类型（整型或浮点值）、枚举类型成员、指针类型、指针到成员类型以及 std::nullptr_t。基本类型通常是标量类型。

复合类型：复合类型包括数组类型、函数类型、类（或结构）类型、联合类型、枚举、引用和指向非静态类成员的指针。

变量：数据量的符号名称。该名称可用于访问它在整个定义代码范围内引用的数据。变量通常指标量实例，其他类的实例为对象。

对象：表示类或结构的实例。在一般意义上包括所有类型。

POD 类型（纯旧数据）：C++ 中此类非正式数据类型类别是指作为标量的类型或 POD 类。POD 类没有非 POD 的静态数据成员，没有用户定义构造函数、用户定义析构函数或用户定义赋值运算符。POD 类无虚函数、基类、私有或受保护的非静态数据成员。通常用于外部数据交换，例如与用 C 语言编写的模块（仅具有 POD 类型）进行数据交换。

C++ 是强类型的静态类型语言，每个对象都有一个类型。C++ 中不存在派生所有其他类型的通用基类型。C++ 的内置类型包括数值类型（`int`、`double`、`long`、`bool` 以及分别针对 ASCII 和 UNICODE 字符的 `char` 和 `wchar_t` 类型等）。C++ 没有内置字符串类型，它是 C 样式字符串。


任何内置或用户定义类型都可由 `const` 限定。 成员函数可受到 `const` 限定，也可以重载 `const`。`const` 类型的值初始化后无法修改。用户定义类型包含 `class`、`struct`、`union`、`enum`。

在 C++ 中，原始指针变量声明只分配足够的内存来存储地址，不包含存储数据值所需的内存；用户定义类型可以通过 `new` 表达式在堆中动态分配内存，并在必要时由相应的 `delete` 删除（C：`malloc` > `free`）。

>---
#### 范围, 链接和存储期

程序中的声明可以出现在很多范围（*scope*，作用域）中。全局范围包含整个程序。名称可见的上下文称为其目标范围。有六种范围：

- 全局范围：全局名称是在任何类、函数或命名空间之外声明的名称。全局名称的范围从声明点扩展到声明文件末尾。

+ 命名空间范围：在命名空间中声明的名称（在任何类、枚举定义、或函数块之外）从其声明点到命名空间末尾可见。命名空间可以在跨不同文件的多个块中定义。

- 局部范围：在函数或 lambda 中声明的名称（包括参数名称）具有局部范围。局部变量仅从声明点到函数或 lambda 正文的末尾可见。局部范围是一种块范围。

+ 类范围：类成员的名称具有类范围，该范围在整个类定义中扩展，与声明点无关。类成员可访问性由 `public`、`private` 和 `protected` 关键字进一步控制。

- 语句范围：在 `for`、`if`、`while` 或 `switch` 、`case` 语句中声明的名称在语句块结束之前可见。

+ 标签范围：标签具有函数范围，这意味着它在整个函数正文中甚至在声明点之前都是可见的。

一个 *symbol*（例如变量或函数名称）可以在其范围内进行任意次数的声明。但一个符号只能被定义一次（单一定义原则，ODR）。声明在程序中（重新）引入一个名称和足够的类型信息，定义引入一个名称并创建它所需的全部信息。名称表示变量，定义会显式创建存储并进行初始化。函数定义由签名和函数体组成。类定义由类名和列出的所有类成员和成员函数组成。 

一个程序包括一个或多个翻译单元。一个翻译单元由一个实现文件及其直接或间接包含的所有标头组成。 实现文件通常具有 `.cpp` 或 `.cxx`。头文件通常具有 `.h` 或 `.hpp`。 每个翻译单元由编译器独立编译。编译完成后，链接器会将编译后的翻译单元合并到单个程序中。ODR 规则的冲突通常显示为链接器错误。在多个翻译单元中定义同一名称时，将发生链接器错误。

通常，使变量在多个文件中可见的最佳方式是在头文件中声明它。然后，在需要声明的每个 `.cpp` 文件中添加一个 `#include` 指令。通过在标头内容周围添加 `include` 防卫，可以确保标头声明的名称对每个翻译单元只声明一次。仅在一个实现文件中定义名称。

```c++
#ifndef HEADER_H
#  define HEADER_H
   // ... code in header.h
#endif
```

在 C++20 中，模块作为头文件的改进替代方法引入。

```c++
import std.compat;
int main()
{
    printf("Hello World");
}
```

链接的类型指定对象的名称是仅在一个文件中可见，还是在所有文件中可见。*Free* 函数是在全局范围或命名空间范围内定义的函数。非常量全局变量和 *Free* 函数通常具有外部链接；它们在程序中的任何翻译单元内可见。可以将一个全局名称声明为 `static`；声明为 `const`, `constexpr`, `typedef`, 全局范围的 `static` 对象具有内部链接；`extern` 显式声明外部链接。

```c++
constexpr int czero = 0;
const struct S { int v; };
typedef struct S S;
static S Max{ INT_MAX };

extern const S Zero { 0 };  // 外部链接
```

>---
#### 名称查找

名称查找规则统一地应用于所有名称（包括 *typedef-names*，*namespace-names* 和 *class-names*）。名称查找将名称的使用与该名称的一组声明相关联。如果通过名称查找找到的声明都表示函数或函数模板，则这些声明被构成函数的重载集。

否则，如果通过名称查找找到的声明不表示相同的实体，则它们具有二义性。重载决策发生在名称查找成功后。只有在名称查找和函数重载决策成功后，才会考虑可访问性规则。只有在名称查找、函数重载决策和访问检查成功之后，才能在进一步的处理中使用声明引入的语义属性。

如果一个对象有多个 `T` 类型的基类子对象，也可以明确地找到基类 `T` 中定义的静态成员、嵌套类型或枚举数。两个基类子对象共享其公共虚基类的非静态成员子对象。

```c++
struct V {
    int v;
};
struct A {
    int a;
    static int s;
    enum { e };
};
struct B : A, virtual V { };
struct C : A, virtual V { };
struct D : B, C { };
void f(D* pd) {
    pd->v++;       // OK, only one v (virtual)
    pd->s++;       // OK, only one s (static)
    int i = pd->e; // OK, only one e (enumerator)
    pd->a++;       // error: ambiguous: two as in D
   	pd->B::a++;	   // OK: B::a
	pd->C::a++;	   // OK: C::a
}
```

从指向派生类对象的指针或指定派生类对象的表达式到指向其基类之一的指针或引用的显式或隐式转换，应明确引用表示基类的唯一对象。

```c++
struct V { };
struct A { };
struct B : A, virtual V { };
struct C : A, virtual V { };
struct D : B, C { };
void g() {
    D d;
    B* pb = &d;
    A* pa = &d; // error: ambiguous: C’s A or B’s A?
    V* pv = &d; // OK, only one V subobject
}
```


>---
#### Lvalues 和 Rvalues

每个 C++ 表达式都有一个类型，属于值类别。值类别是编译器在表达式计算期间创建、复制和移动临时对象时必须遵循的规则的基础。
-*glvalue* 是一个表达式，它的计算可以确定对象、位域或函数的标识。
- *prvalue* 是一个表达式，它的计算可以初始化对象或位域，或计算运算符的操作数值，由它出现的上下文所指定的。
- *xvalue* 是一个 *glvalue*，表示一个对象或位域，该对象或位域的资源可重复使用（通常是因为它接近其生存期的末尾）。某些涉及 *rvalue* 引用的类型的表达式会生成 *xvalue*，例如对返回类型为 *rvalue* 引用或强制转换为 *rvalue* 引用类型的函数的调用。
- *lvalue* 为非 *xvalue* 的 *glvalue*。
- *rvalue* 是一个 *prvalue* 或 *xvalue*。

> *各类别之间的关系*
<pre>
                          lvalue
                glvalue —|
   expression —|         xvalue
                rvalue  —|
                          prvalue  
</pre>

*lvalue* 具有程序可访问的地址。*lvalue* 表达式包括变量名称，例如 `const` 变量、数组元素、返回 *lvalue* 引用的函数调用、位域、联合和类成员。

*prvalue* 表达式没有可供程序访问的地址。例如，*prvalue* 表达式包括文本、可返回非引用类型的函数调用，以及在表达式计算期间创建且由编译器访问的临时对象。

*xvalue* 表达式有一个地址，该地址不再可供程序访问，但可用于初始化 *rvalue* 引用，以提供对表达式的访问。例如，它包括可返回 *rvalue* 引用的函数调用，以及数组下标、成员和指向其中数组或对象是 *rvalue* 引用的成员表达式的指针。

>---
#### 对齐方式

C++ 的低级功能之一是能够指定内存中对象的精确对齐方式，以最大限度利用特定的硬件体系结构。默认情况下、编译器会根据类或结构成员的值的大小进行对齐：`bool` 和 `char` 在 1 字节边界上对齐，`short` 在 2 字节边界上对齐，`int`、`long` 和 `float` 在 4 字节边界上对齐，`long long`、`double` 和 `long double` 在 8 字节边界上对齐。

可以使用 `alignof` 和 `alignas` 来获取或指定对象的对齐方式；对齐方式是内存地址的一个属性，表示为数字地址对 2 的幂次方取模，例如，地址 0x0001103F 对 4 取模为 3，该地址对齐到 4n+3。

CPU 执行作用于内存中所存储数据的指令。数据在内存中用地址标识。单个基准也具有大小。如果一个基准的地址对齐到其大小，则称它为自然对齐。

一般而言，编译器会以自然对齐结构的每一个元素的方式填充结构。例如：

```c++
struct x_
{
   char a;     // 1 byte
   // char _pad0[3];     // padding to put 'b' on 4-byte boundary
   int b;      // 4 bytes
   short c;    // 2 bytes
   char d;     // 1 byte
   // char _pad1[1];    // padding to make sizeof(x_) multiple of 4
} bar[3];
```

>---
#### 布局与 POD

布局是指类、结构或联合类型对象的成员在内存中的排列方式。布局一般由语言规范明确定义。

如果当类或结构包含某些 C++ 语言功能（如虚拟基类、虚拟函数、具有不同访问控制的成员）时，编译器可以自由选择布局。该布局可能会因编译器的优化有所不同，对象甚至可能不会占用连续内存区域。例如，如果某个类具有虚拟函数，则该类的所有实例可能会共享单个虚拟函数表。 

由于布局未定义，因此无法将其传递到使用其他语言（例如 C）编写的程序，并且由于它们可能是非连续的，因此无法使用快速低级函数（例如 `memcopy`）对其进行可靠复制，或者通过网络对其进行序列化。

> *Trivial* 类型

当 C++ 中的类或结构具有编译器提供的或显式默认设置的特殊成员函数时，该类或结构为普通类型。它占用连续内存区域。

普通类型具有普通默认构造函数、普通复制构造函数、普通复制赋值运算符和普通析构函数。 在各种情况下，“普通” 意味着构造函数 / 运算符 / 析构函数并非用户提供，并且属于存在以下情况的类：
- 没有虚拟函数或虚拟基类，
- 没有具有相应非普通构造函数 / 运算符 / 析构函数的基类
- 没有具有相应非普通构造函数 / 运算符 / 析构函数的类类型的数据成员

```c++
struct Trivial
{
   int i;
private:
   int j;
};

struct Trivial2
{
   int i;
   Trivial2(int a, int b) : i(a), j(b) {}
   Trivial2() = default;
private:
   int j;   // Different access control
};
```

> *standard-layout* 类型

当类或结构不包含某些 C++ 语言功能（例如无法在 C 语言中找到的虚拟函数），并且所有成员都具有相同的访问控制时，该类或结构为标准布局类型。可以在内存中对其进行复制，可以由 C 程序使用。标准布局类型可以具有用户定义的特殊成员函数。标准布局类型还具有以下特征：
- 没有虚拟函数或虚拟基类
- 所有非静态数据成员都具有相同的访问控制
- 类类型的所有非静态成员均为标准布局
- 所有基类都为标准布局
- 没有与第一个非静态数据成员类型相同的基类。
- 满足以下条件之一：
  - 最底层派生类中没有非静态数据成员，并且具有非静态数据成员的基类不超过一个，或者
  - 不含非静态数据成员的基类

```c++
struct SL
{
   // All members have same access:
   int i;
   int j;
   SL(int a, int b) : i(a), j(b) {} // User-defined constructor OK
};
```

`Base` 是标准布局，`Derived` 不是标准布局，它（最底层派生类）和 `Base` 都具有非静态数据成员：

```c++
struct Base
{
   int i;
   int j;
};

// std::is_standard_layout<Derived> == false!
struct Derived : public Base
{
   int x;
   int y;
};
```

`Derived` 是标准布局，因为 `Base` 没有非静态数据成员：

```c++
struct Base
{
   void Foo() {}
};

// std::is_standard_layout<Derived> == true
struct Derived : public Base
{
   int x;
   int y;
};
```

如果 `Base` 具有数据成员，并且 `Derived` 仅具有成员函数，则 `Derived` 也是标准布局。

> POD 类型

当某一类或结构同时为普通和标准布局时，该类或结构为 POD（简单旧数据）类型。 因此，POD 类型的内存布局是连续的，并且每个成员的地址都比在其之前声明的成员要高，以便可以对这些类型执行逐字节复制和二进制 I/O。标量类型（例如 `int`）也是 POD 类型。

作为类的 POD 类型只能具有作为非静态数据成员的 POD 类型。

> 普通、标准布局和 POD 类型之间的区别

```c++
#include <type_traits>
#include <iostream>

using namespace std;

struct B
{
protected:
   virtual void Foo() {}
};

// Neither trivial nor standard-layout
struct A : B
{
   int a;
   int b;
   void Foo() override {} // Virtual function
};

// Trivial but not standard-layout
struct C
{
   int a;
private:
   int b;   // Different access control
};

// Standard-layout but not trivial
struct D
{
   int a;
   int b;
   D() {} //User-defined constructor
};

struct POD
{
   int a;
   int b;
};

int main()
{
   cout << boolalpha;
   cout << "A is trivial is " << is_trivial<A>() << endl; // false
   cout << "A is standard-layout is " << is_standard_layout<A>() << endl;  // false

   cout << "C is trivial is " << is_trivial<C>() << endl; // true
   cout << "C is standard-layout is " << is_standard_layout<C>() << endl;  // false

   cout << "D is trivial is " << is_trivial<D>() << endl;  // false
   cout << "D is standard-layout is " << is_standard_layout<D>() << endl; // true

   cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
   cout << "POD is standard-layout is " << is_standard_layout<POD>() << endl; // true

   return 0;
}
```

>---
#### 文本类型

文本类型是可在编译时确定其布局的类型。以下均为文本类型：
- `void`、标量类型、引用；
- `void`、标量类型或引用的数组
- 具有普通析构函数以及一个或多个 `constexpr` 构造函数且没有移动或复制构造函数的类。此外，其所有非静态数据成员和基类必须是文本类型且不可变。

>---
#### 值类型

默认情况下，C++ 类是值类型。可以指定为引用类型，以多态行为支持面向对象的编程。默认情况下，值类型可以复制，这意味着总是有一个复制构造函数和一个复制赋值运算符。 

对于引用类型，将类设为不可复制（禁用复制构造函数和复制赋值运算符），并使用支持其预期多态性的虚拟析构函数。 

```c++
class MyRefType {
private:
    MyRefType & operator=(const MyRefType &);
    MyRefType(const MyRefType &);
public:
    MyRefType () {}
};

int main()
{
    MyRefType Data1, Data2;
    // ...
    Data1 = Data2;
    // error: 'MyRefType::operator =' : cannot access private member declared in class 'MyRefType'
}
```

> *值类型和移动效率*

类必须通过在类定义中声明移动赋值和移动构造函数，以支持复制时的移动优化，避免复制分配开销。*Move* 使用 `&&` *rvalue* 引用，定义移动构造函数和移动赋值函数。

 <!-- TODO -->

>---
#### 类型转换

当表达式包含不同内置类型的操作数且不存在显式强制转换时，编译器将使用内置的 “标准转换” 来转换其中一个操作数，从而使类型相匹配。

在扩大转换中，较小的变量中的值将赋给较大的变量，同时不会丢失数据。扩大转换始终是安全的。

收缩转换可能存在数据丢失，隐式执行收缩转换编译器发出警告，可以添加显式强制转换。任何从浮点类型到整型的转换都是收缩转换，小数部分将会丢弃。

```c++
int i = INT_MAX + 1;   // warning:'+':integral constant overflow
wchar_t wch = 'A';     // OK
char c = wch;          
// warning:'initializing':conversion from 'wchar_t' to 'char', possible loss of data

unsigned char c2 = 0xfffe; 
// warning:'initializing':truncation from 'int' to 'unsigned char'

int j = 1.9f; 
// warning:'initializing':conversion from 'float' to 'int', possible loss of data

int k = 7.7; 
// warning:'initializing':conversion from 'double' to 'int', possible loss of data
```

有符号和无符号整型之间的隐式转换，具有相同的位模式和不同的值解释方式。编译器不会发出有关有符号和无符号整型之间的隐式转换的警告。

利用强制转换运算，可以指示编译器将一种类型的值转换为另一种类型。例如从指向派生类的指针到指向基类的指针的强制转换。还有一种使用情况是强制转换改变变量的常量性以将其传递给需要非常量参数的函数。

```c++
(int) x;  // old-style cast, old-style syntax
int(x);   // old-style cast, functional syntax

static_cast<T>(v)
dynamic_cast<Derived>(base)
const_cast<constT>(noconstv)
reinterpret_cast<T>(v)
```


---
### 内置类型

内置类型（也称基本类型）由 C++ 语言标准指定，未在任何头文件中定义。分为三个主要类别：整型、浮点和 `void`。

>---
#### Void 

`void` 描述值的空集。没有 `void` 类型的变量，主要用于无返回值函数，或声明非类型化的一般指针。任何表达式都可以显示或强制转换为类型 `void`，仅限于：
- 表达式语句；
- 顺序运算符的左操作数；
- 条件运算符的第二个或第三个操作数；

`void*` 指针可以指向任何未 `const` 或 `volatile` 声明的变量。无法对 `void*` 取消引用，只能强制转换为另一种类型。`void*` 指针可以指向 *Free* 函数（非类成员函数）或静态成员函数，不能指向非静态成员函数。

```c++
void return_nothing()
{
   // A void function without value returned
}

// void vobject;   // ERROR
void *pv;       // okay
int *pint; int i;
int main()
{
   pv = &i;
   // Cast is optional in C, required in C++
   pint = (int *)pv;
}
```

>---
#### std::nullptr_t

`nullptr` 表示为 `std::nullptr_t` 的空指针常量，可转换为任何原始指针类型。避免将 NULL 或零 (0) 用作空指针常量

例如，对于给定 `func(std::pair<const char *, double>)`，调用 `func(std::make_pair(NULL, 3.14))` 会导致编译器错误。宏 `NULL` 将扩展到 0，调用 `std::make_pair(0, 3.14)` 将返回 `std::pair<int, double>`，此不可转换为 `std::pair<const char *, double>` 参数类型。

```c++
using namespace std;
void func(std::pair<const char*, double>) {
	cout << "call pair<const char*, double>\n";
}
void func(std::pair<int, double>) {
	cout << "call pair<int, double>\n";
}

int main() {
	func(std::make_pair(NULL, 3.14));
	func(std::make_pair(nullptr, 3.14));
	// call pair<int, double>
	// call pair<const char*, double>
}
```

>---
#### Boolean

`bool` 类型具有值 `true` 和 `false`；条件表达式具有类型 `bool`；`bool` 类型参与了默认整型提升。

```c++
bool a = 1;  // true
bool b = 0;  // false
int ia = a;  // 1
int ib = b;  // 0
auto c = a + b;  // int; 1
```

>---
#### Character

`char` 类型是一种字符表示类型，可有效地对基本执行字符集的成员进行编码。C++ 编译器将 `char`, `signed char` 和 `unsigned char` 类型的变量视为不同类型。

`wchar_t` 类型的变量是宽字符或多字节字符类型。在字符或字符串文本前使用 L 前缀可指定宽字符类型。

`char8_t` 类型用于 UTF-8 字符表示形式。`char16_t` 类型用于 UTF-16 字符表示形式。`char32_t` 类型用于 UTF-32 字符表示形式。 

```c++
char       c = 'A';
int       mc = 'abcd';
char8_t   c8 = u8"A";
char16_t c16 = u"A";
char32_t c32 = U"A";
wchar_t   wc = L'A';
```

>---
#### Floating-point

浮点类型使用 IEEE-754 表示形式，在各种数量级上提供小数值的近似值。C++ 标准中未指定内置浮点类型的绝对大小。

```c
float   // 在 C++ 中最小的浮点类型。
double  // 大于或等于 float 类型但小于或等于 long double 类型
long double // 大于或等于 double类型

float  f = 3.1415f;
double d = 3.1415;
long double ld = 3.1415L; 
```

>---
#### Integer

`int` 类型是默认的基本整数类型。它可以表示某个特定于实现的范围的所有整数。有符号整数可以同时保存正值和负值。大小修饰符指定使用的整数表示形式的宽度，例如 `short`，`long`，`long long`。

```c++
1 == sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

int i = 1;
unsigned ui = 1u;
short s = 1;
long  l = 1L;
long long ll = 1LL;
unsigned long long ull = 1ull;
```

> 声明同义词

```c++
short == short int == signed short == signed short int
unsigned short == unsigned short int
int == signed == signed int
unsigned == unsigned int
long == long int == signed long == signed long int
unsigned long == unsigned long int
long long == long long int == signed long long == signed long long int
unsigned long long == unsigned long long int
```

>---
#### 数值限制

`<limits.h>` 和 `<float.h>`定义了数字限制或给定类型的变量可包含的最小值和最大值。参阅 [C stdlib](https://github.com/JimryYchao/Learn-Programming-C#c-%E6%A0%87%E5%87%86%E5%BA%93c23)。



---
### 声明与定义

程序的实体（*Entity*）包括值、对象、引用、结构化绑定、函数、枚举器、类型、类成员、位字段、模板、模板专用化、命名空间或包。

名称是一个标识符、重载运算符标识符、用户定义文本运算符标识符、或运算符转换类型标识符。实体的名称由声明引入，声明可以是名称声明、块声明或成员声明；初始化声明；结构化绑定声明；参数、类型参数、类型定义等。实体 `E` 由声明 `E` 引入的名称（如果有）或由指定 `E` 的声明引入的 *typedef-name* 表示。

变量是通过声明非静态数据成员或对象以外的引用来引入的。变量的名称（如果有）表示引用或对象。局部实体是具有自动存储期的变量、结构化绑定对应的变量，或 *this 对象。

声明可以（重新）将一个或多个名称和 / 或实体引入翻译单元，并指定这些名称的解释和语义属性。如果可以从实体或 *typedef-name* `X` 中获取另一个 `X` 声明，则该实体或 *typedef-name* `X` 的声明是 `X` 的重新声明。

在对象的定义中，该对象的类型不应该是不完整类型、抽象类类型或其数组（可能是多维的）。

```c++
// 定义声明
int a;                         // defines a
extern const int c = 1;        // defines c
int f(int x) { return x + a; } // defines f and defines x
struct S
{
    int a;
    int b;
}; // defines S, S::a, and S::b
struct X
{                 // defines X
    int x;        // defines non-static data member x
    static int y; // declares static data member y
    X() : x(0) {} // defines a constructor of X
};
int X::y = 1; // defines X::y
enum
{
    up,
    down
}; // defines up and down
namespace N
{
    int d;
} // defines N and N::d
namespace N1 = N; // defines N1
X anX;            // defines anX

// 仅声明
extern int a;       // declares a
extern const int c; // declares c
int f(int);         // declares f
struct S;           // declares S
typedef int Int;    // declares Int
extern X anotherX;  // declares anotherX
using N::d;         // declares d
```

在某些情况下，编译器会为一些定义声明隐式定义默认构造函数、赋值构造函数、移动构造函数、复制赋值运算符、移动赋值运算符或终结器。

```c++
struct C {
    std::string s; // std::string is the standard library class (23.4)
};
// 实现将隐式定义
struct C
{
    std::string s;
    C() : s() {}
    C(const C &x) : s(x.s) {}
    C(C &&x) : s(static_cast<std::string &&>(x.s)) {}
    // : s(std::move(x.s)) { }
    C &operator=(const C &x)
    {
        s = x.s;
        return *this;
    }
    C &operator=(C &&x)
    {
        s = static_cast<std::string &&>(x.s);
        return *this;
    }
    // { s = std::move(x.s); return *this; }
    ~C() {}
};
```

> One-definition rule 

单一定义原则，ODR：任何翻译单元不得包含任何可定义项的一个以上定义。可定义项包括：类类型、枚举类型、函数、变量、模板化实体、参数的默认实参、默认模板实参。

>---
#### 存储类说明符

```c++
static
extern
register   // 弃用
thread_local
mutable
```

变量声明上下文中的存储类说明符是管理对象的生存期、链接和内存位置的类型说明符。给定对象只能有一个存储类。块中定义一般具有自动存储期，除非使用 `extern`、`static` 或 `thread_local`。自动存储期对象和变量不具有链接，块外不可见。

`static` 在全局范围、命名空间范围和类范围声明变量和函数，以绑定内部链接，变量具有静态存储期，类所有实例共享类 `static` 变量和函数。局部范围的 `static` 局部变量具有静态存储期（程序结束时释放）。

```c++
// static1.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
void showstat( int curr ) {
   static int nStatic;    // Value of nStatic is retained
                          // between each function call
   nStatic += curr;
   cout << "nStatic is " << nStatic << endl;
}

int main() {
   for ( int i = 0; i < 5; i++ )
      showstat( i );  // 0,1,3,6,10
}
```

声明为 `extern` 的对象和变量将在另一个翻译单元或在一个封闭范围中定义的对象声明为具有外部链接。`extern` 可以应用于全局变量、函数、类型或模板声明，标识外部链接属性。
- 在非 `const` 全局变量声明中，`extern` 指定变量或函数在另一个翻译单元中定义。
- 在 `const` 变量（内部链接）声明中，它指定变量具有外部链接。
- `extern "C"` 指定函数在别处定义并使用 C 语言调用约定。`extern "C"` 修饰符也可以应用于块中的多个函数声明。不能重载声明为 `extern "C"` 的函数。
- 在模板声明中，`extern` 指定模板已在其他位置实例化。
- 在块范围内声明的 `extern` 变量引用外部变量，且没有初始值设定项；仅声明。

```c++
//fileA.cpp
int i = 42; // declaration and definition

//fileB.cpp
extern int i;  // declaration only. same as i in FileA
extern const int ci = 42;      // extern const definition
extern constexpr int cx = 10;  // extern constexpr definition

export extern "C" void F();
export extern "C++" void F(int);

int main() {
    extern int i /* = 10; ERR */;  // 引用声明外部变量 i
}
```

`register` 关键字不再是受支持的存储类。已作为保留，C++ 17 作为警告。

```c++
void foo(){
    register int val; // warning: 'register' is no longer a supported storage class
}
```


声明为 `thread_local` 的变量仅可在它在其上创建的线程上可访问，变量具有线程存储时间（TLS）。每个线程都有其自己的变量副本。
- 只能在具有静态存储持续时间的数据项上指定 `thread_local`
- `thread_local` 说明符可以与 `static` 或 `extern` 合并。
- `thread_local` 不能用于函数声明或定义。
- 不建议将 `thread_local` 变量与 `std::launch::async` 一起使用。


```c++
thread_local float f = 42.0; // Global namespace. Not implicitly static. extern TLS
struct S // cannot be applied to type definition
{
    thread_local int i; // Illegal. The member must be static.
    thread_local static char buf[10]; // OK; static TLS
};

void DoSomething()
{
    // Apply thread_local to a local variable.
    // Implicitly "thread_local static S my_struct".
    thread_local S my_struct;  // static TLS
}
```

`mutable` 只应用于类的非静态、非常量和非引用数据成员。如果某个数据成员被声明为 `mutable`，则从 `const` 成员函数为此数据成员赋值是合法的。

```c++
// mutable.cpp
class X
{
public:
    bool GetFlag() const
    {
        m_accessCount++;  // allowed
        m_flag = true;    // illegal: assignment of member 'X::m_flag' in read-only object
        return m_flag;
    }
private:
    bool m_flag;
    mutable int m_accessCount;
};
```


>---
#### alignas 对齐

可以对 `struct`、`class`、`union` 或变量声明使用 `alignas(N)` 说明符，`N = 0, 2^(1,2,4,8,16,...)`。不能小于应用于它的类型的自然对齐方式。用户定义的类型的声明和定义必须具有相同的对齐值。

```c++
struct alignas(8) S1     // 8
{
    int x;
};
class alignas(16) C{}    // 16
struct alignas(double) S2  // double
{
    int x;
};

template <typename... Ts> // max{ TS... }
class alignas(Ts...) C2
{
    char c;
};
alignof(C2<int, float, double>) == 8;
```

>---
#### auto 类型推断

`auto` 指示编译器使用已声明变量的初始化表达式或 lambda 表达式参数来推导其类型。`auto` 被视为类型的占位符，但它本身不是类型。因此不能用于强制转换或运算符，如 `sizeof` 和（用于 C++/CLI）`typeid`。变量可以指定 `const`、`volatile` 等说明符和声明符、指针、右值引用。

使用 `auto` 会删除引用、`const` 限定符和 `volatile` 限定符。

```c++
auto PI = 3.141592653;        // double
auto lambda = [](int a, int b){ 
	return a + b; 
};  // int lambda(int, int)

auto const V = 10010;	      // int
auto static SV(V);			  // static int; SV = V
auto extern const ECV = SV;   // extern const int
auto volatile* PSV(&SV);      // volatile int*
auto& reflv = V;			  // const int &
auto&& refrv(10086);		  // int &&
struct S {
	int x;
	int y;
};
auto A(S{ 1, 2 });

for (auto&& i = a; i >= 0; i--)
	cout << "Hello World\n";
```

>---
#### const 不可变

当它修改数据声明时，`const` 指定对象、变量不可修改。`const T` 和 `T` 是不同的数据类型。`const` 常量值具有内部链接。对于声明为 `const` 的对象，只能调用常量成员函数。

```c++
const int i = 10;
i++;   // ERROR
const * pi = &i;
extern const double d;    // 外部链接
```

> `const` 与指针

```c++
const int i = 10;
int mi = 10;

int const* pi = &mi;   // 指向常量整数的指针
const int* pi2 = pi;

int* const cpi = &mi;  // 指向整数的常量指针
const int* cpi2 = &mi;
*cpi = 100;   // 指针不可修改，值可修改

const int* const cpci = &i;   // 指向常量整数的常量指针
const int* const cpci2 = &mi; // 指向整数的常量指针，但无法从指针修改数据
```

> `const` 成员函数

```c++
rt-type funcName(params) const {}  
```

声明 `const` 成员函数将指定为一个 “只读” 函数，它不会修改为其调用该函数的对象。常量成员函数不能修改任何非静态数据成员（除了 `mutable`）或调用任何非常量成员函数。 

```c++
class Date
{
public:
	Date(int mn, int dy, int yr);
	int getMonth() const;     // A read-only function
	void setMonth(int mn);   // A write function; can't be const
private:
	int month;
};

int Date::getMonth() const 
{
	return month;        // Doesn't modify anything
}
void Date::setMonth(int mn)
{
	month = mn;          // Modifies data member
}
int main()
{
	Date MyDate(7, 4, 1998);
	const Date BirthDate(1, 18, 1953);
	MyDate.setMonth(4);         // Okay
	auto _ = MyDate.getMonth(); // okay;
	BirthDate.getMonth();       // Okay
	BirthDate.setMonth(4);      // Error; const v call non-const-func
}
```

可以为非常量对象调用常量或非常量成员函数。可以使用 `const` 关键字重载成员函数使得可以对常量和非常量对象调用不同版本的函数。对于声明为 `const` 的对象，只能调用常量成员函数。

```c++
class Data {
public:
	void MulData(int data) const {
		this->data = data;
	}
	void MulData(int data) {
		this->data = data;
	}
private :
	mutable int data;  // can motify in const-func
};

int main() {
	const auto cd = Data();
	auto d = Data();
	cd.MulData(1);  // call Muldata() const
	d.MulData(1);   // call Muldata()
}
```

>---
#### constexpr 常量表达式

与 `const` 一样，`constexpr` 可以应用于变量；`constexpr` 也可以应用于函数和类 constructor（构造函数）。`constexpr` 指示值或返回值是 constant（常数）。如果可能，可以在编译时进行计算。C++14 标准要求常量表达式中涉及的类型为文本类型。

`constexpr` 变量必须在编译时进行初始化。如果初始化由构造函数执行，则必须将构造函数声明为 `constexpr`。引用可以被声明为 `constexpr`：引用的对象是由常量表达式初始化。

`constexpr` 函数是在使用需要它的代码时，可在编译时计算其返回值的函数。当其自变量为 `constexpr` 值时，函数 `constexpr` 将生成编译时常量。以下规则适用于 `constexpr` 函数：

- `constexpr` 函数或构造函数通过隐式方式 `inline`。
- `constexpr` 变量或函数必须返回文本类型。
- `constexpr` 函数可以递归。
- C++20 后可以定义 `virtual constexpr func`；带有虚拟基类的类不能声明 `constexpr ctor`。
- 主体可以定义为 `= default` 或 `= delete`。
- 可以将非 `constexpr` 模板的显式专用化声明为 `constexpr`。`constexpr` 模板的显式专用化不需要同时是 `constexpr`。
- 它可能包含局部变量声明，但必须初始化该变量。它必须是文本类型，不能是 `static` 或 `thread_local` 的。局部变量不需要是 `const`，并且可以变化。

```c++
template <typename T, int N>
void Iter(T arr[N]) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;
}

constexpr int arr[5] = { 1,3,4,5,6 };
Iter<const int, 5>(arr);

class B {
	constexpr B() = default;
	int constexpr foo() = delete;
};
```

>---
#### 初始值设定项

初始值设定项可指定变量的初始值。

```c++
struct Point {
    int x;
    int y;
};
class PointConsumer {
public:
    void set_point(Point p) {};
    void set_points(initializer_list<Point> my_list) {};
    // 函数返回值
    Point get_new_point(int x, int y) { return { x, y }; }
};

int main() {
    PointConsumer pc{};
    // 变量
    int i = 3;
    Point p1{ 1, 2 };
    // 函数参数
    pc.set_point({});
    pc.set_point(Point{ 3,5 });
    pc.set_point({ 3, 4 });
    pc.set_points({ { 3, 4 }, { 5, 6 } });
}
```

零初始化是指将变量设置为隐式转换为该类型的零值。

```c++
struct my_struct{
    int i;
    char c;
};

int i0;              // zero-initialized to 0
int main() {
    static float f1;  // zero-initialized to 0.000000000
    double d{};       // zero-initialized to 0.00000000000000000
    int* ptr{};       // initialized to nullptr
    char s_array[3]{'a', 'b'};  // the third char is initialized to '\0'
    int int_array[5] = { 8, 9, 10 };  // the fourth and fifth ints are initialized to 0
    my_struct a_struct{};   // i = 0, c = '\0'
}
```

类、结构和联合的默认初始化是具有默认构造函数的初始化。 

```c++
MyClass mc1;
MyClass* mc3 = new MyClass;
```

如果定义标量变量或数组时不使用初始化表达式，则进行默认初始化。它们的值是不确定的。静态变量的声明中没有初始值设定项，则零初始化。

```c++
int i1;
float f;
char c;
int int_arr[3];
static int int1;       // 0
static char char1;     // '\0'
static bool bool1;     // false
static MyClass mc1;    // {0, '\0'}
```

值初始化使用 `{}` 初始化已命名值、`(), {}` 初始化匿名临时对象、`new T(), {}` 初始化对象。直接初始化使用 `{}, {values...}, (values...)`  显式调用构造函数初始化。

```c++
class BaseClass {
private:
    int m_int;
};

int main() {
    BaseClass bc{};    // class is initialized
    BaseClass*  bc2 = new BaseClass();  // class is initialized, m_int value is 0
    int int_arr[3]{};  // value of all members is 0
    int a{};           // value of a is 0
    double b{};        // value of b is 0.00000000000000000
    
    double d(10);
    double d2{};
}
```

复制初始化是指使用一个不同的对象来初始化另一个对象。如果类的复制构造函数被删除或不可访问，复制初始化将导致编译器错误。

```c++
class MyClass {
public:
	MyClass() {}
private:
	MyClass(MyClass& c) = delete;
};
int main() {
	MyClass mc1;
	MyClass mc2 = mc1;  // ERROR: 删除
}
```

列表初始化使用 `{v1,v2,..}` 初始化变量或参数、`new` 类对象、非静态数据成员的初始值设定项、构造函数初始值设定项列表中。

```c++
class MyClass {
public:
    MyClass(int myInt, char myChar) {}
private:
    int m_int[5]{ 3 };
    char m_char;
};
class MyClassConsumer{
public:
    void set_class(MyClass c) {}
    MyClass get_class() { return MyClass{ 0, '\0' }; }
};
struct MyStruct{
    int my_int;
    char my_char;
    MyClass my_class;
};
int main() {
    MyClass mc1{ 1, 'a' };
    MyClass* mc2 = new MyClass{ 2, 'b' };
    MyClass mc3 = { 3, 'c' };

    MyClassConsumer mcc;
    mcc.set_class(MyClass{ 3, 'c' });
    mcc.set_class({ 4, 'd' });

    MyStruct ms1{ 1, 'a', { 2, 'b' } };
}
```

聚合初始化是针对数组或类类型（通常为结构或联合）的一种列表初始化形式。

```c++
struct Point3D {
	struct Point2D {
		int x, y;
	} xy;
	int z;
};
int main() {
    int arr[10](1, 2, 3, 4 /*,0 ...*/);
    int arr2[]{ 1,2,3,4,5,6 };  // arr2[6]

	using Point2D = Point3D::Point2D;
	Point2D p2{ 1,1 };
	Point3D p3{ 1,2,3 };
	Point3D p3_2{ {1,2},3 };
};
```

引用类型的变量必须使用引用类型派生自的类型的对象进行初始化，或使用可转换为引用类型派生自的类型的类型的对象进行初始化。
- 引用自变量的声明需要初始化设定项；除了：
  ```c++
  int func( int& );  // 函数原型
  int& func( int& ); // 引用返回
  class c {public:   int& i;};  // 成员声明
  extern int& iVal;  // 外部引用声明
  ```

```c++
int iVar;
long lVar;
int main()
{
    long& LongRef1 = lVar;        // No conversion required.
    long& LongRef2 = iVar;        // Error; wrong type
    const long& LongRef3 = iVar;  // OK
    LongRef1 = 23L;               // Change lVar through a reference.
    LongRef2 = 11L;               // Change iVar through a reference.
    LongRef3 = 11L;               // Error ; const

	volatile int& viVarRef = iVar;
	const int& ciVarRef = iVar;
}
```

>---
#### using 别名和 typedef

“别名声明” 声明一个类型的同义词别名；

```c++
using identifier = type;
typedef type identifier;

using fmtfl = std::ios_base::fmtflags;
typedef std::ios_base::fmtflags fmtfl;

using func = void(*)(int);
typedef void (*func)(int);
```

`using` 别名和 `typedef` 的区别在于 `using` 可以创建别名模板：

```c++
template<typename T> using ptr = T*;
ptr<int> ptr_int;
```

`typedef` 声明在其范围内引入一个名称，该名称成为声明的 “类型声明” 部分给定的类型的同义词。不引入新类型。引入的名称不能用作类声明中的构造函数名称或析构函数名称。

```c++
typedef unsigned long UL;   // Declare a typedef name, UL.
int UL;                     // Error: redefined.
int Foo()
{
   unsigned int UL;   // Redeclaration hides typedef name
}

typedef char CHAR, *PSTR;
typedef void DRAWF( int, int );  // func

typedef struct {
	int x, y;
} Point2D, * PPoint2D, & RPoint2D, && RRPoint2D;
int main(){
	RRPoint2D rra = Point2D{ 1,1 };
	RPoint2D ra = rra;
	PPoint2D pa = &rra;
}
```

>---
#### using 声明

`using` 声明将名称引入声明性区域；

```c++
using [typename] nested-name-specifier unqualified-id;
using declarator-list;
```

- *nested-name-specifier* 表示命名空间、类或枚举名称和范围解析运算符 (`::`) 的序列，由范围解析运算符终止。单个范围解析运算符用于从全局命名空间引入名称。关键字 `typename` 是可选的，在从基类引入到类模板时，可用于解析依赖名称。

- *unqualified-id* 可以是标识符、重载运算符名称、用户定义的文本运算符或转换函数名称、类析构函数名称或模板名称和参数列表。
  
`using` 声明引入非限定名称作为在其他地方声明的实体的同义词。它允许使用特定命名空间中的单个名称。这与 `using` 指令相反，`using` 指令允许命名空间中的所有名称在没有限定的情况下使用。局部函数声明不能与 `using` 声明引入的函数具有相同的名称和类型。

```c++
#include <iostream>
namespace mySpace {
	void Foo() {};
	struct S {};
};
int main() {
	using std::ostream;

	std::cout << "using std::ostream" << std::endl;

	mySpace::Foo(); // 限定使用

	using mySpace::S;
	S s{};  // using 声明引入

	using namespace std;
	// 引入命名空间
	cout << "using namespace std" << endl;
}
```

用于声明成员时，`using` 声明必须引用基类的成员。

```c++
#include <stdio.h>
class B {
public:
   void f(char) {
      printf_s("In B::f()\n");
   }

   void g(char) {
      printf_s("In B::g()\n");
   }
};

class C {
public:
   int g();
};

class D2 : public B {
public:
   using B::f;   // ok: B is a base of D2
   // using C::g;   // error: C isn't a base of D2
};

int main() {
   D2 MyD2;
   MyD2.f('a');
}
```

`using` 声明中提及的名称的所有实例都必须可访问。

```c++
class A {
private:
   void f(char);
public:
   void f(int);
protected:
   void g();
};

class B : public A {
   using A::f;   // C2876: A::f(char) is inaccessible
public:
   using A::g;   // B::g is a public synonym for A::g
};
```

进行 `using` 声明时，由该声明创建的同义词仅引用在进行 `using` 声明时有效的定义。之后添加到命名空间的定义不是有效同义词。

```c++
namespace A {
   void f(int) {}
}
using A::f;   // f is a synonym for A::f(int) only
namespace A {
   void f(char) {}  // after using A::f
}

void f() {
   f('a');   // refers to A::f(int), even though A::f(char) exists
}

void b() {
   using A::f;   // refers to A::f(int) AND A::f(char)
   f('a');   // calls A::f(char);
}
```

>---
#### volatile 易变

`volatile` 是用于声明可在程序中由硬件修改的对象的类型限定符。可以使用 `volatile` 限定符提供对异步过程（如中断处理程序）使用的内存位置的访问权。

如果将 `struct` 成员标记为 `volatile`，则 `volatile` 将传播到整个结构。如果满足下列条件之一，则 `volatile` 可能对字段不起作用：
- 可变字段的长度超过可使用一条指令在当前体系结构上复制的最大大小。
- 最外层包含 `struct` 的长度（或如果它是可能嵌套的 `struct` 的成员）超过可使用一条指令在当前体系结构上复制的最大大小。

尽管处理器不会对不可缓存的内存访问重新排序，但必须将不可缓存的变量标记为 `volatile`，从而保证此编译器不会对内存访问重新排序。

与 `const` 相似，可以声明 `volatile` 成员函数，`volatile struct` 的易变实例只能调用易变成员函数；普通结构实例可以调用所有成员函数。

```c++
volatile struct  S {
	int V;
public:
	volatile void Foo(volatile int& V) volatile;
	void Foo(int& V); // 重载
	//void Foo(volatile int V);  // 二义性
	//void Foo(int V);  
};
volatile void S::Foo(volatile int& V) volatile {
	cout << "V Foo&" << endl;
}
void S::Foo(int& V) {
	cout << "Foo&" << endl;
}
int main() {
	volatile auto s = S{ 10 }; 
	volatile auto& vrv = s.V;
	int& rv = ( int&)vrv;
	S s2{};
	s.Foo(vrv);   // call s.Foo volatile
	s2.Foo(vrv);  // V Foo&
	s2.Foo(rv);   // Foo&
}
```


>---
#### decltype 和转发函数

`decltype` 类型说明符生成指定表达式的类型。使用 `auto` 和 `decltype` 声明其返回类型取决于其模板自变量类型的函数模板。或者使用 `auto` 和 `decltype` 声明一个函数模板，用来包装对其他函数的调用，然后返回包装函数的返回类型。

```c++
//C++11
template<typename T, typename U>
auto myFunc(T&& t, U&& u) -> decltype (forward<T>(t) + forward<U>(u))
        { return forward<T>(t) + forward<U>(u); };

//C++14
template<typename T, typename U>
decltype(auto) myFunc(T&& t, U&& u)
        { return forward<T>(t) + forward<U>(u); };
```

> *转发函数* C++11

转发函数包装对其他函数的调用。转发函数的返回类型与包装函数的返回类型相同。

```c++
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) ->
decltype(forward<T1>(t1) + forward<T2>(t2))
{
    return forward<T1>(t1) + forward<T2>(t2);
}
class X
{
    friend X operator+(const X& x1, const X& x2)
    {
        return X(x1.m_data + x2.m_data);
    }

public:
    X(int data) : m_data(data) {}
    int Dump() const { return m_data; }
private:
    int m_data;
};

int main()
{
    // Integer
    int i = 4;
    cout <<
        "Plus(i, 9) = " <<
        Plus(i, 9) << endl;   // Plus(i, 9) = 13

    // Floating point
    float dx = 4.0;
    float dy = 9.5;
    cout <<
        setprecision(3) <<
        "Plus(dx, dy) = " <<
        Plus(dx, dy) << endl;  // Plus(dx, dy) = 13.5

    // String
    string hello = "Hello, ";
    string world = "world!";
    cout << Plus(hello, world) << endl;  // Hello, world!

    // Custom type
    X x1(20);
    X x2(22);
    X x3 = Plus(x1, x2);
    cout <<
        "x3.Dump() = " <<
        x3.Dump() << endl;  // x3.Dump() = 42
}
```

>---
#### 特性声明

C++ 标准定义了一组通用属性。属性代表 `#pragma` 指令、`__declspec()` (Visual C++) 或 `__attribute__` (GNU) 等供应商特定扩展的标准化替代项。标准属性包含：
- `[[carries_dependency]]` 指定函数传播线程同步的数据依赖项顺序。应用于一个或多个参数，以指定传入的参数要将依赖项带入函数主体中。用于函数本身以指定返回值要将依赖项带出函数。
- `[[deprecated]]` 指定函数不适合使用，表明已弃用；应用于类、typedef 名称、变量、非静态数据成员、函数、命名空间、枚举、枚举器或模板专用化的声明。
- [[fallthrough]] 可在 `switch` 语句的上下文中用作向编译器（或阅读代码的任何人）显示的提示，指出失败行为是有意的。
- [[likely]] 向编译器指定提示，指出属性化标签或语句的代码路径的执行可能性高于替代项。
- [[unlikely]] 向编译器指定提示，指出属性化标签或语句的代码路径的执行可能性低于替代项。
- [[maybe_unused]] 指定变量、函数、类、*typedef*、非静态数据成员、枚举或模板专用化可能是有意不使用的。
- [[nodiscard]] 指定不应该丢弃函数的返回值。
- [[noreturn]] 指定函数永不返回；它始终引发异常或退出。

```c++
#include <iostream>
#include <utility>
using namespace std;
template<typename T1, typename T2>
[[nodiscard]] auto Plus(T1&& t1, T2&& t2) ->
decltype(forward<T1>(t1) + forward<T2>(t2))
{
	return forward<T1>(t1) + forward<T2>(t2);
}
int main() {
	std::cout << Plus(1, 2) << std::endl;
}

[[noreturn]] void Foo(int exitcode) {
	_Exit(exitcode);
}
```

---
### 运算符与表达式

C++ 语言包括所有 C 运算符并添加多个新的运算符。C++ 运算符的优先级和关联性：

| precedence | operator                     | description        | associativity | alternative |
| :--------- | :--------------------------- | :----------------- | :------------ | :---------- |
| 1          | `::`                         | 范围解析           |               |             |
| 2          | `.`,`->`                     | 成员选择           | 从左到右      |             |
| 2          | `[]`                         | 数组索引           | 从左到右      |             |
| 2          | `()`                         | 函数调用           | 从左到右      |             |
| 2          | `++`                         | 后缀递增           | 从左到右      |             |
| 2          | `--`                         | 后缀递减           | 从左到右      |             |
| 2          | `typeid`                     | 类型名称           | 从左到右      |             |
| 2          | `const_cast`                 | 常量类型转换       | 从左到右      |             |
| 2          | `dynamic_cast`               | 动态类型转换       | 从左到右      |             |
| 2          | `reinterpret_cast`           | 重新解释的类型转换 | 从左到右      |             |
| 2          | `static_cast`                | 静态类型转换       | 从左到右      |             |
| 3          | `sizeof`                     | 对象或类型的大小   | 从右到左      |             |
| 3          | `++`                         | 前缀递增           | 从右到左      |             |
| 3          | `--`                         | 前缀递减           | 从右到左      |             |
| 3          | `~`                          | 二进制反码         | 从右到左      | `compl`     |
| 3          | `!`                          | 逻辑 “非”          | 从右到左      | `not`       |
| 3          | `-`                          | 一元求反           | 从右到左      |             |
| 3          | `+`                          | 一元加             | 从右到左      |             |
| 3          | `&`                          | Address-of         | 从右到左      |             |
| 3          | `*`                          | 间接寻址           | 从右到左      |             |
| 3          | `new`                        | 创建对象           | 从右到左      |             |
| 3          | `delete`                     | 销毁对象           | 从右到左      |             |
| 3          | `typename(V)`, `(typename)V` | 强制转换           | 从右到左      |             |
| 4          | `.*`, `->*`                  | 指向成员的指针     | 从左到右      |             |
| 5          | `*`                          | 乘法               | 从左到右      |             |
| 5          | `/`                          | 除法               | 从左到右      |             |
| 5          | `%`                          | 取模               | 从左到右      |             |
| 6          | `+`                          | 加法               | 从左到右      |             |
| 6          | `-`                          | 减法               | 从左到右      |             |
| 7          | `<<`                         | 左移               | 从左到右      |             |
| 7          | `>>`                         | 右移               | 从左到右      |             |
| 8          | `<`                          | 小于               | 从左到右      |             |
| 8          | `>`                          | 大于               | 从左到右      |             |
| 8          | `<=`                         | 小于或等于         | 从左到右      |             |
| 8          | `>=`                         | 大于或等于         | 从左到右      |             |
| 9          | `==`                         | 等式               | 从左到右      |             |
| 9          | `!=`                         | 不相等             | 从左到右      | `not_eq`    |
| 10         | `&`                          | 按位 “与”          | 从左到右      | `bitand`    |
| 11         | `^`                          | 按位 “异或”        | 从左到右      | `xor`       |
| 12         | `` \| ``                     | 按位 “与或”        | 从左到右      | `bitor`     |
| 13         | `&&`                         | 逻辑与             | 从左到右      | `and`       |
| 14         | `\|\|`                       | 逻辑或             | 从左到右      | `or`        |
| 15         | `? :`                        | 条件               | 从右到左      |             |
| 15         | `=`                          | 赋值               | 从右到左      |             |
| 15         | `*=`                         | 乘法赋值           | 从右到左      |             |
| 15         | `/=`                         | 除法赋值           | 从右到左      |             |
| 15         | `%=`                         | 取模赋值           | 从右到左      |             |
| 15         | `+=`                         | 加法赋值           | 从右到左      |             |
| 15         | `-=`                         | 减法赋值           | 从右到左      |             |
| 15         | `<<=`                        | 左移赋值           | 从右到左      |             |
| 15         | `>>=`                        | 右移赋值           | 从右到左      |             |
| 15         | `&=`                         | 按位 “与” 赋值     | 从右到左      | `and_eq`    |
| 15         | `\|=`                        | 按位 “与或” 赋值   | 从右到左      | `or_eq`     |
| 15         | `^=`                         | 按位 “异或” 赋值   | 从右到左      | `xor_eq`    |
| 15         | `throw`                      | 引发表达式         | 从右到左      |             |
| 16         | `,`                          | 顺序运算           | 从左到右      |             |
	         	
>---
#### alignof 对齐

`alignof` 指定类型的对齐方式（以字节为单位）作为类型 `size_t` 的值返回；常作为某个内存分配例程的参数出现。

```c++
typedef alignas(32) struct { int a; double b; } S;
int n = 50; // array size
S* p = (S*)aligned_malloc(n * sizeof(S), alignof(S));
```

可以使用 `#pragma pack`、`alignas` 修改类型对象的对齐方式；

```c++
#include <stddef.h>
#include <stdio.h>

struct S {
	int i;      // size 4
	short j;    // size 2
	double k;   // size 8
};

#pragma pack(2)
struct T {
	int i;
	short j;
	double k;
};
#pragma pack(0)  // 恢复默认
int main() {
	printf("alignof(S) %zu ", alignof(S));  // 8
	printf("sizeof(S) %zu ", sizeof(S));  // 16
	printf("%zu ", offsetof(S, i));  // 0
	printf("%zu ", offsetof(S, j));  // 4 
	printf("%zu\n", offsetof(S, k)); // 8

	printf("alignof(T) %zu ", alignof(T));  // 2
	printf("sizeof(T) %zu ", sizeof(T));  // 14
	printf("%zu ", offsetof(T, i));  // 0
	printf("%zu ", offsetof(T, j));  // 4
	printf("%zu\n", offsetof(T, k)); // 6
}
```

>---
#### 算数运算

```c++
auto add = a + b;
auto sub = a - b;
auto mul = a * b;
auto div = a / b;
auto mod = a & b;   // integer
auto post = +a;
auto nega = -a;
```

在 Microsoft C++ 中，取模表达式的结果的符号始终与第一个操作数的符号相同。

>---
#### 增量减量运算

```c++
i++;  // 后缀递增
i--;  // 后缀递减
++i;  // 前缀递增
--i;  // 后缀递增
```

无法保证后缀运算作为函数或表达式参数按期望的值进行传递；副作用可能发生在表达式求值或参数求值之后。前缀运算的副作用发生在作为传递参数或赋值等操作之前；

```c++
int i = 10;  // or float
cout << i++ << endl;  // 10
cout << i << endl;    // 11
cout << --i << endl;  // 10
```

不支持直接对枚举类型或其他用户定义类型执行前缀或后缀运算；可以设置用户定义运算符：

```c++
enum Compass { North, South, East, West };
Compass myCompass;
for( myCompass = North; myCompass != West; myCompass++ ) // Error
    ;

Compass& operator++(Compass& c) {
	c = static_cast<Compass>(c + 1);
	return c;
}  // 前缀递增
Compass& operator--(Compass& c) {
	c = static_cast<Compass>(c - 1);
	return c;
}  // 前缀递减
Compass operator++(Compass& c, int i) {
	c = static_cast<Compass>(c + i);
	return c;
}  // 后缀递增
Compass operator--(Compass& c, int i) {
	c = static_cast<Compass>(c - i);
	return c;
}  // 后缀递减

Compass myCompass;
for (myCompass = North; myCompass != West; myCompass++) // ok
	;
for (myCompass = North; myCompass != West; ++myCompass) // ok
	;
```

>---
#### Address-of

*Address-of* 运算符 (`&`) 返回其操作数的地址；操作数是函数指示符，或引用非位字段对象的 *lvalue*（基本类型、结构、类或联合的变量，或下标数组引用）。仅当明确要引用的函数的版本时，才能采用重载函数的地址。

应用于限定名时，结果将取决于限定名称是否指定静态成员，则结果为指向成员类型的指针。对于非静态成员，则结果为指向由限定名称指示的类的成员名称的指针。

```c++
class PTM {
public:
    int iValue;
    static float fValue;
};

int main() {
   int   PTM::*piValue = &PTM::iValue;  // OK: non-static
   float PTM::*pfValue = &PTM::fValue;  // error: static
   float *spfValue     = &PTM::fValue;  // OK
// 由于 `fValue` 是静态成员，因此表达式 `&PTM::fValue` 产生
// 类型 `float *` 而不是类型 `float PTM::*`。
}
```

>---
#### Size-of

```c++
sizeof ( type-name );
sizeof unary-expr; 
sizeof ( unary-expr ); 
```

`sizeof` 返回给定 `type-name` 或一个一元表达式的字节大小；结果为 `size_t`。`sizeof` 是不求值表达式。

当 `sizeof` 运算符应用于 `class`、`struct` 或 `union` 类型时，结果是该类型对象中的字节数，加上为对齐字边界上的成员而添加的任何填充。结果不一定对应于通过将各个成员的存储需求相加计算出的大小。不计算结构中灵活数组的大小。

`type-name` 不能是函数、位域、未定义类、`void`、动态分配的数组、外部数组、不完整类型或不完整类型名称。

```c++
sizeof(ClassA);
sizeof(int);
sizeof ptr;
auto arrLength = sizeof array / sizeof array[0]
```

>---
#### 成员访问

```c++
struct X
{
	void m_func() {
		cout << m_num << endl;
	};
	int m_num;
};
int main() {
	// 函数成员指针
	void (X:: * pxfun)() = &X::m_func;
	int X::* pxnum = &X::m_num;

	X x{0};
	X* px = new X;
	
	// . -> 访问
	x.m_num = 10;
	x.m_func();
	px->m_num = 100;
	px->m_func();

	// .* ->* 成员指针访问
	(x.*pxfun)();  // 10
	x.*pxnum = -10;
	(px->*pxfun)(); // 100
	//px->*pxnum = -100;
}
```

>---
#### 范围解析

范围解析运算符 `::` 用于标识和消除在不同范围内使用的标识符。`:: qualified-id` 表示从全局范围查找。

```c++
namespace NamespaceB {
    class ClassB {
    public:
        int x;
    };
}
namespace NamespaceC{
    using namespace NamespaceB;
}
int main() {
    NamespaceB::ClassB b_b;
    NamespaceC::ClassB c_b;
    b_b.x = 3;
    c_b.x = 4;
}
```

必须使用范围解析运算符来调用类的静态成员。

```c++
class ClassG {
public:
    static int get_x() { return x;}
    static int x;
};

int ClassG::x = 6;
int main() {
    int gx1 = ClassG::x;
    int gx2 = ClassG::get_x();
}
```

范围解析运算符还可以与区分范围的枚举值一起使用：

```c++
enum class EnumA{
    First, Second, Third
};

EnumA enum_value = EnumA::First;
```

>---
#### 赋值运算

```c
int a = b;  
int a += b; // a = a + b
int a -= b;
int a *= b;
int a /= b;
int a %= b;
int a <<= b;
int a >>= b;
int a &= b;  // a = a and_eq b
int a ^= b;  // a = a or_eq  b
int a |= b;  // a = a xor_eq b
```

`const` 和 `volatile` 类型的对象可以赋给仅为 `volatile` 或不为 `const` 或 `volatile` 的类型的左值。

对类类型（`struct`、`union` 和 `class` 类型）的对象的赋值由 `operator=` 函数执行。默认行为是将执行对象的非静态数据成员和直接基类的逐个成员复制赋值；任何从给定基类明确派生的类的对象均可赋给基类的对象。

在 ANSI C 中，赋值表达式的结果不是左值。 这意味着 C 中不允许使用合法的 C++ 表达式 `(a += b) += c`。

>---
#### 按位运算

```c++
unsigned char a = 0b10100101;
unsigned char b = 0b11000011;
auto print = [=](unsigned char expr) {
	char s[64];
	_itoa_s(expr, s, 64, 2);
	printf("%08.8s\n", s);
	};
print(a & b);  // 10000001; 按位与
print(a | b);  // 11100111; 按位或
print(a ^ b);  // 01100110; 按位异或
print(~a);     // 01011010; 按位求补
```

>---
#### 移位运算

`<<` 左移用零补齐低位，是逻辑移位；`>>` 右移时，无符号数零补齐高位，有符号数符号位补齐高位 (Microsoft C++ 行为)。

```c++
unsigned char c1 = 64;
cout << bitset<8>{ (unsigned __int64)c1 } << endl;		// 01000000
cout << bitset<8>{ (unsigned __int64)c1 << 1} << endl;	// 10000000
cout << bitset<8>{ (unsigned __int64)c1 >> 2 } << endl;	// 00010000

signed char c2 = -55;
cout << bitset<8>{ (unsigned __int64)c2 } << endl;		// 11001001
cout << bitset<8>{ (unsigned __int64)c2 << 3} << endl;	// 01001000
cout << bitset<8>{ (unsigned __int64)c2 >> 2 } << endl;	// 11110010
```

>---
#### 强制转换

`()` 运算符提供了用于显式转换对象类型的方法。

```c++
typeA a = (typeA)vb;   // cast 形式的强制类型转换
typeA a = typeA(vb);   // 显式类型转换
```

用户定义的强制转换 `operator type ()`：

```c++
struct KM {
	long double distance;
public:
	KM() { distance = 0; };
	KM(long double dis) { distance = dis; };
	operator long double() { return distance; }   // user-defned cast
	KM operator=(int dis) { return KM{ (long double)dis }; }
	KM operator=(long double dis) { return KM{ dis }; }
	KM operator=(unsigned long long dis) { return KM{ (long double)dis }; }
};
KM operator ""km(long double dis) {
	return KM{ dis };
};
KM operator ""km(unsigned long long dis) {
	return KM{ (long double)dis };
};

int main() {
	KM d1 = 10km;    // int to KM
	KM d2 = 3.14km;  // double to KM
	KM d3 = 10;
	KM d4 = 3.14L;
	long double d = d1;  // or (long double)d1;
}
```

`cast` 语法只能从单个值转换，在强制转换中的类型定义是非法的。显式类型转换可以转换指定多个自变量，例如：

```c++
struct Point { int x, y; };
Point p = Point(1, 2);
```

有几种特定于 C++ 语言的转换运算符。

```c++
// 操作数 expression 转换为 type-id 类型的对象;
dynamic_cast < type-id > ( expression )   

// 仅根据表达式中存在的类型，将 expression 转换为 type-id 类型
static_cast <type-id> ( expression )    

// 从某个类删除 const、volatile 和 __unaligned 属性。
const_cast <type-id> (expression)          

// 允许将任何指针转换为任何其他指针类型。也允许将任何整数类型转换为任何指针类型以及反向转换。
reinterpret_cast < type-id > ( expression )  
```

> *dynamic_cast*

`dynamic_cast` 用于多态类型的转换。`type-id` 是类类型的指针或引用，或者是 `void*`；

托管代码中的 `dynamic_cast` 行为有两项中断性变更：
  - 对指向装箱枚举的基础类型的指针的 dynamic_cast 将在运行时失败，返回 0 而不是转换后的指针。
  - 当 `type-id` 是指向值类型的内部指针时，`dynamic_cast` 将不再引发异常，失败返回空指针值；强制转换在运行时失败。

如果 `type-id` 是指向 `expression` 的明确可访问的直接或间接基类的指针，则结果是指向 `type-id` 类型的唯一子对象的指针。

```c++
class B { };
class C : public B { };
class D : public C { };

D* pd = new D;
C* pc = dynamic_cast<C*>(pd);   
// ok: C is a direct base class, pc points to C subobject of pd
B* pb = dynamic_cast<B*>(pd);  
// ok: B is an indirect base class, pb points to B subobject of pd
```

如果 `type-id` 是 `void*`，则进行运行时检查以确定 `expression` 的实际类型。结果是指向由 `expression` 指向的完整对象的指针。

```c++
class A {virtual void f();};
class B {virtual void f();};

A* pa = new A;
B* pb = new B;
void* pv = dynamic_cast<void*>(pa);  // pv now points to an object of type A
pv = dynamic_cast<void*>(pb);        // pv now points to an object of type B
```
  
如果 `type-id` 不是 `void*`，则进行运行时检查，看看是否可以将 `expression` 指向的对象转换为 `type-id` 指向的类型。
  
如果 `expression` 的类型是 `type-id` 类型的基类，则进行运行时检查，看看 `expression` 是否实际指向 `type-id` 类型的完整对象。如果是，则结果是指向 `type-id` 类型的完整对象的指针。

```c++
class B {virtual void f();};
class D : public B {virtual void f();};

B* pb = new D;   // unclear but ok
B* pb2 = new B;
D* pd = dynamic_cast<D*>(pb);     // ok: pb actually points to a D
D* pd2 = dynamic_cast<D*>(pb2);   // not ok: pb2 points to a B not a D
```

如果有多重继承，可能会导致不明确。使用虚拟基类时，可能会导致更多不明确的情况。

```c++
class A { virtual void f(); };
class B : public A { virtual void f(); };
class C : public A { virtual void f(); };
class D : public B, public C { virtual void f(); };

D* pd = new D;
A* pa = dynamic_cast<A*>(pd);   // C4540, ambiguous cast fails at runtime

// 指向 `D` 类型对象的指针可以安全地强制转换为 `B` 或 `C`。但是，如果 `D` 强制
// 转换为指向 `A` 对象的指针，会产生 `A` 的哪个实例？ 这将导致不明确的强制转换错误。
// 若要解决此问题，可以执行两个明确的强制转换。
B* pb = dynamic_cast<B*>(pd);   // first cast to B
A* pa2 = dynamic_cast<A*>(pb);  // ok: unambiguous
```

未能强制转换为指针类型的值是空指针。如果对引用类型的强制转换失败，会引发 `bad_cast` 异常。 如果 `expression` 没有指向或引用有效对象，则会引发 `__non_rtti_object` 异常。

```c++
class A { virtual void g() {} };
class B { virtual void f() {} };

int main() {
	A* pa = new A;
	try {
		B* pb = dynamic_cast<B*>(pa);   // fails at runtime, not safe;  
		// B not derived from A; pb is null
		B& rb = dynamic_cast<B&>(*pa);  // Bad dynamic_cast!
	}
	catch (bad_cast e) {
		cout <<  e.what() << endl;  
	}
}
```

> *static_cast*

`static_cast` 用于非多态类型的转换。可用于将指向基类的指针转换为指向派生类的指针等操作，但非始终安全。通常使用 `static_cast` 转换数值数据类型，例如将枚举型转换为整型或将整型转换为浮点型。

`static_cast` 转换安全性不如 `dynamic_cast` 转换，因为 `static_cast` 不执行运行时类型检查。

```c++
class B {};
class D : public B { int V; };

B b{};
B* pb = &b; 
D* pd = static_cast<D*>(pb);   // Not safe, D can have fields
```

与 `dynamic_cast` 不同，`pb` 的 `static_cast` 转换不执行运行时检查。由 `pb` 指向的对象可能不是 `D` 类型的对象，在这种情况下使用 `*pd` 会是灾难性的。

```c++
class B {
public:
	virtual void Test() {}  // 多态类型
};
class D : public B {};

int main() {
	B b{};
	B* pb = &b;

	// D* pd1 = pb; // not allowed  
	D* pd1 = dynamic_cast<D*>(pb);
	D* pd2 = static_cast<D*>(pb);
}
```

如果 `pb` 确实指向 `D` 类型的对象，则 `pd1` 和 `pd2` 将获取相同的值。如果 `pb == 0`，它们也将获取相同的值。

如果 `pb` 指向 `B` 类型的对象，而非指向完整的 `D` 类型，则 `dynamic_cast` 足以判断返回零。但是，`static_cast` 依赖于断言，假定 `pb` 指向 `D` 类型的对象；`static_cast` 可以反向执行隐式转换，而在这种情况下结果是不确定的。这需要程序员来验证 `static_cast` 转换的结果是否安全。

```c++
	assert(pd1 == nullptr);  // ok
	assert(pd2 == pd1);  // assert failed
```

该行为也适用于类以外的类型。 例如，`static_cast` 可用于将 `int` 转换为 `char`。但是，得到的 `char` 可能没有足够的位来保存整个 `int` 值。同样，这需要程序员来验证 `static_cast` 转换的结果是否安全。

`static_cast` 运算符还可用于执行任何隐式转换，包括标准转换和用户定义的转换。

```c++
typedef unsigned char BYTE;

void f() {
   char ch;
   int i = 65;
   float f = 2.5;
   double dbl;

   ch = static_cast<char>(i);      // int to char
   dbl = static_cast<double>(f);   // float to double
   i = static_cast<BYTE>(ch);
}
```

`static_cast` 运算符可以将整数值显式转换为枚举类型。如果整型值不在枚举值的范围内，生成的枚举值是不确定的。运算符可以将空指针值转换为目标类型的空指针值。

任何表达式都可以通过 `static_cast` 运算符显式转换为 `void` 类型。目标 `void` 类型可以选择性地包含 `const`、`volatile` 或 `__unaligned` 特性。`static_cast` 运算符无法强制转换掉 `const`、`volatile` 或 `__unaligned` 特性。

```c++
enum E {
	a,b,c,d,
};
void main() {
	//E a = 0;  // not assigned to
	const E a = static_cast<E>(0);  // ok; == E::a
	assert(a == E::a);  // assert success
}
```

> *const_cast*

`const_cast` 用于删除 `const`、`volatile` 和 `__unaligned` 特性。指向任何对象类型或数据成员的 `const`、`volatile`、`__unaligned` 指针可显式转换为完全相同的原始类型；结果将引用原始对象或数据成员的原始对象。根据引用对象的类型，通过生成的指针、引用或指向数据成员的指针的写入操作可能产生未定义的行为。

`const_cast` 也可以将一个空指针值转换为其他目标类型的空指针值。不能使用 `const_cast` 运算符直接重写 `constexpr` 变量的常量状态。

```c++
int number = 10010;
const int& ref_number = number;
int& v = const_cast<int&>(ref_number);
v = 110; 
assert(v == number);  // assert success; both are 110

constexpr int c_number = 10086;
const int& ref_c_number = c_number;
v = const_cast<int&>(ref_c_number);
v = 911;
assert(v == c_number); // failed; c_number = 10086
```

> *reinterpret_cast* 

`reinterpret_cast` 用于对位进行简单的重新解释。允许将任何指针转换为任何其他指针类型，也允许将任何整数类型转换为任何指针类型以及反向转换。

滥用 `reinterpret_cast` 运算符可能很容易带来风险。`reinterpret_cast` 运算符可用于 `char*` 到 `int*` 或 `One_class*` 到 `Unrelated_class*` 之类的转换，这本身并不安全。`reinterpret_cast` 运算符无法强制转换掉 `const`、`volatile` 或 `__unaligned` 特性。

一般使用 `reinterpret_cast` 将空指针值转换为目标类型的空指针值。也允许将指针视为整数类型，并在指针和整数之间相互转换。

```c++
struct IntVector2 { int x, y; };
struct IntVector3 { int x, y, z; };

int main() {
	IntVector2* v2 = new IntVector2{ 2, 2 };
	IntVector3* v3 = new IntVector3{ 3, 3, 3 };

	IntVector2* pv2 = reinterpret_cast<IntVector2*>(v3);  // v3 cast to v2; not safy
	pv2->x = 1; pv2->y = 99;
	printf("v3 = {%d,%d,%d}", v3->x, v3->y, v3->z); // {1,99,3}

	IntVector3* pv3 = reinterpret_cast<IntVector3*>(v2);  // v2 cast to v3; not safy
	pv3->x = 9; pv3->y = 9;
	printf("v2 = {%d,%d}", v2->x, v2->y); // {9,9}
	pv3->z = 10;  // maybe stackOverflow ; danger!
    
	// 未定义行为
	IntVector3 v = static_cast<IntVector3>(*pv3);  
	printf("v = {%d,%d,%d}", v.x, v.y, v.z); // {9,9,10}
}
```

> 向上转换和向下转换

从派生类指针到基类指针的转换是一种隐式的向上转换；反过来从基类指针到派生类指针的转换是向下转换，如果有多层继承，可能会导致不明确。

以下示例演示了 `dynamic_cast` 和 `static_cast` 的用法

```c++
class Base { virtual void f() {}; };
class DerivedA : public Base { virtual void f() {}; };
class DerivedB : public Base { virtual void f() {}; };
class Derived : public DerivedA, public DerivedB {  };

int main() {
	Derived* d = new Derived;
	Base* b = new Base;
	// 向上转换
	DerivedA* da = static_cast<DerivedA*>(d);
	DerivedB* db = static_cast<DerivedB*>(d);
	// 多态的情况下基类不明确
	// Base * bd = static_cast<Base*>(d);  
	// Base* bd = dynamic_cast<Base*>(d);  

	// Derived* pd = static_cast<Derived*>(b);  // 无法编译；Derived 包含多个 Base 的实例
	Derived* pd = dynamic_cast<Derived*>(b); 
	assert(pd == nullptr); // b 不包含 Derived 的值，返回 nullptr
	Base* b1 = dynamic_cast<Base*>(da); // ok; 向上
	Base* b2 = dynamic_cast<Base*>(db); // ok; 向上
	pd = dynamic_cast<Derived*>(b1);
	assert(pd != nullptr);  // 向下转换；ok；Base 包含 Derived 的值，且是 DerivedA::Base 到 Derived
	pd = dynamic_cast<Derived*>(b2);
	assert(pd != nullptr);  // 向下转换; ok; Base 包含 Derived 的值，且是 DerivedB::Base 到 Derived
}
```

>---
#### 顺序运算符

顺序运算符 `(expr1, expr2)` 始终计算左操作数，并且在计算右操作数之前将完成所有副作用，表达式的类型和值是右操作数的类型和值。

```c++
int i = 10, b = 20, c= 30;
i = b, c;  // i = b = 20

i = (b, c); // i = c = 30

i = ((b , c), ++i);   // i = ++i
```

>---
#### 条件运算符

```c++
cond-expr ? true-expr : false-expr
```

`cond-expr` 必须是整数（`bool`）或指针类型；条件运算的结果是第二个或第三个表达式的计算结果；两者具有相同的类型或兼容类型，或 `void`，或第三个操作数返回 `std::exception`。

```c++
isRequest ? Handle(httpRequest) : throw exception{};
```

>---
#### 关系和相等运算

```c++
bool rt = a == b;
bool rt = a != b;
bool rt = a >= b;
bool rt = a <= b;
bool rt = a > b;
bool rt = a < b;
```

>---
#### 逻辑运算

```c++
bool rt = expr1 && expr2;
bool rt = expr1 || expr2;
bool rt = !expr;
```

逻辑运算符的操作数必须是布尔、整数或指针类型或可以转换为 `bool` 的类型。



>---
#### 函数调用和函数调用运算符重载

函数调用运算符 `( argu-list )` 首先对参数列表（如果有）进行求值，参数列表中，首先计算作为实参传递的函数表达式，然后计算任意的参数表达式或默认参数，参数表达式在不确定序列中求值。计算结果可以是函数、函数指针、可调用对象、或对一个对象的引用表达式

函数符号、函数类型、函数指针可以使用函数调用运算符：

```c++
int func(int i) { return i; }       // 返回 T 的函数 func
typedef int funcType(int i);        // 函数类型，具有 T (int i) 签名
typedef int (*funcPointer)(int i);  // 函数指针类型
typedef int(&funcLv)(int i);        // 函数引用
typedef int(&& funcRv)(int i);      // 右值

int main() {
	funcType* f = &func;
	funcPointer pf = &func;
	funcLv flv = func;
	funcRv frv = flv;
    f(0);
    pf(1);
    flv(2);
    frv(3);
}
```

>---
#### new 分配内存

C++ 支持使用 `new` 和 `delete` 运算符动态分配和解除分配对象，`new` 调用特殊函数 `operetor new`，`delete` 调用特殊函数 `operator delete`。`new` 在堆中为对象分配内存。

```c++
type-id * pobj = [::] new type-id ( argu? )?;
type-id * parr = [::] new type-id[size];
[::] delete pobj;
[::] delete [] parr;
```

`new` 尝试分配和初始化指定类型或占位符类型的对象或对象数组，并返回指向对象（或指向数组初始对象）的适当类型化的非零指针。未成功，将返回零或引发异常；可以通过编写自定义异常处理例程并调用 `std::_set_new_handler` 运行时库函数（使用函数名作为其参数）来更改此默认行为。

使用 `new` 为 C++ 类对象分配内存时，将在分配内存后调用对象的构造函数。使用 `delete` 运算符解除由 `new` 运算符分配的内存或数组。`new` 不分配引用类型和函数指针，但可以分配函数指针的数组。

```c++
type *pt1 = new type;
type *pt2 = new type(argus);
const int *cpi = new int(0);
volatile int *vpi = new int(10);
char (*pchar)[10] = new char[dim][10];
int (**p) () = new (int (*[7]) ());

delete cpi;
delete [] pchar;
```

`operator new` 的第一个自变量必须为 `size_t` 类型，且返回类型始终为 `void*`。包含用户定义 `operator new` 的类类型调用用户定义 `new`，否则调用全局 `::operator new`；为类定义的 `operator new` 函数是静态成员函数（不能是虚函数），该函数隐藏此类类型的对象的全局 `operator new` 函数。

```c++
#include <malloc.h>
#include <memory.h>
class Blanks
{
public:
    Blanks(){}
    void *operator new( size_t stAllocateBlock, char chInit );
};
void *Blanks::operator new( size_t stAllocateBlock, char chInit )
{
    void *pvTemp = malloc( stAllocateBlock );
    if( pvTemp != 0 )
        memset( pvTemp, chInit, stAllocateBlock );
    return pvTemp;
}
// For discrete objects of type Blanks, the global operator new function
// is hidden. Therefore, the following code allocates an object of type
// Blanks and initializes it to 0xa5
int main()
{
   Blanks *a5 = new(0xa5) Blanks;
   return a5 != 0;
}
```

如果分配请求的内存不足，`operator new` 会引发 `std::bad_alloc` 异常或 `nullptr`。

```c++
#include <iostream>
#include <new>
using namespace std;
#define BIG_NUMBER 10000000000LL

// 标准 C++ 要求分配器引发 std::bad_alloc 或派生自 std::bad_alloc 的类
try {
    int *pI = new int[BIG_NUMBER];
}
catch (bad_alloc& ex) {
    cout << "Caught bad_alloc: " << ex.what() << endl;
    return -1;
}

// nothrow new
int *pI = new(nothrow) int[BIG_NUMBER];
if ( pI == nullptr ) {
    cout << "Insufficient memory" << endl;
    return -1;
}

// 链接 nothrownew.obj 文件替换全局 operator new
int *pI = new int[BIG_NUMBER];
if ( !pI ) {
    cout << "Insufficient memory" << endl;
    return -1;
}
```

可以为失败的内存分配请求提供处理程序。例如编写自定义恢复例程来处理此类失败。

```c++
void handler()  {
	cerr << "Insufficient memory" << endl;
	throw bad_alloc();
};
set_new_handler(&handler);
int* pI = new int[BIG_NUMBER];
```

>---
#### delete 释放内存

`delete` 用以释放 `new` 动态分配的内存块。`delete` 运算符调用 `operator delete` 函数，并将内存释放回可用池。

```c++
[::] delete cast-expression;       // new ptr
[::] delete [] cast-expression;    // new arr[N]
```

*cast-expression* 自变量必须是指向以前分配给使用 `new` 运算符创建的对象的内存块的指针。对其他指针使用 `delete` 行为未定义；但可以对空指针使用 `delete`，因为 `new` 分配失败时也会返回 `nullptr`；被释放的指针取引用行为未定义。

对对象使用 `delete` 将释放其内存。释放 C++ 类对象（`class`、`struct` 或 `union`）的内存时，将在释放该对象的内存之前调用该对象的析构函数（如果有）；其他非类对象调用全局 `::delete`。对可修改的左值使用，则在 `delete` 该对象后未定义其值。

```c++
struct C {
public:
	~C() { cout << "call ~C" << endl; }
};

int main() {
	C* pc = new C;
	C* pac = new C[10];

	::delete [] pac;
	delete pc;
}
```

全局 `operator delete` 函数和类成员 `operator delete` 函数存在两种形式。只能为给定类定义其中的一个 `operator delete` 函数；如果定义，它会隐藏全局 `operator delete` 函数。始终为所有类型的数组调用全局 `operator delete` 函数。对于不是类类型的对象，将调用全局 `delete` 运算符 `::delete`。

```c++
void operator delete( void * );
void operator delete( void *, size_t );
```

下面是一个记录内存的分配和解除分配的用户定义的 `operator new` 和 `operator delete` 函数：

```c++
#include <iostream>
using namespace std;

int fLogMemory = 0;      
int cBlocksAllocated = 0;  // Count of blocks allocated.

// User-defined operator new.
void* operator new(size_t stAllocateBlock) {
	if (stAllocateBlock == 0) return nullptr;
	static int fInOpNew = 0;   // Guard flag.
	if (fLogMemory && !fInOpNew) {
		fInOpNew = 1;
		cout << "Memory block " << (++cBlocksAllocated)
			<< " allocated for " << stAllocateBlock
			<< " bytes\n";
		fInOpNew = 0;
	}
	return malloc(stAllocateBlock);
}

// User-defined operator delete.
void operator delete(void* pvMem) {
	if (!pvMem) return;
	static int fInOpDelete = 0;   // Guard flag.
	if (fLogMemory && !fInOpDelete) {
		fInOpDelete = 1;
		cout << "Memory block " << cBlocksAllocated--
			<< " deallocated\n";
		fInOpDelete = 0;
	}
	free(pvMem);
}

int main() {
	fLogMemory = 1;   // Turn logging on
	for (int i = 0; i < 10; ++i) {
		char* pMem = new char[i];
		delete[] pMem;
	}
	fLogMemory = 0;  // Turn logging off.
	return cBlocksAllocated;
}
```

在类声明中支持成员数组 `new` 和 `delete` 运算符。

```c++
class X  {
public:
   void * operator new[] (size_t) { return 0; }
   void operator delete[] (void*) {}
};
void f() {
   X *pX = new X[5];
   delete [] pX;
}
```


对于类类型的对象，如果 `delete` 表达式以一元范围解析运算符 (`::`) 开始，则会在全局范围中解析解除分配函数的名称。否则，`delete` 运算符将在释放内存之前为对象调用析构函数（如果指针不为 `null`）。

如果 `delete` 表达式用于释放其静态对象具有虚拟析构函数的类对象，则将通过对象的动态类型的虚拟析构函数解析释放函数。




>---
#### 指针运算与间接寻址

```c++
// address-of
int * pi = &i;
const type cp = &const_type;
volatile type vp = &vola_type;
// 算数
int * p = p + integer;
int * p = p - integer;
ptrdiff_t diff = p1 - p2;
p++;
p--;
p += i;
p -= i;
```

`*` 取消引用指针将其转换为一个左值。如果该指针的值无效，则结果是未定义的。例如：
- 该指针为 null 指针。
- 该指针指定引用时不可见的本地项的地址。
- 该指针指定未针对所指向的对象类型正确对齐的地址。
- 该指针指定执行程序未使用的地址。

```c++
int i = 100;
int *pi = &i;

*pi = 10086; // now i = 10086
```

>---
#### 数组下标运算

```c++
int nArray[5] = { 0, 1, 2, 3, 4 };
cout << nArray[2] << endl;            // prints "2"
cout << 2[nArray] << endl;            // prints "2"

int* pArray = new int[5] { 0, 1, 2, 3, 4 };
cout << pArray[2] << endl;            // prints "2"
cout << 2[pArray] << endl;            // prints "2"

// 多维
int arr[10][10][10]{};
arr[5][5][5] = 1;
5[5[5[arr]]] = 1;  // 不推荐
```

C++ 数组的范围是从 `array[0]` 到 `array[size – 1]`；但支持正负下标，数组下标错误不会产生编译时错误。负下标必须在数组边界内，否则结果不可预知：

```c++
#include <iostream>
using namespace std;
int main() {
    int intArray[1024];
    for (int i = 0, j = 0; i < 1024; i++)
        intArray[i] = j++;
    cout << intArray[512] << endl;   // 512
    cout << 257[intArray] << endl;   // 257
    int *midArray = &intArray[512];  // pointer to the middle of the array
    cout << midArray[-256] << endl;  // 256
    cout << intArray[-256] << endl;  // unpredictable, may crash
}
```

重载下标运算符：

```c++
template<typename T> 
struct Array {
	T* arr;
	size_t len;
public:
	Array(size_t size) {
		arr = new T[size];
		len = size;
	}
	T& operator [] (size_t i) {
		if (i < 0 || i >= len) 
			throw out_of_range("i");
		return this->arr[i];
	}
	~Array() { delete arr; }
};

int main() {
	Array<int> arr(10);
	arr[10] = 10;
}
```

>---
#### typeid

```c++
typeid(type-id)
typeid(expression)
```

`typeid` 运算符允许在运行时确定对象的类型；结果是 `const type_info&`。`typeid` 运算符不适用于托管类型（抽象声明符或实例）。在应用于多态类类型的 *lvalue* 时执行运行时检查，其中对象的实际类型不能由提供的静态信息确定。 此类情况是：
- 对类的引用
- 使用 `*` 取消引用的指针
- 带下标的指针 (`[ ]`)。将下标与指向多态类型的指针一起使用是不安全的。
		
如果 `expression` 指向基类类型，但对象是派生类型的值，则结果是派生类型的 `type_info`。`expression` 必须指向多态类型（具有虚函数的类）。否则结果是 `expression` 中引用的静态类的 `type_info`。必须取消引用指针，这样使用的对象就是它所指向的对象；否则结果将是指针的 `type_info`。	
		
```c++
class Base {
public:
   virtual void vvfunc() {}
};
class Derived : public Base {};
int main() {
   Derived* pd = new Derived;
   Base* pb = pd;
   cout << typeid( pb ).name() << endl;   // "class Base *"
   cout << typeid( *pb ).name() << endl;  // "class Derived"
   cout << typeid( pd ).name() << endl;   // "class Derived *"
   cout << typeid( *pd ).name() << endl;  // "class Derived"
   delete pd;
}
```		
		
在 `typeif` 中取消引用零值指针将引发 `bad_typeid`；指针不指向有效的对象，则会引发 `__non_rtti_object` 异常。

如果 `expression` 不是指针或对对象的基类的引用，则结果是表示 `expression` 的静态类型的 `type_info` 引用。 表达式的静态类型将引用在编译时已知的表达式的类型。在计算表达式的静态类型时，将忽略执行语义；并且将忽略引用（如果可能）。

```c++
typeid(int) == typeid(int&); // evaluates to true
```

`typeid` 可以在模板中使用，以确定模板参数的类型：

```c++
template < typename T >
T max( T arg1, T arg2 ) {
   cout << typeid( T ).name() << "s compared." << endl;
   return ( arg1 > arg2 ? arg1 : arg2 );
}
```
		
> *type_info* 
		
`type_info` 类描述编译器在程序中生成的类型信息。此类的对象可以有效存储指向类型名称的指针。`type_info` 类还可存储适合比较两个类型是否相等或比较其排列顺序的编码值。

```c++
class DerivedA {};
class DerivedB {};
class Derived : public DerivedA, public DerivedB {  };

int main() {
	Derived* d = new Derived;
	DerivedA* da = static_cast<DerivedA*>(d);
	DerivedB* db = static_cast<DerivedB*>(d);
	assert(typeid(*da) == typeid(*db));  // true;
}
```

---
### 语句
#### 空语句

```c++
while(cond)
    ;
```

>---
#### if-else

```c++
if ( [init-statemnet]; condition ) 
    ;  // body or statement
[ else [if-clause] ]
    ;  // body or statement
```
```c++
if (x < 11)
    cout << "x < 11 is true!\n";  // executed
else
    cout << "x < 11 is false!\n"; // not executed
```

可以可选的包含一个初始化语句。

```c++
if (auto it = m.find(10); it != nullptr)
    cout << it->name << endl;
```

从 C++17 开始，可以使用函数模板中的 `if constexpr` 语句做出编译时分支决策，而无需求助于多个函数重载。

```c++
template<typename T>
auto Show(T t)
{
	//if (std::is_pointer_v<T>) // Show(a) results in compiler error for return *t. Show(b) results in compiler error for return t.
	if constexpr (std::is_pointer_v<T>) // This statement goes away for Show(a)
		return *t;
	else
		return t;
}

int main() {
	using namespace std;
	int a = 42;
	int* pB = &a;
	cout << Show(a) << endl;  // prints "42"
	cout << Show(pB) << endl; // prints "42"
}
```

>---
#### switch-case

```c++
swtich ( [init-statement;] condition ){
    case cond1:
        ;  // statements
        break; // return; 
    // case ...
    [default: ]
}

```

`switch` 语句体由一系列 `case` 标签和一个 `default`（可选）标签组成。语句使控件根据 `condition` 的值转移到其语句正文中的一个标签分支语句 `case` 或 `default`；`condition` 必须是整数型或可明确转换为整数型的类类型；标签之间可以贯穿，编译器给出警告。`condition` 中允许使用一个初始化句。

```c++
struct S {
	int stat;
public:
	S(int stat) { S::stat = stat; };
	int operator ()() {
		return this->stat;
	}
};
int main() {
	S s(1);
	switch (int a = s(); a) // or switch( s() ) // s() 转换为 int
	{
	case 1:
		//...
		break;
	// case ...
	default:break;
	}
}
```

属性 `[[fallthrough]]` 表示在 `case` 之间人为设定的发生贯穿，告知编译器两个 `case` 的贯穿是可行的，不必发出警告；

```c++
switch (1) {
case 1:
	cout << 1 << endl;
	[[fallthrough]];
case 2:
	cout << 2 << endl;
default:break; // warning: fallthrough
}
```

在 `case` 中声明的变量属于 `switch` 语句范围，因此共享名称空间和遵循单一定义原则；但前提是可以访问到它们，即所有可能的执行路径都不会绕过它们。

```c++
// switch (char szChEntered[] = "Character entered was:"; 'a')  // init at swtich condition; is ok
switch ('a')  
{
    // Error. Unreachable declaration.
    char szChEntered[] = "Character entered was: "; 
case 'a':
{
    // Declaration of szChEntered OK. Local scope.
    char szChEntered[] = "Character entered was: ";
    cout << szChEntered << "a\n";
}
break;
case 'b':
    // Error. Value of szChEntered undefined.
    cout << szChEntered << "b\n";
    break;
default:
    // Error. Value of szChEntered undefined.
    cout << szChEntered << "neither a nor b\n";
    break;
}
```

>---
#### goto 与标签

标签具有函数范围，在整个函数内可见，与声明位置无关。

```c++
int main() {
   goto Test2;
   cout << "testing" << endl;
   Test2:
      cerr << "At Test2 label." << endl;
}
```

>---
#### while

执行零次到多次；

```c++
while ( expression ) {
   // statement
};
```

>---
#### do-while

至少执行一次；

```c++
do{
    // statement
}while ( expression );
```

>---
#### for

重复执行语句，直到条件变为 `false`。`init-expr` 和 `loop-expr` 可以包含多个语句。

```c++
for (init-expr?; cond-expr?; loop-expr ) {
    statement
}

// for(;;) == while(true)
for (int a = 1, b = 10; a < b; a++, b--, cout << a * b << '\n')
	;
```

>---
#### for-range

```c++
for ( for-range-declaration : expression)
    statement
```

基于范围的 `for` 循环用来循环访问数组和矢量：

```c++
int x[10]{ 1,2,3,4,5,6,7,8,9,0 };
for (auto e : x)
	cout << e << "\n";
```

有关基于范围的 `for` 的情况：
- 自动识别数组。
- 识别拥有 `.begin()` 和 `.end()` 的容器。
- 对于任何其他内容，使用依赖于自变量的查找 `begin()` 和 `end()`。

```c++
template <typename T>
class Iterator {  // 迭代器
private:
	T* iter;
public:
	Iterator(T* para, size_t n) { iter = para + n; }
	T& operator *() { return *iter; }
	bool operator != (const Iterator& that) { return this->iter != that.iter; }
	Iterator& operator++ () { ++iter; return *this; }
};
template <typename T>
class docker {  // 实现 begin 和 end
private:
	T* p;
	size_t size;
public :
	docker(size_t n, T arr[]) :size(n) { p = arr; }
	Iterator<T> begin() { return Iterator<T>(this->p, 0); }
	Iterator<T> end() { return Iterator<T>(this->p, size); }
};

int main(int argc, char* argv[])
{

	int x[10]{ 1,2,3,4,5,6,7,8,9,0 };
	docker<int> d(10, x);
	for (auto& i : d)
		cout << i << ", ";
}
```

>---
#### break, continue, return

`break` 语句可终止执行最近的封闭循环或其所在条件语句。
`continue` 跳过后续语句并开启最小封闭 `do`、`for` 或 `while` 的下一次迭代。
`return` 终止函数的执行并返回到调用方。

```c++
int f(int i)
{
	int c = 0;
	while (i--) {
		if (i > 100) break;
		if (i % 2 == 0) continue;
		cout << i << ",";
		++c;
	}
	cout << endl;
	return c;
}
int main() {
	auto c = f(10);    // 9,7,5,3,1
	printf("Iterate %d\n", c);  // 5
	c = f(1000);  // break
	printf("Iterate %d\n", c);  // 0
}
```

---
### Namespace

命名空间是一个声明性区域，通过单个标识符的 `using` 声明（`using std::string`）来访问成员 `string`；或 `using` 指令 （`using namespace std`）来访问 `std` 命名空间的所有成员；头文件中的代码应始终使用完全限定的命名空间名称。

```c++
namespace ContosoData
{
    class ObjectManager
    {
    public:
        void DoSomething() {}
    };
    void Func(ObjectManager) {}
}

// 使用完全限定名称访问：
ContosoData::ObjectManager mgr;
mgr.DoSomething();
ContosoData::Func(mgr);

// using 声明
using ContosoData::ObjectManager;
ObjectManager mgr;
mgr.DoSomething();

// using 指令
using namespace ContosoData;
ObjectManager mgr;
mgr.DoSomething();
Func(mgr);
```

如果未在显式命名空间中声明某个标识符，隐式全局命名空间的一部分。`main` 入口函数必须在全局命名空间中。所有 C++ 标准库类型和函数都在 `std` 命名空间或嵌套在 `std` 内的命名空间中进行声明。

普通嵌套命名空间的成员仅属于嵌套，父级访问嵌套空间成员需要使用限定名称；普嵌套命名空间具有对其父级成员的非限定访问权限。

```c++
namespace ContosoDataServer
{
    void Foo();
    namespace Details
    {
        int CountImpl;
        void Ban() { return Foo(); }  // 非限定访问
    }
    int Bar(){...};
    int Baz(int i) { return Details::CountImpl; }  // 限定访问
}
```

内联命名空间的成员被视为父级空间的成员。可以在内联命名空间中声明的模板，然后在父命名空间中声明专用化：

```c++
namespace Parent
{
    inline namespace new_ns
    {
         template <typename T>
         struct C
         {
             T member;
         };
    }
    template<>
    class C<int> {};
}
```

可以将内联命名空间用作版本控制机制，以管理对库的公共接口的更改。

```c++
namespace Contoso
{
    namespace v_10   
    {
        template <typename T>
        class Funcs  // 非内联；无法通过 Contoso::Funcs 访问 v_10::Funcs
        {
        public:
            Funcs(void);            
            T Add(T a, T b);
            T Subtract(T a, T b);
            T Multiply(T a, T b);
            T Divide(T a, T b);  // 只能通过 Contoso::v_10::Funcs::Divide 访问
        };
    }
    inline namespace v_20
    {
        template <typename T>
        class Funcs  // 内联，直接通过 Contoso::Funcs 访问
        {
        public:
            Funcs(void);
            T Add(T a, T b);
            T Subtract(T a, T b);
            T Multiply(T a, T b);
            std::vector<double> Log(double);
            T Accumulate(std::vector<T> nums);
        };
    }
}
```

>---
#### 命名空间别名

```c++
namespace a_very_long_namespace_name { class Foo {}; }
namespace AVLNN = a_very_long_namespace_name;
void Bar(AVLNN::Foo foo){ }
```

>---
#### 匿名命名空间

匿名命名空间中的成员对外不可见，仅对其翻译单元范围可见，对外部文件不可见（相当于内部链接）。

```c++
// flieA.cpp
namespace Parent {
	namespace {
		void Myfunc() {
			std::cout << "Call Myfunc" << std::endl;
		}
	}
	void CallMyfunc() {
		Myfunc();  // 当前翻译单元可见
	}
}
// fileB.cpp
namespace Parent {
	void CallMyfuncOther() {
		// Parent::Myfunc 在当前翻译单元不可见
	}
}
int main() {
	Parent::CallMyfunc(); 
}
```

---
### Enum

枚举是用户定义的类型，其中包含一组 “枚举项” 的命名的整型常量。没有 *integerType* 时默认为 `int`。 

```c++
enum Identifier [: integerType ] { ... }       // 非区分范围枚举
enum class Identifier [: integerType ] {...}  // 区分范围枚举类型

enum Week : unsigned char { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
enum class Suit { Diamonds, Hearts, Clubs, Spades };
```

在非区分范围枚举声明中，非限定枚举项在声明 `enum` 的整个范围中可见。在区分范围的枚举中，枚举项名称必须由 `enum` 类型名称限定。非限定枚举项可以隐式转换为 `int`；限定枚举项无法直接隐式转换，需要 `static_cast` 强制转换。

```c++
int main() {
	Week day = Monday;
	Suit kind = Suit::Hearts;

	int tue = Tuesday;
	int clubs = static_cast<int>( Suit::Clubs);
}
```

> 空枚举项的枚举

仅通过使用显式基础类型而无需定义枚举项的枚举，实际上可以视为一种没有任何其他类型隐式转换的新整型类型。

```c++
// std::byte
enum class byte : unsigned char {};

byte operator|(const byte _Left, const byte _Right) noexcept {
	return static_cast<byte>(
		static_cast<unsigned char>(static_cast<unsigned int>(_Left) | static_cast<unsigned int>(_Right)));
}
byte operator&(const byte _Left, const byte _Right) noexcept {
	return static_cast<byte>(
		static_cast<unsigned char>(static_cast<unsigned int>(_Left) & static_cast<unsigned int>(_Right)));
}
byte operator^(const byte _Left, const byte _Right) noexcept {
	return static_cast<byte>(
		static_cast<unsigned char>(static_cast<unsigned int>(_Left) ^ static_cast<unsigned int>(_Right)));
}
byte operator~(const byte _Arg) noexcept {
	return static_cast<byte>(static_cast<unsigned char>(~static_cast<unsigned int>(_Arg)));
}
byte& operator|=(byte& _Left, const byte _Right) noexcept {
	return _Left = _Left | _Right;
}
byte& operator&=(byte& _Left, const byte _Right) noexcept {
	return _Left = _Left & _Right;
}
byte& operator^=(byte& _Left, const byte _Right) noexcept {
	return _Left = _Left ^ _Right;
}
int test() {
	byte b1{ 0 }, b2{ 1 };
	byte rt = b1 | b2;
	rt = b1 & b2;
	rt = b1 ^ b2;
	rt &= b1;
	rt |= b1;
	rt ^= b1;
}
```

---
### Union

联合是一个用户定义类型，其中所有成员都共享同一个内存位置。它始终仅使用足以存储最大成员的内存。如果任何成员类型具有不常用的 constructor（构造函数），则必须编写代码来显式 construct（构造）和销毁该成员。`union` 无法存储引用。`union` 也不支持继承。直接分配初始化表达式时，将该表达式的结果分配给 `union` 的第一个字段

```c++

union RecordType    // Declare a simple union type
{
	char   ch;
	int    i;
	long   l;
	float  f;
	double d;
	int* int_ptr;
public:
	RecordType(char ch) :ch(ch) {}
	template <typename T>
	void print() {
		T* t = new T;
		memcpy(t, this, sizeof(T));
		std::cout << *t << std::endl;
	}
};
int main() {

	RecordType t1 = { 'A' };  // t2.ch = 'A';
	t1.print<char>();  // 'A'
	RecordType t2(0);
	t2.i = 5;    // t holds an int
	t2.print<int>();   // 5
	t2.f = 7.25; // t now holds a float
	t2.print<float>();   // 7.25
}
```

匿名 `union` 中声明的名称可在周围范围中直接使用，就像非成员变量一样。这意味着匿名 `union` 中声明的名称必须在周边范围中是唯一的。匿名 `union` 受以下限制的约束：
- 如果是在文件或命名空间范围内声明的，还必须将其声明为 `static`。
- 它只能有 `public` 成员；在一个匿名的 `union` 中拥有 `private` 成员和 `protected` 成员会产生错误。
- 它不能具有成员函数。

```c++
// 文件范围或命名空间范围的匿名 union
static union {
    short       iValue;
    long        lValue;
    double      dValue;
}

// 结构中的匿名 union
struct Input
{
    WeatherDataType type;
    union
    {
        TempData temp;
        WindData wind;
    };
};
```

`union` 可以包含具有 `class` 类型的非 `static` 数据成员；如果包含这样一个成员，编译器会自动将非用户提供的任何特殊成员函数标记为 `delete`。如果 `union` 是 `class` 或 `struct` 中的匿名联合，则 `class` 或 `struct` 的非用户提供的任何特殊成员函数都会被标记为 `delete`。


---
### 函数

函数是执行某种操作的代码块。在类范围中定义的函数称为成员函数。函数还可以在命名空间范围中定义（包括隐式全局命名空间）。这类函数称为 *Free* 函数或非成员函数。函数可以重载。

```c++
struct S{
    void foo();  // 成员函数，声明
}
void S::foo() {} // 定义, S::foo 调用

void foo(){}   // Free 函数； ::foo() 调用
```



>---
#### 函数声明修饰符

最多只有一个链接属性声明，其他属性和修饰可以组合。
- `constexpr` 修饰函数返回值，表明函数生成的值可在编译时确定。
- `extern "C"` or `extern "C++"` 声明函数链接规范。
- `static` 声明函数的内部链接。
- `extern` 外部引用声明（非定义），或外部链接声明定义。 
- `inline` 声明内联函数。
- `noexcept` 指定函数是否可以引发异常。

```c++
extern "C" void CCall();
extern "C++" void CXXCall();
static void foo();
extern void foo(auto x);
static constexpr int Sum(const int x, const int y)  {
	return x + y;
}
static inline volatile int foo(int&);
extern "C" const int errHandler(int code) noexcept;
```

- `const` 或 `volatile` 修饰参数或返回类型。 

```c++
volatile auto Temp(const auto a, volatile auto b);
const int Sample::GetValue();
```


仅限成员函数：
- `static` 声明静态成员函数，表明函数不与类的任何对象实例关联（无法调用 `this`）。
- `const` or `volatile` 函数 cv 限定，仅限非静态；只是函数仅由 `const` 类型调用还是 `volatile` 类型调用。
- `virtual`、`override` 或 `final` 指定成员函数是虚函数、重写继承的虚函数、还是密封函数，仅限非静态。
- `&`、`&&` ref 引用限定，仅限非静态成员函数，表明隐式对象参数 (`*this`) 是右值引用或左值引用时要选择的函数重载。

```c++
class Base {
	virtual void OverrideFun() volatile;
	virtual void FinalFun() const;
	virtual void LRefFun()&;
	virtual void RRefFun()&&;
};
class Sample : Base {
	void ConstFun() const;
	void VolatileFun() volatile;
	static void StaticFun();
	virtual void VirtualFun();
	void OverrideFun() volatile override;
	void FinalFun() const final;
	void LRefFun() & override;
	void RRefFun() && override;
	void RRefFun() const&&;    // 重载
	void RRefFun() volatile&&;
};
```

>---
#### 函数原型与定义声明

函数原型声明没有函数主体，是没有完整定义的函数样式声明，可以没有参数名称，函数的主体在其他位置定义；调用没有定义的函数原型会引发编译时错误。一般在头文件中声明函数原型；在源文件中声明定义。

函数定义声明必须和函数原型具有相同的签名；

```c++
// header.h
void Foo(int);

// header.cpp
void Foo(int v){ ... }; 
```

在包含 `main` 的翻译单元中 `#include "header.cpp"` 可能会导致多重定义导致链接失败。 

>---
#### 函数返回类型

函数不能返回另一个函数或内置数组；但是可以返回这些类型的指针，或生成函数对象的 lambda。除此之外可以返回范围内的任何类型的值或 `void` 无返回。可以使用 `auto` 指示编译器从函数体推断返回类型，而不必提供结尾返回的具体类型，`auto` 始终推导为按值返回，且不会保留它推到的类型的常量性等属性。

```c++
int getInt();
std::string getString();
void VoidReturn();
void* getBuffer(size_t size);

template<typename T> 
T* createArray(size_t size);

typedef void (*pf)();
pf getFunPtr();

template<typename Lhs, typename Rhs>
auto Add2(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs; // returns a non-const object by value
}
```

返回类型可以有 `const` 或 `volatile` 限定，或按引用返回；`auto&`、`auto&&` 按引用返回：

```c++
const char * hello = "hello world";
const char*& getString() { return hello; }

volatile class Time {};
volatile Time& timeNow();

auto&& getValue();
```

> *结尾返回类型*

结尾返回类型位于签名的最右侧，带有 `-> decltype( expr )`；当返回值的类型取决于模板参数时，结尾返回类型在函数模板中尤其有用。当 `auto` 与结尾返回类型结合使用时，它对于 `decltype` 表达式生成的任何内容都只用作占位符，本身不执行类型推导。

`decltype(auto)` 类型推断规则将保留所有类型信息。

```c++
template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs)
{
    return lhs + rhs;
}
// 等效写法
template<typename Lhs, typename Rhs>
decltype(auto) Add(const Lhs& lhs, const Rhs& rhs)
{
    return lhs + rhs;
}
```

> 多值返回

可通过多种方式从函数返回多个值；
- 将值封装在命名类或结构对象中。要求类或结构定义对调用方可见；

```c++
struct S
{
    string name;
    int num;
};
S g(){ return {"name", 110 } };
```

- 返回 `std::tuple` 或 `std::pair` 对象；

```c++
std::tuple<int, string, double> f()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}
int main()
{
    auto t = f();
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    // --or--
    int myval;
    string myname;
    double mydecimal;
    tie(myval, myname, mydecimal) = f();
    cout << myval << " " << myname << " " << mydecimal << endl;
}
```

- 使用结构化绑定 `auto[v1,v2,...] = f()`；存储返回值的变量在声明的同时被初始化。

```c++
auto[a, b] = g();    // init from POD struct S
auto[x, y, z] = f(); // init from tuple

cout << a << " " << b << endl;
cout << x << " " << y << " " << z << endl;
```

- 使用 ref 引用传递的参数返回；函数可以修改或初始化调用方提供的引用对象的值：

```c++
int foo(const int in, int& out) {
    out = in;
    return in;
}
```

>---
#### 函数形参实参

函数具有零种或多种类型的逗号分隔参数列表，其中每个参数都具有可以用于在函数体内访问它的名称。函数模板可以指定更多类型或值参数。

默认情况下，参数通过值传递给函数，这意味着函数会收到所传递的对象的副本：

```c++
void DoSomething(std::string input){...}
```

若传递的数据类型创建副本的成本过高，可以按引用传递参数：

```c++
void DoSomething(std::string& input){...}
```

若要显式处理通过右值引用或通过左值引用传递的自变量：

```c++
void DoSomething(std::string&& input){...}
```

参数可以有 `const` 或 `volatile` 限定修饰，表明参数是只读或易变属性：

```c++
void DoSomething(const std::string& input, volatile int msgCode){...}
```

无参时可选使用 C 风格的 `void`：

```c++
void DoSomething( void ){...}
```

>---
#### 非静态成员函数的隐式 *this* 参数 

`static` 函数没有提供 `this` 指针作为第一个传递的隐式参数；非静态的成员函数要求隐式 `this` 指针取调用该函数的对象类型相匹配；
- 常规函数中 `this` 被视为 `class_name * const`；
- 在 `const` 限定函数中，`this` 是 `const class_name * const`；
- 在 `volatile` 限定函数中，`this` 是 `volatile class_name * const`；

`obj.name` 的成员运算符实际上是 `(&obj)->name`；非静态成员函数的调用，实际上是 `func(&obg, argu-list)`

```c++
class S {
public:
	// cv 限定区分
	void foo() { cout << "normal foo\n"; }
	void foo() const { cout << "const foo\n"; }
	void foo() volatile { cout << "volatile foo\n"; }
};
int main()
{
	S s{};  	      s.foo();	// normal foo
	const S cs{};     cs.foo();	// const foo
	volatile S vs{};  vs.foo();	// volatile foo

}
```

引用限定符可以根据 `this` 指向的对象是 `rvalue` 还是 `lvalue` 来重载成员函数。但要求所有签名相同的成员函数都具有或不具有引用限定：

```c++
class S {
public:
    // ref 限定
	void foo()& { cout << "& foo\n"; }
	void foo()const& { cout << "const& foo\n"; }
	void foo()volatile& { cout << "volatile& foo\n"; }
	void foo()&& { cout << "&& foo\n"; }
	void foo()const&& { cout << "const&& foo\n"; }
	void foo()volatile&& { cout << "volatile&& foo\n"; }
}
const S&& getRCS() { return S{}; }
volatile S&& getRVS() { return S{}; }
int main()
{
	S s{};			 s.foo();	// & foo
	const S cs{};	 cs.foo();	// const& foo
	volatile S vs{}; vs.foo();	// volatile& foo

	S& ls = s;			  ls.foo();	 // & foo
	const S& lcs{};		  lcs.foo(); // const& foo
	volatile S& lvs = s;  lvs.foo(); // volatile& foo

	/* rs */  (S{}).foo();	  // && foo
	/* rcs */ getRCS().foo(); // const&& foo
	/* rvs */ getRVS().foo(); // volatile&& foo
}
```




>---
#### 默认参数值

函数签名中的最后一个或几个参数可能会分配有默认自变量，这意味着调用方可能会在调用函数时省略自变量。当函数重载决同时匹配常规函数和具有默认参数的函数时，则会引发二义性错误。

```c++
int print( double dvalue );                // Print a double.
int print( double dvalue, int prec);       // Print a double with a given precision.
// 可以将 `print double` 进行功能合并，并对 `prec` 提供默认值：
int print( double dvalue, int prec=2 ); 
```

>---
#### 可变参数

函数的最后一个参数可以是可变参数 `...`，访问可变参数使用头文件 `stdarg.h` 中的 `va_arg`、`va_copy`、`va_end`、`va_start`。`char` 传递给可变参数时转换为 `int`；`flaot` 转换为 `double`；其他类型的值受常见整数和浮点数数值提升的限制。

```c++
#include <cstdarg>
// 约定 f = float,c=char,s=char*,i=int
void ShowVar(const char* szTypes, ...);
int main() {
    ShowVar("fcsi", 32.4f, 'a', "Test string", 4);
}
void ShowVar(char* szTypes, ...) {  
    va_list vl;
    int i;
    va_start(vl, szTypes);
    for (i = 0; szTypes[i] != '\0'; ++i) {
        union Printable_t {
            int     i;
            float   f;
            char    c;
            char* s;
        } Printable;
        switch (szTypes[i]) {   // Type to expect.
        case 'i':
            Printable.i = va_arg(vl, int);
            printf_s("%i\n", Printable.i);
            break;
        case 'f':
            Printable.f = va_arg(vl, double);
            printf_s("%f\n", Printable.f);
            break;
        case 'c':
            Printable.c = va_arg(vl, char);
            printf_s("%c\n", Printable.c);
            break;
        case 's':
            Printable.s = va_arg(vl, char*);
            printf_s("%s\n", Printable.s);
            break;
        default:
            break;
        }
    }
    va_end(vl);
}
```

>---
#### 函数重载

允许在同一范围内指定多个同名函数。这些函数称为重载函数或重载。可以根据参数的类型和数量为函数提供不同的语义。无法通过返回类型的不同和 `noexcept` 异常规范进行重载。

可以通过参数数目、类型、是否包含可变参数、`const` 或 `volatile` 函数限定、`&` 或 `&&` 限定等区分用于重载：

```c++
class S {
public:
	void foo() {}
	void foo(int, ...) {}    // 可变参数区分
	void foo(int, float) {}  // 参数数目区分

	// 参数类别区分
	// void foo(int) {} 
	void foo(long) {}
	void foo(int&) {}     // 调用 int a; foo(a) 无法区分 foo(int) 与 foo(int&)
	void foo(const int&) {}
	void foo(volatile int&) {}
	void foo(int&&) {}   // 调用 foo(10) 无法区分 foo(int) 与 foo(int&&)
	void foo(const int&&) {}
	void foo(volatile int&&) {}

	// cv 限定区分
	void foo(int) const {}
	void foo(int) volatile {}

	// ref 限定区分
	// 仅通过引用限定进行区分的重载需要全部都具有引用限定或都不具有
	void foo(float)& {}
	void foo(float)&& {}
	void foo(float)const& {}
	void foo(float)const&& {}
	void foo(float)volatile& {}
	void foo(float)volatile&& {}

	void foo(auto) {}
	// 可以通过编译，但无法通过函数决策; 它们无法进行区分
    template<typename T>
	decltype(auto) foo(T t) { return t; }
	template<typename T>
	// auto foo(T t) { return t; }    
	// template<typename T>
	// auto foo(T t) -> decltype(t) { return t; }
};
```

编译器根据当前范围内的函数声明与函数调用中提供的参数的最佳匹配，来选择要调用的重载函数。如果找到合适的函数，则调用该函数。编译器为每个自变量创建一组候选函数。其中的实际自变量可以转换为形式自变量的类型。为每个自变量生成一组 “最佳匹配函数”，并且所选函数是所有集的交集。如果交集包含多个函数，则重载是不明确的并会生成错误。

> *Microsoft 专用:*

可以根据返回类型重载 `operator new`，特别是根据指定的内存模型修饰符。

```c++
// Microsoft C++


```

> *参数匹配和转换*

当编译器尝试根据函数声明中的参数匹配实际参数时，如果未找到任何确切匹配项，它可以提供标准转换或用户定义的转换来获取正确类型。不考虑包含多个用户定义转换的转换序列。也不考虑可通过删除中间转换来缩短的转换序列。

常用转换有：

```c++
typename        to  	typename&
typename&	    to      typename
typename[]	    to      typename*
typename	    to      const typename
typename	    to      volatile typename
typename*	    to      const typename*
typename*	    to      volatile typename*
typename(argument-list)   to  	(*typename)(argument-list)
```

还包括数值提升，简单类型隐式转换等。枚举类型是不同的类型，并且可用于区分重载函数。类型 “array of” 和 “pointer to” 是等效的，适用一维数组。

从指向派生类的指针到指向直接或间接基类的指针的转换优于到 `void *` 或 `const void *` 的转换。从指向派生类的指针到指向基类的指针的转换会产生一个到直接基类的更好匹配。

如果内置提升或转换不存在，则用户定义的转换将适用。这些转换是根据要匹配的参数的类型来选择的。

```c++
class UDC
{
public:
   operator int() { return 0;}
   operator long();
};
void Print( int i ) {};
void LogToFile( long l ){};
int main()
{
    UDC udc;
    Print( udc ); // use operator int() 
    
    LogToFile(udc); // check operator long()
    // 由于 UDC:operator long() 没有定义，因此编译器首先使用 int(), 再进行数值提升 int to long 的标准转换  
}
```

如果需要任何用户定义的转换来匹配参数，则在计算最佳匹配时不会使用标准转换。即使多个候选函数需要用户定义的转换，这些函数也被认为是相等的。

```c++
class UDC1
{
public:
   UDC1( int );  // User-defined conversion from int.
};
class UDC2
{
public:
   UDC2( long ); // User-defined conversion from long.
};
void Func( UDC1 );
void Func( UDC2 );
int main()
{
   Func( 1 );   // 二义性
}
```

> *重载、重写和隐藏*

在基类中声明的函数与在派生类中声明的函数不在同一范围内。 如果使用与基类中的 `virtual` 函数相同的名称声明派生类中的函数，则该派生类函数会重写基类函数。如果派生类函数没有 `virtual`、`override`、`final`，则视为该同名名称的函数隐藏了基类函数。

块中声明的本地函数（引用外部）与外部范围的函数或成员的名称相同，视为隐藏，仅能通过完全限定（静态 class_name::static_func）、或 `this->member` 访问被隐藏的名称。 

```c++
void Foo(int) {}
void Foo(const char*) {}
int main()
{
	extern void Foo(const char*);
	Foo("hello");
	Foo(1);    // err;  hidden
	::Foo(1);  // ok;
}
```

通过 `using` 声明引入名称和 `extern` 引用声明的名称相同时，若指向同一个函数定义则将引发冲突；

```c++
void Foo(int) {}
void Foo(const char*) {}
int main()
{
	extern void Foo(const char*);
    using ::Foo;  // 冲突
}
```


>---
#### 显式 default 和 delete 函数

`default` 函数和 `delete` 函数可以显式控制是否自动生成特殊成员函数。`delete` 函数防止所有类型的函数（特殊成员函数和普通成员函数以及非成员函数）的自变量中出现有问题的类型提升，这可能会导致意外的函数调用。

在 C++ 中，如果某个类型未声明它本身，则编译器将自动为该类型生成默认构造函数、复制构造函数、复制赋值运算符和析构函数、移动构造函数和移动赋值运算符。这些函数称为特殊成员函数，它们使 C++ 中的简单用户定义类型的行为如同 C 中的结构。其中：
- 显式声明了任何构造函数，则不会自动生成默认构造函数。
- 显式声明了虚拟析构函数，则不会自动生成默认析构函数。
- 显式声明了移动构造函数或移动赋值运算符，则不自动生成复制构造函数和成复制赋值运算符。
- 显式声明了复制构造函数、复制赋值运算符、移动构造函数、移动赋值运算符或析构函数，则不自动生成移动构造函数和移动赋值运算符。
- 显式声明了复制构造函数或析构函数，则弃用复制赋值运算符的自动生成。
- 显式声明了复制赋值运算符或析构函数，则弃用复制构造函数的自动生成。

如果基类不拥有可派生类调用的默认构造函数，例如没有 `public` 或 `protected` 的默认构造函数，那么派生类无法自动生成它自己的默认构造函数。

还有例如，在 C++11 之前，通过以私有方式声明复制构造函数和复制赋值运算符，而不定义它们，使用户定义类型不可复制：

```c++
struct noncopyable
{
  noncopyable() {};
private:
  noncopyable(const noncopyable&);
  noncopyable& operator=(const noncopyable&); 
};
```

但是它存在几个问题：
- 私有方式声明的复制构造函数是显式完全声明的；因此会阻止自动生成默认构造函数；
- 尽管显式定义的赋值构造函数不执行任何操作，编译器也会将它视为重要内容，其效率低于自动生成的默认构造函数；并且 `noncopyable` 无法称为 POD 类型。
- 成员函数和 `noncopyable` 的友元仍可以调用它们（名义上是隐藏）；未定义时调用它们会导致链接器错误；

不可复制的习语可通过更直接的方法实现：

```c++
struct noncopyable
{
  noncopyable() =default;   // 自动生成
  noncopyable(const noncopyable&) =delete; 
  noncopyable& operator=(const noncopyable&) =delete;
};
```

- 仍可通过声明复制构造函数来阻止生成默认构造函数，但可通过将其显式设置为 `default` 进行恢复。
- 显式设置的默认特殊成员函数仍被视为不重要，因此性能不会下降，并且不会阻止 `noncopyable` 成为 POD 类型；
- 复制构造函数和复制赋值运算符是公共的，但是已删除。定义或调用已删除函数是编译时错误。

对于创建不可移动、只能动态分配或无法动态分配的用户定义类型；可以通过 `default` 和 `delete` 方式进行设定。

> *defualt* *特殊成员函数*

可以默认设置任何特殊成员函数，以显式声明特殊成员函数使用默认实现、定义具有非公共访问限定符的特殊成员函数或恢复其他情况下被阻止其自动生成的特殊成员函数。通过对可内联的特殊成员函数设置为 `default` 而不是空函数体进行实现：

```c++
struct widget
{
  widget()=default;
  inline widget& operator=(const widget&);
};
inline widget& widget::operator=(const widget&) =default;
```

> *delete*

可以删除特殊成员函数和普通成员函数以及非成员函数，以阻止定义或调用它们。删除特殊成员函数，可以阻止编译器生成不需要的特殊成员函数。

```c++
struct widget
{
    // deleted operator new prevents widget from being dynamically allocated.
    void* operator new(std::size_t) = delete;
    widget* operator &() = delete;   // address-of 被删除
};
widget w{};
widget* pw = new widget;  // ERR; 无法调用删除的函数；但是可以调用全局 new ；
widget* pw = ::new widget;  // ok
widget* pw = &w  // ERR; address-of 被删除
```

删除普通成员函数或非成员函数可阻止有问题的类型提升导致调用意外函数。这可发挥作用的原因是，已删除的函数仍参与重载决策，并提供比提升类型之后可能调用的函数更好的匹配。函数调用将解析为更具体的但可删除的函数，并会导致编译器错误。

```c++
// deleted overload prevents call through type promotion of float to double from succeeding.
void call_with_true_double_only(float) =delete;
void call_with_true_double_only(double param) { return; }

call_with_true_double_only(3.14f);  // err
call_with_true_double_only(100);  // ok; int cast to double 
```

若要限制发生隐式类型转换，确保仅发生对 `double` 类型的参数进行调用，可声明一个模板的已删除版本：

```c++
template < typename T >
void call_with_true_double_only(T) =delete; //prevent call through type promotion of any T to double from succeeding.
void call_with_true_double_only(double param) { return; } // also define for const double, double&, etc. as needed.

call_with_true_double_only(3.1415);  // just only double
```


>---
#### 内联函数

函数的内联声明 `inline` 表明建议编译器使用函数定义中的代码替换对该函数的每次调用。调用函数需要将返回地址推送到堆栈、将参数推送到堆栈、跳转到函数体，然后在函数完成时执行返回指令。通过内联函数可以消除此过程。内联函数的一个缺点是程序的整体大小可能会增加。

类声明的主体中定义的函数是隐式内联函数。成员函数在外部定义可以显式声明为 `inline` 函数：

```c++
struct widget
{
	widget();  
	void inlinefoo();
	void* operator new(std::size_t) = delete;  // implicit inline
	widget* operator &() = delete;  // implicit inline
};
widget::widget() {}  // not inline
inline void widget::inlinefoo() {};  // explicit inline
```

给定的内联成员函数在每个编译单元中必须以相同的方式进行声明。内联函数必须只有一个定义。除非该函数的定义包含 `inline` 说明符，否则类成员函数默认为外部链接。 

`inline` 和 `__inline` 说明符建议编译器将函数体的副本插入到调用函数的每个位置。有编译器根据自己的成本收益分析决定是否进行内联展开；`__forceinline` 关键字会重写成本收益分析，改为依赖于程序员的判断。

编译器将内联扩展选项和关键字视为建议。不保证会对函数进行内联。无法强制编译器对特定函数进行内联；

> *宏函数和内联函数*

宏与 inline 函数之间有一些共同之处。但是：
- 宏始终是内联扩展的。
- 宏可能会导致意外行为，从而导致微小的 bug；
- 内联函数受编译器的语义处理约束，而预处理器会扩展宏。宏不是类型安全的，而函数是；
- 计算一次作为内联函数的参数传递的表达式。在某些情况下，作为宏的自变量传递的表达式可计算多次。

```c++
#define sqr(a) ((a) * (a))
int increment(int& number) { return number++; }
inline int square(int a) { return a * a; }

int main()
{
	int c = 5;
	std::cout << sqr(increment(c)) << std::endl; // outputs 30; 5 * 6
	std::cout << c << std::endl; // outputs 7

	c = 5;
	std::cout << square(increment(c)) << std::endl; // outputs 25
	std::cout << c; // outputs 6
}
```

>---
#### 函数类型与函数指针

C++ 通过与 C 语言相同的方式支持函数指针。但是更加类型安全的替代方法通常是使用函数对象。使用 `typedef` 声明函数指针类型的别名：

```c++
int (*myFunction(char* s))(int);  // 返回 int(*)(int) 函数指针的函数

typedef int (*fp)(int);  
fp myFunction(char* s); // 等效声明
```

`typedef` 可以声明一个函数类型；函数参数是一个函数类型时，实际上是一个函数类型指针，可以将函数指针对象作为参数传递。

```c++
typedef int (*fptr)(int);
typedef int (ftype)(int);  // 签名为 `int (int)` 的函数类型 ftype

// 被视为  myFunction(ftype*, int); 
// 因此无法与 myFunction(fptr, int) 重载，它们是等价的。
// 但是函数无法返回 ftype, 可以返回 fptr
int myFunction(ftype s, int v) {   
    return s(v);
}
int foo(int i) { return i; }
int main()
{
    fptr fp = foo; // or &foo
    ftype* ft = foo;
    myFunction(fp, 1);   // ok; fp  to (ftype s)
    myFunction(ft, 1);   // ok; ft  to (ftype s)
    myFunction(*ft, 1);  // ok; *fp to (ftype s)
    myFunction(*ft, 1);  // ok; *ft to (ftype s)
    myFunction(foo, 1);  // ok; foo to (ftype s)
}
```

---
### 运算符重载

可以在全局或为各个类重新定义大多数内置运算符的函数。重载运算符作为函数来实现。可重载的运算符有：

```c++
a() /* 函数调用 */
a[] /* 数组下标 */
delete /* 内存释放 */
new    /* 分配内存 */ 
explicit  // 显式用户定义转换
 :    // 隐式转换

// 一元
!a,  &a, a() /* 转换运算符 */
+a, -a, ++a, a++, --a, a--,
~a,

// 二元
a -> b, a ->*b, (a, b), 
a + b,  a - b,  a * b,  a / b,  a % b, 
a += b, a -= b, a *= b, a /= b, a %= b, 
a < b,  a > b,  a <= b, a >= b,
a != b, a == b,
a && b, a || b, 
a & b,  a | b,  a ^ b,
a &= b, a |= b, a ^= b,
a << b, a >> b, a <<= b, a >>= b
```

`.`, `.*`, `::`, `? :`, `#`, `##` 不可重定义。

重载运算符必须是非静态类成员函数或全局函数。 需要访问私有或受保护的类成员的全局函数必须声明为该类的友元 `friend`。全局函数必须至少采用一个类类型或枚举类型的自变量或其引用。

声明为成员函数的一元运算符没有自变量（使用隐式 `this`）；声明为全局函数使用一个自变量；声明为成员函数的二元运算符有一个自变量；声明为全局函数有两个自变量。除赋值 (`operator=`) 之外的所有重载运算符都可由派生类继承。`[]` 下标的类型可以是任意类型，可以实现自定义索引。

默认 “`operator=`” 函数可由类类型的编译器生成；定义复制赋值运算符的类还应显式定义复制构造函数和析构函数，以及移动构造函数和移动赋值运算符。


```c++
// 一元
<return-type> operator op ();  // 成员函数
<return-type> operator op ( <class-type> );  //非成员函数

// 二元
<return-type> operator op( arg );  // 成员函数
<return-type> operator op( <class-type>, arg );  // 非成员函数
<return-type> operator op( arg, <class-type> );  // or

// 递增递减
<class-type>& operator++();       // ++i; 成员函数
<class-type> operator++(int);     // i++
<class-type>& operator--();       // --i
<class-type> operator--(int);     // i--

friend Point& operator++( Point& );      // ++i; 类中定义友元; 全局范围
friend Point operator++( Point&, int );  // i++
friend Point& operator--( Point& );      // --i
friend Point operator--( Point&, int );  // i--
```

>---
#### 一元重载举例

```c++
struct S {
	bool operator ==(S& s) { return s == *this; };    // 定义相等语法
	bool operator !() { return this == nullptr; };    // 改变语义为检查 this 是否为 nullptr
	S& operator &() { return *this; };				  // 改变语义返回 this 的引用
	bool operator ()(S& s) { return s == *this; };    // 改变语义为比较值是否相等
	S* operator ()() { return this; };				  // 改变语义返回 this 本身
	void* operator new (size_t size) {				  // 改变语义声明一个 nullptr 初始化的空指针
		return nullptr;
	}
};
int main()
{
	S s = S();
	S& rs = &s;
	S* ps = new S;
	while (!ps) {
		cout << "rs is nullptr " << endl;
		ps = rs();  // 初始化
	}
}
```

---
### 类和结构

类和结构在 C++ 中是相同的，在结构中，默认可访问性是 `public`，而在类中是 `private`。`union` 是 C++ 类类型的一种，成员默认是 `public`，但没有继承语义。

>---
#### 类成员

`class` 或 `struct` 由其成员组成。类的工作由其成员函数执行，它所维持的状态存储在其数据成员中。成员的初始化由构造函数完成，释放内存和释放资源等清理工作由析构函数完成。

类的成员有：特殊成员函数、成员函数（静态和非静态）、可变和静态数据成员、运算符、嵌套类声明、枚举、位域、别名和 *type-def*；友元包含在类声明中，但属于其周围范围。

可将数据成员声明为静态，这表示类的所有对象都有权访问它的同一副本。可将成员函数声明为静态，在这种情况下它只能访问类的静态数据成员（且不具有 `this` 指针）。静态数据成员一般需要在声明时为初始值设定项。类的对象、指针、引用可以使用成员选择（`.` 和 `->`）运算符访问静态成员。

如果未在类定义中指定特殊成员函数，那么编译器自动提供的函数则为特殊成员函数：默认构造函数、复制构造函数、移动构造函数、复制赋值运算符、移动赋值运算符、析构函数。

```c++

class TestRun
{
    // Start member list.
    // The class interface accessible to all callers.
public:
    TestRun() = default; // Use compiler-generated default constructor
    TestRun(const TestRun&) = delete; // Don't generate a copy constructor
    TestRun(std::string name);
    void DoSomething();
    int Calculate(int a, double d);
    virtual ~TestRun();  // virtual destructor
    enum class State { Active, Suspended };  // enum class;

    // Accessible to this class and derived classes only.
protected:
    virtual void Initialize();
    virtual void Suspend();
    State GetState();

    // Accessible to this class only.
private:
    State _state{ State::Suspended };  // Default brace-initialization of instance members
    std::string _testName{ "" };
    int _index{ 0 };

    // Non-const static member:
    static int _instances;
};

// Define and initialize static member.
int TestRun::_instances{ 0 };
```

非静态数据成员声明符可以包含初始值设定项；静态数据成员必须是常量 (`constexpr`) 才能包含初始值设定项，否则必须在文件范围内定义静态数据成员并在此范围内将其初始化；静态成员具有外部链接但可以添加可访问性。成员函数可以在类主体中声明定义或在外部定义，内部定义但会隐式声明为 `inline`。

```c++
class Stat {};
class S {
public :
	S() = default;
	static const S& Instance();
	static Stat GetStat(S&);
private:
	static S* s_instance;
	Stat s_stat{};
};
Stat S::GetStat(S& s) { return s.s_stat; };
const S& S::Instance() { return *s_instance; };
S* S::s_instance = new S{};
```

>---
#### 成员访问控制

通过访问控制，可以将类的 `public` 接口与 `private` 内部实现和仅供派生类使用的 `protected` 成员分离开来。`class` 成员默认为 `private`；`struct` 为 `public`；`union` 为 `public` 但没有 `protected`。 

```c++
class Point
{
public:
    Point( int, int ) // Declare public constructor.;
    Point();// Declare public default constructor.
    int &x( int ); // Declare public accessor.
    int &y( int ); // Declare public accessor.

private:                 // Declare private state variables.
    int _x;
    int _y;

protected:      // Declare protected function for derived classes only.
    Point ToWindowCoords();
};
```

基类成员在派生类中的可访问性受基类成员自身的访问说明符，和派生声明基类时使用的访问说明符的交集决定：
- `private` 派生，基类的所有成员都无法访问；
- `protected` 派生，基类的 `protected` 和 `public` 成员在派生类中是 `protected`；
- `public` 派生，基类的 `protected` 成员在派生类中为 `protected`，基类的 `public` 成员在派生类中为 `public`。
派生类不使用访问说明符时，`class` 派生类型使用的基类是 `private`，`struct` 派生类使用的基类是 `public`：

```c++
class Base{};
struct SDerived: Base {}  // 相当于 struct SDerived: public Base 
class CDerived: Base {}   // 相当于 class CDerived: private Base 
```

友元类成员的访问不受访问说明符的限制，它属于声明类的范围的成员。

在将基类指定为 `private` 时，它只影响非静态成员。在派生类中，公共静态成员仍是可访问的。但是，如果使用指针、引用或对象访问基类的静态成员仍需要访问控制转换，`private` 基类无法通过派生的对象直接访问，只能通过限定方式 `base::static_member`。

> *对虚函数的访问*

对 `virtual` 函数的访问控制是由用于进行函数调用的类型决定的。重写函数的声明不会影响给定类型的访问控制。

```c++
// access_to_virtual_functions.cpp
class VFuncBase
{
public:
    virtual int GetState() { return _state; }
protected:
    int _state;
};
class VFuncDerived : public VFuncBase
{
private:
    int GetState() { return _state; }
};

int main()
{
   VFuncDerived vfd;             // Object of derived type.
   VFuncBase *pvfb = &vfd;       // Pointer to base type.
   VFuncDerived *pvfd = &vfd;    // Pointer to derived type.
   int State;

   State = pvfb->GetState();     // GetState is public.
   State = pvfd->GetState();     // C2248 error expected; GetState is private;
}
```

可以使用指向基类 `GetState` 的指针调用虚函数 `VFuncBase`。 这并不意味着调用的函数是该函数的基类版本，它可能在派生类中进行的重写 `override`，或多重继承中的某个中间派生类的重写方法。

>---
#### 类初始化

没有构造类型的类类型的对象可以直接声明或使用初始化器（或空大括号），按类中声明的成员的顺序提供列表元素。

```c++
struct TempData
{
	int StationId;
	time_t timeSet;
	double current;
};

int main()
{
	TempData t0;   // 未初始化的对象
    // 调用自动生成的默认构造，数据成员零初始化
	TempData t1{};

    // timeSet 后面的元素零初始化
	TempData t2{ 1, 1000 };  
	TempData t3(1, 100);     
    
    // 全部列出
    TempData t4{ 1, 100, 0 };  
	TempData t5(1, 100, 0);

	TempData t();  // 含义不明确，声明返回 TempData 的函数 t4
}
```

具有非默认构造函数，则类成员显示顺序是对应参数在构造函数中的显示顺序。

```c++
struct TempData
{
	int StationId;
	time_t timeSet;
	double current;
public:
	TempData() = default;
	TempData(int stationid, time_t tmset) :StationId{ stationid }, timeSet{ tmset } {
		current = 0;
	}
};

int main()
{
	// 调用默认构造
	TempData t0;    
	TempData t1{};  

	// 调用 TempData(int, time_t)
	TempData t2{ 1, 1000 };  
	TempData t3(1, 100);    

	TempData t();  // 含义不明确，声明返回 TempData 的函数 t4
}
```

`initializer_list` 类表示可以在构造函数和其他上下文中使用的指定类型的对象的列表。 

```C++
#include<initializer_list>

initializer_list<int> ilist1{ 5, 6, 7 };
```

标准库容器类以及 `string`、`wstring` 和 `regex` 具有 `initializer_list` 构造函数

```c++
vector<int> v1{ 9, 10, 11 };
map<int, string> m1{ {1, "a"}, {2, "b"} };
string s{ 'a', 'b', 'c' };
regex rgx{ 'x', 'y', 'z' };
```

>---
#### 对象生存期和资源管理

C++ 没有自动回收垃圾， 程序负责将所有已获取的资源返回到操作系统。未被释放未使用的资源是资源泄露（*leak*）。现代 C++ 通过声明堆栈上的对象，尽可能避免使用堆内存。

当对象初始化时，它会获取它拥有的资源，并且该对象负责在其析构函数中释放资源。在堆栈上声明拥有资源的对象本身。对象拥有资源的原则也称为 “资源获取即初始化” (RAII)。当拥有资源的堆栈对象超出范围时，会自动调用其析构函数。C++ 中的垃圾回收与对象生存期密切相关，是确定性的。资源始终在程序中的已知点释放。

```c++
struct buffer {
	friend void print(buffer&);
private:
	char* buf;
	size_t size;
public:
	buffer(size_t size);
	int writeString(string str);
	~buffer();
};
buffer::buffer(size_t size) :size{ size } {
	buf = new char[size];
}
buffer::~buffer() {
	cout << "delete buffer" << endl;
	delete[] buf;
}
int buffer::writeString(string str) {
	int n = 0;
	try {
		for (char c : str) {
			if (n >= size - 1)
				break;
			buf[n++] = c;
		}
	}
	catch (exception e) {
		return -1;
	}
	buf[n] = '\0';
	return n;
}
void print(buffer& buf) {
	printf("%s\n", buf.buf);
}

void WriteToBuffer(std::string& str) {
	buffer b(512);
	int	n = b.writeString(str);
	if (n > 0)
		print(b);
}

int main()
{
	string s{ "Hello World" };
	WriteToBuffer(s);
}
// Hello World
// delete buffer
```

C++ 的设计可确保对象在超出范围时被销毁。也就是说，它们在块被退出时以与构造相反的顺序被摧毁。销毁对象时，将按特定顺序销毁其基项和成员。 在全局范围内在任何块之外声明的对象可能会导致问题。

可以使用智能指针处理对象所需内存资源的分配和删除。使用智能指针将不需要在类中显式定义析构函数。使用智能指针进行内存分配，可以消除内存泄漏的可能性。此模型适用于其他资源，例如文件句柄或套接字。


```c++
#include <memory>
class widget
{
private:
    std::unique_ptr<int[]> data;
public:
    widget(const int size) { data = std::make_unique<int[]>(size); }
    void do_something() {}
};

void usingWidget() {
    widget w(1000000);  // lifetime automatically tied to enclosing scope
                        // constructs w, including the w.data gadget member
    w.do_something();
} // automatic destruction and deallocation for w and w.data
```

>---
#### 友元

类向不属于类成员的函数或单独类中的所有成员授予成员级访问权限非常有用。这些 *Free* 函数和类称为 “友元”，由 `friend` 标记。

如果声明以前未声明的 `friend` 函数，则该函数将被导出到封闭非类范围。`friend` 函数被视为 `extern` 声明。

尽管具有全局范围的函数可以在其原型之前声明为 `friend` 函数，但是成员函数在它们的完整类声明出现前不能声明为 `friend` 函数。

```c++
class ForwardDeclared;   // Class name is known.
class HasFriends
{
    friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
```

在类中声明的友元类可以是 `friend class F` 或 `friend F`；区别是 `class F` 引入新的类但没有定义，稍后定义；而 `friend F` 是引用外部范围的已声明类：

```c++
class F{};
class S {
    friend F;
    friend class NF;
};
// 稍后定义
class NF{ };
```

使用 `friend F` 将模板参数或 `typedef` 声明为友元：

```c++
typedef Foo F;
template <typename T>
class my_class
{
    friend T;
    friend F;
    //...
};
```

`friend` 函数是一个不为类成员的函数；它可以是新声明的属于外部范围的 *Free* 函数，或外部范围已声明的函数原型（未定义，在当前类声明之后定义）。

```c++
class Point
{
    friend void ChangePrivate( Point & );  // 声明原型
public:
    Point( void ) : m_i(0) {}
    void PrintPrivate( void ){cout << m_i << endl; }

private:
    int m_i;
};
void ChangePrivate ( Point &i ) { i.m_i++; }  // 声明定义
```

类成员函数可以声明为其他类中的友元。友元关系不是相互的，例如 `A` 和 `B` 互为友元，但是编译器必须将整个第二个类指定为第一个类的友元；但是可以选择将第一个类中的哪些函数作为第二个类的友元。反之不可。友元关系不能继承，不可传递。

```c++
class A {
	friend class B;
public:
	void fooA(B& b);
};
class B {
	friend A;
	friend void A::fooA(B& b);
private:
	int _v;
};
void A::fooA(B& b) {
	b._v = 110;
}
```

可以在类声明中定义友元函数（给定函数主体）。这些函数是内联函数，类似于成员内联函数。类声明中定义的友元函数在封闭类的范围内。

```c++
class S {
private:
	int _v;
	friend S&& initS(S&& s) {
		s._v = 110;
	}
};
int main()
{
	S s = initS(S{});  // inline S&& initS
}
```

>---
#### 构造函数

创建类时初始化其成员或调用成员函数，可以使用构造函数；可以声明 `inline`、`explicit`、`friend` 或 `constexpr`。构造函数可以初始化一个 `const`、`volatile` 或 `const volatile` 的对象。

构造函数可以选择具有成员初始化表达式列表，该列表会在构造函数主体运行之前初始化类成员。`const` 成员和引用类型的成员必须在成员初始化表达式列表中进行初始化。

```c++
struct Point {
	constexpr Point() :x{}, y{} {};  // 带有成员初始化表达式的默认构造函数
	explicit Point(int x, int y) :x(x), y(y) {}; // 重载 
	int x, y;
};

class Axis {
	Axis() = delete;   // 删除默认构造函数
public:
	Axis(Point p) {}
};

int main() {
	Point p1; // 未初始化对象
	const Point origin{};
	Point p2{ 1,1 };

	// 无法创建
	Axis a{};
	Axis as[6];
	// 可以是
	Axis a0{ Point{1,1} };
	Axis as0[3]{ Point{0,0}, Point{1,1}, Point{-1,-1} };
}
```

> *委托构造函数*

许多类具有执行类似操作（例如，验证参数）的多个构造函数；可以使用委托构造函数减少代码重复性：

```c++
struct Point {
	Point(int x, int y, int z) :x{ x }, y{ y }, z{ z } {};
	Point(int x, int y) : Point(x, y, 0) {};
	Point() : Point(0, 0, 0) {};
	int x, y, z;
};
```

应避免调用循环导致堆栈溢出。

> *复制构造函数*

复制构造函数通过从相同类型的对象复制成员值来初始化对象。一般简单类型可以使用自动生成的复制构造函数，但成员存在指针时，自动生成复制构造只会复制指针值，因此需要自定义声明以分配指针内存；其签名可以是：

```c++
Point(Point& other);   // Avoid if possible--allows modification of other.
Point(const Point& other);
Point(volatile Point& other);
Point(volatile const Point& other);
```

定义复制构造函数还需要定义相应的复制赋值运算符：

```c++
Point& operator=(Point& other);
Point& operator=(const Point& other);
Point& operator=(volatile Point& other);
Point& operator=(volatile const Point& other);
```

可以删除赋值构造以阻止对象被复制：

```c++
Point (const Point&) = delete;
```

下面是一个可复制 *buffer*：

```c++
struct buffer {
// ...
	buffer(buffer&& other) noexcept :size(0), index{ 0 }, buf(nullptr) {
		cout << "move buffer" << endl;
		*this = std::move(other);
	};

	buffer& operator = (buffer&& other)noexcept {
		if (this != &other) {
			delete[] buf;
			size = other.size;
			index = other.index;
			buf = other.buf;
			other.buf = nullptr;
		}
		return *this;
	}
// ...
}
int main()
{
	buffer b{ 512 };
	b.Write("Hello World!");
	buffer b2 = std::move(b);
	b2.Write("JimryYchao");
	Println(b2);
}
/*
	create a new buffer
	move buffer
	Hello World!JimryYchao
	delete buffer
*/
```


---
### 异常处理

异常是一个可能超出程序的控制范围的错误条件，它会阻止程序继续沿其常规执行路径执行。程序错误通常分为两类：
- 编程错误导致的逻辑错误。例如，“索引超出范围” 错误。
- 超出程序员控制的运行时错误。例如，“网络服务不可用” 错误。

在 C 样式的编程和 COM 中，错误报告的管理方式是返回一个表示错误代码或特定函数的状态代码的值，或者设置一个全局变量，调用方可以在每次执行函数调用后选择性地检索该变量来查看是否报告了错误。例如 C `errno`。

```c++
template <typename T>
T Index(T arr[10], int i) {
	if (i < 0 || i >= 10)
		throw std::out_of_range("index is out of range");
	return arr[i];
}
int main() {
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	
	try {
		auto v = Index(arr, -1);
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
		return -1;
	}
}
```

在 `try` 块中，如果引发某个异常，类型与该异常的类型匹配的第一个关联 `catch` 块将捕获该异常。 换言之，执行将从 `throw` 语句跳转到 `catch` 语句。如果未找到可用的 `catch` 块，则调用 `std::terminate` 并且程序会退出。

在 C++ 中可以引发任何类型；但是建议引发直接或间接派生自 `std::exception` 的类型。C++ 中不提供 *finally* 的语义。

> *基本准则*

- 使用断言检查应始终为 `true` 或始终为 `false` 的条件。使用异常来检查可能发生的错误，例如公共函数参数的输入验证错误。
- 当处理错误的代码与通过一个或多个中间函数调用检测错误的代码分离时，请使用异常。当处理错误的代码与检测错误的代码紧密耦合时，请考虑是否在性能关键型循环中使用错误代码。
- 对于每个可能引发或传播异常的函数，请提供三项异常保证之一：强保证、基本保证或 nothrow (noexcept) 保证
- 通过值引发异常，通过引用捕获异常。 不要捕获无法处理的异常。
- 不要允许异常从析构函数或内存解除分配函数中逃逸。
- 使用适用的标准库异常类型。以及从 exception 类层次结构派生自定义的异常类型。

---
### 预处理指令

```c++
// 条件包含
defined                       // 条件编译符号测试
__has_include (C++17)         // 源文件包含测试
__has_cpp_attribute (C++20)   // 属性测试
// 条件控制
#if
#elif
#else
#endif
#ifdef
#ifndef
#elifdef (C++23)
#elifndef (C++23)
// 宏定义与取消宏定义
#define
#undef
// 源文件包含
#include
import (C++20)
// 文件名和行信息
#line
// 诊断指令
#error
#warning (C++23)
// 实现定义行为控制
#pragma
_Pragma

export (C++20)
module (C++20)
```

>---
#### 条件包含

```c++
defined ( identifier )               // 条件编译符号测试
__has_include ( heeder-name )        // 源文件包含测试
__has_cpp_attribute ( pre-tokens )   // 属性测试
```

控制条件包含的表达式是一个整数常量表达式，它可能包含零个或多个 `defined()`, `__has_include()`, `__has_cpp_attribute()` 一元运算符表达式。

已存在定义的宏名称，`defined(id)` 返回 1，这样的宏名称由 `#define` 定义且在条件包含的调用点之前没有 `#undef` 取消。

`__has_include( header )` 检索 `header` 是否由 `#include` 导入；在 `__has_cpp_attribute( attr-pp-token )` 中，如果实现支持通过展开并解释 `pp-token` 指定名称的属性，则每个包含表达示都将替换为相应的 `pp-token` 的整数形式。

```c++
#define assume              202207L
#define carries_dependency  200809L
#define deprecated          201309L
#define fallthrough         201603L
#define likely              201803L
#define maybe_unused        201603L
#define no_unique_address   201803L
#define nodiscard           201907L
#define noreturn            200809L
#define unlikely            201803L
```

>---
#### 条件控制指令

```c++
#if constant-expr
#elif constant-expr
#ifdef identifier      // #if defined identifier
#ifndef identifier     // #if !defined identifier 
#elifdef identifier    // #elif defined identifier 
#elifndef identifier   // #elif !defined identifier 
#else
#endif
```

`#ifdef`、`#ifndef`、`#elifdef` 和 `#elifndef` 指令以及 `defined` 条件包含运算符应将 `__has_include` 和 `__has_cpp_attribute` 视为定义宏的名称。

这些预处理指令检查控制表达式的计算结果是否为非零；根据结果来选择性的跳过结果为 `false`（零）的组；组中的代码和嵌套预处理指令被忽略。

```c++
#if __has_include(<optional>)
# include <optional>
# if __cpp_lib_optional >= 201603
# define have_optional 1
# endif
#elif __has_include(<experimental/optional>)
# include <experimental/optional>
# if __cpp_lib_experimental_optional >= 201411
# define have_optional 1
# define experimental_optional 1
# endif
#endif
#ifndef have_optional
# define have_optional 0
#endif

#if __has_cpp_attribute(acme::deprecated)
# define ATTR_DEPRECATED(msg) [[acme::deprecated(msg)]]
#else
# define ATTR_DEPRECATED(msg) [[deprecated(msg)]]
#endif
ATTR_DEPRECATED("This function is deprecated") void anvil();
```

>---
#### 源文件包含

```c++
#include <header-name> 
#include "header-name" 
#include "source-name" 
```

`#include` 指令以实现定义的方式搜索命名源文件，并将该位置替换为源文件的全部内容。如果 *header-name* 标识一个可导入的头文件，则由实现定义是否将 `#include` 预处理指令替换为 `import header-name;`。

```c++
#if VERSION == 1
#define INCFILE "vers1.h"
#elif VERSION == 2
#define INCFILE "vers2.h" // and so on
#else
#define INCFILE "versN.h"
#endif
#include INCFILE
```

>---
#### 模块指令

```c++

```

模块指令中模块预处理令牌之后的任何预处理令牌的处理方式与普通文本相同。

