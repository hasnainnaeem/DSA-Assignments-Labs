/*
	Sorting Algorithms (Bubble sort, selection sort, insertion sort, merge sort)
	Implemented in C++
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
	for (int i = 0, j; i < leng; i++)
	{
		curr = array[i];
		j = i - 1;
		while (0 <= j && curr < array[j]) //Move elements forward
			//until correct position is found for current element
		{
			array[j + 1] = array[j];
			j = j - 1;
		}

		array[j + 1] = curr; //place correct element at correct location in sub array
	}
}

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