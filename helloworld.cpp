#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <typeinfo>
#include <iostream>
#include <cassert>
#include <bitset>
#include <initializer_list>
using namespace std;

struct Point {
	int x, y;
	Point(int x, int y) : x{ x }, y{ y } {};
	explicit Point(Point& other) {
		x = other.x;
		y = other.y;
	}
	Point(Point&& other) noexcept {
		*this = std::move(other);
	}

	Point& operator= (Point&& other) noexcept {
		cout << "move\n";
		x = other.x;
		y = other.y;
	}

	Point& operator= (Point& other) {
		cout << "copy\n";
		x = other.x;
		y = other.y;
	}
};

int main() {
	vector<Point> ps = initializer_list<Point>{ {1,1}, {0,0}, {1,2}, {3,4} };
	ps.insert(ps.begin() + 2, Point{ 3, 3 });

	Point p = { 1,2 };
	p = { 2,2 };
}
