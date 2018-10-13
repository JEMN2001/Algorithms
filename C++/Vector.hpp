#ifndef _Vector_hpp_
#define _Vector_hpp_

using namespace std;

template<typename datatype>
class Vector {
	private:
		static const unsigned Initial_Capacity = 10;
		datatype *vec;
		unsigned count;
		unsigned capacity;
	public:
		Vector();
		Vector(Vector<datatype> & other);
		~Vector();
		Vector<datatype> & operator=(const Vector<datatype> & other);
		datatype & operator[](const unsigned idx);
		unsigned size() const;
		unsigned Capacity() const;
		bool empty() const;
		void clear();
		void resize(unsigned newSize);
		void reserve(unsigned newCap);
		datatype & at(unsigned idx);
		datatype & front();
		datatype & back();
		void push_back(datatype rhs);
		void pop_back();
};

#include "Vector.cpp"

#endif //_Vector_hpp_