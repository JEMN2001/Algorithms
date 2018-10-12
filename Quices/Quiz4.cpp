#include <iostream>
#include <vector>
using namespace std;

void ExpandCapacity(int *&array, int & size);
void CreateArray(int *&array, int & size);
void sum_cont(const vector<int> & vec);

int main() {
	int size = 5, *array = new int[size];
	vector<int> vec;
	CreateArray(array, size);
	for (int i = 0; i < size; ++i) {
		if (array[i] != 0) {
			vec.push_back(array[i]);
		}
	}
	delete[] array;
	cout << "------------------------------------" << endl;
	sum_cont(vec);
	return 0;
}

void CreateArray(int *&array, int & size) {
	int in, count = 0;
	cout << "Enter 0 to stop" << endl << "> ";
	cin >> in;
	while (in != 0) {
		if (count == size) {
			ExpandCapacity(array, size);
		}
		array[count++] = in;
		cout << "> ";
		cin >> in;
	}
}
void ExpandCapacity(int *&array, int & size) {
	int *old = array;
	size *= 2;
	array = new int[size];
	for (int i = 0; i < size/2; ++i) *(array+i) = *(old+i);
	for (int j = size/2; j < size; ++j) *(array+j) = 0;
	delete[] old;
	old = nullptr;
}

void sum_cont(const vector<int> & vec) {
	for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
		int first = *iter, second = *(++iter), sum = first + second;
		--iter;
		cout << first << " + " << second << " = " << sum << endl;
	}
}
