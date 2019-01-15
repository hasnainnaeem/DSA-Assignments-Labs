/*
Binary Search Tree implementation in C++
Written by: Muhamamd Hasnain Naeem
Dated: 11/20/2018
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	struct tree_node {
		tree_node* left;
		tree_node* right;
		int data;
	};

public:
	tree_node* root;

	BinarySearchTree() {
		root = nullptr;
	}
	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);

	tree_node* remove(int d, tree_node* node) {
		//First locate the element, if the element is not found, simply generate an error message
		// Then there will be three cases in removing d. Code accordingly
		// 1. Removing a leaf node
		// 2. Removing a node with a single child
		// 3. Removing a node with 2 children, then adjust its parents and grand children links 

		if (node == nullptr)
			return nullptr;

		else if (d < node->data)
		{
			node->left = remove(d, node->left);
			return node;
		}

		else if (d > node->data)
		{
			node->right = remove(d, node->right);
			return node;
		}


		else if (d == node->data)
		{
			// case 1
			if (node->left == nullptr) {
				return node->right;
			}

			// case 2
			else if (node->right == nullptr)
			{
				return node->left;
			}

			// case 3 -> further it has 2 cases
			else
			{
				node->right == lift(node->right, node);
				return node;
			}
		}
	}

	tree_node* lift(tree_node* node, tree_node* nodeToDelete)
	{
		// case 1
		if (node->left)
		{
			node->left = lift(node->left, nodeToDelete);
			return node;
		}
		// case2
		else
		{
			nodeToDelete->data = node->data;
			return node->right;
		}
	}

};


void BinarySearchTree::insert(int d) {

	tree_node* t = new tree_node;
	tree_node* parent = root;
	t->data = d;
	t->left = nullptr;
	t->right = nullptr;

	if (root == nullptr) {
		root = t;
		return;
	}

	// Smaller elements should go to the left, whereas larger  elements should go to the right
	else {
		while (true)
		{
			if (parent->data < d)
			{
				if (parent->right == nullptr) {
					parent->right = t;
					break;
				}
				else parent = parent->right;
			}
			else if (parent->data >= d)
			{
				if (parent->left == nullptr) {
					parent->left = t;
					break;
				}
				else parent = parent->left;
			}
		}

	}
}




void BinarySearchTree::print_inorder() {
	inorder(root);
	cout << endl;
}

void BinarySearchTree::inorder(tree_node* p) {
	if (p != nullptr)
	{
		inorder(p->left);
		cout << p->data << "\t";
		inorder(p->right);
	}
}


void BinarySearchTree::print_preorder() {
	preorder(root);
	cout << endl;
}

void BinarySearchTree::preorder(tree_node* p) {
	if (p != nullptr)
	{
		cout << p->data << "\t";
		inorder(p->left);
		inorder(p->right);
	}
}

void BinarySearchTree::print_postorder() {
	postorder(root);
	cout << endl;
}

void BinarySearchTree::postorder(tree_node* p) {
	if (p != nullptr)
	{
		inorder(p->left);
		inorder(p->right);
		cout << p->data << "\t";
	}
}

void insertIntoTree(BinarySearchTree* b) {
	cout << "How many elements do you want to insert?" << endl;
	int n;
	cin >> n;
	int val;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element # " << i << ":" << "\t";
		cin >> val;
		b->insert(val);
	}
}
int main()
{
	BinarySearchTree b;

	while (true) {

		int menuOption = 0;

		while (menuOption > 6 || menuOption < 1) //This loop can exit program
		{
			cout << "\t*****************************************" << endl;
			cout << "\t* Select Option:\t\t\t*" << endl;
			cout << "\t*\t1. Insert New Data\t\t*" << endl;
			cout << "\t*\t2. In-Order Traversal\t\t*" << endl;
			cout << "\t*\t3. Pre-Order Traversal\t\t*" << endl;
			cout << "\t*\t4. Post-Order Traversal\t\t*" << endl;
			cout << "\t*\t5. Delete an item\t\t*" << endl;
			cout << "\t*\t6. Exit\t\t\t\t*" << endl;
			cout << "\t*****************************************" << endl;

			cout << "> ";
			cin >> menuOption;

			if (menuOption == 6) {
				return 0; //Exiting
			}


			switch (menuOption)
			{
			case 1:
			{
				insertIntoTree(&b);
				break;
			}
			case 2:
			{
				b.print_inorder();
				break;
			}
			case 3:
			{
				b.print_preorder();
				break;
			}
			case 4:
			{
				b.print_postorder();
				break;
			}
			case 5:
			{
				cout << "Enter element to remove:" << endl;
				int elem;
				cin >> elem;
				b.remove(elem, b.root);
			}
			}
		}

	}
	getchar();
}
