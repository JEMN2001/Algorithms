#include <iostream>
#include <set>
#include <cmath>
using namespace std;

set<int> createPrimeSet(size_t & max);
size_t num;
set<int> test;

int main() {
	cout << "Enter the maximum:\n> ";
	cin >> num;
	test = createPrimeSet(num);
	for(set<int>::iterator iter=test.begin(); iter!=test.end();++iter){
			cout << *iter << " ";
	}
	cout << endl;
	return 0;
}

set<int> createPrimeSet(size_t & max) {
	set<int> out;
	for (size_t i = 2; i <= max; ++i) {
		out.emplace(i);
		for (size_t j = 2; j <= ((size_t) sqrt(i)); ++j) {
			if (i%j == 0) {
				out.erase(i);
				break;
			}
		}
	}
	return out;
}

