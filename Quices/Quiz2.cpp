#include <iostream>
#include <vector>
using namespace std;

void zerostoFront(vector<int> & vec);
void zerostoFront2(vector<int> & vec);
vector<int> vec = {0, 5, 3, 9, 0, 0, 4, 0};

int main() {
	zerostoFront2(vec);
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i < vec.size()-1) {
			cout << vec.at(i) << ", ";
		}
		else {
			cout << vec.at(i) << endl;
		}
	}
	return 0;
}
/*
*Methods that move all the zeros to the right, and don't affect the order of the other integers, with cuadratic complexity
*/
void zerostoFront(vector<int> & vec) {
	int index = vec.size()-1;
	for (size_t i = 0; i < vec.size()/2; ++i) {
		if (vec.at(i) == 0 && vec.at(index) != 0) {
			swap(vec.at(i), vec.at(index));
			--index;
		}
		else if (vec.at(i) == 0 && vec.at(index) == 0) {
			while (vec.at(index) == 0) {
				--index;
			}
			swap(vec.at(i), vec.at(index));
		}
	}
}
/*
*Methods that move all the zeros to the right, and don't affect the order of the other integers, with linear *complexity
*/
void zerostoFront2(vector<int> & vec) {
	int zeros = 0;
	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec.at(i) == 0) {
			vec.erase(vec.begin()+i);
			++zeros;
			--i;
			cout << "1" << endl;
		}
	}
	while (zeros > 0) {
		vec.push_back(0);
		--zeros;
	}
}
