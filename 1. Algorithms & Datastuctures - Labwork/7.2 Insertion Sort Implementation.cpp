/*
	Insertion Sort Algorithm
	Implemented in C++
	Written by Hasnain Naeem
	Dated: 10/30/2018
*/
#include "pch.h" // used by visual studio compiler
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

#define LENG 10000 // Used in temporary arrays of algorithms. Defines limit of maximum elements which can be handled

void insertionSort(int* array, int leng)
{
	/*
	Complexity for Comparisons
		Average: n^2
		Best: n
		Worst: n^2
	Complexity for Swaps
		Average: n^2
		Best: 1
		Worst: n^2
	*/
	cout << "\t-Running insertion Sort-" << endl;

	int curr;
	for (int i = 1, j; i < leng; i++)
	{
		curr = array[i];
		j = i - 1;
		while (0 <= j && curr < array[j]) //Move elements forward
			//until correct position is found for current element
		{
			array[j + 1] = array[j];
			j = j - 1;
		}

		array[j + 1] = curr; //place element at correct location in sub array
	}
}

int main()
{
	int array[100];
	int j = 0;

	cout << "Before sorting: " << endl;

	// Initializing array with worst case values
	for (int j = 0; j < 100; j++) {
		array[j] = rand() % 100 + 1;
		cout << array[j] << "\t"; // Priting value
	}
	cout << endl;

	/* Sorting and counting time */

	// Used these to compare time taken by written algorithms with built-in method
	//sort(array, array + 100); // Best Case
	//sort(arr, arr+n, greater<int>()); // Worst Case

	clock_t startTime = clock(); // Start counting

	cout << "_____________________________________________" << endl;
	// Sorting
	insertionSort(array, 100); 
	cout << endl << "Time Taken during Sorting:" << endl;
	cout << 1000 * (double(clock() - startTime) / (double)CLOCKS_PER_SEC) << endl;
	cout << "_____________________________________________" << endl;

	// Printing array
	cout << "After Sorting:" << endl;
	for (int j = 0; j < 100; j++) {
		cout << array[j] << "\t";
	}
	cout << endl;

	getchar();
	return 0;
}
