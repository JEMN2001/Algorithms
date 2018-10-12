#include <iostream>
#include <string>
using namespace std;

bool IsPal(string str);
string in;

int main() {
	cout << "Ingrese algo:\n> ";
	getline(cin, in);
	if (IsPal(in)) {
		cout << "Es palindrome" << endl;
	}
	else {
		cout << "No es Palindrome" << endl;
	}
	return 0;
}

bool IsPal(string str) {
	if (str.size() == 0 || str.size() == 1) {
		return true;
	}
	else if (str.size() == 2) {
		return str.at(0) == str.at(1);
	}
	else {
		return (str.at(0) == str.at(str.size()-1) && IsPal(str.substr(1, str.size()-2)));
	}
}
