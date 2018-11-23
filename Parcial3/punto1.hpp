//
//  bst.hpp
//  aug_bst
//  Created by Julian Rincon on 2018-11-18.
//

#ifndef bst_hpp
#define bst_hpp

#include <iostream>

template <typename keyType>
class bst {
public:
    bst();
    ~bst();
    
    void remove(keyType);
    void insert(keyType);
    bool find(keyType) const;
    
    void clear(void);
    void display(std::ostream & = std::cout) const;

private:
    struct bstNode {
        keyType key;
        bstNode *left;
        bstNode *right;
    };
    
    size_t full_nodes(bstNode *tree) const;
    size_t num_leaves(bstNode *tree) const;

    size_t count;
    bstNode *tree;
    
    bstNode * min(bstNode *) const;
    void remove(bstNode * &, keyType);
    void insert(bstNode * &, keyType);
    bstNode * find(bstNode *, keyType) const;
    
    void clear(bstNode * &);
    void display(bstNode *, std::ostream &) const;
};

#include "punto1.cpp"

#endif /* bst_hpp */

/*
En el caso de full_nodes, T(N) = T(nodes(left))+T(nodes(right)), el peor caso es cuando el arbol no este balanceado,
teniendo que nodes(left) = 0 y nodes(right) = N (o viseversa), por lo que T(N) = THEETA(N).
En el mejor caso, el arbol esta perfectamente balanceado, por lo que nodes(left) aprox= N/2 y nodes(right) aprox= N/2,
por lo que T(N) = 2*T(N/2) = THEETA(N).

En num_leaves ocurre algo similar, T(N) = T(nodes(left)) + T(nodes(right)). Por lo que por los argumentos de full_nodes,
tenemos que el algoritmo tiene T(N) = THEETA(N).
*/
