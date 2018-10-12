#ifndef _Domino_hpp_
#define _Domino_hpp_
#include <iostream>
using namespace std;

class Domino {
	private:
		unsigned int left;
		unsigned int right;
	public:
		Domino(unsigned int left = 0, unsigned int right = 0);
		unsigned int getLeft();
		unsigned int getRight();
		void setLeft(unsigned int left);
		void setRight(unsigned int right);
		string toString() const;
		friend ostream & operator<<(ostream & os, const Domino & dom);
		friend istream & operator>>(istream & is, Domino & dom);
		friend bool operator==(Domino & dom1, Domino & dom2);
		friend bool operator<(const Domino & dom1, const Domino & dom2);
		friend bool operator<=(const Domino & dom1, const Domino & dom2);
		friend bool operator>(const Domino & dom1, const Domino & dom2);
		friend bool operator>=(const Domino & dom1, const Domino & dom2);
		void flipped();
};

#endif //_Domino_hpp_