#include <iostream>
#include <string>
using namespace std;

void roll_dice(unsigned dice);
void roll_dice_helper(unsigned dice, string str);

int main() {
	int in;
	cout << "Ingrese la cantidad de dados:" << endl << "> ";
	cin >> in;
	roll_dice(in);
	return 0;
}

void roll_dice(unsigned dice) {
	roll_dice_helper(dice, "{");
}
void roll_dice_helper(unsigned dice, string str) {
	if (dice == 1) {
		for (int i = 1; i < 7; ++i) {
			cout << str << i << "}" << endl;
		}
	}
	else if (dice > 1) {
		string temp;
		for (int i = 1; i < 7; ++i) {
			temp = str + to_string(i) + ", ";
			roll_dice_helper(dice-1, temp);
			temp = str;
		}
	}
}