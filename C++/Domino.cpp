#include <iostream>
#include <string>
#include "Domino.hpp"
using namespace std;

Domino::Domino(unsigned int left, unsigned int right) {
	if ((left >= 0 && left <= 6) && (right >= 0 && right <= 6)) {
		this->left = left;
		this->right = right;
	}
	else {
		this->left = 0;
		this->right = 0;
	}
}
unsigned int Domino::getLeft() {
	return left;
}
unsigned int Domino::getRight() {
	return right;
}
void Domino::setLeft(unsigned int left) {
	if (left >= 0 && left <= 6) {
		this->left = left;
	}
}
void Domino::setRight(unsigned int right) {
	if (right >= 0 && right <= 6) {
		this->right = right;
	}
}
string Domino::toString() const{
	string out = "+-------+-------+\n";
	if (left == 0 && right == 0) {
		out += "|       |       |\n|       |       |\n|       |       |\n";
	}
	else if (left == 0 && right == 1) {
		out += "|       |       |\n|       |   #   |\n|       |       |\n";
	}
	else if (left == 0 && right == 2) {
		out += "|       |       |\n|       | #   # |\n|       |       |\n";
	}
	else if (left == 0 && right == 3) {
		out += "|       |       |\n|       | # # # |\n|       |       |\n";
	}
	else if (left == 0 && right == 4) {
		out += "|       | #   # |\n|       |       |\n|       | #   # |\n";
	}
	else if (left == 0 && right == 5) {
		out += "|       | #   # |\n|       |   #   |\n|       | #   # |\n";
	}
	else if (left == 0 && right == 6) {
		out += "|       | # # # |\n|       |       |\n|       | # # # |\n";
	}
	else if (left == 1 && right == 0) {
		out += "|       |       |\n|   #   |       |\n|       |       |\n";
	}
	else if (left == 1 && right == 1) {
		out += "|       |       |\n|   #   |   #   |\n|       |       |\n";
	}
	else if (left == 1 && right == 2) {
		out += "|       |       |\n|   #   | #   # |\n|       |       |\n";
	}
	else if (left == 1 && right == 3) {
		out += "|       |       |\n|   #   | # # # |\n|       |       |\n";
	}
	else if (left == 1 && right == 4) {
		out += "|       | #   # |\n|   #   |       |\n|       | #   # |\n";
	}
	else if (left == 1 && right == 5) {
		out += "|       | #   # |\n|   #   |   #   |\n|       | #   # |\n";
	}
	else if (left == 1 && right == 6) {
		out += "|       | # # # |\n|   #   |       |\n|       | # # # |\n";
	}
	else if (left == 2 && right == 0) {
		out += "|       |       |\n| #   # |       |\n|       |       |\n";
	}
	else if (left == 2 && right == 1) {
		out += "|       |       |\n| #   # |   #   |\n|       |       |\n";
	}
	else if (left == 2 && right == 2) {
		out += "|       |       |\n| #   # | #   # |\n|       |       |\n";
	}
	else if (left == 2 && right == 3) {
		out += "|       |       |\n| #   # | # # # |\n|       |       |\n";
	}
	else if (left == 2 && right == 4) {
		out += "|       | #   # |\n| #   # |       |\n|       | #   # |\n";
	}
	else if (left == 2 && right == 5) {
		out += "|       | #   # |\n| #   # |   #   |\n|       | #   # |\n";
	}
	else if (left == 2 && right == 6) {
		out += "|       | # # # |\n| #   # |       |\n|       | # # # |\n";
	}
	else if (left == 3 && right == 0) {
		out += "|       |       |\n| # # # |       |\n|       |       |\n";
	}
	else if (left == 3 && right == 1) {
		out += "|       |       |\n| # # # |   #   |\n|       |       |\n";
	}
	else if (left == 3 && right == 2) {
		out += "|       |       |\n| # # # | #   # |\n|       |       |\n";
	}
	else if (left == 3 && right == 3) {
		out += "|       |       |\n| # # # | # # # |\n|       |       |\n";
	}
	else if (left == 3 && right == 4) {
		out += "|       | #   # |\n| # # # |       |\n|       | #   # |\n";
	}
	else if (left == 3 && right == 5) {
		out += "|       | #   # |\n| # # # |   #   |\n|       | #   # |\n";
	}
	else if (left == 3 && right == 6) {
		out += "|       | # # # |\n| # # # |       |\n|       | # # # |\n";
	}
	else if (left == 4 && right == 0) {
		out += "| #   # |       |\n|       |       |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 1) {
		out += "| #   # |       |\n|       |   #   |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 2) {
		out += "| #   # |       |\n|       | #   # |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 3) {
		out += "| #   # |       |\n|       | # # # |\n| #   # |       |\n";
	}
	else if (left == 4 && right == 4) {
		out += "| #   # | #   # |\n|       |       |\n| #   # | #   # |\n";
	}
	else if (left == 4 && right == 5) {
		out += "| #   # | #   # |\n|       |   #   |\n| #   # | #   # |\n";
	}
	else if (left == 4 && right == 6) {
		out += "| #   # | # # # |\n|       |       |\n| #   # | # # # |\n";
	}
	else if (left == 5 && right == 0) {
		out += "| #   # |       |\n|   #   |       |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 1) {
		out += "| #   # |       |\n|   #   |   #   |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 2) {
		out += "| #   # |       |\n|   #   | #   # |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 3) {
		out += "| #   # |       |\n|   #   | # # # |\n| #   # |       |\n";
	}
	else if (left == 5 && right == 4) {
		out += "| #   # | #   # |\n|   #   |       |\n| #   # | #   # |\n";
	}
	else if (left == 5 && right == 5) {
		out += "| #   # | #   # |\n|   #   |   #   |\n| #   # | #   # |\n";
	}
	else if (left == 5 && right == 6) {
		out += "| #   # | # # # |\n|   #   |       |\n| #   # | # # # |\n";
	}
	else if (left == 6 && right == 0) {
		out += "| # # # |       |\n|       |       |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 1) {
		out += "| # # # |       |\n|       |   #   |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 2) {
		out += "| # # # |       |\n|       | #   # |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 3) {
		out += "| # # # |       |\n|       | # # # |\n| # # # |       |\n";
	}
	else if (left == 6 && right == 4) {
		out += "| # # # | #   # |\n|       |       |\n| # # # | #   # |\n";
	}
	else if (left == 6 && right == 5) {
		out += "| # # # | #   # |\n|       |   #   |\n| # # # | #   # |\n";
	}
	else if (left == 6 && right == 6) {
		out += "| # # # | # # # |\n|       |       |\n| # # # | # # # |\n";
	}
	out += "+-------+-------+";
	return out;
}
ostream & operator<<(ostream & os, const Domino & dom) {
	return os << dom.toString();
}
istream & operator>>(istream & is, Domino & dom) {
	char ch1 = '[';
	char ch2 = ']';
	char ch3 = '|';
	is >> ch1 >> dom.left >> ch3 >> dom.right >> ch2;
	return is;
}
bool operator==(Domino & dom1, Domino & dom2) {
	return dom1.left == dom2.left && dom1.right == dom2.right;
}
bool operator<(const Domino & dom1, const Domino & dom2) {
	if (dom1.left < dom2.left) {
		return true;
	}
	else if (dom1.left == dom2.left && dom1.right < dom2.right) {
		return true;
	}
	else {
		return false;
	}
}
bool operator<=(const Domino & dom1, const Domino & dom2) {
	if (dom1.left <= dom2.left) {
		return true;
	}
	else if (dom1.left == dom2.left && dom1.right <= dom2.right) {
		return true;
	}
	else {
		return false;
	}
}
bool operator>(const Domino & dom1, const Domino & dom2) {
	if (dom1.left > dom2.left) {
		return true;
	}
	else if (dom1.left == dom2.left && dom1.right > dom2.right) {
		return true;
	}
	else {
		return false;
	}
}
bool operator>=(const Domino & dom1, const Domino & dom2) {
	if (dom1.left >= dom2.left) {
		return true;
	}
	else if (dom1.left == dom2.left && dom1.right >= dom2.right) {
		return true;
	}
	else {
		return false;
	}
}
void Domino::flipped() {
	int temp = left;
	left = right;
	right = temp;
}