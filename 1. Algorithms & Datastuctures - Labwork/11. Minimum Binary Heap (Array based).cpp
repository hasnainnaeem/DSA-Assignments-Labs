/*
Minimum Binary Heap (MinHeap) Implementation in C++
Also includes Array to Minimum binary heap convertor
Written by : m. hasnain naeem
*/
class MinHeap
{
	int capacity, currentSize, *heap;

public:
	// Constructor
	MinHeap(size_t maxSize)
	{
		capacity = maxSize;
		currentSize = 0;
		heap = new int[maxSize];
	}

	template <class T> inline void swap(T& a, T&b)
	{
		T c = a;
		a = b;
		b = c;
	}

	// Calculates left index for given parent index
	size_t left(size_t index) {
		return 2 * index + 1;
	}

	// Calculates right index for a given parent index
	size_t right(size_t index) {
		return 2 * index + 2;
	}

	// Calculates parent index for a given index
	size_t parent(size_t index) {
		return (index - 1) / 2;
	}

	bool pushData(int val)
	{
		if (currentSize == capacity)
			return false;
		// Storing new value
		heap[currentSize] = val;
		// Now we have to make sure that new value is at correct place
		size_t i = currentSize;
		while (heap[parent(i)] > heap[i] && i != 0)
		{
			swap<int>(heap[parent(i)], heap[i]);
			i = parent(i);
		}

		currentSize++;
		return true;
	}

	// Reorganizes the heap 
	void buildHeap(size_t index)
	{
		size_t leftChild = left(index);
		size_t rightChild = right(index);
		size_t min = index;
		if (leftChild < currentSize && heap[leftChild] < heap[index])
		{
			min = leftChild;
		}

		if (rightChild < currentSize && heap[rightChild] < heap[min])
		{
			min = rightChild;
		}

		if (min != index)
		{
			swap<int>(heap[index], heap[min]);
			buildHeap(min);
		}
	}

	// Converts given array to heap. Complexity of convertion is O(N) (includes both methods used during conversion)
	void arrToMinHeap(int* arr, size_t n)
	{
		for (int i = currentSize / 2; i >= 0; --i)
			buildHeap(arr, i, n);
	}

	// ArrToMinHeap uses this method
	// Complexity is O(N)
	void buildHeap(int* arr, size_t index, size_t currentSize)
	{
		size_t leftChild = left(index);
		size_t rightChild = right(index);
		// Suppose given index element is minimum
		size_t min = index;

		// Compare with left child, if left is minimum then update min
		if (leftChild < currentSize && arr[leftChild] < arr[index])
		{
			min = leftChild;
		}

		// Compare min with right child, if that is minimum update min
		if (rightChild < currentSize && arr[rightChild] < arr[min])
		{
			min = rightChild;
		}

		// if min is updated then swap
		if (min != index)
		{
			swap<int>(arr[index], arr[min]);
			// Recuresively call buildHeap to place children on right position
			buildHeap(arr, min, currentSize);
		}
	}

	void heapSort(int *arr, size_t currentSize)
	{
		size_t newSize = currentSize -1 ;
		// Start from end
		for (int i = currentSize-1; i >= 1; i--)
		{
			// swap last element with first one, First one is minimum
			swap(arr[i], arr[0]);
			// Decrease size; first one is at last position and sorted.
			newSize = newSize - 1;
			// Build heap to get minimum element again (greater than previous)
			buildHeap(arr, 0, newSize);
		}
	}

	// Returns minimum (top) element and returns
	// Complexity: O(1)
	int top()
	{
		return heap[0];
	}

	// Removes minimum (top) element and returns
	int popTop()
	{
		switch (currentSize)
		{
		case 0:
			return INT16_MAX; // Value for error
			break;
		case 1:
			return heap[--currentSize];

		default:
		{
			int returnVal = heap[0];
			heap[0] = heap[--currentSize];
			buildHeap(0);
			return returnVal;
		}
		}
	}

	size_t getSize()
	{
		return currentSize;
	}

