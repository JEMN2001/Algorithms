#include <iostream>
using namespace std;

size_t Comb(size_t n, size_t k);

int main() {
	cout << "Testing the Comb() Function" << endl;
	cout << "(5 3) = " << Comb(5,3) << endl << "[";
	for (size_t i = 0; i < 7; ++i) {
		cout << Comb(6, i);
		if (i < 6)
			cout << ", ";
	}
	cout << "]" << endl;
	return 0;
}

size_t Comb(size_t n, size_t k) {
	if (k <= n) {
		if (k == 0 || k == n) {
			return 1;
		}
		if (k == 1 || k == (n-1)) {
			return n;
		}
		return Comb(n-1, k-1)+Comb(n-1, k);
	}
	throw;
}