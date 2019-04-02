#ifndef _Queue_cpp_
#define _Queue_cpp_
#include <iostream>
#include "Queue.hpp"

template<typename datatype>
void Queue<datatype>::expandCapacity() {
	datatype *old = array;
	capacity *= 2;
	array = new datatype[capacity];
	for (size_t i = 0; i < capacity/2; ++i) {
		*(array+i) = *(old+((i+head)%(capacity/2)));
	}
	head = 0;
	tail = capacity/2;
	delete[] old;
}

template<typename datatype>
void Queue<datatype>::deepCopy(const Queue<datatype> & que) {
	if (array != nullptr)
		delete[] array;
	array = new datatype[que.capacity] {};
	datatype *temp = que.array;
	for (size_t i = que.head; i < (que.head+que.tail)%que.capacity; ++i) {
		*(array+i) = *(temp+i);
	}
	head = que.head;
	tail = que.tail;
	capacity = que.capacity;
	notfull = que.notfull;
}

template<typename datatype>
Queue<datatype>::Queue() {
	array = new datatype[Initial_Capacity] {};
	capacity = Initial_Capacity;
	head = 0;
	tail = 0;
	notfull = true;
}

template<typename datatype>
Queue<datatype>::Queue(const Queue<datatype> & que) {
	array = nullptr;
	this->deepCopy(que);
}

template<typename datatype>
Queue<datatype>::~Queue() {
	delete[] array;
	array = nullptr;
	capacity = 0;
	head = 0;
	tail = 0;
	notfull = true;
}

template<typename datatype>
size_t Queue<datatype>::size() const {
	if (head != tail || empty()) {
		return (capacity-head+tail)%capacity;
	}
	else {
		return capacity;
	}
}

template<typename datatype>
bool Queue<datatype>::empty() const {
	return head == tail && notfull;
}

template<typename datatype>
void Queue<datatype>::clear() {
	delete[] array;
	array = new datatype[Initial_Capacity] {};
	capacity = Initial_Capacity;
	head = 0;
	tail = 0;
	notfull = true;
}

template<typename datatype>
void Queue<datatype>::push(datatype dt) {
	if (size() == capacity) {
		expandCapacity();
	}
	array[tail] = dt;
	tail =  (tail+1)%capacity;
	notfull = false;
}

template<typename datatype>
datatype Queue<datatype>::pop() {
	if (empty()) {
		throw invalid_argument("Function pop() invoked when queue was empty");
	}
	datatype out = *(array+head);
	head = (head+1)%capacity;
	notfull = true;
	return out;
}

template<typename datatype>
datatype Queue<datatype>::top() const {
	if (empty()) {
		throw invalid_argument("Function top() invoked when queue was empty");
	}
	return *(array+head);
}

template<typename datatype>
Queue<datatype> & Queue<datatype>::operator=(const Queue<datatype> & que) {
	this->deepCopy(que);
	return *this;
}

#endif // _Queue_cpp_
