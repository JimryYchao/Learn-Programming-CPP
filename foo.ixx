module;
#include<string>
export module foo;

#define X "foo"

export std::string f();

export module foo:part1;
std::string f() {
	return X;
}