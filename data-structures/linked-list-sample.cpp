#include <iostream>
#include "LinkedList.h"

int main() {
	std::cout << "Hello Linked List" << std::endl;
	int items[] = { 10, 15, 20, 17, 30, 40, 55, 70, 33 };
	int n = sizeof(items) / sizeof(items[0]);
	int cycleStart = 3;
	LinkedList list;
	Node* node;
	Node* cycleStartNode;
	for(int i=0; i<n; i++) {
		std::cout << "Adding node:" << items[i] << std::endl;
		node = new Node(items[i]);
		if (cycleStart == i) {
			cycleStartNode = node;
		}
		list.addNode(node);
	}
	list.print();
	std::cout << "Cycle:" << list.hasCycle() << std::endl;

	// Creating cycle in the list
	Node* now = list.head;
	while(nullptr != now->next) {
		now = now->next;
	}
	now->next = cycleStartNode;
	list.print();

	std::cout << "Cycle:" << list.hasCycle() << std::endl;

	if(list.hasCycle()) {
		std::cout << "Cycle Node Data:" << list.findCycleNode()->data << std::endl;
	}
	
	return 0;
}
