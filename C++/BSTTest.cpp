#include <iostream>
#include "BST.hpp"

using namespace std;

int main() {
	BST<int> mytree;
	mytree.insert(5);
	mytree.insert(1);
	mytree.insert(10);
	mytree.printTree(mytree.root);
	return 0;
}