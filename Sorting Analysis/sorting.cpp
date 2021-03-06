#include <iostream>
#include <iomanip>
#include <cmath>
#include "sorting.h"
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
/*
* Title: Sorting and Algorithm Efficiency
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 1
* Description: This file will implement the details of the sorting algorithms in header file
*/
const int MAX_SIZE = 30000;

/* This function is helper function for some sorting algorithms that swaps the given two values
*@param x and y as the values that are wanted to be swaped
*@param moveCount as the counter of data moves
*/
void swap(int& x, int& y, int& moveCount)
{
	int temp = x;
	x = y;
	y = temp;
	moveCount += 3;
}
/*This function is helper function for selection sort algorithms that find the largest item in the array
*@param arr as the array of integers
*@param size as the size of the array
*@param compCount as the counter for data comparisons 
*@return the index of the largest element in the array
*/
int indexOfLargest(const int* arr, int size, int &compCount)
{
	int largestIndex = 0;
	for(int currIndex = 1; currIndex < size; currIndex++)
	{
		if(arr[currIndex] > arr[largestIndex])
		{
			largestIndex = currIndex;
		}
		compCount++;
	}
	return largestIndex;
}
/*This function will make the selection sort
*@param arr as the array of integers
*@param size as the size of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
	for(int last = size-1; last >= 1; --last)
	{
		//find largest element in the array
		int largest = indexOfLargest(arr, last +1, compCount);
		//swap largest item with the arr[last]
		swap(arr[largest],arr[last], moveCount);
	}
}
/*This function will make the merge sort
*@param arr as the array of integers
*@param size as the size of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
	mergeSort(arr,0,size-1,compCount,moveCount);
	
}
/*This function will make the merge sort
*@param arr as the array of integers
*@param first as the first index of the array
*@param last as the last index of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
 void mergeSort(int* arr, int first, int last, int &compCount, int &moveCount)
 {
 	if(first<last)
 	{
 		int mid = (first + last) /2;
 		mergeSort(arr,first,mid, compCount,moveCount);
 		mergeSort(arr,mid +1, last, compCount,moveCount);
 		
 		merge(arr,first,mid,last,compCount,moveCount);
	 }
 }
 /*This function will merge 
*@param arr as the array of integers
*@param first as the first index of the array
*@param mid as the middle index of the array
*@param last as the last index of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
 void merge(int *arr, int first, int mid, int last, int& compCount,int& moveCount)
 {
 	int tempArray[MAX_SIZE]; 
 	int first1 = first;
 	int last1 = mid;
 	int first2 = mid +1;
 	int last2 = last;
 	int index = first1;
 	
 	for(;(first1 <= last1)&&(first2 <= last2); ++index)
 	{
 		if(arr[first1] < arr[first2])
 		{
 			tempArray[index] = arr[first1];
 			first1++;
 			moveCount++; //data move
		}
		else{
			tempArray[index] = arr[first2];
			first2++;
			moveCount++;//data move
		}
		compCount++; //increment comparision by one
	}
	for(; first1 <= last1; ++first1,++index)
	{
		tempArray[index] = arr[first1];
		moveCount++; //data move
	}
	for(; first2 <= last2; ++first2,++index)
	{
		tempArray[index] = arr[first2];
		moveCount++; //data move
	}
	for(index = first; index <= last; ++index)
	{
		arr[index] = tempArray[index];
		moveCount++; //data move
	}
 }
/*This function will make the quick sort
*@param arr as the array of integers
*@param size as the size of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
void quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
	quickSort(arr,0,size-1,compCount,moveCount);
}
/*This function will make the quick sort
*@param arr as the array of integers
*@param first as the first index of the array
*@param last as the last index of the array
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
void quickSort(int *arr,int first, int last, int &compCount, int &moveCount)
{
	int pivotIndex;
	if(first < last)
	{
		partition(arr, first,last, pivotIndex, compCount, moveCount);
		quickSort(arr, first,pivotIndex-1, compCount, moveCount);
		quickSort(arr, pivotIndex+1, last, compCount, moveCount);
	}
}
/*This function will make partition for quick sort
*@param arr as the array of integers
*@param first as the first index of the array
*@param last as the last index of the array
*@param pivotIndex 
*@param compCount as the counter for data comparisons 
*@param moveCount as the counter of data moves
*/
void partition(int* arr, int first, int last,int& pivotIndex,int& compCount, int& moveCount )
{
	int pivot = arr[first];
	moveCount++;
	int lastS1 = first;
	int firstUnknown = first +1;
	
	for(; firstUnknown <= last; ++ firstUnknown){
		if(arr[firstUnknown] < pivot){
			lastS1++;
			swap(arr[firstUnknown],arr[lastS1],moveCount);
		}
		compCount++;
	}
	swap(arr[first],arr[lastS1],moveCount);
	pivotIndex = lastS1;
}
/* This function will make the radix sort
*@param arr as the array of integers
*@param size of the array
*/
void radixSort(int *arr, const int size)
{
	//find the max num of d in the given array
	int compCount = 0;  
	int index = indexOfLargest(arr,size, compCount);//O(n)
	int largest = arr[index];
	int d = 0;
	for(; largest != 0; largest = largest/10,d++);
	for( int j = 0; j < d; j++)
	{
		//Initialize 10 groups to empty
		int groups [10][size]; 
		//Initialize a counter for each group to 0
		int counters[10] = {0,0,0,0,0,0,0,0,0,0};
		for(int i = 0; i < size; i++)
		{
			//get the the digit
			int k = arr[i] / pow(10,j);
			k = k % 10;
			// Place arr[i] at the end of group k
			groups[k][counters[k]] = arr[i];
			counters[k] = counters[k] + 1;
		}
		//Replace the items in arr 
		for(int i = 0, indx = 0; i <10; i++)
		{
			for(int n = 0; n < counters[i]; n++)
			{
				arr[indx] = groups[i][n];
				indx++;
			}
		}
	}	
}
//auxiliary global functions
/* This function unction displays the array items on the screen. 
* @param arr as the array of integers
* @param size  
*/
void displayArray(const int *arr, const int size)
{
	cout<<"[ ";
	for(int i = 0; i < size; i ++)
	{
		cout<< arr[i] << "\t";
	}
	cout<<" ]"<<endl;	
}
/*This function will create four identical array with unordered numbers
*@param arr1, arr2, arr3 and arr4 as arrays which will to be created
*@param size of these arrays
*/
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
	int interval = 100000;
	srand(4*time(0));
	for(int i = 0; i < size; i ++)
	{
		int num = rand() % interval;
		arr1[i] = num;
		arr2[i] = num;
		arr3[i] = num;
		arr4[i] = num;
	}	
}
/*This function will create four identical array with ascending order
*@param arr1, arr2, arr3 and arr4 as arrays which will to be created
*@param size of these arrays
*/
void createAscendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
	int compCount,moveCount = 0;
	//create random array
	createRandomArrays(arr1, arr2, arr3, arr4, size);
	//sort them
	mergeSort(arr1,size,compCount,moveCount);
	mergeSort(arr2,size,compCount,moveCount);
	mergeSort(arr3,size,compCount,moveCount);
	mergeSort(arr4,size,compCount,moveCount);
}
/*This function will create four identical array with descending order
*@param arr1, arr2, arr3 and arr4 as arrays which will to be created
*@param size of these arrays
*/
void createDescendingArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
	createAscendingArrays(arr1,arr2,arr3,arr4,size);
	//reverse them
	for(int i = 0; i <size;i++)
	{
		arr2[i] = arr1[size-1-i];
		arr3[i] = arr1[size-1-i];
		arr4[i] = arr1[size-1-i];
	}
	for(int i = 0; i <size; i++)
	{
		arr1[i] = arr2[i];
	}
	
}
/*
*This function will show th performance analysis of the selection, merge , quick and radix sorts
*/
void performanceAnalysis()
{
	//4 array 
	int size[] = {6000,10000,14000,18000,22000,26000,30000};
	// for random arrays
	cout<<"Random numbers"<<endl;
	int* arr[28];
	for(int i = 0; i <7;i++)
	{
		//create arrays with sizes
		arr[4*i] = new int[size[i]];
		arr[4*i+1] = new int[size[i]];
		arr[4*i+2]= new int[size[i]];
		arr[4*i+3]= new int[size[i]];
		//make them random Arrays
		createRandomArrays(arr[4*i], arr[4*i+1], arr[4*i+2],arr[4*i+3], size[i]);			
	}
				
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Selection Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			selectionSort(arr[4*i],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Merge Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			mergeSort(arr[4*i+1],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Quick Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			quickSort(arr[4*i+2],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Radix Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<endl;
		for(int i = 0; i <7; i++)
		{		
			auto start = std::chrono::high_resolution_clock::now();
			radixSort(arr[4*i+1],size[i]);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<<endl;
		}
		//delete for memleak
		for(int i = 0; i <7;i++)
		{
			//create arrays with sizes
			delete [] arr[4*i];
			delete []arr[4*i+1];
			delete []arr[4*i+2];
			delete []arr[4*i+3];	
		}
		
		//For ascending arrays	
		cout<<"****************************"<<endl;
		cout<<"Ascending numbers"<<endl;
		for(int i = 0; i <7;i++)
		{
			//create arrays with sizes
			arr[4*i] = new int[size[i]];
			arr[4*i+1] = new int[size[i]];
			arr[4*i+2]= new int[size[i]];
			arr[4*i+3]= new int[size[i]];
			//make them random Arrays
			createAscendingArrays(arr[4*i], arr[4*i+1], arr[4*i+2],arr[4*i+3], size[i]);		
		}
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Selection Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			selectionSort(arr[4*i],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Merge Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			mergeSort(arr[4*i+1],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Quick Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			quickSort(arr[4*i+2],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Radix Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<endl;
		for(int i = 0; i <7; i++)
		{		
			auto start = std::chrono::high_resolution_clock::now();
			radixSort(arr[4*i+1],size[i]);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<<endl;
		}
		//delete for memleak
		for(int i = 0; i <7;i++)
		{
			//create arrays with sizes
			delete [] arr[4*i];
			delete []arr[4*i+1];
			delete []arr[4*i+2];
			delete []arr[4*i+3];	
		}
		//For descending arrays	
		cout<<"****************************"<<endl;
		cout<<"Descending numbers"<<endl;
		for(int i = 0; i <7;i++)
		{
			//create arrays with sizes
			arr[4*i] = new int[size[i]];
			arr[4*i+1] = new int[size[i]];
			arr[4*i+2]= new int[size[i]];
			arr[4*i+3]= new int[size[i]];
			//make them random Arrays
			createDescendingArrays(arr[4*i], arr[4*i+1], arr[4*i+2],arr[4*i+3], size[i]);			
		}
		
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Selection Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			selectionSort(arr[4*i],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Merge Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			mergeSort(arr[4*i+1],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	 
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Quick Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<setw(15)<<"compCount"<<setw(15)<<"moveCount"<<endl;
		for(int i = 0; i <7; i++)
		{		
			int compCount = 0;
			int moveCount = 0;
			auto start = std::chrono::high_resolution_clock::now();
			quickSort(arr[4*i+2],size[i],compCount,moveCount);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<< setw(15)<<compCount<<setw(15)<<moveCount<<endl;
		}	
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"Analysis of Radix Sort"<<endl;
		cout<<"Array Size"<<setw(15)<<"Elapsed time"<<endl;
		for(int i = 0; i <7; i++)
		{		
			auto start = std::chrono::high_resolution_clock::now();
			radixSort(arr[4*i+1],size[i]);
			auto finish = std::chrono::high_resolution_clock::now();
    		std::chrono::duration<double> elapsed = finish - start;
    		cout<<size[i]<<setw(15)<<elapsed.count()<<" ms"<<endl;
		}
		//delete for memleak
		for(int i = 0; i <7;i++)
		{
			//create arrays with sizes
			delete [] arr[4*i];
			delete []arr[4*i+1];
			delete []arr[4*i+2];
			delete []arr[4*i+3];	
		}
		
		
}




