#ifndef _Stack_hpp_
#define _Stack_hpp_
/*
*Author: JEMN2001
*Last Update: 18/10/2018
*/

using namespace std;

/*
*This class recreates the stack class of c++, using dynamic memory allocation and Linked Lists
*Only give acces to take out the last element in the container, and to insert elements at the end of the container
*/
template<typename datatype>
class Stack {
	//private section of the class
	private:
		/*
		*Struct for the Linked List
		*data: data that will be storaged in the container
		*link: pointer to the next cell of the list
		*/
		struct Cell {
			datatype data;
			Cell *link;
		};
		//pointer to the first cell of the container
		Cell *stack;
		//size of the container
		size_t count;
		/*
		*Method that copy all the content of a container
		*stk: container that will be copied
		*/
		void deepCopy(const Stack<datatype> & stk);
	//public section of the class
	public:
		/*
		*Creates a new Stack
		*/
		Stack();
		/*
		*deletes the actual stack
		*/
		~Stack();
		/*
		*Function that return the size of the container
		*return: size of the container
		*/
		size_t size() const;
		/*
		*Function that returns true if the container is empty, false if not
		*/
		bool empty() const;
		/*
		*Method that delets the actual container
		*/
		void clear();
		/*
		*Method that insert a new element to the last position of the container
		*dt: element that will be inserted
		*/
		void push(datatype dt);
		/*
		*Function that return the last element in the containern, and erase it
		*return: the element in the last position of the container
		*/
		datatype pop();
		/*
		*Method that return the last element of the container, but dont erase it
		*return: the element in the last position of the container
		*/
		datatype peek() const;
		/*
		*Function that overload the operator = for the stack class
		*/
		Stack<datatype> & operator=(const Stack<datatype> & stk);
};

#include "Stack.cpp"

#endif //_Stack_hpp_
