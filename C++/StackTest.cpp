#include <iostream>
#include "Stack.hpp"
using namespace std;

int main() {
	Stack<int> mystack, two;
	for (int i = 1; i <= 20; ++i) {
		mystack.push(i);
	}
	two = mystack;
	Stack<int> three = two;
	int size = mystack.size();
	for (int i = 0; i < size; ++i) {
		cout << mystack.pop() << endl;
	}
	cout << "-------------------------" << endl;
	size = two.size();
	for (int i = 0; i < size; ++i) {
		cout << two.pop() << endl;
	}
	cout << "-------------------------" << endl;
	size = three.size();
	for (int i = 0; i < size; ++i) {
		cout << three.pop() << endl;
	}
	//This should throw a exception
	//cother << mystack.peek() << endl;
	return 0;
}
