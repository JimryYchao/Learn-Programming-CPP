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
#### 用户定义文本 TODO






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

- 语句范围：在 `for`、`if`、`while` 或 `switch` 语句中声明的名称在语句块结束之前可见。

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
- 没有具有相应非普通构造函数/运算符/析构函数的基类
- 没有具有相应非普通构造函数/运算符/析构函数的类类型的数据成员

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

> 文本类型

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
#### 类型转换 TODO

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
### 声明与定义

程序的实体（*Entity*）包括值、对象、引用、结构化绑定、函数、枚举器、类型、类成员、位字段、模板、模板专用化、命名空间或包。

实体的名称由声明引入，声明可以是名称声明、块声明或成员声明；初始化声明；结构化绑定声明；参数、类型参数、类型定义等。实体 `E` 由声明 `E` 引入的名称（如果有）或由指定 `E` 的声明引入的 *typedef-name* 表示。

变量是通过声明非静态数据成员或对象以外的引用来引入的。变量的名称（如果有）表示引用或对象。局部实体是具有自动存储期的变量、结构化绑定对应的变量，或 *this 对象。

声明可以（重新）将一个或多个名称和 / 或实体引入翻译单元，并指定这些名称的解释和语义属性。如果可以从实体或 *typedef-name* `X` 中获取另一个 `X` 声明，则该实体或 *typedef-name* `X` 的声明是 `X` 的重新声明。

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




---
### 类型与变量


---
### 表达式


---
### 语句



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

