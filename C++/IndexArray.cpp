#include <iostream>
using namespace std;

/*
*Struct for the linked list
*key: the element that wants to be storaged
*link: a pointer to the next cell of the list
*/
struct Bloque {
	int key;
	Bloque *link;
};

/*
*Function that creats an integers array, with the condition that in the K'th is the value K.
*max: Size of the array
*return: A pointer to the first element of the array
*/
int *IndexArray(int max);
/*
*Method that takes a integer array, and delete it
*pointer: pointer to gthe first element of the array
*/
void destroyArray(int *pointer);
/*
*Function that crates a linked list of integers, with the condition that in the K'th position, is the value K
*max: Size of the list
*return: A pointer to the first cell of the list
*/
Bloque *IndexList(int max);
/*
*Method that takes a linked list, and delete it
*pointer: pointer to the first cell of the list
*/
void destroyList(Bloque *pointer);

int main() {
	int size = 10, *intpointer = IndexArray(size);
	for (int i = 0; i < size; ++i) {
		cout << *(intpointer+i) << ", ";
	}
	cout << endl;
	destroyArray(intpointer);
	Bloque *Blockpointer = IndexList(size), *copy = Blockpointer;
	while(Blockpointer != nullptr) {
		cout << Blockpointer->key << ", ";
		Blockpointer = Blockpointer->link;
	}
	cout << endl;
	destroyList(copy);
	return 0;
}

int *IndexArray(int max) {
	int *array = new int[max];
	for (int i = 0; i < max; ++i) {
		*(array+i) = i;
	}
	return array;
}

void destroyArray(int *pointer) {
	delete[] pointer;
	pointer = nullptr;
}

Bloque *IndexList(int max) {
	Bloque *ptr = new Bloque, *out = ptr;
	ptr->key = 0;
	ptr->link = nullptr;
	for (int i = 0; i < max; ++i) {
		ptr->key = i;
		if (i < max-1) {
			ptr->link = new Bloque;
			ptr = ptr->link;
			ptr->link = nullptr;
		}
		else if (i == max-1) {
			ptr->link = nullptr;
		}
	}
	return out;
}

void destroyList(Bloque *pointer) {
	Bloque *temp;
	while (pointer != nullptr) {
		temp = pointer;
		pointer = pointer->link;
		delete temp;
		temp = nullptr;
	}
}
