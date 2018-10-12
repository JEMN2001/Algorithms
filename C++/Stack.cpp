#ifndef _Stack_cpp_
#define _Stack_cpp_
#include <iostream>
#include "Stack.hpp"

template <typename datatype>
Stack<datatype>::Stack() {
	stack = nullptr;
	count = 0;
}

/*template<typename datatype>
Stack<datatype>::Stack(const Stack<datatype> & stk) {
	this->deepCopy(stk);
}*/

template <typename datatype>
Stack<datatype>::~Stack() {
	clear();
}

template <typename datatype>
size_t Stack<datatype>::size() {
	return count;
}

template <typename datatype>
bool Stack<datatype>::empty() {
	return count == 0;
}

template <typename datatype>
void Stack<datatype>::clear() {
	while (stack != nullptr) {
		Cell *old = stack;
		stack = stack->link;
		delete old;
		old = nullptr;
	}
	count = 0;
}

template <typename datatype>
void Stack<datatype>::push(datatype dt) {
	if (stack == nullptr) {
		stack = new Cell;
		stack->data = dt;
		stack->link = nullptr;
	}
	else {
		Cell *temp = stack;
		stack = new Cell;
		stack->data = dt;
		stack->link = temp;
	}
	++count;
}

template <typename datatype>
datatype Stack<datatype>::pop() {
	if (stack == nullptr) {
		throw invalid_argument("Function pop() was invoked when stack was empty");
	}
	else {
		Cell *old = stack;
		datatype out = stack->data;
		stack = stack->link;
		delete old;
		old = nullptr;
		count--;
		return out;
	}
}

template <typename datatype>
datatype Stack<datatype>::peek() {
	if (stack == nullptr) {
		throw invalid_argument("Function peek() was invoked when stack was empty");
	}
	else {
		return stack->data;
	}
}

template<typename datatype>
void Stack<datatype>::deepCopy(const Stack<datatype> & stk) {
	clear();
	Cell *temp = stk.stack, *begin = stack;
	if (temp != nullptr) {
		stack = new Cell;
		stack->data = temp->data;
		stack->link = nullptr;
		temp = temp->link;
		begin = stack;
		count++;
	}
	while (temp != nullptr) {
		stack->link = new Cell;
		stack = stack->link;
		stack->data = temp->data;
		temp = temp->link;
		count++;
	}
	stack->link = nullptr;
	stack = begin;
}

template <typename datatype>
Stack<datatype> Stack<datatype>::operator=(const Stack<datatype> & stk) {
	this->deepCopy(stk);
	return *this;
}

#endif //_Stack_cpp_
