#include <iostream>
#include "Queue.hpp"
using namespace std;

int main() {
	Queue<int> que, two;
	for (int i = 1; i < 21; ++i) {
		que.push(i);
		if (i == 3 || i == 7) {
			que.pop();
		}
	}
	two = que;
	Queue<int> three = two;
	size_t size = que.size();
	for (size_t i = 0; i < size; ++i) {
		cout << que.pop() << endl;
	}
	if (que.empty()) {
		cout << "el queue esta vacio!" << endl;
	}
	cout << "------------------------" << endl;
	size = two.size();
	for (size_t i = 0; i < size; ++i) {
		cout << two.pop() << endl;
	}
	if (two.empty()) {
		cout << "el otro queue esta vacio!" << endl;
	}
	cout << "-----------------------------------" << endl;
	size = three.size();
	for (size_t i = 0; i < size; ++i) {
		cout << three.pop() << endl;
	}
	if (three.empty()) {
		cout << "el otro queue esta vacio!" << endl;
	}
	return 0;
}
