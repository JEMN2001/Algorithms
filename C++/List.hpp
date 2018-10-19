/*
*Created by: JEMN2001
*Last update: 19/10/2018
*/
#ifndef _List_hpp_
#define _List_hpp_
#include <iostream>

using namespace std;

/*
*This class recreates the std::list class of c++, using dynamic memory allocation, and doubly linked lists
*Give acces to the first, and the last element in the container, with constant insertions in the edges
*/
template<typename datatype>
class List {
	//private section of the class
	private:
		//Struct for the doubly linked list
		struct Cell {
			//The element storaged
			datatype data;
			//pointer to the left cell of the list
			Cell *left;
			//pointer to the right cell of the list
			Cell *right;
		};
		//pointer to the beginning of the list
		Cell *front;
		//pointer to the end of the list
		Cell *back;
		//size of the list
		size_t count;
		/*
		*Function that copies all the elements of a list to another one
		*ls: List that will be copied
		*/
		void deepCopy(const List<datatype> & ls);
	//public section of the class
	public:
		/*
		*Creates a new List
		*/
		List();
		/*
		*Creates a new List, identical to another one
		*ls: the other one
		*/
		List(const List<datatype> & ls);
		/*
		*Creates a new ist, identical to a initializer list
		*ls: initializer list that will be used
		*/
		List(const initializer_list<datatype> & ls);
		/*
		*Deletes the current List
		*/
		~List();
		/*
		*overloads the = operator for the class
		*ls: list that will be copied
		*return: a reference to a List, identical to ls
		*/
		List<datatype> & operator=(const List<datatype> & ls);
		/*
		*Function that returns the actual size of the container
		*return: size of the container
		*/
		size_t size() const;
		/*
		*Function that says if the list is empty
		*return: True if the container is empty, False if not
		*/
		bool empty() const;
		/*
		*Method that clears the container
		*/
		void clear();
		/*
		*Function that access to the first element
		*return: element in the beginning of the list
		*/
		datatype & Front();
		/*
		*Function that access to the last element
		*return: element at the last position of the list
		*/
		datatype & Back();
		/*
		*Method that insert a element at the beginning of the container
		*dt: element that will be inserted
		*/
		void push_front(datatype dt);
		/*
		*Method that insert a element at the end of the container
		*dt: element that will be iinserted
		*/
		void push_back(datatype dt);
		/*
		*Method that deletes the element at the beginning of the container
		*/
		void pop_front();
		/*
		*Method  that deletes the element at the end of the container
		*/
		void pop_back();
};

#include "List.cpp"

#endif //_List_hpp_