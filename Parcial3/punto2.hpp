//
//  hashMap.hpp
//  hashMap
//  Created by Julian Rincon on 2018-05-19.
//

#ifndef hashMap_hpp
#define hashMap_hpp

#include <list>
#include <iostream>

const std::size_t PRIME_INITIAL_DIMENSION = 5; // 101

template <typename dataType> class hashFunction;

template <typename keyType, typename valueType>
class hashMap {
    struct pair {
        keyType key;
        valueType val;
    };
    
    std::size_t total_colls;
    std::size_t count;
    std::size_t nBuckets;
    std::list<pair> *table;
    
    std::size_t hashing(const keyType &) const;
    
public:
    hashMap();
    ~hashMap();

    float total_ave_colls() const;
    float curr_ave_colls() const;
    void colls_warning() const;
    
    bool find(const keyType &) const;
    bool insert(const keyType &, const valueType &);
    bool remove(const keyType &);
  
    void clear();
    void display() const;
};

#include "punto2.cpp"

#endif /* hashMap_hpp */
