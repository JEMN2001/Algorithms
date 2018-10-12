#include <iostream>
using namespace std;

int mcd(int num, int den);
class Rational {
	private:
		int num;
		int den;
	public:
		Rational(int num = 0, int den = 1) {
			this->num = num;
			if (den != 0) {
				this->den = den;
			}
			else {
				cerr << "You cant put 0 at denominator" << endl;
				exit(1);
			}
		}
		Rational(const Rational & rat) {
			num = rat.num;
			den = rat.den;
		}
		int getNum() {
			return num;
		}
		int getDen() {
			return den;
		}
		void setNum(int num) {
			this->num = num;
		}
		void setDen(int den) {
			if (den != 0) {
				this->den = den;
			}
			else  {
				cerr << "0 is not a valid denominator" << endl;
			}
		}
		void simplificar() {
			int max = mcd(num, den);
			while (max != 1) {
				num /= max;
				den /= max;
				max = mcd(num, den);
			}
		}
		friend ostream & operator<<(ostream & os, Rational & rat) {
			return os << rat.num << "/" << rat.den;
		}
		friend istream & operator>>(istream & is, Rational & rat) {
			char ch = '/';
			is >> rat.num >> ch >> rat.den;
			return is;
		}
		friend Rational & operator++(Rational & rat) {
			rat.num += rat.den;
			rat.simplificar();
			return rat;
		}
		friend Rational operator++(Rational & rat, int) {
			Rational temp = rat;
			rat.num += rat.den;
			rat.simplificar();
			return temp;
		}
		friend Rational & operator--(Rational & rat) {
			rat.num -= rat.den;
			rat.simplificar();
			return rat;
		}
		friend Rational operator--(Rational & rat, int) {
			Rational temp = rat;
			rat.num -= rat.den;
			rat.simplificar();
			return temp;
		}
		friend bool operator>(Rational & rat1, Rational & rat2) {
			return  ((double)rat1.num/rat1.den) > ((double)rat2.num/rat2.den);
		}
		friend bool operator<(Rational & rat1, Rational & rat2) {
			return  ((double)rat1.num/rat1.den) < ((double)rat2.num/rat2.den);
		}
		friend bool operator>=(Rational & rat1, Rational & rat2) {
			return  ((double)rat1.num/rat1.den) >= ((double)rat2.num/rat2.den);
		}
		friend bool operator<=(Rational & rat1, Rational & rat2) {
			return  ((double)rat1.num/rat1.den) <= ((double)rat2.num/rat2.den);
		}
		friend bool operator!=(Rational & rat1, Rational & rat2) {
			return ((double)rat1.num/rat1.den) != ((double)rat2.num/rat2.den);
		}
		friend Rational operator+=(Rational & rat1, Rational & rat2) {
			Rational out = Rational((rat1.num*rat2.den)+(rat1.den*rat2.num), rat1.den*rat2.den);
			out.simplificar();
			return out;
		}
		friend Rational operator+=(Rational & rat, int y) {
			Rational out = Rational(rat.num+(y*rat.den), rat.den);
			out.simplificar();
			return out;
		}
		friend Rational operator-=(Rational & rat1, Rational & rat2) {
			Rational out = Rational((rat1.num*rat2.den)-(rat1.den*rat2.num), rat1.den*rat2.den);
			out.simplificar();
			return out;
		}
		friend Rational operator-=(Rational & rat, int y) {
			Rational out = Rational(rat.num-(y*rat.den), rat.den);
			out.simplificar();
			return out;
		}
		friend Rational operator*=(Rational & rat1, Rational & rat2) {
			return Rational(rat1.num*rat2.num, rat1.den*rat2.den);
		}
		friend Rational operator*=(Rational & rat, int y) {
			Rational out = Rational(rat.num*y, rat.den);
			out.simplificar();
			return out;
		}
		friend Rational operator/=(Rational & rat1, Rational & rat2) {
			Rational out = Rational(rat1.num*rat2.den, rat1.den*rat2.num);
			out.simplificar();
			return out;
		}
		friend Rational operator/=(Rational & rat, int y) {
			Rational out = Rational(rat.num, rat.den*y);
			out.simplificar();
			return out;
		}
		friend Rational operator+(Rational & rat1, Rational & rat2) {
			Rational out = Rational((rat1.num*rat2.den)+(rat1.den*rat2.num), (rat1.den*rat2.den));
			out.simplificar();
			return out;
		}
		friend Rational operator-(Rational & rat1, Rational & rat2) {
			Rational out = Rational((rat1.num*rat2.den)-(rat1.den*rat2.num), (rat1.den*rat1.den));
			out.simplificar();
			return out;
		}
		friend Rational operator*(Rational & rat1, Rational & rat2) {
			Rational out = Rational(rat1.num*rat2.num, rat1.den*rat2.den);
			out.simplificar();
			return out;
		}
		friend Rational operator/(Rational & rat1, Rational & rat2) {
			Rational out = Rational(rat1.num*rat2.den, rat1.den*rat2.num);
			out.simplificar();
			return out;
		}
};
int main() {
	Rational a, b, c;
	cin >> a;
	cin >> b;
	c = a+b;
	cout << c << endl;
	return 0;
}

int mcd(int num, int den) {
	long mcd, tmp, rest;
	mcd = abs(num);
	tmp = den;
	while (tmp > 0) {
		rest = mcd % tmp;
		mcd = tmp;
		tmp = rest;
	}
	return mcd;
}
