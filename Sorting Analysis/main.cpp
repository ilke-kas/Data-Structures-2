#include <iostream>
#include "sorting.h"
using namespace std;
/*
* Title: Sorting and Algorithm Efficiency
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 1
* Description: This main function will run selectionSort, mergeSort, quickSort and radixSort
*/
int main()
{
	//Selection Sort
	int compCount = 0;
	int moveCount = 0;
	int array[] =  {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	cout<<"Selection Sort: "<<endl;
	selectionSort(array,16,compCount,moveCount);
	cout<<"Number of key comparisons: "<< compCount<<endl;
	cout<<"Number of data moves: "<< moveCount<<endl;
	displayArray(array,16);
	//Merge Sort
	compCount = 0;
	moveCount = 0;
	int array1[] =  {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	cout<<"Merge Sort: "<<endl;
	mergeSort(array1,16,compCount,moveCount);
	cout<<"Number of key comparisons: "<< compCount<<endl;
	cout<<"Number of data moves: "<< moveCount<<endl;
	displayArray(array1,16);
	//Quick Sort
	compCount = 0;
	moveCount = 0;
	int array2[] =   {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	cout<<"Quick Sort: "<<endl;
	quickSort(array2,16,compCount,moveCount);
	cout<<"Number of key comparisons: "<< compCount<<endl;
	cout<<"Number of data moves: "<< moveCount<<endl;
	displayArray(array2,16);
	//Radix Sort
	compCount = 0;
	moveCount = 0;
	int array3[] =  {12, 7, 11, 18, 19, 9, 6, 14, 21, 3, 17, 20, 5, 12, 14, 8};
	cout<<"Radix Sort: "<<endl;
	radixSort(array3,16);
	displayArray(array3,16);
//performance analysis
	performanceAnalysis();

	
}
