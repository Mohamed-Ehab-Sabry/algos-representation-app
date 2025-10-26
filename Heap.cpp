#include <iostream>
#include <vector>

using namespace std;

// Definition of the Max-heap class
class Heap
{
private:
	vector<int> heap;
	void heapify_up(int index);		// Helper function to maintain heap property after insertion
	void heapify_down(int index); 	// Helper function to maintain heap property after extraction

public:
	void insert(int value); // Insert a new value into the heap
	int extractMax();		// Remove and return the maximum value
	int extractMin();		// Remove and return the minimum value
	int getMax() const;		// Get the maximum value without removing it
	int getMin() const;		// Get the minimum value without removing it
	void display() const;	// Display the heap elements
};
// Move element up to maintain heap property (Helper function)
void Heap :: heapify_up(int index)
{
	while (index > 0)
	{
		int parent = (index - 1) / 2;
		if (heap[index] > heap[parent])
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
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		int largest = index;

		// find the largest among index, left and right
		if (left < size && heap[left] > heap[largest])
		{
			largest = left;
		}
		if (right < size && heap[right] > heap[largest])
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
	heap.push_back(value);
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

	int max = heap[0];
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
		if (heap[i] < heap[minIndex])
		{
			minIndex = i;
		}
	}

	int minValue = heap[minIndex];
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
	return heap[0];
}
// Get the minimum value without removing it
int Heap::getMin() const
{
	if (heap.empty())
	{
		cout << "Heap is empty!!!!!!!" << endl;
		return -1;
	}

	int minValue = heap[0];
	for (int i = 1; i < heap.size(); i++)
	{
		if (heap[i] < minValue)
		{
			minValue = heap[i];
		}
	}

	return minValue;
}
// Display the heap elements
void Heap::display() const
{
	for (int value : heap)
	{
		cout << value << " ";
	}
	cout << endl;
}

// =====================================================================================
// PRIORITY QUEUE (USING MAX HEAP)

// Definition of the Node structure
struct Node
{
	int value;
	int priority;
};

// Definition of the Priority Queue class
class Priority_Queue
{
private:
	vector<Node>heap;
	// Helper functions to get parent and child indices
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }

	void heapifyUp(int index);		// Maintain heap property after insertion
	void heapifyDown(int index);	// Maintain heap property after extraction

public:
	void push(int value, int priority); // Insert a new node into the priority queue
	void pop();							// Remove the node with the highest priority

	Node top() const { return heap.front(); }	// Get the node with the highest priority without removing it
	bool empty() { return heap.empty(); }		// Check if the priority queue is empty
	void display() const;						// Display the priority queue elements
};

// Move element up to maintain heap property
void Priority_Queue::heapifyUp(int index)
{
	while (index > 0 && heap[index].priority > heap[parent(index)].priority)
	{
		swap(heap[parent(index)], heap[index]);
		index = parent(index);
	}
}
// Move element down to maintain heap property
void Priority_Queue::heapifyDown(int index)
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
	heapifyUp(heap.size() - 1);
}
// Remove the node with the highest priority
void Priority_Queue::pop()
{
	if (heap.empty())
		return;

	heap[0] = heap.back();
	heap.pop_back();
	heapifyDown(0);
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

int main()
{
	return 0;
}