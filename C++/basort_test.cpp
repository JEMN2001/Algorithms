#include<iostream>
#include<vector>
#include "basort.hpp"
using namespace std;

void printvector(vector<int> & lst);

int main() {
	vector<int> myvec = {71, 51, 6, 30, 49, 2, 35, 75, 51, 82, 6, 99, 7, 57, 69, 59, 84, -3};
	printvector(myvec);
	DoubleSelectionSort(myvec);
	cout << IsSorted(myvec) << endl;
	return 0;
}

void printvector(vector<int> & lst) {
	cout << '[';
	for (size_t i = 0; i < lst.size(); ++i) {
		if (i < lst.size()-1) {
			cout << lst.at(i) << ", ";
		}
		else {
			cout << lst.at(i) << ']' << endl;
		}
	}
}