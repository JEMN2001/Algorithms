/*
* 3rd Quiz
* JUan Murcia
*/
#include <iostream>
#include <string>
using namespace std;

void print_num(int n);
void print_num_aux(string str);

int main() {
	int in;
	cout << "Enter a number:\n> ";
	cin >> in;
	print_num(in);
	return 0;
}

void print_num_aux(string str) {
	if (str.size() == 0) {
		cout << endl;
	}
	else {
		int x = (int) (str.at(0)-'0');
		cout << x;
		print_num_aux(str.substr(1, str.size()-1));
	}
}
void print_num(int n) {
	print_num_aux(to_string(n));
}
//Profe lo intente hacer con division entera, pero no supe como obtener el numero de cifras de un int, es por eso que tuve que usar el tipo de dato string, ya que esto imprime el numero invertido

/*void print_num(int n) {
	if (n >= 0 && n <= 9) {
		cout << n << endl;
	}
	else {
		cout << n%10;
		print_num(n/10);
	}
}*/
