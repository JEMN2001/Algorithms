//
//  hashMap.cpp
//  hashMap
//  Created by Julian Rincon on 2018-05-19.
//

#ifdef hashMap_hpp

template <typename keyType, typename valueType>
hashMap<keyType, valueType>::hashMap() {
    std::cout << "Constructor for hashMap" << std::endl;
    
   	total_colls = 0;
    count = 0;
    nBuckets = PRIME_INITIAL_DIMENSION;
    table = new std::list<pair>[nBuckets]{};
    
    std::cout << nBuckets << " " << count << std::endl;
}


template <typename keyType, typename valueType>
hashMap<keyType, valueType>::~hashMap() {
    std::cout << "Destructor for hashMap" << std::endl;
    clear();
    delete[] table;
}


template <typename keyType, typename valueType>
std::size_t hashMap<keyType, valueType>::hashing(const keyType & key) const {
    hashFunction<keyType> hashFunctor;
    return hashFunctor(key) % nBuckets;
}


template <typename keyType, typename valueType>
bool hashMap<keyType, valueType>::find(const keyType & key) const {
    std::size_t hashCode = hashing(key);
    auto & bucket = table[hashCode];

    for (const auto & item : bucket) if (item.key == key) return true;

    return false;
}


template <typename keyType, typename valueType>
bool hashMap<keyType, valueType>::insert(const keyType & key, const valueType & val) {
    pair data = {key, val};
    std::size_t hashCode = hashing(key);
    auto & bucket = table[hashCode];

    for (const auto & item : bucket) if (item.key == data.key) return false;

    count++;
	if (bucket.size() > 0) total_colls++;
    bucket.push_front(data);

    colls_warning();
    return true;
}


template <typename keyType, typename valueType>
bool hashMap<keyType, valueType>::remove(const keyType & key) {
    std::size_t hashCode = hashing(key);
    auto & bucket = table[hashCode];
    
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            count--;
            return true;
        }
    }

    return false;
}


template <typename keyType, typename valueType>
void hashMap<keyType, valueType>::clear(void) {
    for (std::size_t idx = 0; idx < nBuckets; idx++)
        table[idx].clear();

    count = 0;
    total_colls = 0;
}


template <typename keyType, typename valueType>
void hashMap<keyType, valueType>::display(void) const {
    std::cout << "Info hashMap\n";
    std::cout << "Total number of elements: " << count << std::endl;

    std::size_t total = 0;
    
    for (std::size_t idx = 0; idx < nBuckets; idx++) {
        auto sz = table[idx].size();
	std:: cout << "Bucket: " << idx << " --> " << sz << std::endl;
	total += sz;
    }
    if (count != total) std::cout << "ERROR: number of elements wrong!\n";
    std::cout << "Total number of colls: " << total_colls << std::endl;
    std::cout << "Total ave colls: " << total_ave_colls() << std::endl;
    std::cout << "Current ave colls: " << curr_ave_colls() << std::endl;
}

template<typename keyType, typename valueType>
float hashMap<keyType, valueType>::total_ave_colls() const {
	return ((float) total_colls)/nBuckets;
}

template<typename keyType, typename valueType>
float hashMap<keyType, valueType>::curr_ave_colls() const {
	std::size_t curr_colls = 0;
	for (std::size_t i = 0; i < nBuckets; ++i) {
		auto & bucket = table[i];
		if (bucket.size() > 1) curr_colls += bucket.size()-1;
	}
	return ((float) curr_colls)/nBuckets;
}

template<typename keyType, typename valueType>
void hashMap<keyType, valueType>::colls_warning() const {
	if (total_colls > nBuckets) {
		std::cout << "Warning, the total number of collisions is grater than the number of buckets" << std::endl;
	}
}


#endif /* hashMap_hpp */
