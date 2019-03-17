#include <iostream>
using namespace std;

bool subSet_Sum(int array[], size_t size, int sum);

int main() {
	size_t in;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "Enter the sum\n> ";
	cin >> in;
	cout << subSet_Sum(array, 10, in);
	return 0;
}

bool subSet_Sum(int array[], size_t size, int sum) {
	if (size == 0)
		return false;
	if (size == 1)
		return ((array[0] == sum) ? true : false);
	return (subSet_Sum(array, size-1, sum-array[size-1]) || subSet_Sum(array, size-1, sum));
}