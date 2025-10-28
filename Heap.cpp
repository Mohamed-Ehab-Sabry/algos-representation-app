#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>

using namespace std;

// Definition of the Node structure
struct Node
{
	int value;
	int priority;
};

// =====================================================================================
// BASE HEAP CLASS (MAX-HEAP)
// ====================================================================================

// Definition of the Max-heap class
class Heap
{
protected:
	vector<Node> heap;
	virtual void heapify_up(int index);		// Helper function to maintain heap property after insertion
	virtual void heapify_down(int index); 	// Helper function to maintain heap property after extraction

public:
	void insert(int value); // Insert a new value into the heap
	int extractMax();		// Remove and return the maximum value
	int extractMin();		// Remove and return the minimum value
	int getMax() const;		// Get the maximum value without removing it
	int getMin() const;		// Get the minimum value without removing it
	virtual void display() const;	// Display the heap elements
	virtual void displayAsTreeRecursive(int index = 0, int indent = 0) const;

	// Helper functions to get parent and child indices
	int parent(int i) const { return (i - 1) / 2; }
	int left(int i) const { return 2 * i + 1; }
	int right(int i) const { return 2 * i + 2; }
};
// Move element up to maintain heap property (Helper function)
void Heap :: heapify_up(int index)
{
	while (index > 0)
	{
		int parent = this->parent(index);
		if (heap[index].value > heap[parent].value)
		{
			swap(heap[index], heap[parent]);
			index = parent;
		}
		else
		{
			break;
		}
	}
}
// Move element down to maintain heap property (Helper function)
void Heap ::heapify_down(int index)
{
	int size = heap.size();

	while (index < size)
	{
		int left = this->left(index);
		int right = this->right(index);

		int largest = index;

		// find the largest among index, left and right
		if (left < size && heap[left].value > heap[largest].value)
		{
			largest = left;
		}
		if (right < size && heap[right].value > heap[largest].value)
		{
			largest = right;
		}

		// if largest is not index, swap and continue heapifying down
		if (largest != index)
		{
			swap(heap[index], heap[largest]);
			index = largest;
		}
		else
		{
			break;
		}
	}
}
// Insert a new value into the heap
void Heap::insert(int value)
{
	heap.push_back({ value,0 });
	heapify_up(heap.size() - 1);
}
// Remove and return the maximum value
int Heap::extractMax()
{
	if (heap.empty())
	{
		cout << "Heap is empty!!!!!!!" << endl;
		return -1;
	}

	int max = heap[0].value;
	heap[0] = heap.back();
	heap.pop_back();

	if (!heap.empty())
	{
		heapify_down(0);
	}
	return max;
}
// Remove and return the minimum value
int Heap::extractMin()
{
	if (heap.empty())
	{
		cout << "Heap is empty!!!!!!!" << endl;
		return -1;
	}

	int minIndex = 0;
	for (int i = 1; i < heap.size(); i++)
	{
		if (heap[i].value < heap[minIndex].value)
		{
			minIndex = i;
		}
	}

	int minValue = heap[minIndex].value;
	heap.erase(heap.begin() + minIndex);

	return minValue;
}
// Get the maximum value without removing it
int Heap::getMax() const
{
	if (heap.empty())
	{
		cout << "Heap is empty!!!!!!!" << endl;
		return -1;
	}
	return heap[0].value;
}
// Get the minimum value without removing it
int Heap::getMin() const
{
	if (heap.empty())
	{
		cout << "Heap is empty!!!!!!!" << endl;
		return -1;
	}

	int minValue = heap[0].value;
	for (int i = 1; i < heap.size(); i++)
	{
		if (heap[i].value < minValue)
		{
			minValue = heap[i].value;
		}
	}

	return minValue;
}
// Display the heap elements
void Heap::display() const
{
	for (Node node : heap)
	{
		cout << node.value << " ";
	}
	cout << endl;
}

void Heap::displayAsTreeRecursive(int index, int indent) const
{
	if (index >= heap.size()) return;

	int right = this->right(index);
	int left = this->left(index);

	// Print right subtree first (appears on top)
	displayAsTreeRecursive(right, indent + 4);

	// Print current node
	if (indent)
		cout << setw(indent) << ' ';
	cout << heap[index].value << "\n";

	// Print left subtree
	displayAsTreeRecursive(left, indent + 4);
}

// =====================================================================================
// PRIORITY QUEUE (USING MAX HEAP)
// =====================================================================================

// Definition of the Priority Queue class
class Priority_Queue : public Heap
{
protected:
	void heapify_up(int index) override;		// Maintain heap property after insertion
	void heapify_down(int index) override;		// Maintain heap property after extraction

public:
	void push(int value, int priority); // Insert a new node into the priority queue
	void pop();							// Remove the node with the highest priority

	Node top() const { return heap.front(); }	// Get the node with the highest priority without removing it
	bool empty() const { return heap.empty(); }		// Check if the priority queue is empty
	void display() const override;				// Display the priority queue elements
	void displayAsTreeRecursive(int index = 0, int indent = 0) const override;
};

// ------------------------------------------------------
// Implementation of Priority Queue methods
// ------------------------------------------------------

// Move element up to maintain heap property
void Priority_Queue::heapify_up(int index)
{
	while (index > 0 && heap[index].priority > heap[parent(index)].priority)
	{
		swap(heap[parent(index)], heap[index]);
		index = parent(index);
	}
}
// Move element down to maintain heap property
void Priority_Queue::heapify_down(int index)
{
	int size = heap.size();
	while (index < size)
	{
		int largest = index;
		int left = this->left(index);
		int right = this->right(index);

		if (left < size && heap[left].priority > heap[largest].priority)
		{
			largest = left;
		}
		if (right < size && heap[right].priority > heap[largest].priority)
		{
			largest = right;
		}

		if (largest != index)
		{
			swap(heap[largest], heap[index]);
			index = largest;
		}
		else
			break;
	}
}
// Insert a new node into the priority queue
void Priority_Queue::push(int value, int priority)
{
	heap.push_back({ value,priority });
	heapify_up(heap.size() - 1);
}
// Remove the node with the highest priority
void Priority_Queue::pop()
{
	if (heap.empty())
		return;

	heap[0] = heap.back();
	heap.pop_back();
	heapify_down(0);
}
// Display the priority queue elements
void Priority_Queue::display() const
{
	for (const auto& node : heap)
	{
		cout << "(" << node.value << ", " << node.priority << ") ";
	}
	cout << endl;
}

void Priority_Queue::displayAsTreeRecursive(int index, int indent) const
{
	if (index >= heap.size()) return;

	int right = this->right(index);
	int left = this->left(index);

	// Print right subtree first (appears on top)
	displayAsTreeRecursive(right, indent + 4);

	// Print current node
	if (indent)
		cout << setw(indent) << ' ';
	cout << "(" << heap[index].value << ", " << heap[index].priority << ")\n";

	// Print left subtree
	displayAsTreeRecursive(left, indent + 4);
}

// =====================================================================================
// Testing the Heap and Priority Queue classes
// =====================================================================================


int main()
{
	Heap maxHeap;
	maxHeap.insert(10);
	maxHeap.insert(20);
	maxHeap.insert(5);
	maxHeap.insert(30);
	maxHeap.insert(15);

	cout << "Max-Heap elements: ";
	maxHeap.display();
	cout << endl;
	maxHeap.displayAsTreeRecursive();
	return 0;
}