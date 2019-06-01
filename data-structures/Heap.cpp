#include <iostream>
#include "Heap.h"

Heap::Heap(int items[], int n) {
	heap = std::vector<int>(items, items + n);
	size = n;
}

void Heap::print() {
	for(int i=0; i<size; i++) {
		std::cout << heap[i] << " ";
	}
	std::cout << std::endl;
}

int Heap::getLeftChildIndex(int parent) {
	return 2 * parent + 1;
}

int Heap::getRightChildIndex(int parent) {
	return 2 * parent + 2;
}

int Heap::getParentIndex(int child) {
	return (int) (child-1) / 2;
}

bool Heap::hasLeftChild(int parent) {
	return (getLeftChildIndex(parent)<size);
}

bool Heap::hasRightChild(int parent) {
	return (getRightChildIndex(parent)<size);
}

void Heap::swap(int index1, int index2) {
	int temp = heap[index1];
	heap[index1] = heap[index2];
	heap[index2] = temp;
}

int Heap::peek() {
	return heap[0];
}

int Heap::getSmallerChildIndex(int parent) {
	if (!hasLeftChild(parent)) return parent;
	int smallerChild = getLeftChildIndex(parent);
	if (hasRightChild(parent)) {
		int rightChild = getRightChildIndex(parent);
		if (heap[rightChild] < heap[smallerChild]) {
			smallerChild = rightChild;
		}
	}
	return smallerChild;
}

void Heap::heapifyDown() {
	int parent = 0;
	int smallerChild = getSmallerChildIndex(parent);
	while(heap[parent] > heap[smallerChild]) {
		swap(parent, smallerChild);
		parent = smallerChild;
		smallerChild = getSmallerChildIndex(parent);
	}
}

void Heap::heapifyUp() {
	int child = size-1;
	int parent = getParentIndex(child);
	while (heap[child] < heap[parent]) {
		std::cout << "Child " << child << " is less than its parent " << parent << std::endl;
		swap(child, parent);
		child = parent;
		parent = getParentIndex(child);
	}
}

int Heap::remove() {
	int item = heap[0];
	size--;
	heap[0] = heap[size];
	heap.pop_back();
	heapifyDown();
	return item;
}

void Heap::insert(int item) {
	heap.push_back(item);
	size++;
	heapifyUp();
}

Heap::~Heap() {
}









