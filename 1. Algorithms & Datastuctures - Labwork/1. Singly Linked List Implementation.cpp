/*
Written by: Muhammad Hasnain Naeem
Dated: September, 2018
Description: 
Implementation of Linked Lists using C++ 
*/
#include <iostream>

using namespace std;


class Node
{
public:
    int data;
    Node* next = nullptr; //stores address of next node

    Node(int data = 0, Node* ref = nullptr) { //Constructor
        this->data = data;
        this->next = ref;
    }
    ~Node(){}
};



class SinglyLinkedList {
private:
    Node *head;
    Node *tail;
    size_t size;

public:

    SinglyLinkedList() { //Constructor
        head = nullptr;
        tail = nullptr;
    }
    ~SinglyLinkedList(){}

    void createNode(int value) {
        Node *temp = new Node(value);
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        Node *temp;
        temp = head;

        while (temp != nullptr) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }


    void insert(int position, int value) {

        /*
        * Inserts at given index - If given index exceeds the size of list, it inserts new node at the end.
        */

        Node *newNode = new Node(value);
        Node *previous = nullptr;
        Node *current = nullptr;

        if (head == nullptr){

            head = newNode;
            tail = newNode;
            return;

        }

        if (position == 0){
            newNode->next = head;
            head = newNode;
        }
        else {

            current = head->next;

            for (int i = 0; i < position; i++){

                previous = current;
                current = current->next;

                if (current == nullptr){ //Given position exceeds the size of list
                    //In this case node will be inserted at the end of the list.
                    tail->next = newNode;
                    tail = newNode;
                    return;
                } //if ends

            } //for ends

            previous->next = newNode;
            newNode->next = current;
        }
    }

    void insertAtStart(int data){
        insert(0, data);
    }

    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        Node *previous = nullptr;
        Node *current = nullptr;

        if (head == nullptr){

            head = newNode;
            tail = newNode;
            return;

        }

        else {

            current = head->next;

            while (true){
                previous = current;
                current = current->next;
                if (current == nullptr){ //Given position exceeds the size of list
                    //In this case node will be inserted at the end of the list.
                    tail->next = newNode;
                    tail = newNode;
                    return;
                } //if ends

            } //while ends

        }
    }

    bool deleteNode(size_t position) {

        Node *previous = nullptr;
        Node* current = nullptr;
        Node *next = nullptr;

        if (head == nullptr){ //List is empty
            return false;
        }

        if (position == 0){ //Deleting first node
            current = head;
            head = head->next;
            delete(current);
            return true;
        }
        else {
            current = head;
            next = head->next;

            for (size_t i = 0; i < position; i++){

                previous = current;
                current = current->next;
                next = current->next;

                if (next == nullptr){ //Given position exceeds the size of list
                    //This means that given value index can not be deleted
                    previous->next = nullptr;
                    delete(current);
                    tail = previous;
                    return true;
                } //if ends

            } //for ends


            previous->next = next;
            delete(current);
            return true;
        }
    }


    void deleteHead(){
        deleteNode(0);
    }

    void deleteTail(){

        Node *previous = nullptr;
        Node *current = nullptr;

        if (head == nullptr){ //List is empty
            return;
        }

        else {

            current = head->next;

            while (true){

                previous = current;
                current = current->next;

                if (current->next == nullptr){
                    previous->next = nullptr;
                    tail = previous;
                    delete(current);
                    return;
                } //if ends

            } //while ends
        }
    }

    bool deleteElement(int item){

        /*
       * Deletes first occurrence of given number and Returns True. Returns False if given number was not found.
       */

        Node* previous = head;
        Node* iterator = previous->next;

        if (head->data == item){
            iterator = head;
            delete(head);
            head = iterator->next;
            return true;
        }

        while(iterator != nullptr){

            if(iterator->data == item){
                if(iterator == tail) {
                    previous->next = nullptr;
                    tail = previous;
                }
                else
                    previous->next = iterator->next;
                delete(iterator);
                return true; //Returns true if item is deleted
            }

            previous = iterator;
            iterator = iterator->next;
        }
        return false;
    }

    int access(size_t index){

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

    void destroy(){
        Node* temp = nullptr;
        Node* current = head;

        if (head == nullptr)
            return; //list is empty

        while (true){
            if (current == nullptr)
                break;
            temp = current;
            current = current->next;
            cout << "Deleting " << temp->data << endl;
            delete(temp);
        }

        head = tail = nullptr;
    }

    size_t countNodes(){
        this->size = 0;
        Node *temp;
        temp = head;

        while (temp != nullptr) {
            this->size++;
            temp = temp->next;
        }

        return size;
    }

};

void makeList(SinglyLinkedList* list, size_t noOfNodes){
    /*
    This function adds elements in list equal to noOfNode and value for each node is equal to its index
    */
    for (size_t i = 0; i < noOfNodes; i++){
        list->createNode(i);
    }
}

void deleteGivenNode(SinglyLinkedList * list){
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
    SinglyLinkedList list;

    bool flag = true;
    while (flag){

        int choice = -1;
        cout << "Select option:" << endl;

        cout << "\t1. Make List of given size" << endl;
        cout << "\t2. Insert into List" << endl;
        cout << "\t3. Display List" << endl;
        cout << "\t4. Delete Nodes" << endl;
        cout << "\t5. Count number of elements in List" << endl;
        cout << "\t6. Exit" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                cout << endl << "\tEnter size for list: ";
                size_t size = 0;
                cin >> size;
                makeList(&list, size);
                cout << "\tList successfully created." << endl;
                break;
            }
            case 2:
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

            case 3:
            {
                cout << "\tDisplaying List:" << endl;
                list.display();
                cout << endl;
                break;
            }

            case 4:
            {
                int deleteChoice = 1;
                cout << "\tSelect Option:" << endl;
                cout << "\t\t1. Delete using index input" << endl;
                cout << "\t\t2. Delete using element input" << endl;
                cin >> deleteChoice;
                switch(deleteChoice){
                    case 1: {
                        cout << endl << "\t\tEnter element index to delete: ";
                        size_t position = 0;
                        cin >> position;
                        list.deleteNode(position);
                        cout << "\t\tElement successfully deleted." << endl;
                        break;
                    }
                    case 2: {
                        cout << endl << "\t\tEnter element to delete: ";
                        int element = 0;
                        cin >> element;
                        bool flag = list.deleteElement(element);
                        if (flag == true)
                            cout << "\t\tElement successfully deleted." << endl;
                        else
                            cout << "\t\tCould not delete as element wasn't found inside list." << endl;
                        break;
                    }
                    default:
                        cout << "\t\tWrong choice input." << endl;
                        break;
                }
                break;
            }

            case 5:
            {
                int size = list.countNodes();
                cout << "No. of nodes: " << size << endl;
                break;
            }
            case 6:
                flag = false; //Exiting the loop
                break;

            default:
                cout << "Wrong option input. Try Again." << endl;
                break;
        }
        cout << "_______________________" << endl;
    }
}

Task 1 Output Screenshot:
 
 
 
 
