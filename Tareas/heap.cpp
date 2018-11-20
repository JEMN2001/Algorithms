#ifndef _heap_cpp_
#define _heap_cpp_

#include "heap.hpp"

template<typename dataType>
void BinaryHeap<dataType>::percolateDown(std::size_t hole) {
	std::size_t left = (2*hole)+1, right = 2*(hole+1), smallest = hole;
	if (right < array.size()) {
		smallest = (array.at(left) < array.at(right)) ? left : right;
	}
	else if (left < array.size()) {
		smallest = left;
	}
	if (smallest != hole) {
		dataType temp = array.at(smallest);
		array.at(smallest) = array.at(hole);
		array.at(hole) = temp;
		percolateDown(smallest);
	}
	else {
		dataType temp = array.at(hole);
		array.at(hole) = array.at(array.size()-1);
		array.at(array.size()-1) = temp;
	}
}

template<typename dataType>
BinaryHeap<dataType>::BinaryHeap(std::size_t capacity) {
	array.reserve(capacity);
}

template<typename dataType>
bool BinaryHeap<dataType>::isEmpty() const {
	return array.size() == 0;
}

template<typename dataType>
const dataType & BinaryHeap<dataType>::findMin() const {
	if (array.size() > 0) {
		return array.at(0);
	}
	else {
		throw std::underflow_error("Function findMin() invoked when heap was empty");
	}
}

template<typename dataType>
void BinaryHeap<dataType>::insert(dataType elem) {
	array.push_back(elem);
	std::size_t position = array.size()-1, parent = std::floor(position/2);
	while(parent >= 0 && array.at(parent) > array.at(position)) {
		dataType temp = array.at(parent);
		array.at(parent) = array.at(position);
		array.at(position) = temp;
		position = parent;
		parent = std::floor(position/2);
	}
}

template<typename dataType>
void BinaryHeap<dataType>::deleteMin() {
	if (array.size() > 0) {
		percolateDown(0);
		array.pop_back();
	}
	else {
		throw std::underflow_error("Function deleteMin() invoked when heap was empty");
	}
}

template<typename dataType>
void BinaryHeap<dataType>::clear() {
	array.clear();
}

template<typename dataType>
std::size_t BinaryHeap<dataType>::size() const {
	return array.size();
}

template<typename dataType>
void BinaryHeap<dataType>::display() const {
	std::cout << '[';
	for (auto iter = array.cbegin(); iter != array.cend(); ++iter) {
		if (iter+1 != array.cend()) {
			std::cout << *iter << ", ";
		}
		else {
			std::cout << *iter;
		}
	}
	std::cout << "]" << std::endl;
}

#endif //_heap_cpp_