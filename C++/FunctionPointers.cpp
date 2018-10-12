#include <iostream>
using namespace std;

void BubbleSort(int array[], int size, bool (*cmp)(int, int));
bool less_than(int i, int j);
bool more_than(int i, int j);

int main() {
	int size = 5, arr1[] = {32, 54, 3, 46, 89}, arr2[] = {32, 54, 3, 46, 89};
	BubbleSort(arr1, size, less_than);
	BubbleSort(arr2, size, more_than);
	for (int i = 0; i < size; ++i) {
		cout <<  arr1[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < size; ++i) {
		cout <<  arr2[i] << ", ";
	}
	return 0;
}

bool less_than(int i, int j) {
	return i < j;
}
bool more_than(int i, int j) {
	return i > j;
}
void BubbleSort(int array[], int size, bool (*cmp)(int, int)) {
	int n = size;
	for(int i = 0; i < n-1; ++i) {
		for (int j = 0; j < n-1; ++j) {
			if (cmp(array[j], array[j+1])) {
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}