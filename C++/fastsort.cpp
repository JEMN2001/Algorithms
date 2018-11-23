#ifndef _fastsort_cpp_
#define _fastsort_cpp_

#include "fastsort.hpp"

template<typename Type>
void heapsort(std::vector<Type> & vec) {
	for (std::size_t i = vec.size()/2 ; i > 0; i--) {
		percolateDown(vec, i-1, vec.size());
	}
	for (std::size_t i = vec.size(); i > 0; i--) {
		std::swap(vec.at(0), vec.at(i-1));
		percolateDown(vec, 0, i-1);
	}
}

template<typename Type>
void percolateDown(std::vector<Type> & vec, std::size_t i, std::size_t n) {
	std::size_t largest = i, left = 2*i + 1, right = 2*i + 2;
	if (left < n && vec.at(left) > vec.at(largest)) {
		largest = left;
	}
	if (right < n && vec.at(right) > vec.at(largest)) {
		largest = right;
	}
	if (largest != i) {
		std::swap(vec.at(i), vec.at(largest));
		percolateDown(vec, largest, n);
	}
}

template<typename Type>
void mergesort(std::vector<Type> & vec) {
	std::vector<Type> tmpArray(vec.size());
	mergesort(vec, tmpArray, 0, vec.size() - 1);
}

template<typename Type>
void mergesort(std::vector<Type> & vec, std::vector<Type> & tmp, std::size_t left, std::size_t right) {
	if (left < right) {
		std::size_t center = (left+right) /2;
		mergesort(vec, tmp, left, center);
		mergesort(vec, tmp, center+1, right);
		merge(vec, tmp, left, center+1, right);
	}
}

template<typename Type>
void merge(std::vector<Type> & vec, std::vector<Type> & tmp, std::size_t leftPos, std::size_t rightPos, std::size_t rightEnd) {
	std::size_t leftEnd = rightPos - 1, tmpPos = leftPos;
	std::size_t numElements = rightEnd - leftPos + 1;

	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (vec.at(leftPos) <= vec.at(rightPos)) {
			tmp.at(tmpPos++) = vec.at(leftPos++);
		}
		else {
			tmp.at(tmpPos++) = vec.at(rightPos++);
		}
	}
	while (leftPos <= leftEnd) {
		tmp.at(tmpPos++) = vec.at(leftPos++);
	}
	while (rightPos <= rightEnd) {
		tmp.at(tmpPos++) = vec.at(rightPos++);
	}
	for (std::size_t i = 0; i < numElements; ++i) {
		vec.at(rightEnd) = tmp.at(rightEnd);
		--rightEnd;
	}
}

template<typename Type>
const Type & median3(std::vector<Type> & vec, std::size_t left, std::size_t right) {
	std::size_t center = (left+right)/2;
	if (vec.at(center) < vec.at(left)) {
		std::swap(vec.at(left), vec.at(center));
	}
	if (vec.at(right) < vec.at(left)) {
		std::swap(vec.at(right), vec.at(left));
	}
	if (vec.at(right) < vec.at(center)) {
		std::swap(vec.at(center), vec.at(right));
	}
	std::swap(vec.at(center), vec.at(right));
	return vec.at(right);
}

template<typename Type>
std::size_t partition(std::vector<Type> & vec, std::size_t left, std::size_t right) {
	const Type & pivot = median3(vec, left, right);
	std::size_t i = (left-1);
	for (std::size_t j = left; j <= right-1; j++) {
		if (vec.at(j) <= pivot) {
			i++;
			std::swap(vec.at(i), vec.at(j));
		}
	}
	std::swap(vec.at(i+1), vec.at(right));
	return (i+1);
}

template<typename Type>
void quicksort(std::vector<Type> & vec, std::size_t left, std::size_t right) {
	if (left < right) {
		std::size_t pi = partition(vec, left, right);
		quicksort(vec, left, pi-1);
		quicksort(vec, pi+1, right);
	}
}

#endif //_fastsort_cpp_