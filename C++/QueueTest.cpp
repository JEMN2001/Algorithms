#include <iostream>
#include "Queue.hpp"
using namespace std;

int main() {
	Queue<int> que;
	for (int i = 1; i < 21; ++i) {
		que.push(i);
		if (i == 3 || i == 7) {
			que.pop();
		}
	}
	size_t size = que.size();
	for (size_t i = 0; i < size; ++i) {
		cout << que.pop() << endl;
	}
	if (que.empty()) {
		cout << "el queue esta vacio!" << endl;
	}
	return 0;
}
