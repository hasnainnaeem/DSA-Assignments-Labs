/*
   Quicksort Implementation
   Implemented in C++
   Written by Hasnain Naeem
   Dated: 06/11/2018
*/

#include "pch.h" // used by visual studio
#include <iostream>
#include<time.h>

using namespace std;


void swap(int* elem1, int* elem2)
{
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

int quickSortSub(int* array, int start, int end) {
	int pivot = array[end];

	int i = start - 1;
	for (int j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	int newPivotIndex = i + 1;
	swap(&array[newPivotIndex], &array[end]);
	return (newPivotIndex);
}

void quickSort(int* array, int start, int end)
{
	if (start < end)
	{
		int m = quickSortSub(array, start, end);
		quickSort(array, start, m - 1);
		quickSort(array, m + 1, end);
	}
}


#define LEN 6
int main()
{
	int array[LEN];
	int j = 0;

	cout << "Before sorting: " << endl;
	// Initializing array with random values and Printing
	for (int j = 0; j < LEN; j++) {
		array[j] = rand() % 100 + 1;
		cout << array[j] << "\t";
	}
	cout << endl;

	/* Sorting and counting time */
	cout << "_____________________________________________" << endl;

	quickSort(array, 0, LEN - 1); //Calling Sorting function


	/* Printing */
	cout << endl << "Printing sorted array:" << endl;
	for (int i = 0; i < LEN; i++) {
		cout << array[i] << "\t";
	}
	getchar();
	return 0;
}
