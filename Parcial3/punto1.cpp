//
//  bst.cpp
//  aug_bst
//  Created by Julian Rincon on 2018-11-18.
//

#ifdef bst_hpp

template<typename keyType>
size_t bst<keyType>::full_nodes(bst<keyType>::bstNode *tree) const {
	if (tree == nullptr) {
		return 0;
	}
	else if (tree->left != nullptr && tree->right != nullptr) {
		return 1+full_nodes(tree->left)+full_nodes(tree->right);
	}
	else {
		return full_nodes(tree->left)+full_nodes(tree->right);
	}
}

template<typename keyType>
size_t bst<keyType>::num_leaves(bst<keyType>::bstNode *tree) const {
	if (tree == nullptr) {
		return 0;
	}
	else if (tree->left != nullptr || tree->right != nullptr) {
		return num_leaves(tree->left)+num_leaves(tree->right);
	}
	else {
		return 1;
	}
}

template <typename keyType>
bst<keyType>::bst() {
    tree = nullptr;
    count = 0;
}


template <typename keyType>
bst<keyType>::~bst() {
    clear();
}


template <typename keyType>
void bst<keyType>::insert(bstNode * & bush, keyType key) {
    if (bush == nullptr) {
        count++;
        bush = new bstNode;
        bush->key = key;
        bush->left = nullptr;
        bush->right = nullptr;
        // std::cout << "dir " << bush << " key " << bush->key << "\n";
    } else {
        if (key != bush->key) {
            if (key < bush->key) {
                insert(bush->left, key);
            } else {
                insert(bush->right, key);
            }
        }
    }
}


template <typename keyType>
void bst<keyType>::insert(keyType key) {
    insert(tree, key);
}


template <typename keyType>
void bst<keyType>::remove(bstNode * & bush, keyType key) {
    if (bush == nullptr) return;
    
    if (key < bush->key) {
        remove(bush->left, key);
    } else if (key > bush->key) {
        remove(bush->right, key);
    } else if (bush->left == nullptr) {
        bstNode *tmp = bush;
        bush = bush->right;
        delete tmp;
        count--;
    } else if (bush->right == nullptr) {
        bstNode *tmp = bush;
        bush = bush->left;
        delete tmp;
        count--;
    } else if (bush->left != nullptr && bush->right != nullptr) {
        bush->key = min(bush->right)->key;
        remove(bush->right, bush->key);
    }
}


template <typename keyType>
void bst<keyType>::remove(keyType key) {
    remove(tree, key);
}


template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::find(bstNode * bush, keyType key) const {
    if (bush == nullptr) return nullptr;
    if (key == bush->key) return bush;
    
    if (key < bush->key) {
        return find(bush->left, key);
    } else {
        return find(bush->right, key);
    }
}


template <typename keyType>
bool bst<keyType>::find(keyType key) const {
    if (find(tree, key) != nullptr) {
        return true;
    } else {
        return false;
    }
}


template <typename keyType>
void bst<keyType>::display(bstNode * bush, std::ostream & out) const {
    if (bush != nullptr) {
        display(bush->left, out);
        out << "key: " << bush->key << std::endl;
        display(bush->right, out);
    }
}


template <typename keyType>
void bst<keyType>::display(std::ostream & out) const {
    out << "Tree " << tree << " nodes: " << count << " full nodes: " << full_nodes(tree) << " num leaves: " << num_leaves(tree) << std::endl;
    display(tree, out);
}


template <typename keyType>
void bst<keyType>::clear(bstNode * & bush) {
    if (bush != nullptr) {
        clear(bush->left);
        clear(bush->right);
        delete bush;
        count--;
    }
    bush = nullptr;
    std::cout << "Clear: nodes left " << count << " " << bush << std::endl;
}


template <typename keyType>
void bst<keyType>::clear(void) {
    clear(tree);
}


template <typename keyType>
typename bst<keyType>::bstNode * bst<keyType>::min(bstNode *bush) const {
    if (bush == nullptr) {
        return nullptr;
    } else {
        return bush->left == nullptr ? bush : min(bush->left);
    }
}


#endif /* bst_hpp */
