#include <iostream>
#include <string>
#include "SOperator.hpp"
using namespace std;

int VowelsOf(string str) {
	int out = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
			out++;
		}
	}
	return out;
}
int NumbersOf(string str) {
	int out = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9') {
			out++;
		}
	}
	return out;
}
string Copy_in_lowers(string str) {
	string out = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			out += str[i]+'a'-'A';
		}
		else {
			out += str[i];
		}
	}
	return out;
}
void To_lowers(string & str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 'a'-'A';
		}
	}
}
void no_Spaces(string & str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			str.erase(i, 1);
		}
	}
}
string Acronym(string str){
	string out = "";
	if (str.at(0) >= 'A' && str.at(0) <= 'Z'){
		out += str.at(0);
	}
	for (int i = 0; i < str.length(); i++) {
		if (i+1 < str.length()){
			if (str.at(i) == ' ' && str.at(i+1) >= 'A' && str.at(i+1) <= 'Z') {
				out += str.at(i+1);
			}
		}
	}
	return out;
}
