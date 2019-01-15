/*
   Radix Sort Implementation in C++
   Written by Hasnain Naeem
   Dated: 11/13/2018
*/

#include "pch.h" // used by visual studio
#include <iostream>
#include <time.h>
#include <algorithm>
#include <queue>

using namespace std;


void radixSort(long* array, int n)
{
	register int d, j, k, factor;
	const int radix = 10;
	const int digits = 10;
	queue<long> queues[radix];

	for (d = 0, factor = 1; d < digits; factor *= radix, d++)
	{
		for (j = 0; j < n; j++)
			queues[(array[j] / factor) % radix].push(array[j]); // Pushing each digit of each number from right to left into queue

		for (j = k = 0; j < radix; j++) { // Sorting from right to left
			while (!queues[j].empty()) {
				array[k++] = queues[j].front();
				queues[j].pop();
			}
		}
	}
}

void initBestCase(long* array, int len)
{
	// Initializes each slot with 0 - len-1 number range
	for (long j = 0; j < len; j++) {
		array[j] = j;
	}
}

void initAverageCase(long* array, int len)
{
	// Initializes each slot with 0 - len-1 number range
	for (long j = 0; j < len; j++) {
		array[j] = (rand() % 100); // random number less than 100
	}
}

void initWorstCase(long* array, int len)
{
	// Initializes each slot with len -1 to 0 number range
	for (long j = len - 1; j >= 0; j--) {
		array[j] = j;
	}
}

void printArray(long* array, int len)
{
	for (int j = 0; j < len; j++) {
		cout << array[j] << "\t";
	}
}

#define LEN 200000
int main()
{

	cout << "Enter length of array:" << endl;
	int leng = 0;
	cin >> leng;
	cout << endl;

	long array[LEN];
	while (true) {

		int menuOption = 0;

		while (menuOption > 6 || menuOption < 1) //This loop can exit program
		{
			cout << "\t*****************************************************************" << endl;
			cout << "\t* Select Option:\t\t\t\t\t\t*" << endl;
			cout << "\t*\t1. Initialize with best case values\t\t\t*" << endl;
			cout << "\t*\t2. Initialize with average case values\t\t\t*" << endl;
			cout << "\t*\t3. Initialize with worst case values\t\t\t*" << endl;
			cout << "\t*\t4. Sort array using Radix Sort\t\t\t\t*" << endl;
			cout << "\t*\t5. Print Array\t\t\t\t\t\t*" << endl;
			cout << "\t*\t6. Exit\t\t\t\t\t\t\t*" << endl;
			cout << "\t******************************************************************" << endl;

			cout << "> ";
			cin >> menuOption;

			if (menuOption == 6) {
				return 0; //Exiting
			}


			switch (menuOption)
			{
			case 1:
			{
				initBestCase(array, leng);
				break;
			}
			case 2:
			{
				initAverageCase(array, leng);
				break;
			}
			case 3:
			{
				initWorstCase(array, leng);
				break;
			}

			case 4: // Radix Sort
			{
				
				clock_t startTime = clock(); // Start counting time
				radixSort(array, leng);
				cout << endl << "Time Taken during Sorting:" << endl;
				cout << 1000 * double(clock() - startTime) / (double)CLOCKS_PER_SEC << " ms" << endl; // Stop counting
				break;
			}

			case 5:
			{

				printArray(array, leng);
				break;
			}
			}
		}

	}

	getchar();
	return 0;
}


