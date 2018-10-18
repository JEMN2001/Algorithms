#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> doSet_Strings(size_t length, set<char> st);
set<string> doSet_Strings_helper(size_t length, set<char> st, string str);

int main() {
	set<char> st = {'1', '0'};
	size_t length = 3;
	set<string> con = doSet_Strings(length, st);
	for(auto it = con.begin(); it != con.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

set<string> doSet_Strings(size_t length, set<char> st) {
	return doSet_Strings_helper(length, st, "");
}

set<string>  doSet_Strings_helper(size_t length, set<char> st, string str) {
	set<string> out;
	if (length == 1) {
		for (auto iter = st.begin(); iter != st.end(); ++iter) {
			string temp = str;
			temp.push_back(*iter);
			out.insert(temp);
		}
	}
	else if (length > 1) {
		for(auto iter = st.begin(); iter != st.end(); ++iter) {
			string temp = str;
			temp.push_back(*iter);
			set<string> tempst = doSet_Strings_helper(length-1, st, temp);
			for (auto i = tempst.begin(); i != tempst.end(); ++i) {
				out.insert(*i);
			}
		}
	}
	return out;
}