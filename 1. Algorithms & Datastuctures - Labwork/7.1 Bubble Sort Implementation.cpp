/*
	Bubble Sort Implementation in C++
	Written by Hasnain Naeem
	Dated: 10/30/2018
*/

#include "pch.h" // used by visual studio
#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

#define LENG 10000 // Used in temporary arrays of algorithms. Defines limit of maximum elements which can be handled

void swap(int* elem1, int* elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

void bubbleSort(int* array, int leng) {
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
	cout << "\t-Running Bubble Sort-" << endl;

	bool flag = false;
	for (int i = 0; i < leng; i++)
	{
		for (int j = 0; j < leng - 1; j++)
		{
			if (array[j] > array[j + 1]) { //if previous is greator than next
				swap(array + j, array + j + 1); //swap them
				flag = true;
			}
			if (flag == false) //Breaking after one iteration if sorted
				break;
		}
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

	// Used these to compare time taken by written algorithm with built-in method
	//sort(array, array + 100); // Best Case
	//sort(arr, arr+n, greater<int>()); // Worst Case

	clock_t startTime = clock(); // Start counting

	cout << "_____________________________________________" << endl;
	// Sorting
	bubbleSort(array, 100); 
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