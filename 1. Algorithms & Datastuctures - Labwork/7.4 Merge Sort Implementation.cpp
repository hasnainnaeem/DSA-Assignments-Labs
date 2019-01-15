/*
	Merge Sort Algorithm
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


/*
	* Merge Sort Algorithm uses 2 functions given below
	* Complexity of merge sort is (log n) * n
	* Space complexity: N
	*/
void merge(int* array, int start, int mid, int end) {
	/*
		* Time Complexity of this method is N
		* There are no swaps
		*/
	int tempArr[LENG];

	int i = start; //for left part of array
	int j = mid + 1; //for right part of array
	int k = 0; //for temp array
	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
		{
			tempArr[k] = array[i];
			i++;
			k++;
		}
		else {
			tempArr[k] = array[j];
			j++;
			k++;
		}
	}

	while (i <= mid) {
		tempArr[k] = array[i];
		i++;
		k++;
	}

	while (j <= end) {
		tempArr[k] = array[j];
		j++;
		k++;
	}

	// Assign sorted data stored in temp[] to array[]
	for (i = start; i <= end; i++)
	{
		array[i] = tempArr[i - start];
	}
}

void mergeSort(int* array, int start, int end) {
	/*
		* Complexity of this part is log n
		*/
	int mid;

	if (start < end) { //dividing array until there's 1 element in each array
		mid = (start + end) / 2; //to divide array into two parts

		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);

		merge(array, start, mid, end); //merging and sorting subarrays
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
	mergeSort(array, 100); 
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