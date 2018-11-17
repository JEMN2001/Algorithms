#ifndef _HashPair_cpp_
#define _HashPair_cpp_

#include <list>
#include "hash_pair.hpp"

template<typename dataType>
std::size_t hashFunction<dataType>::operator()(const dataType & key) {
	return static_cast<std::size_t >(key);
}

template<typename keyType, typename valueType>
std::size_t hashPair<keyType, valueType>::hashing(const keyType & key) const {
	hashFunction<keyType> hashFunctor;
	return hashFunctor(key) % nBuckets;
}

template<typename keyType, typename valueType>
hashPair<keyType, valueType>::hashPair() {
	count = 0;
	nBuckets = PRIME_INITIAL_DIMENSION;
	table = new std::list<std::pair<keyType, valueType>>[nBuckets] {};
}

template<typename keyType, typename valueType>
hashPair<keyType, valueType>::~hashPair() {
	clear();
}

template<typename keyType, typename valueType>
bool hashPair<keyType, valueType>::find(const keyType & key) const {
	auto position = table[hashing(key)];
	for (auto iter = position.cbegin(); iter != position.cend(); ++iter) {
		if (iter->first == key) {
			return true;
		}
	}
	return false;
}

template<typename keyType, typename valueType>
bool hashPair<keyType, valueType>::insert(const std::pair<keyType, valueType> & item) {
	if (!find(item.first)) {
		table[hashing(item.first)].push_back(item);
		count++;
		return true;
	}
	return false;
}

template<typename keyType, typename valueType>
bool hashPair<keyType, valueType>::insert(const keyType key, valueType value) {
	if (!find(key)) {
		std::pair<keyType, valueType> pr;
		pr.first = key;
		pr.second = value;
		table[hashing(key)].push_back(pr);
		count++;
		return true;
	}
	return false;
}

template<typename keyType, typename valueType>
bool hashPair<keyType, valueType>::remove(const keyType & key) {
	if (find(key)) {
		for (auto iter = table[hashing(key)].begin(); iter != table[hashing(key)].end(); ++iter) {
			if (iter->first == key) {
				table[hashing(key)].erase(iter);
				count--;
				return true;
			}
		}
	}
	return false;
}

template<typename keyType, typename valueType>
valueType & hashPair<keyType, valueType>::operator[] (const keyType & key) {
	std::size_t pos = hashing(key);
	for (auto iter = table[pos].begin(); iter != table[pos].end(); ++iter) {
		if (iter->first == key) {
			return iter->second;
		}
	}
	throw;
}

template<typename keyType, typename valueType>
std::size_t hashPair<keyType, valueType>::size(void) const{
	return count;
}

template<typename keyType, typename valueType>
void hashPair<keyType, valueType>::clear(void) {
	delete[] table;
	count = 0;
	table = new std::list<std::pair<keyType, valueType>>[nBuckets] {};
}

template<typename keyType, typename valueType>
void hashPair<keyType, valueType>::display(void) const {
	std::cout << "Load Factor: " << ((double) count)/nBuckets << std::endl;
	for (size_t i = 0; i < nBuckets; ++i) {
		auto lst = table[i];
		std::cout << "Buucket: " << i << "   size: " << lst.size() << std::endl;
	}
}

#endif //_HashPair_cpp_