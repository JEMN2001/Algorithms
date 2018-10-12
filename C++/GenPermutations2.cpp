#include<iostream>
#include<string>
using namespace std;

void permute(string str);
void permute_helper(string str, string choice);

int main() {
	string in;
	cout << "Ingrese la palabra:" << endl << "> ";
	cin >> in;
	cout << "Sus permutaciones son: " << endl;
	permute(in);
}


void permute(string str) {
	permute_helper(str, "");
}

void permute_helper(string str, string choice) {
	if(str.empty()) {
		cout << choice << endl;
	}
	else {
		for(size_t i = 0; i < str.length(); i++) {
			char ch = str.at(i);
			choice.push_back(ch);
			str.erase(i, 1);
			permute_helper(str, choice);
			str.insert(i, 1, ch);
			choice.pop_back();
		}	
	}
}
