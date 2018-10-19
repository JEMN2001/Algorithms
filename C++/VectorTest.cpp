#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {
	Vector<int> myvec, three;
	myvec.push_back(1);
	myvec.push_back(2);
	Vector<int> other = myvec;
	cout << myvec << endl << myvec.Capacity() << endl;
	myvec.resize(15);
	three = myvec;
	cout << myvec << endl << myvec.Capacity() << endl;
	myvec.clear();
	cout << myvec << endl << myvec.Capacity() << endl;
	cout << other << endl << other.Capacity() << endl;
	cout << three << endl << other.Capacity() << endl;
	return 0;
}