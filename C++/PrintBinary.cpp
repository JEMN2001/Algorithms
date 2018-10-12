#include <iostream>
#include <string>
using namespace std;

void print_binary_helper(int digits, string prefix);
void print_binary(int digits);
int in;

int main() {
	cout << "Enter the number of digits:\n> ";
	cin >> in;
	print_binary(in);
	return 0;
}

void print_binary_helper(int digits, string prefix) {
	if (digits == 0) {
		cout << prefix << endl;
	}
	else  {
		print_binary_helper(digits - 1, prefix+"0");
		print_binary_helper(digits - 1, prefix+"1");
	}
}
void print_binary(int digit) {
	print_binary_helper(digit, "");
}
