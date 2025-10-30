#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <algorithm>

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
	virtual void heapify_up(int index);	  // Helper function to maintain heap property after insertion
	virtual void heapify_down(int index); // Helper function to maintain heap property after extraction

public:
	void insert(int value);		  // Insert a new value into the heap
	int extractMax();			  // Remove and return the maximum value
	int extractMin();			  // Remove and return the minimum value
	int getMax() const;			  // Get the maximum value without removing it
	int getMin() const;			  // Get the minimum value without removing it
	virtual void display() const; // Display the heap elements
	virtual void displayAsTreeRecursive(int index = 0, int indent = 0, char branch = '*') const;

	// Helper functions to get parent and child indices
	int parent(int i) const { return (i - 1) / 2; }
	int lft(int i) const { return 2 * i + 1; }
	int right(int i) const { return 2 * i + 2; }
};
// Move element up to maintain heap property (Helper function)
void Heap ::heapify_up(int index)
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
		int left = this->lft(index);
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
	heap.push_back({value, 0});
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
	heap[minIndex] = heap.back();
	heap.pop_back();

	// Restore heap property
	if (minIndex < heap.size()) // check if the minIndex still exists in the heap after poping
	{
		heapify_down(minIndex);
		heapify_up(minIndex);
	}

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

void Heap::displayAsTreeRecursive(int index, int indent, char branch) const
{
	if (index >= heap.size())
		return;

	int right = this->right(index);
	int left = this->lft(index);

	// Print right subtree first (appears on top)
	displayAsTreeRecursive(right, indent + 6, '/'); // right child

	// Print current node
	if (indent)
		cout << setw(indent) << ' ';
	cout << branch << "-" << heap[index].value << "\n";

	// Print left subtree
	displayAsTreeRecursive(left, indent + 6, '\\'); // left child
}

// =====================================================================================
// PRIORITY QUEUE (USING MAX HEAP)
// =====================================================================================

// Definition of the Priority Queue class
class Priority_Queue : public Heap
{
protected:
	void heapify_up(int index) override;   // Maintain heap property after insertion
	void heapify_down(int index) override; // Maintain heap property after extraction

public:
	void push(int value, int priority); // Insert a new node into the priority queue
	void pop();							// Remove the node with the highest priority

	Node top() const { return heap.front(); }	// Get the node with the highest priority without removing it
	bool empty() const { return heap.empty(); } // Check if the priority queue is empty
	void display() const override;				// Display the priority queue elements
	void displayAsTreeRecursive(int index = 0, int indent = 0, char branch = '*') const override;
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
		int left = this->lft(index);
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
	heap.push_back({value, priority});
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
	cout << left << setw(10) << "Value" << setw(10) << "Priority" << endl;
	cout << string(20, '-') << endl;
	for (const Node node : heap)
	{
		cout << left << setw(10) << node.value << setw(10) << node.priority << endl;
	}
	cout << endl;
}

void Priority_Queue::displayAsTreeRecursive(int index, int indent, char branch) const
{
	if (index >= heap.size())
		return;

	int right = this->right(index);
	int left = this->lft(index);

	// Print right subtree first
	if (right < heap.size())
		displayAsTreeRecursive(right, indent + 10, '/');

	// Print current node with indentation
	cout << setw(indent) << ' ';
	cout << branch << "-(" << heap[index].value << ", " << heap[index].priority << ")\n";

	// Print left subtree
	if (left < heap.size())
		displayAsTreeRecursive(left, indent + 10, '\\');
}

// =====================================================================================
// Testing the Heap and Priority Queue classes
// =====================================================================================

