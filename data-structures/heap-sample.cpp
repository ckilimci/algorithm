#include <iostream>
#include "Heap.h"

int main() {
	std::cout << "Hello Heap" << std::endl;
	int items[] = { 10, 15, 20, 17 };
	int n = sizeof(items) / sizeof(items[0]);
	Heap heap(items, n);
	heap.print();

	int index = 10;
	std::cout << "Left Child Index of " << index << " is " << heap.getLeftChildIndex(index) << std::endl;
	std::cout << "Right Child Index of " << index << " is " << heap.getRightChildIndex(index) << std::endl;
	std::cout << "Parent Index of " << index << " is " << heap.getParentIndex(index) << std::endl;
	std::cout << "Has Index of " << index << " left child " << heap.hasLeftChild(index) << std::endl;
	std::cout << "Has Index of " << index << " right child " << heap.hasRightChild(index) << std::endl;
	
	std::cout << "Peek " << heap.peek() << std::endl;
	heap.print();
	int inserting = 8;
	std::cout << "Inserting " << inserting << std::endl;
	heap.insert(inserting);
	heap.print();
	std::cout << "Remove " << heap.remove() << std::endl;
	heap.print();
	return 0;
}
