#include <iostream>
#include "BinaryHeap.hpp"

using namespace std;

int main() {
	BinaryHeap<int> myheap(10);
	for (int i = 9; i > -10; --i) {
		myheap.insert(i);
	}
	myheap.display();
	size_t size = myheap.size();
	for (size_t i = 0; i < size; ++i) {
		myheap.deleteMin();
		myheap.display();
	}
}