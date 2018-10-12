#include <iostream>
#include <string>
using namespace std;

string ReverseString(string str);
string in;

int main() {
	cout << "> ";
	getline(cin, in);
	cout << "Su string al revez es:\n" << ReverseString(in) << endl;
	return 0;
}

string ReverseString(string str) {
	string out = "";
	if (str.size() == 0 || str.size() == 1) {
		return str;
	}
	else if (str.size() == 2) {
		swap(str.at(0), str.at(1));
		return str;
	}
	else {
		out = str.at(str.size()-1)+ReverseString(str.substr(1, str.size()-2))+str.at(0);
		return out;
	}
}
