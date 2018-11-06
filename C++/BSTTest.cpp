#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
	BST<int> mytree;
	mytree.insert(5);
	mytree.insert(1);
	mytree.insert(10);
	BST<int> other = mytree;
	mytree.display();
	cout << "My actual size is: " << mytree.size() << endl;
	mytree.remove(5);
	mytree.display();
	cout << "My actual size is: " << mytree.size() << endl << "------------------------------" << endl;
	mytree.remove(1);
	mytree.remove(10);
	mytree.display();
	cout << "My actual size is: " << mytree.size() << endl;
	cout << "-----------------------------------" << endl;
	other.display();
	cout << "My actual size is: " << other.size() << endl;
	if(other.find(10)) {
		cout << "10 is in the tree" << endl;
	}
	if (other.find(25)) {
		cout << "25 is in the tree" << endl;
	}
	other.clear();
	other.display();
	cout << "My actual size is: " << other.size() << endl;
	return 0;
}