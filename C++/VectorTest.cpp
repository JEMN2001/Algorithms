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
	cout << three << endl << three.Capacity() << endl;
	three = {1, 2, 3, 4, 5};
	cout << three << " " << three.Capacity() << endl;
	three.erase(2);
	cout << three << " " << three.Capacity() << " " << three.size() << endl;
	three.insert(2, 3);
	cout << three << " " << three.Capacity() << " " << three.size() << endl;
	Vector<char> charvec(10, 'a');
	cout << charvec << " " << charvec.Capacity() << endl;
	return 0;
}