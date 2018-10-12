#include <iostream> 
using namespace std;

bool Is_in_position(int a[], int Size) {
	for (int i = 0; i < Size; ++i) {
		if (a[i] == i) {
			return true;
		}
	}
	return false;
}
int main() {
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	if (Is_in_position(a, 10)) {
		cout << "Si hay un elemento n en la posicion n" << endl;
	}
	else {
		cout << "No hay un elemento n en la posicion n" << endl;
	}
}
