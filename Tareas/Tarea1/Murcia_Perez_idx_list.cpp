#ifndef _indexable_list_cpp
#define _indexable_list_cpp
#include "Murcia_Perez_idx_list.hpp"

template<typename dataType>
indexable_list<dataType>::indexable_list() {
	head = nullptr;
	count = 0;
}

template<typename dataType>
indexable_list<dataType>::~indexable_list() {
	clear();
	delete head;
}

template<typename dataType>
ostream & operator<<(ostream & out, indexable_list<dataType> & lst) {
	out << '[';
	typename indexable_list<dataType>::Cell *temp = lst.head;
	for (size_t i = 0; i < lst.count; ++i) {
		out << temp->data;
		if (i < lst.count-1)
			out << ", ";
		temp = temp->link;
	}
	out << ']' << "\tsize=" << lst.size();
	return out;
}

template<typename dataType>
const dataType & indexable_list<dataType>::operator[](size_t idx) const {
	cout << "This was used" << endl;
	Cell *temp = head;
	for (size_t i = 0; i <= idx; ++i) {
		temp = temp->link;
	}
	const dataType & out = temp->data;
	return out;
}

template<typename dataType>
dataType & indexable_list<dataType>::operator[](size_t idx) {
	Cell *temp = head;
	for (size_t i = 0; i < idx; ++i) {
		temp = temp->link;
	}
	return temp->data;
}

template<typename dataType>
size_t indexable_list<dataType>::size() const {
	return count;
}

template<typename dataType>
bool indexable_list<dataType>::empty() const {
	return count == 0;
}

template<typename dataType>
void indexable_list<dataType>::clear() {
	while (head != nullptr) {
		Cell *old = head;
		head = head->link;
		delete old;
		old = nullptr;
	}
	count = 0;
}

template<typename dataType>
void indexable_list<dataType>::append(dataType value) {
	if (head != nullptr) {
		Cell *temp = head;
		for (size_t i = 0; i < count-1 ; ++i) {
			temp = temp->link;
		}
		temp->link = new Cell;
		temp->link->data = value;
		temp->link->link = nullptr;
	}
	else {
		head = new Cell;
		head->data = value;
		head->link = nullptr;
	}
	count++;
}

template<typename dataType>
dataType indexable_list<dataType>::obtain(size_t idx) const {
	if (idx < count) {
		Cell *temp = head;
		for (size_t i = 0; i < idx; ++i) {
			temp = temp->link;
		}
		return temp->data;
	}
	else {
		throw invalid_argument("index out of range");
	}
}

template<typename dataType>
void indexable_list<dataType>::insert(size_t idx, dataType value){
	if (idx == 0) {
		Cell *temp = head;
		head = new Cell;
		head->data = value;
		head->link = temp;
	}
	else if (idx < count && idx > 0) {
		Cell *toinsert = head, *tomove = head;
		for(size_t i = 0; i < idx -1; ++i) {
			toinsert = tomove = toinsert->link;
		}
		tomove = tomove->link;
		toinsert->link = new Cell;
		toinsert->link->data = value;
		toinsert->link->link = tomove;
	}
	else if (idx == count) {
		Cell *toinsert = head;
		for (size_t i = 0; i < idx-1; ++i) {
			toinsert = toinsert->link;
		}
		toinsert->link = new Cell;
		toinsert->link->data = value;
		toinsert->link->link = nullptr;
	}
	else {
		throw invalid_argument ("insert(idx, value): index out of range");
	}
	count++;
}

template<typename dataType>
void indexable_list<dataType>::replace(size_t idx, dataType value){
	if (idx < count) {
		Cell *tmp = head;
		for(size_t i = 0; i < idx; ++i) {
			tmp = tmp->link;
		}
		tmp->data = value;
	}
	else {
		throw invalid_argument("replace(idx): index out of range");
	}
}

template<typename dataType>
dataType indexable_list<dataType>::erase(size_t idx) {
	dataType out;
	if (idx == 0) {
		Cell *temp = head;
		out = head->data;
		head = head->link;
		delete temp;
		temp = nullptr;
	}
	else if (idx < count-1 && idx > 0) {
		Cell *toerase = head, *tomove = head;
		for(size_t i = 0; i < idx-1; ++i) {
			toerase = tomove = toerase->link;
		}
		out = tomove->link->data;
		tomove = tomove->link->link;
		delete toerase->link;
		toerase->link = tomove;
	}
	else if (idx == count-1) {
		Cell *toerase = head;
		for (size_t i = 0; i < idx-1; ++i) {
			toerase = toerase->link;
		}
		out = toerase->link->data;
		delete toerase->link;
		toerase->link = nullptr;
	}
	else {
		throw invalid_argument ("erase(idx): index out of range");
	}
	count--;
	return out;
}
#endif //_indexable_list_cpp