	int indexOf(int val)
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			if (heap[i] == val)
			{
				return i;
			}
		}

		return -1; // Value not found 
	}

	bool isEmpty()
	{
		if (currentSize == 0)
			return true;
		else
			return false;
	}

	void print()
	{
		for (size_t i = 0; i < currentSize; i++)
		{
			cout << heap[i] << "\t";
		}
		cout << endl;
	}

	int getHeight()
	{
		return ceil(log2(currentSize) + 1);
	}

	// Destroys heap and makes a new heap having given capacity
	void destroy(size_t newCapacity)
	{
		int* temp;
		temp = heap;
		delete(temp);
		heap = new int[newCapacity];
		currentSize = 0;
		capacity = newCapacity;
	}
};


void InsertIntoHeap(MinHeap* heap) {
	cout << "How many elements do you want to insert?" << endl;
	int n;
	cin >> n;
	int val;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter element # " << i << ":" << "\t";
		cin >> val;
		heap->pushData(val);
	}
}

void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int main()
{
	MinHeap* heap = new MinHeap(100);
	while (true) {

		int menuOption = 0;

		while (menuOption > 11 || menuOption < 1) //This loop can exit program
		{
			cout << "\t*****************************************" << endl;
			cout << "\t* Select Option:\t\t\t*" << endl;
			cout << "\t*\t1. Push Elements Into Heap\t*" << endl;
			cout << "\t*\t2. Pop From Heap\t\t*" << endl;
			cout << "\t*\t3. Get Top Element\t\t*" << endl;
			cout << "\t*\t4. Check if Empty\t\t*" << endl;
			cout << "\t*\t5. Check Size\t\t\t*" << endl;
			cout << "\t*\t6. Check Height\t\t\t*" << endl;
			cout << "\t*\t7. Print Heap\t\t\t*" << endl;
			cout << "\t*\t8. Destroy Heap\t\t\t*" << endl;
			cout << "\t*\t9. Heapify a given array\t*" << endl;
			cout << "\t*\t10. Heap sort (Descending order)*" << endl;
			cout << "\t*\t11. Exit\t\t\t*" << endl;
			cout << "\t*****************************************" << endl;

			cout << "> ";
			cin >> menuOption;

			if (menuOption == 11) {
				return 0; //Exiting
			}


			switch (menuOption)
			{
				// Push into heap
			case 1:
			{
				InsertIntoHeap(heap);
				break;
			}

			// Pop from Heap
			case 2:
			{
				cout << "Popped Element: ";
				cout << heap->popTop() << endl;
				break;
			}

			// Get Top Element
			case 3:
			{
				cout << "Top Element: ";
				cout << heap->top() << endl;
				break;
			}

			// Check if empty
			case 4:
			{
				if (heap->isEmpty())
					cout << "Heap is empty" << endl;
				else
					cout << "Heap is not empty." << endl;
				break;
			}

			// Check Size
			case 5:
			{
				cout << "Size of heap: " << heap->getSize() << endl;
				break;
			}

			// Check Height
			case 6:
			{
				cout << "Height of heap: " << heap->getHeight() << endl;
				break;
			}

			// Print Heap
			case 7:
			{
				cout << "Printing Heap:" << endl;
				heap->print();
				break;
			}

			// Destroy Heap
			case 8:
			{
				cout << "Enter capacity for new heap: ";
				int n;
				cin >> n;
				heap->destroy(n);
				cout << "Previous heap is destroyed and new heap of capacity " << n << " is formed." << endl;
				break;
			}

			// Heapify a given array
			case 9:
			{
				cout << "Enter no. of elements: ";
				int n;
				cin >> n;
				int* arr = new int[n];
				for (int i = 0; i < n; i++)
				{
					cout << "Enter Element # " << i << ": ";
					cin >> arr[i];
				}

				for (int i = (n - 2) / 2; i >= 0; --i)
				{
					heap->buildHeap(arr, i, n);
				}
				printArr(arr, n);
				break;
			}
			// Heap Sort a given array
			case 10:
			{
				cout << "Enter no. of elements: ";
				int n;
				cin >> n;
				int* arr = new int[n];
				for (int i = 0; i < n; i++)
				{
					cout << "Enter Element # " << i << ": ";
					cin >> arr[i];
				}

				// Heapifying
				for (int i = (n - 2) / 2; i >= 0; --i)
				{
					heap->buildHeap(arr, i, n);
				}
				cout << "Heapified Array:" << endl;
				printArr(arr, n);
				// Sorting
				cout << "Sorted Array:" << endl;
				heap->heapSort(arr, n);
				printArr(arr, n);
				break;
			}
			}
		}
	}
	delete(heap);
	getchar();
}
