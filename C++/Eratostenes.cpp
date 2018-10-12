#include <iostream>
#include <map>
#include <string>
#include <cmath>
using namespace std;

map<int, string> primes;
map<int, string> Erathostenes(int & maximum);
int num;

int main() {
	cout << "Enter a number:\n> ";
	cin >> num;
	primes = Erathostenes(num);
	cout << "All primes to " << num << ":" << endl;
	for (size_t i = 1; i <= num; ++i) {
		if (primes.at(i) == "prime") {
			cout << i << endl;
		}
	}
	cout << "All no primes to " << num << ":" << endl;
	for (size_t j = 1; j <= num; ++j) {
		if (primes.at(j) == "noprime") {
			cout << j << endl;
		}
	}
	return 0;
}

map<int, string> Erathostenes(int & maximum) {
	map<int, string> out = {{1, "noprime"}};
	for (size_t i = 2; i <= maximum; ++i) {
		out.emplace(i, "prime");
		for (size_t j = 2; j <= ((int) sqrt(i)); ++j) {
			if (out.at(j) == "prime") {
				if (i%j == 0) {
					out.at(i) = "noprime";
					break;
				}
			}
		}
	}
	return out;
}
