#ifndef _Vector_cpp_
#define _Vector_cpp_

#include "Vector.hpp"

template<typename datatype>
Vector<datatype>::Vector() {
	vec = new datatype[Initial_Capacity] {};
	count = 0;
	capacity = Initial_Capacity;
}

template<typename datatype>
Vector<datatype>::Vector(Vector<datatype> & other) {
	vec = new datatype[other.capacity] {};
	for (size_t i = 0; i < other.count; ++i) {
		vec[i] = other[i];
	}
	count = other.count;
	capacity = other.capacity;
}

template<typename datatype>
Vector<datatype>::~Vector() {
	delete[] vec;
	vec = nullptr;
	count = 0;
	capacity = 0;
}

template<typename datatype>
Vector<datatype> & Vector<datatype>::operator=(const Vector<datatype> & other) {
	vec = new datatype[other.capacity] {};
	for (size_t i = 0; i < other.count; ++i) {
		vec[i] = other[i];
	}
	count = other.count;
	capacity = other.capacity;
	return *this;
}

template<typename datatype>
ostream & operator<<(ostream & os, Vector<datatype> & vec) {
	os << '[';
	for (size_t i = 0; i < vec.size(); ++i) {
		if (i+1 < vec.size()) {
			os << vec.at(i) << ", ";
		}
		else {
			os << vec.at(i);;
		}
	}
	os << "]";
	return os;
}

template<typename datatype>
datatype & Vector<datatype>::operator[](const size_t idx) {
	return *(vec+idx);
}

template<typename datatype>
size_t Vector<datatype>::size() const {
	return count;
}

template<typename datatype>
size_t Vector<datatype>::Capacity() const {
	return capacity;
}

template<typename datatype>
bool Vector<datatype>::empty() const {
	return count == 0;
}

template<typename datatype>
void Vector<datatype>::clear() {
	delete[] vec;
	vec = new datatype[Initial_Capacity] {};
	count = 0;
	capacity = Initial_Capacity;
}


template<typename datatype>
void Vector<datatype>::resize(size_t newsize) {
	datatype *old = vec;
	if (newsize > count) {
		capacity = newsize*2;
		vec = new datatype[capacity] {};
		for (size_t i = 0; i < count; ++i) {
			vec[i] = old[i];
		}
		delete[] old;
	}
	else if (newsize < count) {
		vec = new datatype[capacity] {};
		for (size_t i = 0; i < newsize; ++i) {
			vec[i] = old[i];
		}
		delete[] old;
	}
	else {
		vec = old;
	}
	count = newsize;
}

template<typename datatype>
void Vector<datatype>::reserve(size_t newCap) {
	datatype *old = vec;
	if (newCap > capacity) {
		vec = new datatype[newCap] {};
		for (size_t i = 0; i < count; ++i) {
			vec[i] = old[i];
		}
		delete[] old;
		capacity = newCap;
	}
}

template<typename datatype>
datatype & Vector<datatype>::at(size_t idx) {
	if (idx < count) {
		return vec[idx];
	}
	throw;
}

template<typename datatype>
datatype & Vector<datatype>::front() {
	return vec[0];
}

template<typename datatype>
datatype & Vector<datatype>::back() {
	return vec[count-1];
}

template<typename datatype>
void Vector<datatype>::push_back(datatype rhs) {
	if (count == capacity) {
		reserve(capacity*2);
	}
	vec[count++] = rhs;
}

template<typename datatype>
void Vector<datatype>::pop_back() {
	if (count > 0) {
		count--;
	}
	else {
		throw;
	}
}

#endif //_Vector_cpp_