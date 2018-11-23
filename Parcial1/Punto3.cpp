#include <iostream>
#include <queue>
using namespace std;

const char stop_ch = '\n';
const char inter_ch = '*';

void sleep(void);
queue<char> store(void);
void retrieve(queue<char> & kb);
int main(void) {
	queue<char> keybuff;
	keybuff = store();
	retrieve(keybuff);
	return 0;
}
void sleep(void) {
	for (int i = 0; i < 5e7; i++) {}
}
queue<char> store(void) {
	char ch = ' ';
	queue<char> out;
	while (ch != stop_ch) {
		ch = getchar();
		out.push(ch);
	}
	return out;
}
void retrieve(queue<char> & kb) {
	char ch;
	cout << "The message you entered is:\n\n";
	while (!(kb.empty())) {
		if (kb.front() != inter_ch) {
			cout << kb.front() << flush;
			sleep();
			kb.pop();
		}
		else {
			cout << endl << flush;
			sleep();
			kb.pop();
		}
	}
}
