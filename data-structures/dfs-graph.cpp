#include <iostream>
#include "Graph.h"

void printList(Node* ptr) {
	while(nullptr != ptr) {
		std::cout << "->" << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Hello Graph DFS" << std::endl;
	Edge edges[] =
	{
		{0,1}, {1,2}, {2,0}, {2,1},
		{3,2}, {4,5}, {5,4}
	};

	int N = 6;
	int n = sizeof(edges)/sizeof(edges[0]);
	Graph graph(edges, n, N);
	for (int i=0; i<N; i++) {
		std::cout << i << " ==";
		printList(graph.head[i]);
	}
	return 0;
}
