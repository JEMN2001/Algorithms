#ifndef _indexable_list_hpp_
#define _indexable_list_hpp_
#include <iostream>

using namespace std;

template<typename dataType>
class indexable_list {
	private:
		struct Cell {
			dataType data;
			Cell *link;
		};

		Cell *head;
		size_t count;
	public:
		indexable_list();
		~indexable_list();
		template<typename Type> friend ostream & operator<<(ostream & out, indexable_list<Type> & lst);
		const dataType & operator[](size_t idx) const;
		dataType & operator[](size_t idx);
		size_t size() const;
		bool empty() const;
		void clear();
		void append(dataType value);
		dataType obtain(size_t idx) const;
		void insert(size_t idx, dataType value);
		void replace(size_t idx, dataType value);
		dataType erase(size_t idx);
};

#include "Murcia_Perez_idx_list.cpp"

#endif //_indexable_list_hpp