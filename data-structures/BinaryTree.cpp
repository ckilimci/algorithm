#include <iostream>
#include "BinaryTree.h"

BinaryTree::BinaryTree(int items[], int n) {
	for(int i=0; i<n; i++) {
		std::cout << "inserting " << items[i] << std::endl;
		insert(items[i]);
	}
}

void BinaryTree::print() {
	for(auto node : tree) {
		std::cout << "Data: " << node << std::endl;
	}
}

void BinaryTree::insert(int item) {
	tree.push_back(item);
}

int BinaryTree::getLeftChildIndex(int parent) {
	return 2 * parent + 1;
}

int BinaryTree::getRightChildIndex(int parent) {
	return 2 * parent + 2;
}

int BinaryTree::getParentIndex(int child) {
	return (child - 1) / 2;
}

void BinaryTree::inorderprint() {
	inorderprint(0);	
}

void BinaryTree::preorderprint() {
	preorderprint(0);	
}

void BinaryTree::postorderprint() {
	postorderprint(0);	
}

void BinaryTree::inorderprint(int index) {
	if (index >= tree.size()) return;
	inorderprint(getLeftChildIndex(index));
	std::cout << "In-Order: " << tree[index] << std::endl;
	inorderprint(getRightChildIndex(index));
}

void BinaryTree::preorderprint(int index) {
	if (index >= tree.size()) return;
	std::cout << "Pre-Order: " << tree[index] << std::endl;
	preorderprint(getLeftChildIndex(index));
	preorderprint(getRightChildIndex(index));
}

void BinaryTree::postorderprint(int index) {
	if (index >= tree.size()) return;
	postorderprint(getLeftChildIndex(index));
	postorderprint(getRightChildIndex(index));
	std::cout << "Post-Order: " << tree[index] << std::endl;
}

BinaryTree::~BinaryTree() {
}









