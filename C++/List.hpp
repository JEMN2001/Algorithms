#ifndef _List_hpp_
#define _List_hpp_
#include <iostream>

using namespace std;

template<typename datatype>
class List {
	private:
		struct Cell {
			datatype data;
			Cell *left;
			Cell *right;
		};
		Cell *front;
		Cell *back;
		size_t count;
		void deepCopy(const List<datatype> & ls);
	public:
		List();
		List(const List<datatype> & ls);
		~List();
		List<datatype> & operator=(const List<datatype> & ls);
		size_t size() const;
		bool empty() const;
		void clear();
		datatype & Front();
		datatype & Back();
		void push_front(datatype dt);
		void push_back(datatype dt);
		void pop_front();
		void pop_back();
};

#include "List.cpp"

#endif //_List_hpp_