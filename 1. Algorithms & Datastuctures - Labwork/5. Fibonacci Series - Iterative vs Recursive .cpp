/*
Fibonacci series calculator (iterative and recursive) along with running time calculator.
Written by: M. Hasnain Naeem
*/

#include <iostream>
#include <time.h>
using namespace std;

long fibonacci(size_t n) {
	int first = 0, second = 1, sum, i;
	if (n == 0)
		return first;
	for (i = 2; i <= n; i++)
	{
              //each number in series is sum of previous two numbers
		sum = first + second;
		first = second;
		second = sum;
	}
	return second;
}


long fibonacciRecur(size_t n) {
	if (n == 0 || n == 1)
		return n;
	else if (n < 0)
		return -1; //Wrong input case
	else
		return fibonacciRecur(n - 1) + fibonacciRecur(n - 2);
}

int main() {
	cout << "\t\tNth Fibonacci Number Calculator\n";

	while (true) {
		//input number
		size_t num;
		cout << "Enter Number:\t";
		cin >> num;

		//selection code
		int choice;
		cout << "Select:" << endl;
		cout << "1. Find nth fibonacci number using recursion " << endl;
		cout << "2. Find nth fibonacci number using loops " << endl;
		cout << "> ";
		cin >> choice;

		//starting time count
		clock_t startTime = clock();

		//calculating fibonacci
		switch (choice) {
		case 1:
		{
			cout << "Nth Fibonacci Number using Recursion:\t";
			cout << fibonacciRecur(num) << endl;
			cout << "Time taken:\t";
			cout << 1000 * double(clock() - startTime) / double(CLOCKS_PER_SEC);
			break;
		}
		case 2:
		{
			cout << "Nth Fibonacci Number using Loops:\t";
			cout << fibonacci(num) << endl;
			cout << "Time taken:\t";
			cout << 1000 * double(clock() - startTime) / double(CLOCKS_PER_SEC);
			break;
		}
		default:
			cout << "Wrong selection input." << endl;
		}

		//Running again code
		cout << endl << endl << "Run again? (y/n)" << endl;
		char exitChoice;
		cin >> exitChoice;

		if (exitChoice == 'n')
			break;
		cout << "___________________________" << endl;
	}
	getchar();
	getchar();
	return 0;
}
