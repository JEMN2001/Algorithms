#include <iostream>
#include <vector>
#include "fastsort.hpp"

using namespace std;

int main() {
	vector<int> vec = {3, 5, 2, 9, 6, 1};
	quicksort(vec, 0, vec.size()-1);
	cout << '[';
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		if (iter+1 != vec.end()) {
			cout << *iter << ", ";
		}
		else {
			cout << *iter;
		}
	}
	cout << ']' << endl;
	return 0;
}