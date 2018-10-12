#include <iostream>
#include <string>
using namespace std;

int main(){
	//Leyendo del teclado la linea entera
	string x;
	cout << "Ingrese algo: ";
	getline(cin, x);
	cout << "Ingresaste: " << x << endl;
	//Leyendo Palabra por palabra
	string z;
	string y;
	cout << "Ingrese algo con 2 palabras: " ;
	cin >> y >> z;
	cout << "Ingresaste " << y << " y " << z << endl;
	return 0;
}
