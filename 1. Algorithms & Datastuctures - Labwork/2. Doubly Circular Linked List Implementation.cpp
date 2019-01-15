/*
Code for Doubly circular linked list in c++
Written by Hasnain Naeem
Dated: 25/09/2018 
*/
#include <iostream>
#include <string>
using namespace std;


class Node
{
public:
	int data;
	Node* next = nullptr; //stores address of next node
	Node* previous = nullptr; //Stores address of previous node

	Node(int data = 0, Node* next = nullptr, Node* previous = nullptr) { //Constructor
		this->data = data;
		this->next = next;
		this->previous = previous;
	}
	~Node(){}
};



class DoublyCircularList {
private:
	Node *head;
	Node *tail;
	size_t size;

public:

	DoublyCircularList() { //Constructor
		head = tail = nullptr;
	}
	~DoublyCircularList(){}

	void createNode(int value) {
		this->size++;
		Node *newNode = new Node(value);

		if (head == nullptr) {
			newNode->next = newNode;
			newNode->previous = newNode;

			head = newNode;
			tail = newNode;
		}

		else {
			tail->next = new Node(value, head, tail);
			tail->next->previous = tail;
			head->previous = tail->next;
			tail = tail->next;
		}
	}

	void display() {
		
		if (head == nullptr)
			return;

		Node *temp;
		temp = head;

		 do{
			cout << temp->data << "\t";
			temp = temp->next;
		 } while (temp != head);
	}


	void insert(int position, int value) {

		this->size++;

		/*
		* Inserts at given index - If given index exceeds the size of list, it inserts new node at the end.
		*/

		Node *newNode = new Node(value);
		//Iterators
		Node *previous = nullptr;
		Node *current = nullptr;

		if (head == nullptr){ //List is empty. 

			newNode->previous = newNode;
			newNode->next = newNode;
			head = newNode;
			tail = newNode;
			
			return;
		}

		if (position == 0){

			newNode->next = head;
			head->previous = newNode;

			tail->next = newNode;
			newNode->previous = tail;
			head = newNode;
		}

		else {

			current = head->next;

			for (int i = 1; i < position; i++){

				previous = current;
				current = current->next;

				if (current == nullptr){ //Given position exceeds the size of list
					//In this case node will be inserted at the end of the list.
					tail->next = newNode;
					newNode->previous = tail;
					tail = newNode;
					tail->next = head; //Making it circular
					head->previous = tail;
					return;
				} //if ends

			} //for ends

			previous->next = newNode;
			newNode->previous = previous;
			newNode->next = current;
			current->previous = newNode;
		}
	}

	void insertAtStart(int data){
		insert(0, data);
	}

	void insertAtEnd(int value){
		Node* newNode = new Node(value, head, tail);
		tail->next = newNode;
		head->previous = newNode;
		tail = newNode;
	}

	bool deleteNode(size_t position) { //Returns True when Node is deleted

		Node *previous = nullptr;
		Node* current = nullptr;
		Node *next = nullptr;

		if (head == nullptr){ //List is empty
			return false;
		}

		if (position == 0){ //Deleting first node
			current = head;
			head = head->next;
			tail->next = head;
			head->previous = tail;
			delete(current);
			this->size--;
			return true;
		}

		else {
			current = head;
			next = head->next;

			for (size_t i = 0; i < position; i++){

				previous = current;
				current = current->next;
				next = current->next;

				if (current == tail){ 
					previous->next = head;
					head->previous = previous;
					delete(current);
					this->size--;
					tail = previous;
					return true;
				} //if ends

			} //for ends


			previous->next = next;
			next->previous = previous;
			delete(current);
			this-> size--;
			return true;
		}
	}


	void deleteHead(){

		if (head == nullptr)
			return;

		deleteNode(0);
	}

	void deleteTail(){

		if (head == nullptr)
			return;

		head->previous = tail->previous;
		tail = tail->previous;
		tail->next = head;
		size--;
	}

