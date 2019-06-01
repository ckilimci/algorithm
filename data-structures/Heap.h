#include <iostream>
#include <vector>

class Heap {
	std::vector<int> heap;
	int size;
	void heapifyUp();
	void heapifyDown();
	void swap(int, int);
	public:
	Heap(int[], int);
	void print();
	int getLeftChildIndex(int);
	int getRightChildIndex(int);
	int getSmallerChildIndex(int);
	int getParentIndex(int);
	bool hasLeftChild(int);
	bool hasRightChild(int);
	void insert(int);
	int peek();
	int remove();
	~Heap();
};
