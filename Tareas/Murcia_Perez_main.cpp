#include <iostream>
#include "Murcia_Perez_idx_list.hpp"
using namespace std;

int main() {

	//constructor
	cout << "Constructor: " << endl;
	indexable_list<char> mylist;

	cout << mylist << endl;

	//append
	for (int i = 'a'; i <= 'z'; ++i) {
		mylist.append(i);
	}

	//operator <<
	cout << "\noperator <<: " << endl;
	cout << mylist << endl << endl;

	//operator [] const
	cout << "operator [] const:" << endl;
	const char p = mylist[4];
	cout << p << endl ;
	//operator []
	cout << "\noperator []: " << endl;
	for (size_t i = 0; i < mylist.size(); ++i) {
		cout << mylist[i] << " ";
	}
	cout << "\n\nmodified with operator []" << endl;
	mylist[0] = '&';
	mylist[25] = '&';
	cout << mylist << endl;

	//obtain
	cout << "\nobtain: " << endl;
	for (size_t i = 0; i < mylist.size(); ++i) {
		cout << mylist.obtain(i) << " ";
	}
	cout << endl << endl;
	//This should throw an exception
	//cout << mylist.obtain(mylist.size()) << endl;

	//insert
	cout << "insert: " << endl;
	mylist.insert(0, 'A');
	mylist.insert(27, 'A');
	cout << mylist << endl << endl;

	//replace
	cout << "replace: " << endl;
	mylist.replace(0, 'B');
	cout << mylist << endl << endl;

	//erase
	cout << "The element: " << mylist.erase(0) << " was deleted" << endl;
	cout << mylist << endl << endl;

	//clear
	cout << "clear: " << endl;
	mylist.clear();
	cout << mylist << endl << endl;

	//empty
	cout << "empty: " << endl;
	if (mylist.empty()) {
		cout << "The list is empty" << endl;
	}
}