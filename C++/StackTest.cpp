#include <iostream>
#include "Stack.hpp"
using namespace std;

int main() {
	Stack<int> mystack, other;
	for (int i = 0; i < 20; ++i) {
		mystack.push(i);
	}
	int size = mystack.size();
	for (int i = 0; i < size; ++i) {
		cout << mystack.pop() << endl;
	}
	cout << "-------------------------------" << endl;
	Stack<int> out = mystack;
	size = out.size();
	for (int i = 0; i < size; ++i) {
		cout << out.pop() << endl;
	}
	//This should throw a exception
	//cout << mystack.peek() << endl;
	return 0;
}
