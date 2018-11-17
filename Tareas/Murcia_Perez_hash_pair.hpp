#ifndef _HashPair_hpp_
#define _HashPair_hpp_

#include <list>
#include <iostream>

std::size_t PRIME_INITIAL_DIMENSION = 5;

template<typename dataType>
class hashFunction {
	public:
		std::size_t operator() (const dataType & key);
};

template<typename keyType, typename valueType>
class hashPair {
	private:
		std::size_t count;
		std::size_t nBuckets;
		std::list<std::pair<keyType, valueType>> *table;

		std::size_t hashing(const keyType & key) const;
	public:
		hashPair();
		~hashPair();

		bool find(const keyType & key) const;
		bool insert(const std::pair<keyType, valueType> & item);
		bool insert(const keyType key, valueType value);
		bool remove(const keyType & key);

		valueType & operator[] (const keyType & key);

		std::size_t size(void) const;
		void clear(void);
		void display(void) const;
};

#include "hash_pair.cpp"

#endif //_HashPair_hpp_