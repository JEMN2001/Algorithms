#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> generatePermutations(const string & str);
set<string> putCharInGrooves(set<string> & st, char lst);
set<string> test;
string in;

int main() {
	cout << "> ";
	cin >> in;
	test = generatePermutations(in);
	cout << "Sus permutaciones son:" << endl;
	for (set<string>::iterator it = test.begin(); it != test.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}

set<string> generatePermutations(const string & str) {
	set<string> fin;
	if(str.size() == 0) {
		fin.insert("");
		return fin;
	}
	else if (str.size() == 1) {
		fin.insert(str);
		return fin;
	}
	else  {
		char first = str.at(0);
		string temp = str.substr(1, str.size()-1);
		set<string> s_tmp = generatePermutations(temp);
		fin = putCharInGrooves(s_tmp, first);
		return fin;
	}
}
set<string> putCharInGrooves(set<string> & st, char lst) {
	set<string> out;
	string str, temp, ch(1,lst );
	for (set<string>::iterator iter = st.begin(); iter != st.end(); ++iter) {
		str = *iter;
		for (size_t i = 0; i <= str.size(); ++i) {
			temp = str;
			temp.insert(i, ch);
			out.insert(temp);
		}
	}
	return out;
}
