#include <iostream>
#include <vector>
#include "basort.hpp"
using namespace std;

void InsertionSort(vector<int> & lst) {
	for(size_t i = 1; i < lst.size(); ++i) {
		int b = lst.at(i);
		int j = i-1;
		while ((j >= 0) and (lst.at(j) > b)) {
			lst.at(j+1) = lst.at(j);
			j -= 1;
		}
		lst.at(j+1) = b;
	}
}
void SelectionSort(vector<int> & lst) {
	for (size_t i = 0; i < lst.size(); ++i) {
		int minIndex = i;
		for (size_t j = i+1; j < lst.size(); ++j) {
			if (lst.at(j) < lst.at(minIndex)) {
				minIndex = j;
			}
		}
		int temp = lst.at(i);
		lst.at(i) = lst.at(minIndex);
		lst.at(minIndex) = temp;
	}
}
void StoogeSort(vector<int> & lst, int start, int end) {
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
bool IsSorted(vector<int> & lst) {
	int count = lst.size();
	while (--count >= 1) {
		if (lst.at(count) < lst.at(count-1)) {
			return false;
		}
	}
	return true;
}
void Shuffle(vector<int> & lst) {
	size_t count = lst.size();
	int temp, rnd;
	for (size_t i = 0; i < count; ++i) {
		rnd = rand() % count;
		temp = lst.at(i);
		lst.at(i) = lst.at(rnd);
		lst.at(rnd) = temp;
	}
}
void BogoSort(vector<int> & lst) {
	while(!IsSorted(lst)) {
		Shuffle(lst);
	}
}
void BubbleSort(vector<int> & lst) {
	size_t n = lst.size();
	for(size_t i = 0; i < n-1; ++i) {
		for (size_t j = 0; j < n-1; ++j) {
			if (lst.at(j) > lst.at(j+1)) {
				int temp = lst.at(j);
				lst.at(j) = lst.at(j+1);
				lst.at(j+1) = temp;
			}
		}
	}
}
