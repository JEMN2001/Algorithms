#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
	BST<int> mytree;
	mytree.insert(5);
	mytree.insert(1);
	mytree.insert(10);
	cout << "My actual size is: " << mytree.size() << endl;
	mytree.remove(5);
	cout << "My actual size is: " << mytree.size() << endl << "------------------------------" << endl;
	mytree.remove(1);
	mytree.remove(10);
	if (mytree.root == nullptr) {
		cout << "es null" << endl;
	}
	cout << "My actual size is: " << mytree.size() << endl;
	return 0;
}