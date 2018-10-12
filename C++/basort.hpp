#ifndef _basort_hpp_
#define _basort_hpp_

#include <vector>

/**
*Method that takes by reference a vector of integers, and sort it using the InsertionSort Algorithm
*lst: vector that will be sorted
**/
void InsertionSort(std::vector<int> & lst);
/**
*Method that takes by reference a vector of integers, and sort it using the SelectionSort Algorithm
*lst: vector that will be sorted
**/
void SelectionSort(std::vector<int> & lst);
/**
*Method that takes by reference a vector of integers, and sort it using the StoogeSort Algorithm
*lst: vector that will be sorted
*start: starting index of the vector
*end: ending index of the vector
**/
void StoogeSort(std::vector<int> & lst, int start, int end);
/**
*Method that takes by reference a vector of integers, and sort it using the BogoSort Algorithm
*lst: Vector that will be sorted
**/
void BogoSort(std::vector<int> & lst);
/**
*Method that takes by reference a vector of integers, and sort it using the BubbleSort Algorithm
*lst: vector that will be sorted
**/
void BubbleSort(std::vector<int> & lst);
/**
*FUnction that takes by reference a vector of integers, and ckeck if the vector is sorted
*lst: vector that will be checked
*return: true, if it's sorted, false if not
**/
bool IsSorted(std::vector<int> & lst);
/**
*Function that takes by reference a vector of integers and make a random permutation of the contents of the vector
*lst: vector that will be permuted
**/
void Shuffle(std::vector<int> & lst);

#endif //_basort_hpp_
