#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {
	Vector<int> myvec;
	myvec.push_back(1);
	myvec.push_back(2);
	cout << myvec << endl << myvec.Capacity() << endl;
	myvec.resize(15);
	cout << myvec << endl << myvec.Capacity() << endl;
	myvec.clear();
	cout << myvec << endl << myvec.Capacity() << endl;
	return 0;
}