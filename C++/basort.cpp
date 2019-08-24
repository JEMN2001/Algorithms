#include <iostream>
#include <vector>
#include "basort.hpp"

void InsertionSort(std::vector<int> & lst) {
	for(std::size_t i = 1; i < lst.size(); ++i) {
		int b = lst.at(i);
		int j = i-1;
		while ((j >= 0) and (lst.at(j) > b)) {
			lst.at(j+1) = lst.at(j);
			j -= 1;
		}
		lst.at(j+1) = b;
	}
}

void SelectionSort(std::vector<int> & lst) {
	for (std::size_t i = 0; i < lst.size(); ++i) {
		int minIndex = i;
		for (std::size_t j = i+1; j < lst.size(); ++j) {
			if (lst.at(j) < lst.at(minIndex)) {
				minIndex = j;
			}
		}
		int temp = lst.at(i);
		lst.at(i) = lst.at(minIndex);
		lst.at(minIndex) = temp;
	}
}

void DoubleSelectionSort(std::vector<int> & lst) {
	size_t n = lst.size(), i, i2 = n, j, temp;
	for (i = 0; i < i2-1; ++i) {
		i2 = n-1-i;
		size_t minIndex = i, maxIndex = i2;
		if (lst.at(i) > lst.at(i2)) {
			minIndex = i2;
			maxIndex = i;
		}
		for (j = i+1; j < i2; ++j) {
			if (lst.at(j) < lst.at(minIndex)) {
				minIndex = j;
			}
			if (lst.at(j) > lst.at(maxIndex)) {
				maxIndex = j;
			}
		}
		if (i+1 != i2) {
			temp = lst.at(i);
			lst.at(i) = lst.at(minIndex);
			lst.at(minIndex) = temp;
			if (i == maxIndex) {
				maxIndex = minIndex;
			}
			temp = lst.at(i2);
			lst.at(i2) = lst.at(maxIndex);
			lst.at(maxIndex) = temp;
		}
		else {
			if (minIndex == i2) {
				temp = lst.at(i);
				lst.at(i) = lst.at(i2);
				lst.at(i2) = temp;
			}
		}
	}
}

void StoogeSort(std::vector<int> & lst, int start, int end) {
	if (lst.at(start) > lst.at(end)) {
		int temp = lst.at(start);
		lst.at(start) = lst.at(end);
		lst.at(end) = temp;
	}
	if (end-start+1 > 2) {
		int t = (end-start+1)/3;
		StoogeSort(lst, start, end-t);
		StoogeSort(lst, start+t, end);
		StoogeSort(lst, start, end-t);
	}
}

bool IsSorted(std::vector<int> & lst) {
	int count = lst.size();
	while (--count >= 1) {
		if (lst.at(count) < lst.at(count-1)) {
			return false;
		}
	}
	return true;
}

void Shuffle(std::vector<int> & lst) {
	std::size_t count = lst.size();
	int temp, rnd;
	for (std::size_t i = 0; i < count; ++i) {
		rnd = rand() % count;
		temp = lst.at(i);
		lst.at(i) = lst.at(rnd);
		lst.at(rnd) = temp;
	}
}

void BogoSort(std::vector<int> & lst) {
	while(!IsSorted(lst)) {
		Shuffle(lst);
	}
}

void BubbleSort(std::vector<int> & lst) {
	std::size_t n = lst.size();
	for(std::size_t i = n-1; i > 0; --i) {
		for (std::size_t j = 0; j < i; ++j) {
			if (lst.at(j) > lst.at(j+1)) {
				int temp = lst.at(j);
				lst.at(j) = lst.at(j+1);
				lst.at(j+1) = temp;
			}
		}
	}
}

void CocktailSort(std::vector<int> & lst) {
	std::size_t n = lst.size(), i2 = 0, i, j;
	for (i = n-1; i > i2; --i) {
		i2 = n-1-i;
		for (j = i2; j < i; ++j) {
			if (lst.at(j) > lst.at(j+1)) {
				int temp = lst.at(j);
				lst.at(j) = lst.at(j+1);
				lst.at(j+1) = temp;
			}
		}
		for (j = i-1; j > i2; --j) {
			if (lst.at(j) < lst.at(j-1)) {
				int temp = lst.at(j);
				lst.at(j) = lst.at(j-1);
				lst.at(j-1) = temp;
			}
		}
	}
}