#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;

pair<map<char, string>, map<string, char>> doMaps(string filename);
string toMorse(char ch);
char toWords(string str);
queue<char> keybuff;
pair<map<char, string>, map<string, char>> pr;

int main() {
	pr = doMaps("Morse");
	while (true) {
		cout << "> ";
		char c = getchar();
		if (c == '\n') {
			break;
		}
		while (c != '\n') {
			keybuff.push(c);
			c = getchar();
		}
		if (keybuff.front() != '.' && keybuff.front() != '-') {
			while (!keybuff.empty()) {
				char temp = keybuff.front();
				cout << toMorse(temp) << " ";
				keybuff.pop();
			}
			cout << endl;
		}
		else {
			string test = "";
			while (!keybuff.empty()) {
				if (keybuff.front() != ' ') {
					test.push_back(keybuff.front());
				}
				else {
					cout << toWords(test);
					test = "";
				}
				keybuff.pop();
			}
			cout << toWords(test) << endl;
		}
	}
}

pair<map<char, string>, map<string, char>> doMaps(string filename) {
	map<char, string> out1;
	map<string, char> out2;
	fstream archivo(filename+".txt");
	string linea;
	int count = 0;
	int count2 = 0;
	if (!archivo.is_open()) {
		archivo.open(filename+".txt", ios::in);
	}
	while (getline(archivo, linea)) {
		if (count < 26) {
			out1.emplace((char) 'A'+count, linea);
			out1.emplace((char) 'a'+count, linea);
			out2.emplace(linea, (char) 'A'+count);
			count++;
		}
		else {
			out1.emplace((char) '0'+count2, linea);
			out2.emplace(linea, '0'+count2);
			count2++;
		}
	}
	archivo.close();
	pair<map<char, string>, map<string, char>> out;
	out.first = out1;
	out.second = out2;
	return out;
}

string toMorse(char ch) {
	string out;
	if (pr.first.count(ch)) {
		out = pr.first.at(ch);
		return out;
	}
	else {
		out.push_back(ch);
		return out;
	}
}

char toWords(string str) {
	char out;
	if (pr.second.count(str)) {
		out = pr.second.at(str);
	}
	else {
		cout << endl << (str+" no es valido") << endl;
		out = ' ';
	}
	return out;
}