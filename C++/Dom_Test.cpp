#include <iostream>
#include <string>
#include "Domino.hpp"
#include <set>
using namespace std;

int main() {
	set<Domino> st;
	Domino p;
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			p = Domino(j, i);
			if (st.count(p) == 0) {
				p.flipped();
				st.insert(p);
			}
		}
	}
	for (set<Domino>::iterator iter = st.begin(); iter != st.end(); ++iter) {
		cout << *iter << endl;
	}
	return 0;
}