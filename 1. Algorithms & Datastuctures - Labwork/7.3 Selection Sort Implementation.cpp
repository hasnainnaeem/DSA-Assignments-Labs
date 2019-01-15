/*
	Selection Sort Algorithm Implementation in C++
	Written by Hasnain Naeem
	Dated: 10/30/2018
*/
#include "pch.h" // used by visual studio
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

#define LENG 10000 // Used in temporary arrays of algorithms. Defines limit of maximum elements which can be handled


void selectionSort(int* array, int leng)
{
	/*
	Complexity for Comparisons
		Average: n^2
		Best: n^2
		Worst: n^2
	Complexity for Swaps
		Average: n
		Best: n
		Worst: n
	*/
	cout << "\t-Running Selection Sort-" << endl;

	int smallest; //to save index of smallest number in each iteration
	for (int i = 0, j; i < leng; i++)
	{
		smallest = i;
		for (j = i + 1; j < leng; j++) //finding smallest in unsorted array
		{
			if (array[j] < array[smallest])
			{
				smallest = j;
			}
		}
		swap(array + i, array + smallest); //Place smallest on left side
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
	selectionSort(array, 100); 
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