#include <iostream>
#include <vector>
using namespace std;

void Sort();

int main() {
	Sort();
	return 0;
}

void Sort() {
	int in;
	vector<int> frec (100, 0);
	cout << "Ingres los numeros que desea organizar" << endl;
	while(true) {
		cout << "> ";
		cin >> in;
		if (in < 0 || in > 99) {
			break;
		}
		++frec.at(in);
	}
	for (size_t i = 0; i < 100; ++i) {
		for (size_t j = 0; j < frec.at(i); ++j) {
			cout << i << ", ";
		}
	}
	cout << endl;
}
