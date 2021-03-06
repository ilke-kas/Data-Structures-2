#ifndef _SORTING_H
#define _SORTING_H
#include <iostream>
/*
* Title: Sorting and Algorithm Efficiency
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 1
* Description: This header will contain the prototypes of selectionSort, mergeSort, quickSort and radixSort
*/
	//added prototypes by me
	void partition(int* arr, int first, int last,int& pivotIndex,int& compCount, int& moveCount );
	void quickSort(int *arr,int first, int last, int &compCount, int &moveCount);
	void mergeSort(int* arr, int first, int last,int &compCount, int &moveCount);
	void merge(int *arr, int first, int mid, int last, int& compCount,int& moveCount);	
	int indexOfLargest(const int* arr, int size, int &compCount);
	void swap(int& x, int& y, int& moveCount);
	//given prototypes
	void selectionSort(int *arr, const int size, int &compCount, int &moveCount);
	void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
	void quickSort(int *arr, const int size, int &compCount, int &moveCount);
	void radixSort(int *arr, const int size);
	//auxiliary global functions
	void displayArray(const int *arr, const int size);
	void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
	void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
	void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);	
	//performanceAnalysis function
	void performanceAnalysis();
#endif 
