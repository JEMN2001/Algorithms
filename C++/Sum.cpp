#include <iostream>
using namespace std;

int maxSubSum4(const int a[]) {
	int size = 27;
	int maxSum = 0, thisSum = 0, ini = 0, end = size-1;
	for (int j = 0; j < size; ++j) {
        	thisSum += a[j];
		if (thisSum > maxSum) { 
			maxSum = thisSum;
			end = j;
		}
		else if (thisSum < 0) {
			thisSum = 0;
			ini = j+1;
		}
    	}
	cout << ini << " " << end << endl;
	return maxSum;
}
int main() {
	int a[] = {1,2,4,3,5,6,88,99,77,66,55,6,7,77,65 ,-111,33, -11,33,44,66,11,22,33,-44-22-34};
	int sum = maxSubSum4(a);
	cout << sum << endl;
	return 0;
}
