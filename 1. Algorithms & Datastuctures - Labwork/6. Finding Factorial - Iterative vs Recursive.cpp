/* 
Factorial calculator (Iterative, Recursive) along with running time calculator.
*/

#include <iostream>
#include <time.h>
using namespace std;

unsigned long long factorial(size_t n) {
	if (n < 0) //wrong input case
		return -1;

	if (n == 1 || n == 0)
		return 1;
	unsigned long long total = 1;
	for (int i = 1; i <= n; i++) {
		total = i * total;
	}
	return total;
}


unsigned long long factorialRecur(size_t n) {
	if (n == 0 || n == 1)
		return 1;
	else if (n < 0)
		return -1; //Wrong input case
	else
		return n * factorialRecur(n - 1);
}

int main() {
	cout << "\t\tFactorial Calculator\n";

	while (true) {

		//input number
		size_t num;
		cout << "Enter Number:\t";
		cin >> num;

		//selection code
		int choice;
		cout << "Select:" << endl;
		cout << "1. Find factorial using recursion " << endl;
		cout << "2. Find factorial using loops " << endl;
		cout << "> ";
		cin >> choice;

		//starting time count
		clock_t startTime = clock();

		switch (choice) {
		case 1:
		{
			cout << "Factorial of " << num << " using recursion" << "\t";
			cout << factorialRecur(num) << endl;
			cout << "Time taken:\t";
			cout << 1000 * (clock() - startTime) / double(CLOCKS_PER_SEC);
			break;
		}
		case 2:
		{
			cout << "Factorial of " << num << " using loops" << "\t";
			cout << factorial(num) << endl;
			cout << "Time taken:\t";
			cout << 1000 * (clock() - startTime) / double(CLOCKS_PER_SEC);
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
	return 0;
}
