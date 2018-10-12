/*
*Author: Me
*Last Modification: 10/09/2018
*/
#include <iostream>
using namespace std;

//Class Point
class Point {
public:
	int p;
	int c;
	Point(int c = 0, int p = 0): c(c), p(p) {}
	Point(const Point & k): c(k.c), p(k.p) {}
	friend bool operator==(Point & p, Point & k);
	friend ostream & operator<<(ostream & os, Point c);
	friend double operator*(Point & p, Point & c);
};
//Definition of some random methods
bool operator==(Point & p, Point & k) {
	return (p.p == k.p && p.c == k.c);
}
ostream & operator<<(ostream & os, Point c) {
	return os << "(" << c.p << "," << c.c << ")";
}
double operator*(Point & p, Point & c) {
	return ((p.p*c.p)+(p.c*c.c));
}
//Main Method
int main() {
	Point p = Point(3, 4); 
	Point k = p;
	cout << p << endl;
	cout << k << endl;
	cout << (p==k) << endl;
	cout << (p*k) << endl;
	return 0;
}
//End of Execution
