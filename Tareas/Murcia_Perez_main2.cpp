#include <iostream>
#include "Murcia_Perez_hash_pair.hpp"

using namespace std;

int main() {
	hashPair<char, int> mapa;
	pair<char, int> pair;
	pair.first = 'c';
	pair.second = 5;
	if (mapa.insert(pair)) {
		cout << "the pair ('c', 5) was inserted" << endl;
	}
	mapa.insert('q', 10);
	mapa.display();
	if (mapa.find('c')) {
		cout << "c is in the map" << endl;
	}
	if (!mapa.find('j')) {
		cout << "j isnt in the map" << endl;
	}
	cout << "My actual size: " << mapa.size() << endl;
	if (mapa.remove('c')) {
		cout << "c was deleted" << endl;
	}
	cout << "My actual size: " << mapa.size() << endl;
	cout << "The element at the 'q' key: " << mapa['q'] << endl;
	mapa.display();
	mapa.clear();
	cout << "My actual size: " << mapa.size() << endl;
	mapa.display();
	if (!mapa.remove('q')) {
		cout << "q couldnt be removed because it wasnt in the map" << endl;
	}
	return 0;
}