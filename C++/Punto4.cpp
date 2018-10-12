#include <iostream>
#include "SOperator.hpp"
using namespace std;

string test = "Hola Mundo 1234";
string test2 = "United Nations Educational, Scientific and Cultural Organization";

int main() {
	cout << "El texto es: " << test << endl;
	cout << "Tiene " << VowelsOf(test) << " vocales" << endl;
	cout << "Tiene " << NumbersOf(test) << " cifras" << endl;
	cout << "EN minusculas " << Copy_in_lowers(test) << endl;
	cout << "Para revisar que no se modifico " << test << endl;
	To_lowers(test);
	cout << "En minusculas pero modificando el string " << test << endl;
	no_Spaces(test);
	cout << "Sin espacios " << test << endl;
	cout << "La prueba 2 es: " << test2 << endl;
	cout << "El acronimo es: " << Acronym(test2) << endl;
	return 0;
}
