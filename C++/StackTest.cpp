#include <iostream>
#include "Stack.hpp"
using namespace std;

int main() {
	Stack<int> mystack;
	for (int i = 1; i <= 20; ++i) {
		mystack.push(i);
	}
	other.printList();
	int size = mystack.size();
	for (int i = 0; i < size; ++i) {
		cout << mystack.pop() << endl;
	}
	//This should throw a exception
	//cother << mystack.peek() << endl;
	return 0;
}
