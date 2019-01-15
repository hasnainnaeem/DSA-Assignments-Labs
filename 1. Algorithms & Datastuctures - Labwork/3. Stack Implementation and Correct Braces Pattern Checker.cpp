/*
Array based stack implementation using C++
Correct braces pattern checker - Stack Application

Written by: M. Hasnain Naeem
*/

#include <stdio.h>
#include "pch.h"
#include <iostream>
using namespace std;

class Stack {
	static int const CAPACITY = 100;
private:
	char charArr[CAPACITY];
	char* top = charArr;
	int currSize = 0;
public:
	bool isEmpty() {
		if (currSize == 0)
			return true;
		return false;
	}

	char pop() {
		if (currSize == 0) // stack is empty.
			return '\0';
		char retValue = charArr[currSize - 1];
		currSize--;
		return retValue;
	}

	bool push(char value) {
		if (currSize == CAPACITY) // Can not push if stack is full
			return false; // failed to push
		charArr[currSize] = value;
		currSize++;
		return true; // successfully pushed
	}

	char getTop() {
		return charArr[currSize - 1];
	}
};

#include <iostream>
#include <stdio.h>
#include "pch.h"
using namespace std;

int main() {

	int const SIZE = 100;
	char input[SIZE];

	//Taking input
	cout << "Enter mathematical expression to check for correct braces placement:" << endl;

	char ch;
	int i = 0;
	while (true) {  //Character by character input until enter is pressed

		ch = getchar();

		if (ch == '\n') {
			input[i] = '\0';
			break;
		}

		input[i] = ch;
		i++;
	}
	int numOfChars = i;
	//Game begins from here
	Stack stack1;

	char openingBraces[] = { '[', '{', '('};
	char closingBraces[] = { ']', '}', ')' };

	for (int j = 0; j < numOfChars; j++) {
		//Checking if opening brace
		for (int k = 0; k <= 2; k++) {

			// push into stack if opening brace
			if (input[j] == openingBraces[k]) {
				stack1.push(input[j]);
			}
		}

		//Checking if closing brace
		for (int k = 0; k <= 2; k++) {
			// pop from stack if closing brace and it matches last brace
			if (input[j] == closingBraces[k]) {
				if((input[j] == ')' && stack1.getTop() == '(') ||
					(input[j] == '}' && stack1.getTop() == '{') ||
					(input[j] == ']' && stack1.getTop() == '['))
					stack1.pop();
			}
		}
	}

	if (stack1.isEmpty())
		cout << "Correct expression!" << endl;
	else
		cout << "Incorrect expression!" << endl;

	getchar();
	return 0;
}




