//
//  main.cpp
//  hashMap
//  Created by Julian Rincon on 2018-05-19.
//

#include <random>
#include <iostream>
#include "punto2.hpp"

template <>
class hashFunction<int> {
public:
    std::size_t operator()(const int & key) {
        return static_cast<std::size_t>(key);
    }
};

int main() {
    std::cout << std::boolalpha;

    const int min = -15, max = +15;
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(min, max);

    hashMap<int, bool> parity;

    // insert pairs
    for (int i = 0; i < max; ++i) {
        int key = distribution(generator);
        parity.insert(key, key % 2 == 0);
        std::cout << "Insert: " << key << std::endl;
    }

    parity.display();
    
    // find keys
    for (int key = min; key < max; ++key)
        std::cout << "Find: " << key << " " << parity.find(key) << std::endl;
    
    // remove pairs
    for (int i = min; i < max; ++i) {
        int key = distribution(generator);
        std::cout << "Remove: " << key << " " << parity.remove(key) << std::endl;
    }
    
    // find keys again
    for (int key = min; key < max; ++key)
        std::cout << "Find: " << key << " " << parity.find(key) << std::endl;
    
    parity.display();
    
    return 0;
}
