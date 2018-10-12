#include <iostream>
#include <queue>
#include <string>
using namespace std;

void Killing(queue<string> que, int jumps);
queue<string> que;
string temp = "";
string test = "";
int jum;

int main() {
	cout << "Ingrese los nombres de las personas " << endl;
	while (true) {
		cout << "> ";
		cin >> temp;
		if (temp == "0") {
			if (test.size() >= 2) {
				test = test.substr(0, test.size()-2);
			}
			break;
		}
		que.push(temp);
		test += temp+", ";
	}
	cout << "La fila es: " << endl << test << endl;
	cout << endl << "Ingrese la cantidad de saltos: ";
	cin >> jum;
	Killing(que, jum);
	return 0;
}
void Killing(queue<string> que, int jumps) {
	string hi;
	for (size_t z = 0; z < jumps-1; ++z) {
		hi = que.front();
		que.pop();
		que.push(hi);
	}
	while (que.size() > 1) {
		for (size_t i = 0; i < jumps; ++i) {
			hi = que.front();
			que.pop();
			que.push(hi);
		}
		cout << "Se ha matado a: " << que.front() << endl;
		que.pop();
	}
	cout << "Sobrevivio " << que.front() << endl;
}
