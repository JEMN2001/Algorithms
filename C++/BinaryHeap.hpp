#ifndef _BinaryHeap_hpp_
#define _BinaryHeap_hpp_

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

#include "BinaryHeap.cpp"

#endif //_BinaryHeap_hpp_