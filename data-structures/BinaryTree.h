#include <iostream>
#include <vector>

class BinaryTree {
	std::vector<int> tree;
	public:
	BinaryTree(int[], int);
	int getLeftChildIndex(int);
	int getRightChildIndex(int);
	int getParentIndex(int);
	void inorderprint();
	void inorderprint(int);
	void preorderprint();
	void preorderprint(int);
	void postorderprint();
	void postorderprint(int);
	void print();
	void insert(int);
	~BinaryTree();
};
