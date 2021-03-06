#ifndef _BST_cpp_
#define _BST_cpp_

#include "BST.hpp"

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::min(BST<datatype>::BST::BSTNode *root) const{
	BSTNode *temp = root;
	if (temp != nullptr) {
		while (temp->left != nullptr) {
			temp = temp->left;
		}
	}
	return temp;
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::max(BST<datatype>::BST::BSTNode *root) const{
	BSTNode *temp = root;
	if (temp != nullptr) {
		while (temp->right != nullptr) {
			temp = temp->right;
		}
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
		if (temp->right == nullptr) {
			return temp;
		}
		temp = temp->right;
		while (temp->left != nullptr) {
			temp = temp->left;
		}
		return temp;
	}
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::predecessor(BST<datatype>::BSTNode *root) const {
	BSTNode *temp = root;
	if (temp == nullptr) {
		return temp;
	}
	else {
		if (temp->left == nullptr) {
			return temp;
		}
		temp = temp->left;
		while (temp->right != nullptr) {
			temp = temp->right;
		}
		return temp;
		}
	}
}

template<typename datatype>
void BST<datatype>::remove(BST<datatype>::BSTNode * &root, datatype key) {
	BSTNode *temp = Find(root, key), *other = temp;
	if (temp != nullptr) {
		if (temp->left == nullptr && temp->right == nullptr) {
			temp = temp->parent;
			if (temp != nullptr) {
				if (temp->left == other) {
					temp->left = nullptr;
				}
				else if (temp->right == other) {
					temp->right = nullptr;
				}
			}
			else {
				this->root = nullptr;
			}
			delete other;
		}
		else if (temp->left == nullptr && temp->right != nullptr) {
			temp = temp->parent;
			if (temp != nullptr) {
				if (key < temp->key) {
					temp->left = other->right;
				}
				else if (key > temp->key) {
					temp->right = other->right;
				}
			}
			else {
				this->root = other->right;
				this->root->parent = nullptr;
			}
			delete other;
		}
		else if (temp->left != nullptr && temp->right == nullptr) {
			temp = temp->parent;
			if (temp != nullptr) {
				if (key < temp->key) {
					temp->left = other->left;
				}
				else if (key > temp->key) {
					temp->right = other->left;
				}
			}
			else {
				this->root = other->left;
				this->root->parent = nullptr;
			}
			delete other;
		}
		else {
			BSTNode *other2 = predecessor(other);
			other->key = other2->key;
			remove(other2, other2->key);
			count++;
		}
		count--;
	}
}

template<typename datatype>
typename BST<datatype>::BSTNode * BST<datatype>::copy(BST<datatype>::BSTNode * root, BST<datatype>::BSTNode *parent) {
	BSTNode *out = nullptr;
	if (root != nullptr) {
		out = new BSTNode;
		out->parent = parent;
		out->key = root->key;
		out->left = copy(root->left, out);
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
void BST<datatype>::display(BSTNode *root, std::ostream & out, size_t times) const {
	if (root != nullptr) {
		if (times < count) {
			display(root->left, out, ++times);
			out << root->key << ", ";
			display(root->right, out, ++times);
		}
		else {
			out << root->key;
		}
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
	this->root = copy(rhs.root, nullptr);
	count = rhs.count;
}

template<typename datatype>
BST<datatype>::~BST() {
	clear();
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

template<typename datatype>
void BST<datatype>::display(std::ostream &out) const {
	out << "[";
	display(root, out, 1);
	out << "]\n";
}

#endif //_BST_cpp_