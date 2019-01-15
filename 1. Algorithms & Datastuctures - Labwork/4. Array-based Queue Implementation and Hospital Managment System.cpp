
/*
     Title: Queue Implementation in C++ and Hospital Management Application
     Written by: Muhammad Hasnain Naeem
     Dated: 10/9/2018
*/

#include <iostream>
#include <time.h>
#include <string>
#include <algorithm>
using namespace std;

class Queue {
	#define LIMIT 10
	int intData[LIMIT]; //Array to store data
	
	int front; //head of queue
	int rear; //tail of queue
	size_t size;

public:
	string strData[LIMIT]; //Public data

	Queue() 
	{
		for (int i = 0; i < getLimit(); i++)
		{ 
			//Initializing string Dat
			strData[i] = "";
		}

		front = -1;
		rear = -1;		

		size = 0;
	}

public:
	bool isEmpty() 
	{
		if (front == -1)
			return true;
		return false;
	}

	bool isFull() 
	{
		if ((front == rear + 1) || (front == 0 && rear == LIMIT - 1))
			return true;
		else
			return false;
	}

	bool enqueue(int val)
	{
		if (isFull())
			return false; //Queue is full
		else
		{
			//Action
			if (rear == LIMIT - 1)
				rear = 0;
			else
				rear++;

			//Assigning value
			intData[rear] = val;

			//Updating front
			if (front == -1)
				front = 0;

			size++;
			return true; //Success
		}
	}

	int getRear() {
		return rear;
	}

	int* dequeue()
	{
		int* array = new int[2];
		int val;
		if (isEmpty())
			return nullptr; //Queue is empty

		else {
			*array = intData[front];
			*(array + 1) = front;


			if (front == rear) 
				front =- 1, rear = - 1;
			else {
				if (front == LIMIT - 1)
					front = 0;
				else
					front++;
			}
		}
		size--;
		return (array);
	}

	void displayValues() 
	{
		for (int i = front; i <= rear; i++) {
			cout << "Int Data: " << intData[i] << "\tString Data: " << strData[i] << endl;
		}
		cout << endl;
	}

	void Clear() //1 to set all elements to -1 & 2 to delete array
	{
		for (int i = 0; i < LIMIT; i++)
		{
			front = -1;
			rear = -1;
			strData[i] = "";
		}
	}

	void FirstElement()
	{
		cout << "Int Data: " << intData[rear] << "\tString Data: " << strData[rear] << endl;
	}

	int getLimit() {
		return LIMIT;
	}

};

class HospitalManagment {
	Queue queue;
	int id = -1;
public:

	void RegisterPatient()
	{
		bool flag = queue.enqueue(++id);
		if (!flag) // Assigning id to new patient
		{
			cout << "Queue is full! " << endl << endl;
			id--;
			return;
		}

		else {
			cout << endl << "Enter Your Name: ";
			char name[100];
			getchar();
			cin.get(name, 100);
			queue.strData[queue.getRear()] = string(name);
			cout << "Patient Registered with ID '" << id << "' and Name : '" << queue.strData[id] << "' registered." << endl;
		}
	}

	void ServePatient()
	{
		int* servedData = queue.dequeue();
		if (servedData !=nullptr)
		{
			cout << endl << "Serving Patient with ID '" << *servedData << "' and Name : '" << queue.strData[*(servedData+1)] << "'" << endl;
			queue.strData[*(servedData + 1)] = ""; //Removing name of served patient
		}
		else {
			cout << endl << "There no patient waiting in queue." << endl;
		}
	}

	void CancelAll()
	{
		queue.Clear();

		id = -1; //Resetting ID start for patients
	}

	bool CanDoctorGoHome() {
		if (queue.isEmpty())
			return true;
		else
			return false;
	}

	void printNames() {
		int N = sizeof(queue.strData) / sizeof(queue.strData[0]); //Get the array size

		sort(queue.strData, queue.strData + N); //Sorting names of patients

		cout << endl << "Names of Patients in Queue:" << endl;
		for (int i = 0; i < N; i++) {
			if (queue.strData[i].compare("") )
				cout << "\t" << queue.strData[i] << endl;
		}
		cout << endl;
	}

	int getLimit() {
		return queue.getLimit();
	}
	
};

int main() {
	HospitalManagment hospitalmanagment{};

	bool flag = true;
	int choice = 0;
	while (flag) {

		cout << "Select Option:" << endl;
		cout << "\t1. Register Patient" << endl;
		cout << "\t2. Serve Patient" << endl;
		cout << "\t3. Show Names of Patients" << endl;
		cout << "\t4. Cancel All Appointments" << endl;
		cout << "\t5. Check if doctor can go home" << endl;
		cout << "\t6. Exit" << endl;
		cout << "> ";
		cin >> choice;

		switch (choice) {

			case 1:
			{
				hospitalmanagment.RegisterPatient();
				break;
			}

			case 2:
			{
				hospitalmanagment.ServePatient();
				break;
			}

			case 3:
			{
				hospitalmanagment.printNames();
				break;
			}

			case 4:
			{
				hospitalmanagment.CancelAll();
				cout << "Cancelled all appointments successfully." << endl;
				break;
			}

			case 5:
			{
				if (hospitalmanagment.CanDoctorGoHome())
					cout << endl << "Yes! Doctor can go home. There are no patients in queue." << endl;
				else
					cout << endl << "No! Doctor can't go home. Patients are waiting in queue." << endl;
				break;
			}

			case 6:
			{
				flag = false;
				break;
			}

			default:
			{
				cout << "Wrong choice selected." << endl;
				break;
			}

		}
		cout << endl;
		cout << "__________________________________" << endl;
		cout << endl;

	}


	getchar();
	return 0;
}

 
  


