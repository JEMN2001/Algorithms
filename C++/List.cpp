#ifndef _List_cpp_
#define _List_cpp_
#include "List.hpp"

template<typename datatype>
void List<datatype>::deepCopy(const List<datatype> & ls) {
	Cell *temp = ls.front;
	if (temp != nullptr) {
		front = new Cell;
		back = front;
		front->data = temp->data;
		front->left = nullptr;
		front->right = nullptr;
		temp = temp->right;
	}
	while (temp != nullptr) {
		back->right = new Cell;
		back->right->left = back;
		back = back->right;
		back->data = temp->data;
		back->right = nullptr;
		temp = temp->right;
	}
	count = ls.count;
}

template<typename datatype>
List<datatype>::List() {
	back = front = nullptr;
	count = 0;
}

template <typename datatype>
List<datatype>::List(const List<datatype> & ls) {
	front = back = nullptr;
	this->deepCopy(ls);
}

template<typename datatype>
List<datatype>::~List() {
	this->clear();
}

template<typename datatype>
List<datatype> & List<datatype>::operator=(const List<datatype> & ls) {
	this->clear();
	this->deepCopy(ls);
	return *this;
}

template<typename datatype>
size_t List<datatype>::size() const{
	return count;
}

template<typename datatype>
bool List<datatype>::empty() const{
	return count == 0;
}

template<typename datatype>
void List<datatype>::clear() {
	while (front != nullptr) {
		Cell *old = front;
		front = front->right;
		delete old;
		if (front != nullptr) {
			front->left = nullptr;
		}
		else {
			back = nullptr;
		}
	}
	count = 0;
}

template<typename datatype>
datatype & List<datatype>::Front() {
	if (!this->empty()) {
		return front->data;
	}
	else {
		throw invalid_argument("Function Front() invoked when List was empty");
	}
}

template<typename datatype>
datatype & List<datatype>::Back() {
	if (!this->empty()) {
		return back->data;
	}
	else {
		throw invalid_argument("Frunction Back() invoked when List was empty");
	}
}

template<typename datatype>
void List<datatype>::push_front(datatype dt) {
	if (!this->empty()) {
		Cell *old = front;
		front = new Cell;
		front->data = dt;
		front->left = nullptr;
		old->left = front;
		front->right = old;
	}
	else {
		front = back = new Cell;
		front->data = dt;
		front->left = nullptr;
		front->right = nullptr;
	}
	count++;
}

template<typename datatype>
void List<datatype>::push_back(datatype dt) {
	if (!this->empty()) {
		Cell *old = back;
		back = new Cell;
		back->data = dt;
		back->right = nullptr;
		old->right = back;
		back->left = old;
	}
	else {
		front = back = new Cell;
		back->data = dt;
		back->left = nullptr;
		back->right = nullptr;
	}
	count++;
}

template<typename datatype>
void List<datatype>::pop_front() {
	if (!this->empty()){
		Cell *old = front;
		front = front->right;
		delete old;
		if (front != nullptr) {
			front->left = nullptr;
		}
		else {
			back = nullptr;
		}
		count--;
	}
	else {
		throw invalid_argument("Function pop_front() invoked when List was empty");
	}
}

template<typename datatype>
void List<datatype>::pop_back() {
	if (!this->empty()) {
		Cell *old = back;
		back = back->left;
		delete old;
		if (back != nullptr) {
			back->right = nullptr;
		}
		else {
			front = nullptr;
		}
		count--;
	}
	else {
		throw invalid_argument("Function pop_back() invoked when List was empty");
	}
}

#endif //_List_cpp_