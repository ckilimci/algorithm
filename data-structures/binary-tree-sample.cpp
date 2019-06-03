#include <iostream>
#include "BinaryTree.h"

int main() {
	std::cout << "Hello Binary Tree" << std::endl;
	int items[] = { 10, 15, 20, 17 };
	int n = sizeof(items) / sizeof(items[0]);
	BinaryTree bt(items, n);
	bt.print();

	int inserting = 8;
	std::cout << "Inserting " << inserting << std::endl;
	bt.insert(inserting);
	bt.print();
	bt.inorderprint();
	bt.preorderprint();
	bt.postorderprint();
	return 0;
}
