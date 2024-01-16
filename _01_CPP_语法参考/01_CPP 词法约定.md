# CPP：词法约定

---
## 1. 单独翻译

程序的文本保存在本文档中称为源文件的单元中。一个源文件连同所有的头文件和通过预处理指令 `#include` 包含的源文件，减去任何条件包含预处理指令跳过的源行，被称为预处理翻译单元。

一个 C++ 程序不需要全部同时翻译。以前翻译过的翻译单元和实例化单元可以单独保存或保存在库中。程序的独立翻译单元通过 (例如) 调用其标识符具有外部或模块链接的函数、操作其标识符具有外部或模块链接的对象或操作数据文件进行通信。翻译单元可以单独翻译，然后再链接以产生可执行程序。

---
## 2. 翻译阶段

翻译语法规则的优先顺序由以下几个阶段指定：
1. 实现应支持 UTF-8 代码单元序列 (UTF-8 文件) 的输入文件。它还可以支持一组由实现定义的其他类型的输入文件，如果是这样，那么输入文件的类型将以一种由实现定义的方式确定，这种方式包括一种将输入文件指定为 UTF-8 文件的方法，与它们的内容无关。换句话说，仅仅识别 **U+FEFF BYTE ORDER MARK** 是不够的。<br>
如果一个输入文件被确定为 UTF-8 文件，那么它应该是一个格式良好的 UTF-8 代码单元序列，并对其进行解码以产生一个 Unicode 标量值序列。然后，通过将每个 Unicode 标量值映射到相应的翻译字符集元素，形成翻译字符集元素序列。在结果序列中，由 U+000D 回车后跟 U+000A 换行组成的输入序列中的每对字符，以及每个 U+000D 回车后面没有紧跟着 U+000A 换行的字符，都被单个换行字符替换。对于实现支持的任何其他类型的输入文件，字符以实现定义的方式映射到翻译字符集元素序列，将行尾指示符表示为换行符。
<br>

