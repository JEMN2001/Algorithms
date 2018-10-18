#ifndef _Queue_hpp_
#define _Queue_hpp_
/*
*Created by: JEMN2001
*Last Update: 18/10/2018
*/

using namespace std;

/*
*This class redefines the queue class of c++, using dynamic memory allocation, and dynamic arrays
*Only gives acces to take out the element in the first position, and only let insert elements into the last position
*/
template <typename datatype>
class Queue {
	private:
		//Initial capacity of thq queue
		static const size_t Initial_Capacity = 10;
		
		//array: pointer to the forst element of the container
		datatype *array;
		/*
		*capacity: size of the container
		*/
		size_t capacity;
		/*
		*head: initial position of the container
		*tail: last position of the container
		*/
		int head, tail;
		/*
		*True if the head was the one that change, false if was the tail
		*/
		bool notfull;
		/*
		*takes the array, and duplicates its capacity
		*/
		void expandCapacity();
		/*
		*copy the que conteiner into another container
		*Queue<datatype> que: container that will be copied
		*/
		void deepCopy(const  Queue<datatype> & que);
	public:
		/*
		*Creates a new queue
		*/
		Queue();
		/*
		*Creates a new queue identical to another
		*que: Queue that will be copied
		*/
		Queue(const Queue<datatype> & que);
		/*
		*deletes the actual queue
		*/
		~Queue();
		/*
		*function that returns the size of the container
		*/
		size_t size() const;
		/*
		*Function that returns true if the container is empty, false if not
		*/
		bool empty() const;
		/*
		*Method that clears out the container
		*/
		void clear();
		/*
		*Method that insert a new element to the last position of the container
		*dt: element that will be added to the container
		*/
		void push(datatype dt);
		/*
		*Function that takes the first element of the container, erase it and return it
		*return: first element in the container
		*/
		datatype pop();
		/*
		*Function that returns the first element in the container, but dont erase it
		*return: the first element of the container
		*/
		datatype top() const;
		/*
		*overloads the = operator for queue assigments
		*que: queue that will be assigned
		*return: a copy of que
		*/
		Queue<datatype> & operator=(const Queue<datatype> & que);
};

#include "Queue.cpp"

#endif //_Queue_hpp_
