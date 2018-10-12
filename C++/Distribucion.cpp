#include <iostream>
#include <stack>
using namespace std;

stack<char> test;
string input;
bool isFine(stack<char> & stk);
bool isOpen(char & z);

int main() {
	cout << "Ingrese la cadena: ";
	cin >> input;
	for (size_t i = 0; i < input.length(); ++i){
		test.push(input.at(i));
	}
	if (isFine(test)) {
		cout << "Estan bien distribuidos" << endl;
	}
	else {
		cout << "No estan bien distribuidos" << endl;
	}
}
bool isOpen(char & z) {
	if ((z == '{') || (z == '(') || (z == '[')) {
		return true;
	}
	return false;
}
bool isFine(stack<char> & stk) {
	char z = stk.top();
	char temp = z;
	int par = 0;
	int lla = 0;
	int cor = 0;
	if (isOpen(z)) {
		return false;
	}
	else {
		if (z == ')') {++par;}
		else if (z == '}') {++lla;}
		else if (z == ']') {++cor;}
		stk.pop();
		while (!(stk.empty())) {
			z = stk.top();
			if (z == ')') {++par;}
			else if (z == '}') {++lla;}
			else if (z == ']') {++cor;}
			else if (z == '(' && par <= 0) {return false;}
			else if (z == '(' && par > 0 && (isOpen(temp) || temp == ')')) {--par;}
			else if (z == '{' && lla <= 0) {return false;}
			else if (z == '{' && lla > 0 && (isOpen(temp) || temp == '}')) {--lla;}
			else if (z == '[' && cor <= 0) {return false;}
			else if (z == '[' && cor > 0 && (isOpen(temp) || temp == ']')) {--cor;}
			temp = stk.top();
			stk.pop();
		}
		if ((par != 0) || (lla != 0) || (cor != 0)) {
			return false;
		}
		return true;
	}
}
