#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
}

void LinkedList::limitedPrint() {
	Node* now = head;
	int i = 0;
	while(nullptr != now && i++<20) {
		std::cout << "Data:" << now->data << std::endl;
		now = now->next;
	}
	std::cout << std::endl;
}

void LinkedList::print() {
	Node* now = head;
	if (hasCycle()) {
		limitedPrint();
		return;
	}
	while(nullptr != now) {
		std::cout << "Data:" << now->data << std::endl;
		now = now->next;
	}
	std::cout << std::endl;
}

void LinkedList::addNode(Node* node) {
	std::cout << "Adding Node. Node data:" << node->data << std::endl;
	if (nullptr == head) {
		head = node;
		return;
	}
	Node* now = head;
	while(nullptr != now->next) {
		std::cout << "Now data:" << now->data << std::endl;
		now = now->next;
	}
	now->next = node;
}

bool LinkedList::hasCycle() {
	Node* now = head;
	Node* fast = head->next;
	while(nullptr != fast && fast->next != nullptr) {
		if (fast == now) return true;
		fast = fast->next->next;
		now = now->next;
	}
	return false;
}

Node* LinkedList::findCycleNode() {
	if (!hasCycle()) return nullptr;
	Node* slow = head->next;
	Node* fast = head->next->next;
	// First find the meeting point
	while(fast != slow) {
		fast = fast->next->next;
		slow = slow->next;
	}
	// Slow down fast one and start slow from head;
	slow = head;
	while(fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
	
}

LinkedList::~LinkedList() {
}