	int access(size_t index){ //Accessing node using index

		if (index == 0){
			return head->data;
		}

		Node* iterator;
		iterator = head;

		for (size_t i = 0; i < index; i++){
			iterator = iterator->next;
		}

		return iterator->data;
	}


	size_t countNodes(){
		return size;
	}

	void PrintTail(){
		cout << tail->data << endl;
	}

	void PrintHead(){
		cout << head->data << endl;
	}
};

void makeList(DoublyCircularList* list, size_t noOfNodes){
	/*
	This function adds elements in list equal to noOfNode and value for each node is equal to its index
	*/
	int input;
	for (size_t i = 0; i < noOfNodes; i++){
		cout << "Enter element: ";
		cin >> input;
		list->createNode(input);
	}
}

void deleteGivenNode(DoublyCircularList * list){
	while (true){
		cout << endl << "Enter index (-1 to stop) for node which you want to delete: " << endl;
		int index = 0;
		cin >> index;
		if (index == -1)
			break;
		bool flag = list->deleteNode(index);
		if (flag == false){
			cout << "Could not delete! List is empty." << endl;
			return;
		}
		cout << "Node " << "at index " << index << " successfully deleted." << endl;
		cout << "New List:" << endl;
		list->display();
		cout << endl;
	}
}

int main(){
	//Making list
	DoublyCircularList list;

	bool flag = true;
	while (flag){

		int choice = -1;
		cout << "Select option:" << endl;

		cout << "\t1. Make List of given size" << endl;
		cout << "\t2. Insert at specific index" << endl;
		cout << "\t3. Insert at start" << endl;
		cout << "\t4. Insert at end" << endl;
		cout << "\t5. Display List" << endl;
		cout << "\t6. Delete Nodes" << endl;
		cout << "\t7. Delete head" << endl;
		cout << "\t8. Delete tail" << endl;
		cout << "\t9. Count number of elements in List" << endl;
		cout << "\t10. Exit" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1: //Making list
		{
			cout << endl << "\tEnter size for list: ";
			size_t size = 0;
			cin >> size;
			makeList(&list, size);
			cout << "\tList successfully created." << endl;
			break;
		}

		case 2: //Insertion
		{
			cout << endl << "\tEnter element to insert: ";
			int element = 0;
			cin >> element;
			cout << endl << "\tEnter Index: ";
			size_t position = 0;
			cin >> position;
			list.insert(element, position);
			cout << "\tElement successfully inserted." << endl;
			break;
		}

		case 3: //Insertion at head
		{
			cout << endl << "\tEnter element to insert: ";
			int element = 0;
			cin >> element;
			list.insertAtStart(element);
			cout << "\tElement successfully inserted." << endl;
			break;
		}

		case 4: //Insertion at tail
		{
			cout << endl << "\tEnter element to insert: ";
			int element = 0;
			cin >> element;
			list.insertAtEnd(element);
			cout << "\tElement successfully inserted." << endl;
			break;
		}

		case 5: //Displaying
		{
			cout << "\tDisplaying List:" << endl;
			list.display();
			cout << endl;
			break;
		}

		case 6: //Deleting using index
		{
			cout << endl << "\t\tEnter element index to delete: ";
			size_t position = 0;
			cin >> position;
			list.deleteNode(position);
			cout << "\t\tElement successfully deleted." << endl;

			break;
		}

		case 7: //Deleting head
		{
			list.deleteHead();
			break;
		}

		case 8: //Deleting tail
		{
					list.deleteTail();
			break;
		}

		case 9: //Counting nodes
		{
				  int size = list.countNodes();
				  cout << "No. of nodes: " << size << endl;
				  break;
		}

		case 10:
			flag = false; //Exiting the loop
			break;

		default:
			cout << "Wrong option input. Try Again." << endl;
			break;
		}

		cout << "_______________________" << endl;
	}
}