2. 如果第一个翻译字符是 **U+FEFF BYTE ORDER MARK**，则删除。每个反斜杠字符 (`\`) 后面紧跟着零个或多个空白字符的序列 (而不是换行后面跟着一个换行符的序列) 将被删除，拼接物理源行形成逻辑源行。只有任何物理源行上的最后一个反斜杠才有资格成为这种拼接的一部分。行拼接可以形成通用字符名。非空且 (拼接后) 不以换行字符结束的源文件将被处理，就像在文件中附加了一个额外的换行字符一样。
<br>

3. 源文件被分解为预处理令牌和空白字符序列（包括注释）。源文件不应以部分预处理令牌或部分注释结束。每个注释被替换为一个空格字符。保留换行符。除换行符外的每个非空白字符序列是否保留或被一个空格字符替换是未指定的。当从源文件中消耗字符以形成下一个预处理令牌（即，不作为注释或其他形式的空白的一部分被消耗）时，除了匹配 *c-char-sequence*、*s-char-sequence*、*r-char-sequence*、*h-char-sequence* 或 *q-char-sequence* 时，*universal-character-names* 被识别并被替换为翻译字符集的指定元素。将源文件的字符划分为预处理令牌的过程是上下文相关的。
<br>

4. 执行预处理指令，扩展宏调用，并执行 `_Pragma` 一元运算符表达式。`#include` 预处理指令导致命名的头文件或源文件从阶段 1 到阶段 4 递归地被处理。然后删除所有预处理指令。
<br>

5. 对于两个或更多相邻的字符串字面量令牌的序列，确定一个公共的编码前缀。然后将每个这样的字符串字面量令牌都视为具有那个公共的编码前缀。
<br>

6. 相邻的字符串字面量令牌被连接。
<br>

7. 分隔令牌的空白字符不再重要。每个预处理令牌被转换为一个令牌。结果令牌构成一个翻译单元，并被语法和语义分析和翻译。分析和翻译令牌的过程有时会导致一个令牌被一系列其他令牌替换。是否需要提供当前翻译单元具有接口依赖性的模块单元和头单元的源是由实现定义的。源文件、翻译单元和翻译后的翻译单元不必一定存储为文件，也不必在这些实体和任何外部表示之间有任何一对一的对应关系。描述只是概念性的，不指定任何特定的实现。
<br>

8. 翻译后的翻译单元和实例化单元按如下方式组合，这些可以全部或部分从库中提供：
     - 检查每个翻译后的翻译单元以产生所需实例化的列表。这可以包括已经明确请求的实例化。
     - 找到所需模板的定义。是否需要提供包含这些定义的翻译单元的源是由实现定义的。实现可以选择将足够的信息编码到翻译后的翻译单元中，以确保这里不需要源。
     - 执行所有所需的实例化以产生实例化单元。这些与翻译后的翻译单元类似，但不包含对未实例化模板的引用和没有模板定义。
     - 如果任何实例化失败，程序就是格式错误的。
<br>

9. 解析所有外部实体引用。链接库组件以满足对当前翻译中未定义的实体的外部引用。所有这样的翻译器输出被收集到一个程序映像中，该映像包含在其执行环境中执行所需的信息。

---
## 3. 字符集

翻译字符集由以下元素组成：
- 在 Unicode 标准中指定的 Unicode 代码空间中分配了代码点的每个抽象字符，以及
- 对于每个未分配给抽象字符的 Unicode 标量值，都有一个独特的字符。

Unicode 代码点是范围在 [0, 10FFFF]（十六进制）的整数。替代代码点是范围在 [D800, DFFF]（十六进制）的值。Unicode 标量值是任何不是替代代码点的代码点。

基本字符集是翻译字符集的子集，由下表中指定的 99 个字符组成。Unicode 短名称仅作为识别字符的一种方式给出；在此上下文中，数值没有其他含义。

| Unicode          | Character                   | glyph                                               |
| :--------------- | :-------------------------- | :-------------------------------------------------- |
| U+0009           | character tabulation        |                                                     |
| U+000B           | line tabulation             |                                                     |
| U+000C           | form feed                   |                                                     |
| U+0020           | space                       |                                                     |
| U+000A           | line feed                   | new-line 换行                                       |
| U+0021           | exclamation mark            | !                                                   |
| U+0022           | quotation mark              | "                                                   |
| U+0023           | number sign                 | #                                                   |
| U+0024           | dollar sign                 | $                                                   |
| U+0025           | percent sign                | %                                                   |
| U+0026           | ampersand                   | &                                                   |
| U+0027           | apostrophe                  | ’                                                   |
| U+0028           | left parenthesis            | (                                                   |
| U+0029           | right parenthesis           | )                                                   |
| U+002A           | asterisk                    | *                                                   |
| U+002B           | plus sign                   | +                                                   |
| U+002C           | comma                       | ,                                                   |
| U+002D           | hyphen-minus                | -                                                   |
| U+002E           | full stop                   | .                                                   |
| U+002F           | solidus                     | /                                                   |
| U+0030 .. U+0039 | digit zero .. nine          | 0 1 2 3 4 5 6 7 8 9                                 |
| U+003A           | colon                       | :                                                   |
| U+003B           | semicolon                   | ;                                                   |
| U+003C           | less-than sign              | <                                                   |
| U+003D           | equals sign                 | =                                                   |
| U+003E           | greater-than sign           | >                                                   |
| U+003F           | question mark               | ?                                                   |
| U+0040           | commercial at               | @                                                   |
| U+0041 .. u+005A | latin capital letter A .. Z | A B C D E F G H I J K L M N O P Q R S T U V W X Y Z |
| U+005B           | left square bracket         | [                                                   |
| U+005C           | reverse solidus             | \                                                   |
| U+005D           | right square bracket        | ]                                                   |
| U+005E           | circumflex accent           | ^                                                   |
| U+005F           | low line                    | _                                                   |
| U+0060           | grave accent                | `                                                   |
| U+0061 .. u+007A | latin small letter a .. z   | a b c d e f g h i j k l m n o p q r s t u v w x y z |
| U+007B           | left curly bracket          | {                                                   |
| U+007C           | vertical line               | \                                                   |
| U+007D           | right curly bracket         | }                                                   |
| U+007E           | tilde                       | ~                                                   |

*universal-character-name* 构造提供了命名其他字符的方法。

<pre>
<em>universal-character-name</em> :
        \u <em>hex-quad</em>
        \U <em>hex-quad hex-quad</em>
        \u{ <em>simple-hexadecimal-digit-sequence</em> }
        <em>named-universal-character</em>

<em>hex-quad</em> :
        <em>hexadecimal-digit hexadecimal-digit hexadecimal-digit hexadecimal-digit</em>

<em>simple-hexadecimal-digit-sequence</em> :
        <em>hexadecimal-digit</em>
        <em>simple-hexadecimal-digit-sequence hexadecimal-digit</em>

<em>named-universal-character</em> : 
        \N{ <em>n-char-sequence</em> }

<em>n-char-sequence</em> : 
        <em>n-char</em>
        <em>n-char-sequence n-char</em>

<em>n-char</em> : 翻译字符集的任何成员之一，除了 U+007D 右花括号或换行字符
</pre>

形如 \u *hex-quad*、\U *hex-quad hex-quad* 或 \u{ *simple-hexadecimal-digit-sequence* }的 *universal-character-name* 指定翻译字符集中的字符，其 Unicode 标量值是 *universal-character-name* 中的十六进制数字序列所表示的十六进制数。如果该数不是 Unicode 标量值，程序就是格式错误的。

一个是 *named-universal-character* 的 *universal-character-name* 指定 Unicode 标准中的对应字符，如果 *n-char-sequence* 等于其字符名称或其类型为 “control”、“correction” 或 “alternate” 的字符名称别名；否则，程序就是格式错误的。这些别名列在 Unicode 字符数据库的 NameAliases.txt 中。这些名称或别名都没有前导或尾随空格。

如果一个 *universal-character-name* 在字符字面量或字符串字面量的 *c-char-sequence*、*s-char-sequence* 或 *r-char-sequence* 之外（在任何一种情况下，包括在用户定义的字面量中）对应于控制字符或基本字符集中的字符，程序就是格式错误的。在* r-char-sequence* 中类似 *universal-character-name* 的字符序列不形成 *universal-character-name*。

基本字面字符集由基本字符集中的所有字符以及下表中指定的控制字符组成。

| Unicode | Character       |
| :------ | :-------------- |
| U+0000  | null            |
| U+0007  | alert           |
| U+0008  | backspace       |
| U+000D  | carriage return |

代码单元是字符类型的整数值。在字符字面量中，除了多字符或不可编码的字符字面量，或在字符串字面量中的字符，都被编码为一个或多个代码单元的序列，由编码前缀确定；这被称为各自的字面量编码。普通字面量编码是应用于普通字符或字符串字面量的编码。宽字面量编码是应用于宽字符或字符串字面量的编码。

字面量编码或执行字符集中的一个的特定于区域的编码，将基本字面字符集的每个元素编码为一个非负值的单个代码单元，与任何其他此类元素的代码单元不同。不在基本字面字符集中的字符可以用多个代码单元编码；这样的代码单元的值可以与基本字面字符集中的元素的代码单元的值相同。

U+0000 空字符被编码为值 0。翻译字符集的其他元素没有一个被编码为值 0 的代码单元。每个十进制数字字符的代码单元值在数字 0（U+0030）之后应该比前一个的值大一。普通和宽字面量编码在其他方面是由实现定义的。对于 UTF-8、UTF-16 或 UTF-32 字面量，实现应该将翻译字符集中每个字符对应的 Unicode 标量值编码为 Unicode 标准中指定的相应 Unicode 编码形式。

---
## 4. 预处理令牌

<pre>
<em>preprocessing-token</em> : 
        <em>header-name</em>
        <em>import-keyword</em>
        <em>module-keyword</em>
        <em>export-keyword</em>
        <em>identifier</em>
        <em>pp-number</em>
        <em>character-literal</em>
        <em>user-defined-character-literal</em>
        <em>string-literal</em>
        <em>user-defined-string-literal</em>
        <em>preprocessing-op-or-punc</em>
        每个非空白字符，不能是上述字符之一
</pre>

每个预处理令牌被转换为一个具有关键字、标识符、字面量、运算符或标点符号的词法形式的令牌。

预处理令牌是语言在翻译阶段 3 到 6 中的最小词法元素。在本文档中，使用字形来识别基本字符集的元素。预处理令牌的类别有：头文件名、由预处理 `import` 和 `module` 指令（*import-keyword*、*module-keyword* 和 *export-keyword*）产生的占位符令牌、标识符、预处理数字、字符字面量（包括用户定义的字符字面量）、字符串字面量（包括用户定义的字符串字面量）、预处理运算符和标点符号，以及单个非空白字符，这些字符在词法上不匹配其他预处理令牌类别。如果 U+0027 撇号或 U+0022 引号字符匹配最后一类，程序就是格式错误的。如果任何不在基本字符集中的字符匹配最后一类，程序就是格式错误的。预处理令牌可以由空白分隔；这包括注释，或空白字符（U+0020 空格，U+0009 水平制表符，换行符，U+000B 垂直制表符，和 U+000C 分页符），或两者。在翻译阶段 4 的某些情况下，空白（或其缺失）作为超过预处理令牌分隔的作用。空白只能作为头文件名的一部分或字符字面量或字符串字面量的引号字符之间出现在预处理令牌内。

如果输入流已经被解析为预处理令牌，直到给定的字符：
- 如果下一个字符开始的字符序列可能是原始字符串字面量的前缀和初始双引号，如 `R"`，下一个预处理令牌应该是原始字符串字面量。在原始字符串的初始和最后的双引号字符之间，执行的任何阶段 2（行拼接）的转换都被恢复；这种恢复应该在识别任何 *d-char*、*r-char* 或定界括号之前应用。原始字符串字面量被定义为匹配原始字符串模式的字符的最短序列 *encoding-prefix*<sub>*opt*</sub> R *raw-string*
- 否则，如果下一个三字符是 `<::`，并且后续的字符既不是 `:` 也不是 `>`，`<` 被当作一个预处理令牌本身处理，而不是替代令牌 `<:` 的第一个字符。
- 否则，下一个预处理令牌是可以构成预处理令牌的字符的最长序列，即使这会导致进一步的词法分析失败，除非头文件名只有在以下情况下才形成
  - 在 `#include` 或 `import` 指令中的 `include` 或 `import` 预处理令牌之后，或
  - 在 *has-include-expression* 中。
  
  ```c++
  #define R "x"
  const char* s = R"y"; // ill-formed raw string, not "x" "y"
  ```

*import-keyword* 是通过处理 `import` 指令产生的，*module-keyword* 是通过预处理 `module` 指令产生的，*export-keyword* 是通过预处理前两个指令中的任何一个产生的。

例如，程序片段 `0xe+foo` 被解析为一个预处理数字令牌（一个不是有效的整数字面量或浮点字面量令牌），即使作为三个预处理令牌 `0xe`、`+` 和 `foo` 的解析可以产生一个有效的表达式（例如，如果 `foo` 是定义为 1 的宏）。类似地，程序片段 `1E1` 被解析为一个预处理数字（一个是有效的浮点字面量令牌），无论 `E` 是否是宏名称。

例如，程序片段 `x+++++y` 被解析为 `x ++ ++ + y`，如果 `x` 和 `y` 具有整数类型，违反了对增量运算符的约束，即使解析 `x ++ + ++ y` 可以产生一个正确的表达式。

---
## 5. 替代令牌

为一些操作符和标点符提供了可选的令牌表示。在该语言的所有方面，除了拼写不同之外，每个替代令牌的行为都与基础令牌相同。替代标记的集合定义在下表中：

| Alternative | Primary | Alternative | Primary | Alternative | Primary |
| :---------: | :-----: | :---------: | :-----: | :---------: | :-----: |
|     <%      |    {    |     and     |   &&    |   and_eq    |   &=    |
|     %>      |    }    |    bitor    |   \|    |    or_eq    |   \|=   |
|     <:      |    [    |     or      |  \|\|   |   xor_eq    |   ^=    |
|     :>      |    ]    |     xor     |    ^    |     not     |    !    |
|     %:      |    #    |    compl    |    ~    |   not_eq    |   !=    |
|    $:%:     |   ##    |   bitand    |    &    |             |         |

---
## 6. 令牌

<pre>
<em>token</em> : 
        <em>identifier</em>
        <em>keyword</em>
        <em>literal</em>
        <em>operator-or-punctuator</em>
</pre>

有五种令牌：标识符、关键字、字面值、运算符和其他分隔符。如下所述的空格、水平和垂直制表符、换行符、换页符和注释 (统称为空白，*whitespace*) 将被忽略，除非它们用于分隔令牌。需要一些空白来分隔相邻的标识符、关键字、数字字面值和包含字母字符的替代标记。

---
## 7. 注释

字符序列 `/*` 开始一个注释，注释以字符序列 `*/` 结束。这些注释不嵌套。

字符序列 `//` 开始一个注释，它在下一个换行字符之前立即终止。如果在这样的注释中有换行符或垂直制表符，则在它和结束注释的换行符之间只能出现空白字符。不需要进行诊断。

注释 `//`、`/*` 和 `*/` 在 `//` 注释中没有特殊含义，与其他字符一样被处理。同样，注释 `//` 和 `/*` 在 `/*` 注释中也没有特殊含义。

```c++
/* first line.
    another line. */
// single line
```

---
## 8. 头文件名称

<pre>
<em>header-name</em> : 
        < <em>h-char-sequence</em> >
        " <em>q-char-sequence</em> "
    
<em>h-char-sequence</em> : 
        <em>h-char</em>
        <em>h-char-sequence h-char</em>

<em>h-char</em> : 
        翻译字符集的任何成员，除了换行符和 U+003E 大于号

<em>q-char-sequence</em> :
        <em>q-char</em>
        <em>q-char-sequence q-char</em>

<em>q-char</em> : 
        翻译字符集的任何成员，除了换行符和 U+0022 引号
</pre>

头文件名预处理令牌只出现在 `#include` 预处理指令中，`__has_include` 预处理表达式，或出现在某个 `import` 令牌之后。头文件名的两种形式的序列都以实现定义的方式映射到头文件名或指定的外部源文件名。

*q-char-sequence* 或 *h-char-sequence* 中出现字符 `'` 或 `\` 或字符序列 `/*` 或 `//` 中的任何一个都是由实现定义的语义有条件地支持的，正如在 *h-char-sequence* 中出现字符 `"` 一样。

---
## 9. 预处理数字

<pre>
<em>pp-number</em> : 
        <em>digit</em>
        <em>. digit</em>
        <em>pp-number identifier-continue</em>
        <em>pp-number</em> ’<em>digit</em>
        <em>pp-number</em> ’<em>nondigit</em>
        <em>pp-number</em> e <em>sign</em>
        <em>pp-number</em> E <em>sign</em>
        <em>pp-number</em> p <em>sign</em>
        <em>pp-number</em> P <em>sign</em>
        <em>pp-number</em> .
</pre>

预处理数字符号在词法上包括所有整型符号和所有浮点型符号。预处理数没有类型或值；它在成功转换为整型符号或浮点型符号后获得这两种类型。

---
## 10. 标识符
<pre>
<em>identifier</em> :
        <em>identifier-start</em>
        <em>identifier identifier-continue</em>

<em>identifier-start</em> :
        <em>nondigit</em>  翻译字符集的元素，具有 Unicode 属性 XID_Start
            
<em>identifier-continue</em> :
        <em>digit</em>
        <em>nondigit</em>  翻译字符集的元素，具有 Unicode 属性 XID_Continue
        
<em>nondigit</em> : one of
        a b c d e f g h i j k l m
        n o p q r s t u v w x y z
        A B C D E F G H I J K L M
        N O P Q R S T U V W X Y Z _
        
<em>digit</em> : one of
        0 1 2 3 4 5 6 7 8 9
</pre>

字符属性 XID_Start 和 XID_Continue 是由 Unicode 标准的 UAX #44 描述的派生核心属性。如果标识符不符合 Unicode 标准中指定的规范化形式 C，则程序格式错误。

标识符是区分大小写的。附件 E 比较了 Unicode 标准 UAX #31 与 C++ 标识符规则的要求。在翻译阶段 4 中，标识符还包括那些在随后的翻译阶段 7 中区分为关键字的预处理令牌。

以下的标识符在出现在特定上下文中时具有特殊含义。当在语法中引用时，这些标识符被显式使用，而不是使用标识符语法生成。除非另有说明，否则任何关于给定标识符是否具有特殊含义的歧义都会被解析，以将令牌解释为常规标识符。

```c++
final
import
module
override
```

另外，一些作为令牌或预处理令牌出现的标识符保留供 C++ 实现使用，不得用于其他用途。不需要诊断。
  - 每个包含双下划线 `__` 或以下划线后跟大写字母开头的标识符都保留给实现以供任何使用。
  - 每个以下划线开头的标识符都保留给实现作为全局命名空间中的名称使用。

---
## 11. 关键字

<pre>
<em>keyword</em> :
        下表中列出的任何标识符
        <em>import-keyword</em>
        <em>module-keyword</em>
        <em>export-keyword</em>
</pre>

```c++
alignas         constinit       false           public             true     
alignof         const_cast      float           register           try                
asm             continue        for             reinterpret_cast   typedef                     
auto            co_await        friend          requires           typeid             
bool            co_return       goto            return             typename     
break           co_yield        if              short              union     
case            decltype        inline          signed             unsigned     
catch           default         int             sizeof             using     
char            delete          long            static             virtual     
char8_t         do              mutable         static_assert      void             
char16_t        double          namespace       static_cast        volatile                     
char32_t        dynamic_cast    new             struct             wchar_t     
class           else            noexcept        switch             while             
concept         enum            nullptr         template                        
const           explicit        operator        this                            
consteval       export          private         thread_local                    
constexpr       extern          protected       throw       
```

上表中所示的标识符保留用作关键字 (也就是说，它们在翻译阶段 7 中被无条件地视为关键字)，但特性令牌除外。`register` 关键字是未使用的，但保留以备将来使用。此外，下表中为某些操作符和标点符号所示的替代表示是保留的，不得用于其他用途。

```c++
and             not_eq        
and_eq          or
bitand          or_eq
bitor           xor
compl           xor_eq
not             
```

---
## 12. 运算符和标点符

C++ 程序的词法表示包括许多预处理标记，这些标记在预处理程序的语法中使用，或者被转换为操作符和标点符号的标记。在翻译阶段 7 中，每个操作符或标点符被转换为单个标记。

<pre>
<em>preprocessing-op-or-punc</em> :
        <em>preprocessing-operator</em>
        <em>operator-or-punctuator</em>

<em>preprocessing-operator</em> : one of
        #       ##      %:      %:%:

<em>operator-or-punctuator</em> : one of
        {       }       [       ]       (       )
        <:      :>      <%      %>      ;       :       ...
        ?       ::      .       .*      ->      ->*     ~
        !       +       -       *       /       %       ^       &       |
        =       +=      -=      *=      /=      %=      ^=      &=      |=
        ==      !=      <       >       <=      >=      <=>     &&      ||
        <<      >>      <<=     >>=     ++      --      ,
        and     or      xor     not     bitand  bitor   compl
        and_eq  or_eq   xor_eq  not_eq
</pre>

---
## 13. 字面值
### 13.1 字面值的分类

<pre>
<em>literal</em> :
        <em>integer-literal</em>
        <em>character-literal</em>
        <em>floating-point-literal</em>
        <em>string-literal</em>
        <em>boolean-literal</em>
        <em>pointer-literal</em>
        <em>user-defined-literal</em>
</pre>

当作为表达式出现时，字面量具有类型和值类别。

>---
### 13.2 整数字面值

<pre>
<em>integer-literal</em> :
        <em>binary-literal integer-suffix<sub>opt</sub></em>
        <em>octal-literal integer-suffix<sub>opt</sub></em>
        <em>decimal-literal integer-suffix<sub>opt</sub></em>
        <em>hexadecimal-literal integer-suffix<sub>opt</sub></em>

<em>binary-literal</em> :
        <em>0b binary-digit</em>
        <em>0B binary-digit</em>
        <em>binary-literal ’<sub>opt</sub> binary-digit</em>

<em>octal-literal</em> :
        <em>0</em>
        <em>octal-literal ’<sub>opt</sub> octal-digit</em>

<em>decimal-literal</em> :
        <em>nonzero-digit</em>
        <em>decimal-literal ’<sub>opt</sub> digit</em>

<em>hexadecimal-literal</em> :
        <em>hexadecimal-prefix hexadecimal-digit-sequence</em>
        
<em>binary-digit</em> : one of
        0 1

<em>octal-digit</em> : one of
        0 1 2 3 4 5 6 7

<em>nonzero-digit</em> : one of
        1 2 3 4 5 6 7 8 9

<em>hexadecimal-prefix</em> : one of
        0x 0X
    
<em>hexadecimal-digit-sequence</em> :
        <em>hexadecimal-digit</em>
        <em>hexadecimal-digit-sequence ’<sub>opt</sub> hexadecimal-digit</em>

<em>hexadecimal-digit</em> : one of
        0 1 2 3 4 5 6 7 8 9
        a b c d e f
        A B C D E F

<em>integer-suffix</em> :
        <em>unsigned-suffix long-suffix<sub>opt</sub></em>
        <em>unsigned-suffix long-long-suffix<sub>opt</sub></em>
        <em>unsigned-suffix size-suffix<sub>opt</sub></em>
        <em>long-suffix unsigned-suffix<sub>opt</sub></em>
        <em>long-long-suffix unsigned-suffix<sub>opt</sub></em>
        <em>size-suffix unsigned-suffix<sub>opt</sub></em>

<em>unsigned-suffix</em> : one of
        u U

<em>long-suffix</em> : one of
        l L
<em>long-long-suffix</em> : one of
        ll LL
<em>size-suffix</em> : one of
        z Z
</pre>

在整数字面值中，二进制数、八进制数、数字或十六进制数的序列被解释为 ***N*** 进制整数。数字序列的词法上的第一个数字是最重要的。在确定值时，前缀和任何可选的分隔单引号将被忽略。

十六进制数字 a ~ f 或 A ~ F 的十进制值为 10 ~ 15。数字 12 可以写成 12、014、0XC 或 Ob1100。整数 1048576、1'048'576、0X100000、Ox10'0000 和 0'004'000'000 都有相同的值。

整数字面值的类型是下表中与它的可选整数后缀相对应的第一个类型，它的值可以用整数后缀表示。

| *integer-suffix*                 | *dicimal-literal*                                                 | *integer-literal* other than *decimal-literal*                                                              |
| :------------------------------- | :---------------------------------------------------------------- | :---------------------------------------------------------------------------------------------------------- |
| none                             | `int`<br>`long int`<br>`long long int`                            | `int`<br>`unsigned int`<br>`long int`<br>`unsigned long int`<br>`long long int`<br>`unsigned long long int` |
| `u` or `U`                       | `unsigned int`<br>`unsigned long int`<br>`unsigned long long int` | `unsigned int`<br>`unsigned long int`<br>`unsigned long long int`                                           |
| `l` or `L`                       | `long int`<br>`long long int`                                     | `long int`<br>`unsigned long int`<br>`long long int`<br>`unsigned long long int`                            |
| `ul` or `Ul` and `uL` or `UL`    | `unsigned long int`<br>`unsigned long long int`                   | `unsigned long int`<br>`unsigned long long int`                                                             |
| `ll` or `LL`                     | `long long int`                                                   | `long long int` <br>`unsigned long long int`                                                                |
| `ull` or `Ull` or `uLL` or `ULL` | `unsigned long long int`                                          | `unsigned long long int`                                                                                    |
| `z` or `Z`                       | 对应的有符号整数类型 `std::size_t`                                | 对应的有符号整数类型 `std::size_t`<br> `std::size_t`                                                        |
| `uz` or `Uz` or `uZ` or `UZ`     | `std::size_t`                                                     | `std::size_t`                                                                                               |

除了包含 *size-suffix* 的整型字面值，如果整型字面值的值不能用其列表中的任何类型表示，而扩展的整型类型可以表示其值，则它可以具有扩展的整型类型。如果整型字面值列表中的所有类型都是有符号的，则扩展的整型类型是有符号的。如果整型列表中的所有类型都是无符号的，则扩展整数类型是无符号的。如果列表同时包含有符号类型和无符号类型，则扩展整数类型可以是有符号类型或无符号类型。如果整型不能用任何允许的类型表示，则程序是格式错误的。带有 `z` 或 `Z` 后缀的整型字面值如果不能用 `std::size_t` 表示，则是格式错误的。

>---
### 13.3 字符字面值

<pre>
<em>character-literal</em> :
        <em>encoding-prefix<sub>opt</sub> ’ c-char-sequence ’</em>

<em>encoding-prefix</em> : one of
        u8 u U L

<em>c-char-sequence</em> :
        <em>c-char</em>
        <em>c-char-sequence c-char</em>
        
<em>c-char</em> :
        <em>basic-c-char</em>
        <em>escape-sequence</em>
        <em>universal-character-name</em>

<em>basic-c-char</em> : 
        翻译字符集的任何成员，除了 U+0027 撇号、U+005C 回车符或换行符

<em>escape-sequence</em> : 
        <em>simple-escape-sequence</em>
        <em>numeric-escape-sequence</em>
        <em>conditional-escape-sequence</em>

<em>simple-escape-sequence</em> : 
        \ <em>simple-escape-sequence-char</em>

<em>simple-escape-sequence-char</em> : one of
        ’ " ? \ a b f n r t v

<em>numeric-escape-sequence</em> : 
        <em>octal-escape-sequence</em>
        <em>hexadecimal-escape-sequence</em>

<em>simple-octal-digit-sequence</em> : 
        <em>octal-digit</em>
        <em>simple-octal-digit-sequence octal-digit</em>

<em>octal-escape-sequence</em> : 
        \ <em>octal-digit</em>
        \ <em>octal-digit octal-digit</em>
        \ <em>octal-digit octal-digit octal-digit</em>
        \o{ <em>simple-octal-digit-sequence</em> }

<em>hexadecimal-escape-sequence</em> : 
        \x <em>simple-hexadecimal-digit-sequence</em>
        \x{ <em>simple-hexadecimal-digit-sequence</em> }

<em>conditional-escape-sequence</em> : 
        \ <em>conditional-escape-sequence-char</em>

<em>conditional-escape-sequence-char</em> : 
        基本字符集的任何成员，它不是八进制数字、简单转义序列字符或字符 N, o, u, U, 或 x
</pre>

多字符字面值是其 *c-char-sequence* 由多个 *c-char* 组成的 *character-literal*。多字符字面值不能有编码前缀 (*encoding-prefix*)。如果一个多字符字面值包含一个在普通字面值编码中不能作为单个代码单元进行编码的 *c-char*，则该程序是格式错误的。多字符字面值是有条件支持的。

字符字面值的种类、类型和与之相关的字符编码由其 *encoding-prefix* 和 *c-char-sequence* 决定，如下表所定义。

| 编码前缀 | 种类              | 类型       | 关联字符编码   | 示例     |
| :------- | :---------------- | :--------- | :------------- | :------- |
| none     | 常规字符字面值    | `char`     | 常规字面值编码 | `'v'`    |
| none     | 多字符字面值      | `int`      | 常规字面值编码 | `'abcd'` |
| `L`      | 宽字符字面值      | `wchar_t`  | 宽字面值编码   | `L'w'`   |
| `u8`     | UTF-8 字符字面值  | `char8_t`  | UTF-8          | `u8'x'`  |
| `u`      | UTF-16 字符字面值 | `char16_t` | UTF-16         | `u'y'`   |
| `U`      | UTF-32 字符字面值 | `char32_t` | UTF-32         | `U'z'`   |

在翻译阶段 4 中，*character-literal* 的值是使用在翻译阶段 7 中 *character-literal* 类型的可表示值的范围来确定的。多字符字面值有一个实现定义的值。任何其他类型的字符字面量的值由如下方式确定：
  - 由单个 *basic-c-char*、*simple-escape-sequence* 或 *universal-character-name* 组成的 *c-char-sequence* 的字符字面量是指定字符的编码单位值，用该字符字面量的相关字符编码进行编码。如果指定的字符在文字的关联字符编码中缺乏表示，或者如果它不能被编码为单个代码单元，则程序是格式错误的。
  - 由单个数字转义序列组成的 *c-char-sequence* 的字符字面量的值如下：
    - 设 *v* 为整数值，由八进制转义序列中包含的八进制数字序列表示，或由十六进制转义序列中包含的十六进制数字序列表示。
    - 如果 *v* 没有超出字符字面值类型的可表示值的范围，则该值为 *v*。
    - 否则，如果字符字面值的编码前缀不存在或为 `L`，并且 *v* 不超过字符字面值类型的基础类型对应的无符号类型的可表示值的范围，则该值为字符字面值类型 `T` 中与 `v` 模 2<sup>*N*</sup> 相等的唯一值，其中 *N* 为 `T` 的宽度。
    - 否则，程序格式错误。
  - 由单个条件转义序列组成的 *c-char-sequence* 的字符字面量是有条件支持的，并且具有实现定义的值。

下表中指定了由简单转义序列指定的字符。为了与 ISO C++ 2014 和 ISO C 兼容，支持对问号使用转义序列。

| Unicode | 字符                 | 转义序列 |
| :------ | :------------------- | :------- |
| U+000a  | line feed            | \n       |
| U+0009  | character tabulation | \t       |
| U+000b  | line tabulation      | \v       |
| U+0008  | backspace            | \b       |
| U+000d  | carriage return      | \r       |
| U+000c  | form feed            | \f       |
| U+0007  | alert                | \a       |
| U+005c  | reverse solidus      | \\\\     |
| U+003f  | question mark        | \?       |
| U+0027  | apostrophe           | \’       |
| U+0022  | quotation mark       | \"       |

>---
### 13.4 浮点字面值

<pre>
<em>floating-point-literal</em> :
        <em>decimal-floating-point-literal</em>
        <em>hexadecimal-floating-point-literal</em>

<em>decimal-floating-point-literal</em> :
        <em>fractional-constant exponent-part<sub>opt</sub> floating-point-suffix<sub>opt</sub></em>
        <em>digit-sequence exponent-part floating-point-suffix<sub>opt</sub></em>

<em>hexadecimal-floating-point-literal</em> :
        <em>hexadecimal-prefix hexadecimal-fractional-constant binary-exponent-part floating-point-suffix<sub>opt</sub></em>
        <em>hexadecimal-prefix hexadecimal-digit-sequence binary-exponent-part floating-point-suffix<sub>opt</sub></em>

<em>fractional-constant:</em>
        <em>digit-sequence<sub>opt</sub> . digit-sequence</em>
        <em>digit-sequence .</em>

<em>hexadecimal-fractional-constant</em> :
        <em>hexadecimal-digit-sequenceopt . hexadecimal-digit-sequence</em>
        <em>hexadecimal-digit-sequence .</em>

<em>exponent-part</em> :
        e <em>sign<sub>opt</sub> digit-sequence</em>
        E <em>sign<sub>opt</sub> digit-sequence</em>

<em>binary-exponent-part:</em>
        p <em>sign<sub>opt</sub> digit-sequence</em>
        P <em>sign<sub>opt</sub> digit-sequence</em>

<em>sign</em> : one of
        + -
<em>digit-sequence</em> :
        <em>digit</em>
        <em>digit-sequence ’<sub>opt</sub> digit</em>

<em>floating-point-suffix</em> : one of
        f l f16 f32 f64 f128 bf16 F L F16 F32 F64 F128 BF16
</pre>

浮点字面值的类型由下表中指定的浮点后缀决定。浮点后缀 `f16`, `f32`, `f64`, `f128`, `bf16`, `F16`, `F32`, `F64`, `F128`, 和 `BF16` 是有条件支持的。

| floating-point-suffix | type              |
| :-------------------- | :---------------- |
| none                  | `double`          |
| `f` or `F`            | `float`           |
| `l` or `L`            | `long double`     |
| `f16` or `F16`        | `std::float16_t`  |
| `f32` or `F32`        | `std::float32_t`  |
| `f64` or `F64`        | `std::float64_t`  |
| `f128` or `F128`      | `std::float128_t` |
| `bf16` or `BF16`      | `std::bfloat16_t` |

浮点字面值的有效位数是小数浮点字面值的小数常量或数字序列，或十六进制浮点字面值的十六进制小数常量或十六进制数字序列。在有效数中，数字序列或十六进制数字和可选的句点被解释为一个以 *N* 为基数的实数 *s*，其中 *N* 对于小数浮点字面值为 10，对于十六进制浮点字面值为 16。在确定值时，任何可选的分隔单引号都会被忽略。

如果存在指数部分或二进制指数部分，则浮点字面值的指数 *e* 是将可选符号和数字的序列解释为基数为 10 的整数的结果。否则，指数 *e* 为0。对于小数浮点字面值，字面值的缩放值为 *s* × 10<sup>*e*</sup>，对于十六进制浮点字面值，其缩放值为 *s* × 2<sup>*e*</sup>。浮点字面值 `49.625` 和 `OxC.68p+2` 具有相同的值，`1.602'176'565e-19` 和 `1.602176565e-19` 具有相同的值。

如果缩放后的值不在其类型的可表示值范围内，则程序格式错误。否则，浮点字面值的值是可表示的缩放值，否则以实现定义的方式选择最接近缩放值的较大或较小的可表示值。

>---
### 13.5 字符串字面值

<pre>
<em>string-literal</em> :
        <em>encoding-prefix<sub>opt</sub></em> " <em>s-char-sequence<sub>opt</sub></em> "
        <em>encoding-prefix<sub>opt</sub></em> R <em>raw-string</em>

<em>s-char-sequence</em> :
        <em>s-char</em>
        <em>s-char-sequence s-char</em>

<em>s-char</em> :
        <em>basic-s-char</em>
        <em>escape-sequence</em>
        <em>universal-character-name</em>

<em>basic-s-char</em> :
        翻译字符集的任何成员，但 U+0022 引号、U+005C 回车号或换行字符除外

<em>raw-string</em> :
        " <em>d-char-sequence<sub>opt</sub></em> ( <em>r-char-sequence<sub>opt</sub></em> ) <em>d-char-sequence<sub>opt</sub></em> "

<em>r-char-sequence</em> :
        <em>r-char</em>
        <em>r-char-sequence r-char</em>

<em>r-char</em> :
        翻译字符集的任何成员，除了 U+0029 括号，后面跟着初始 <em>d-char-sequence</em> (可以是空的)，后面跟着 U+0022 引号

<em>d-char-sequence</em> :
        <em>d-char</em>
        <em>d-char-sequence d-char</em>

<em>d-char</em> :
        基本字符集的任何成员，除了: U+0020 空格、U+0028 左括号、U+0029 右括号、U+005C 回车符、U+0009 水平制表符、U+000B 垂直制表符、U+000C 分页符和换行符
<em></em>
</pre>

字符串字面值的种类、类型和相关字符编码由其编码前缀和 *s-chars* 序列或 *r-chars* 序列决定，如下表所定义，其中 *n* 是编码的代码单元数：

| 编码前缀 | 类别             | 类型                | 关联字符编码 | 示例                                              |
| :------- | :--------------- | :------------------ | :----------- | :------------------------------------------------ |
| none     | 常规字符串字面值 | `const char[n]`     | 常规字符编码 | `"ordinary string"`<br>`R"(ordinary raw string)"` |
| `L`      | 宽字符串字面值   | `const wchar_t[n]`  | 宽字符编码   | `L"wide string"`<br>`LR"w(wide raw string)w"`     |
| `u8`     | UTF-8 字符串     | `const char8_t[n]`  | UTF-8        | `u8"UTF-8 string"`<br>`u8R"x(UTF-8 raw string)x"` |
| `u`      | UTF-16 字符串    | `const char16_t[n]` | UTF-16       | `u"UTF-16 string"`<br>`uR"y(UTF-16 raw string)y"` |
| `U`      | UTF-32 字符串    | `const char32_t[n]` | UTF-32       | `U"UTF-32 string"`<br>`UR"z(UTF-32 raw string)z"` |


前缀中有 *R* 的字符串字面值是原始字符串字面值。*d-char-sequence* 用作分隔符。原始字符串的终止 *d-char-sequence* 与初始 *d-char-sequence* 是相同的字符序列。一个 *d-char-sequence* 最多包含 16 个字符。

字符 `(` 和 `)` 允许出现在原始字符串中。因此，`R"delimiter((alb))delimiter"` 等价于 `"(alb)"`。原始字符串字面值中的换行会导致执行字符串字面值中的换行。假设在下面的例子中行首没有空格，`assert` 将会成功:

## end 

接下来你会翻译我说的每句英文为中文 