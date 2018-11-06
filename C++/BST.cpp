#ifndef _BST_cpp_
#define _BST_cpp_

#include "BST.hpp"

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::min(BST<datatype>::BST::BSTNode *root) const{
	BSTNode *temp = root;
	while (temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::max(BST<datatype>::BST::BSTNode *root) const{
	BSTNode *temp = root;
	while (temp->right != nullptr) {
		temp = temp->right;
	}
	return temp;
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::succesor(BST<datatype>::BSTNode *root) const {
	BSTNode *temp = root;
	if (temp == nullptr) {
		return temp;
	}
	else {
		temp = temp->right;
		if (temp == nullptr) {
			return temp;
		}
		else {
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			return temp;
		}
	}
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::predecessor(BST<datatype>::BSTNode *root) const {
	BSTNode *temp = root;
	if (temp == nullptr) {
		return temp;
	}
	else {
		temp = temp->left;
		if (temp == nullptr) {
			return temp;
		}
		else {
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			return temp;
		}
	}
}

template<typename datatype>
void BST<datatype>::remove(BST<datatype>::BSTNode * &root, datatype key) {
	BSTNode *temp = Find(root, key);
	if (temp != nullptr) {
		BSTNode *parent = temp->parent, *left = temp->left, *right = temp->right;
		if (left == nullptr && right == nullptr) {
			if (parent->left == temp) {
				parent->left = nullptr;
			}
			else if (parent->right == temp) {
				parent->right = nullptr;
			}
		}
		else if (left == nullptr && right != nullptr) {
			if (parent->left == temp) {
				parent->left = right;
			}
			else if (parent->right == temp) {
				parent->right = right;
			}
		}
		else if (left != nullptr && right == nullptr) {
			if (parent->left == temp) {
				parent->left = left;
			}
			else if (parent->right == temp) {
				parent->right = left;
			}
		}
		else {
			BSTNode *other;
			if (parent->right == temp) {
				parent->right = right;
				other = min(right);
				other->left = left;
			}
			else if (parent->left == temp) {
				parent->left = left;
				other = max(left);
				other->right = right;
			}
		}
		delete temp;
		count--;
	}
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::copy(BST<datatype>::BSTNode *root, BST<datatype>::BSTNode *parent) {
	BSTNode out = nullptr;
	if (root != nullptr) {
		out = new BSTNode;
		out->parent = parent;
		out->key = root->key;
		out->Left = copy(root->left, out);
		out->right = copy(root->right, out);
	}
	return out;
}

template<typename datatype>
void BST<datatype>::clear(BST<datatype>::BSTNode *root) {
	if (root != nullptr) {
		BSTNode *left = root->left, *right = root->right;
		delete root;
		clear(left);
		clear(right);
	}
}

template<typename datatype>
void BST<datatype>::insert(BST<datatype>::BSTNode * &root, datatype key, BST<datatype>::BSTNode *parent) {
	if (root == nullptr) {
		root = new BSTNode;
		root->key = key;
		root->parent = parent;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (key < root->key) {
			insert(root->left, key, root);
		}
		else if (key > root->key) {
			insert(root->right, key, root);
		}
	}
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::Find(BST<datatype>::BSTNode *root, datatype key) const{
	if (root == nullptr) {
		return nullptr;
	}
	else {
		if (key == root->key) {
			return root;
		}
		else if (key < root->key) {
			return Find(root->left, key);
		}
		else {
			return Find(root->right, key);
		}
	}
}

template<typename datatype>
BST<datatype>::BST() {
	root = nullptr;
	count = 0;
}

template<typename datatype>
BST<datatype>::BST(const BST & rhs) {
	copy(rhs);
	count = rhs.count;
}

template<typename datatype>
BST<datatype>::~BST() {
	clear();
}

template<typename datatype>
void BST<datatype>::printTree(BSTNode *rt) const{
	if (rt != nullptr) {
		printTree(rt->left);
		std::cout << rt->key << std::endl;
		printTree(rt->right);	
	}
}

template<typename datatype>
void BST<datatype>::remove(datatype key) {
	remove(root, key);
}

template<typename datatype>
bool BST<datatype>::empty(void) const {
	return count == 0;
}

template<typename datatype>
void BST<datatype>::clear(void) {
	clear(root);
	root = nullptr;
	count = 0;
}

template<typename datatype>
size_t BST<datatype>::size(void) const {
	return count;
}
template<typename datatype>
bool BST<datatype>::find(datatype key) const {
	if (Find(root, key) == nullptr) {
		return false;
	}
	return true;
}

template<typename datatype>
void BST<datatype>::insert(datatype key) {
	insert(root, key, nullptr);
	count++;
}

#endif //_BST_cpp_