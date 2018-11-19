<<<<<<< HEAD
#ifndef _Hash_pair_cpp
#define _Hash_pair_cpp_

#include <list>

const std::size_t PRIME_INITIAL_DIMENSION = 5

template <typename dataType> class hashFunction {
	public:
		std::size_t operator() (const int & key);	
};

template<typename keyType, typename dataType>
=======
#ifndef _HashPair_hpp_
#define _HashPair_hpp_

#include <list>
#include <iostream>

const std::size_t PRIME_INITIAL_DIMENSION = 5;

template<typename dataType>
class hashFunction {
	public:
		std::size_t operator() (const dataType & key);
};

template<typename keyType, typename valueType>
>>>>>>> 2c8f7e6a150a78122b713da3576440dac3bcef07
class hashPair {
	private:
		std::size_t count;
		std::size_t nBuckets;
<<<<<<< HEAD
		std::list<std::pair<keyType, dataType>> *table;

		std:: size_t hashing(const keyType & key);
=======
		std::list<std::pair<keyType, valueType>> *table;

		std::size_t hashing(const keyType & key) const;
>>>>>>> 2c8f7e6a150a78122b713da3576440dac3bcef07
	public:
		hashPair();
		~hashPair();

		bool find(const keyType & key) const;
<<<<<<< HEAD
		bool insert(const std::pair<keyType, dataType> & item);
		bool remove(const keyType & key);

		void clear(void);
		void display(void) const;
};
=======
		bool insert(const std::pair<keyType, valueType> & item);
		bool insert(const keyType key, valueType value);
		bool remove(const keyType & key);

		valueType & operator[] (const keyType & key);

		std::size_t size(void) const;
		void clear(void);
		void display(void) const;
};

#include "Murcia_Perez_hash_pair.cpp"

#endif //_HashPair_hpp_
>>>>>>> 2c8f7e6a150a78122b713da3576440dac3bcef07
