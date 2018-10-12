#include <iostream>
#include <string>
#include <queue>
using namespace std;

string in;
queue<char> que;
void sleep();
void store(queue<char> & fila, string & str);
void retrive(queue<char> & fila);

int main() {
	getline(cin, in);
	store(que, in);
	retrive(que);
}
void sleep() {
  for (int i = 0; i < 5E7; i++) {}
}
void store(queue<char> & fila, string & str) {
	for (size_t i = 0; i < in.size(); ++i) {
		que.push(in.at(i));
	}
}
void retrive(queue<char> & fila) {
	while (!(fila.empty())) {
		if (fila.front() != '*') {
			cout << fila.front() << flush;
			sleep();
			fila.pop();
		}
		else  {
			cout << endl << flush;
			sleep();
			fila.pop();
		}
	}
}
