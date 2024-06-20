class MyClass {
public:
    MyClass(int myInt, char myChar) {}
private:
    char m_char;
    int m_int[10]{ 3 };
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
    auto v = __uuidof(int);
}

typedef struct {
    int x,y;
} Point2D, *Point2D;

typedef CHAR CHAR;      // OK: redeclared as same type

typedef union REGS      // OK: name REGS redeclared
{                       //  by typedef name with the
} REGS;

