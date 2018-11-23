#ifndef _fastsort_hpp_
#define _fastsort_hpp_

#include<vector>

template<typename Type>
void heapsort(std::vector<Type> & vec);

template<typename Type>
void percolateDown(std::vector<Type> & vec, std::size_t i, std::size_t n);

template<typename Type>
void mergesort(std::vector<Type> & ves);

template<typename Type>
void mergesort(std::vector<Type> & vec, std::vector<Type> & tmp, std::size_t left, std::size_t right);

template<typename Type>
void merge(std::vector<Type> & vec, std::vector<Type> & tmp, std::size_t leftPos, std::size_t rightPos, std::size_t rightEnd);

template<typename Type>
const Type & median3(std::vector<Type> & vec, std::size_t left, std::size_t right);

template<typename Type>
std::size_t partition(std::vector<Type> & vec, std::size_t left, std::size_t right);

template<typename Type>
void quicksort(std::vector<Type> & vec, std::size_t left, std::size_t right);

#include "fastsort.cpp"

#endif //_fastsort_hpp_