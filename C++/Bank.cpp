#include <iostream>
#include <set>
#include <string>
using namespace std;

bool Rebota(set<string> & st, string & name);
set<string> con = {"Juan", "Nicolas", "Edwin", "Samuel", "Ladino", "Julian", "Rodrigo", "Carlos", "Edgar", "Margot", "Valerie"};
string stri;

int main() {
	cout << "Ingrese su nombre:\n> ";
	cin >> stri;
	if (Rebota(con, stri)) {
		cout << stri << ", su cheque fue ingresado con exito" << endl;
	}
	else {
		cout << "Lo sentimos " << stri << ", su cuenta esta bloqueada" << endl;
	}
	return 0;
}

bool Rebota(set<string> & st, string & name) {
	return st.count(name) == 0;
}
