#ifndef _heap_hpp_
#define _heap_hpp_

#include <vector>
#include <cmath>

template<typename dataType>
class BinaryHeap {
	private:
		std::vector<dataType> array;
		void percolateDown(std::size_t hole);
	public:
		BinaryHeap(std::size_t capacity = 100);
		bool isEmpty() const;
		const dataType & findMin() const;
		void insert(dataType elem);
		void deleteMin();
		void clear();
		std::size_t size() const;
		void display() const;
};

#include "heap.cpp"

#endif //_heap_hpp_