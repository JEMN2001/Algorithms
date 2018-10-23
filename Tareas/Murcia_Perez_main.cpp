#include <iostream>
#include "Murcia_Perez_idx_list.hpp"
using namespace std;

int main() {

	//constructor
	indexable_list<char> mylist;

	//append function
	for (int i = 'a'; i <= 'z'; ++i) {
		mylist.append(i);
	}

	//operator <<
	cout << mylist << endl;

	//operator []
	cout << "operator []: ";
	for (size_t i = 0; i < mylist.size(); ++i) {
		cout << mylist[i] << " ";
	}
	cout << endl;

	//obtain
	cout << "obtain: ";
	for (size_t i = 0; i < mylist.size(); ++i) {
		cout << mylist.obtain(i) << " ";
	}
	cout << endl;
	//This should throw an exception
	//cout << mylist.obtain(mylist.size()) << endl;

	//insert
	mylist.insert(26, 'A');
	cout << mylist << endl;

	//replace
	mylist.replace(4, 'B');
	cout << mylist << endl;


	//clear
	mylist.clear();
	cout << mylist << endl;

	//empty
	if (mylist.empty()) {
		cout << "The list is empty" << endl;
	}
}