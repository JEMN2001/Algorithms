#include <iostream>
using namespace std;

int x = 1;
float y = 3.14;
bool z = true;
long a = 123456789;
long long b = 12345678987654321;
short c = 1;
char d = 'a';
double e = 3.1415;

int main() {
	cout << "Size of integer: " << sizeof(x) << endl;
	cout << "Size of float: " << sizeof(y) << endl;
	cout << "Size of double: " << sizeof(e) << endl;
	cout << "Size of bool: " << sizeof(z) << endl;
	cout << "Size of long: " << sizeof(a) << endl;
	cout << "Size of long long: " << sizeof(b) << endl;
	cout << "Size of short: " << sizeof(c) << endl;
	cout << "Size of an char: " << sizeof(d) << endl;
	return 0;
}
