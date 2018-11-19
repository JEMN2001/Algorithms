#ifndef _Hash_pair_cpp
#define _Hash_pair_cpp_

#include <list>

const std::size_t PRIME_INITIAL_DIMENSION = 5

template <typename dataType> class hashFunction {
	public:
		std::size_t operator() (const int & key);	
};

template<typename keyType, typename dataType>
class hashPair {
	private:
		std::size_t count;
		std::size_t nBuckets;
		std::list<std::pair<keyType, dataType>> *table;

		std:: size_t hashing(const keyType & key);
	public:
		hashPair();
		~hashPair();

		bool find(const keyType & key) const;
		bool insert(const std::pair<keyType, dataType> & item);
		bool remove(const keyType & key);

		void clear(void);
		void display(void) const;
};