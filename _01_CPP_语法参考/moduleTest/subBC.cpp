module;

#include <iostream>

module myMain:subBC;
using namespace std;

void MyFuncBC() {
	cout << "Call MyFuncA in MyFuncBC: ";
	MyFuncA();
}

void MyFuncB() {
	std::cout << "MyFuncB in subBC\n";
}
void MyFuncC() {
	std::cout << "MyFuncC in subBC\n";
}

