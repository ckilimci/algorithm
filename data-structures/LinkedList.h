#include <iostream>
#include <vector>

struct Node {
	int data;
	Node* next;
	Node() { Node(0); }
	Node(int d) {
		data = d;
		next = nullptr;
	}
};

class LinkedList {
	public:
	Node* head;
	LinkedList();
	void limitedPrint();
	void print();
	void addNode(Node*);
	bool hasCycle();
	Node* findCycleNode();
	~LinkedList();
};