void test_heap()
{
	cout << setw(40) << "**HEAP TESTING**" << endl
		 << string(80, '=') << endl;
	vector<int> arr = {10, 20, 5, 30, 15, 25, 35, 40, 1, 25, 50, 45};
	Heap heap;
	cout << endl
		 << setw(30) << "INSERTING ELEMENTS" << endl
		 << string(80, '-') << endl;
	for (int val : arr)
	{
		heap.insert(val);
		cout << "Inserted: " << val << endl;
		cout << "Current Heap: ";
		heap.display();
		cout << endl;
		heap.displayAsTreeRecursive();
		cout << string(80, '-') << endl;
	}

	cout << setw(40) << "**HEAP EXTRACTION**" << endl
		 << string(80, '-') << endl
		 << endl;

	cout << "EXPECTED MAX_EXTRACTION: 50" << endl;
	int max = heap.getMax();
	assert(heap.extractMax() == max);
	cout << "OUTPUT: " << max << endl;
	cout << "Heap after max extraction:\n"
		 << endl;
	heap.displayAsTreeRecursive();

	cout << endl
		 << "EXPECTED MIN_EXTRACTION: 1" << endl;
	int min = heap.getMin();
	assert(heap.extractMin() == min);
	cout << "OUTPUT: " << min << endl;
	cout << "Heap after min extraction:\n"
		 << endl;
	heap.displayAsTreeRecursive();

	assert(heap.getMax() == 45);
	assert(heap.getMin() == 5);
}

void test_Priority_Queue()
{
	cout << setw(40) << "**PRIORITY QUEUE TEST**" << endl
		 << string(80, '=') << endl;

	vector<Node> arr = {
		{10, 2}, {20, 1}, {5, 4}, {30, 3}, {15, 5}, {25, 2}, {35, 3}, {40, 1}, {1, 5}, {50, 4}};

	Priority_Queue pq;

	cout << endl
		 << setw(30) << "INSERTING ELEMENTS" << endl;
	cout << string(80, '-') << endl;

	for (auto &node : arr)
	{
		cout << "Pushing value: " << setw(2) << node.value
			 << " with priority: " << node.priority << endl;

		pq.push(node.value, node.priority);

		cout << "Current top: ";
		Node top = pq.top();
		cout << "(value=" << top.value << ", priority=" << top.priority << ")" << endl;

		pq.display();
		cout << endl;
		pq.displayAsTreeRecursive();
		cout << endl
			 << string(80, '-') << endl;
	}

	cout << setw(40) << "**EXTRACTION TESTS**" << endl
		 << string(80, '=') << endl;

	cout << "EXPECTED TOP ELEMENT: (value=15, priority=5) or (value=1, priority=5)" << endl;
	Node topBefore = pq.top();
	cout << "OUTPUT: (value=" << topBefore.value << ", priority=" << topBefore.priority << ")" << endl;
	assert(topBefore.priority == 5);

	cout << endl
		 << "Popping top element..." << endl;
	pq.pop();

	cout << "Queue after one pop:\n";
	pq.display();

	cout << endl
		 << "EXPECTED NEXT TOP: (priority <= 5)" << endl;
	Node topAfter = pq.top();
	cout << "OUTPUT: (value=" << topAfter.value << ", priority=" << topAfter.priority << ")" << endl;
	assert(topAfter.priority <= 5);

	cout << string(80, '=') << endl;
	cout << "All priority queue tests passed successfully!" << endl;
}

void heapsort(vector<int> &arr)
{

	Heap heap;
	for (int &elm : arr)
	{
		heap.insert(elm);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		arr[arr.size() - i - 1] = heap.extractMax();
	}
}

void test_heapsort()
{
	cout << setw(40) << "**HEAPSORT TEST**" << endl
		 << string(80, '=') << endl;

	// hard-coded input (includes duplicates and negative)
	vector<int> a = {123, 893289, 1234, 1, 12, -88, 1234, 312, 333, 2001};
	vector<int> expected = a;

	cout << "Input: ";
	for (int x : a)
		cout << x << " ";
	cout << endl;

	// run heapsort implementation
	heapsort(a);

	cout << "Heapsort output: ";
	for (int x : a)
		cout << x << " ";
	cout << endl;

	// validate: compare with std::sort result (checks ordering and element multiset)
	sort(expected.begin(), expected.end());
	assert(a == expected); // will abort if heapsort produced wrong result

	cout << "Heapsort test passed successfully." << endl;
	cout << string(80, '=') << endl;
}

int main()
{
	cout << string(80, '=') << endl;
	test_heap();
	cout << endl
		 << string(80, '=') << endl;
	test_Priority_Queue();
	test_heapsort();

	return 0;
}