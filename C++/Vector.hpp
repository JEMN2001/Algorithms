/*
*Created by: JEMN2001
*Last Update: 19/10/2018
*/
#ifndef _Vector_hpp_
#define _Vector_hpp_
#include <iostream>

using namespace std;
/*
*This class recreates the std::vector class of c++, using dynamic memory allocation, and dynamic arrays
*indexble container, with dynamic size
*/
template<typename datatype>
class Vector {
	//private section of the class
	private:
		//initial capacity of the vector
		static const size_t Initial_Capacity = 10;
		//pointer to the first element in the container
		datatype *vec;
		//size of the container
		size_t count;
		//max size of the container
		size_t capacity;
	//public section of the class
	public:
		/*
		*Creates a new vector
		*/
		Vector();
		/*
		*Creates a new vector, identical to another one
		*other: Vector that will be copied
		*/
		Vector(Vector<datatype> & other);
		/*
		*Creates a new vector, acording to a std::initializer_list
		*ls: initializar_list that will be used
		*/
		Vector(const initializer_list<datatype> & ls);
		/*
		*Creates a new vector, of size sz, with all the elements being equal to dt
		*sz = size of the vector
		*dt: Element for all the positions
		*/
		Vector(size_t sz, datatype dt);
		/*
		*deletes the actual vector
		*/
		~Vector();
		/*
		*Function that overloads the = operator for the Vector class
		*other: vector for the assigment
		*return: a reference to a copy of the 'other' vector
		*/
		Vector<datatype> & operator=(const Vector<datatype> & other);
		/*
		*Function that overloads the << operator for the Vector class
		*os: ostream that will be modified
		*vec: actual vector
		*return: the ostream modified with the vector
		*/
		template<class type> friend ostream & operator<<(ostream & os, Vector<type> & vec);
		/*
		*Function that overloads the operator [] for the Vector class
		*idx: position of the element
		*return: the element in the idx position on the container
		*/
		datatype & operator[](const size_t idx);
		/*
		*Function that returns the size of the container
		*return: current size
		*/
		size_t size() const;
		/*
		*Function that returns the size of the dynamic array
		*return: size of the dynamic array that contains the vector
		*/
		size_t Capacity() const;
		/*
		*Function that say if the vector is empty
		*return: True if the vector is empty, False if not
		*/
		bool empty() const;
		/*
		*Function that clears the container
		*/
		void clear();
		/*
		*Function that resize the container
		*newSize: the new size for the container
		*/
		void resize(size_t newSize);
		/*
		*Function that changes the size of the array
		*newCap: the new size for the array that contains the vector
		*/
		void reserve(size_t newCap);
		/*
		*Function that returns the element in the idx position of the container
		*idx: position of the element
		*return: element in the idx position of the container
		*/
		datatype & at(size_t idx);
		/*
		*Function that returns the first element in the container
		*return: element in the 0 position
		*/
		datatype & front();
		/*
		*Function that returns the last element in the container
		*return: the element in the size-1 position
		*/
		datatype & back();
		/*
		*Function that adds an element to the last position of the container
		*rhs: element that will be inserted
		*/
		void push_back(datatype rhs);
		/*
		*Function that deletes the last element in the container
		*/
		void pop_back();
		/*
		*Method that erase the element in the idx position
		*idx: position of the element
		*/
		void erase(size_t idx);
		/*
		*Method that inserts the element dt in the idx position
		*idx: position for the element
		*dt: element
		*/
		void insert(size_t idx, datatype dt);
};

#include "Vector.cpp"

#endif //_Vector_hpp_