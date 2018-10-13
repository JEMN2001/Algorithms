#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {
	Vector<int> myvec;
	myvec.push_back(1);
	myvec.push_back(2);
	for (unsigned i = 0; i < myvec.size(); ++i) {
		cout << myvec.at(i) << ", ";
	}
	cout << endl << myvec[1] << endl;
	return 0;
}