//
//  main.cpp
//  aug_bst
//  Created by Julian Rincon on 2018-11-18.
//

#include <vector>
#include <string>
#include <random>
#include <iostream>
#include "punto1.hpp"

int main(void) {
    // special array to create perfect tree
    std::vector<int> pt = {0, -4, 4, -8, -2 , 2, 8, -10, -6, -3, -1, 1, 3, 6, 10};

    // binary search tree declaration
    bst<int> test;
    
    // fill out perfect tree
    for (auto key : pt) {
        test.insert(key);
    }
    
    // print tree using inorder traversal
    test.display();
    
    // remove some keys from perfect tree
    for (size_t i = 0; i < pt.size(); i += 2) {
        test.remove(pt[i]);
        std::cout << "--------------------------\n";
        std::cout << "remove " << pt[i] << std::endl;
        test.display();
    }
    
    std::cout << "\n************************************************\n\n";

    // integer random number generation
    std::string msg;
    std::random_device rd;
    std::default_random_engine generator{rd()};
    std::uniform_int_distribution<int> distribution(-9, 9);
    
    // binary search tree declaration
    bst<int> root;
    
    // fill out tree
    for (int i = 0; i < 9; i++) {
        int number = distribution(generator);
        std::cout << "number " << number << std::endl;
        root.insert(number);
    }
    
    // print tree using inorder traversal
    root.display();
    
    // checking whether an int is in tree
    for (int i = -9; i <= 9; i++) {
        msg = root.find(i) ? "true" : "false";
        std::cout << "find: " << i << " " << msg << std::endl;
    }
    
    // removing some one-child nodes
    for (int i = -9; i <= 9; i+=3) {
        std::cout << "--------------------------\n";
        std::cout << "remove " << i << std::endl;
        root.remove(i);
        root.display();
    }
    
    return 0;
}
