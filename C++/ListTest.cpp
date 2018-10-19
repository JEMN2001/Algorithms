#include <iostream>
#include "List.hpp"
using namespace std;

int main() {
	List<int> ls, p, c = ls;
	while(!c.empty()) {
		cout << c.Front() << endl;
		c.pop_front();
	}
	ls.push_front(3);
	ls.push_front(4);
	ls.push_back(17);
	p = ls;
	while (!ls.empty()) {
		cout << ls.Front() << ", ";
		ls.pop_front();
	}
	cout << endl << "-----------------------------" << endl;
	while (!p.empty()) {
		cout << p.Back() << ", ";
		p.pop_back();
	}
	cout << endl << "-----------------------------" << endl;
	c = {1, 2, 3, 4, 5};
	while (!c.empty()) {
		cout << c.Front() << ", ";
		c.pop_front();
	}
	cout << endl;
	return 0;
}