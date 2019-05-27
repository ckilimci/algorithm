#include <iostream>
#include "Graph.h"
/*
struct Node {
	int data;
	Node* next;
};

struct Edge {
	int src, dest;
};
*/

Graph::Graph(Edge edges[], int n, int N) {
	this->N = N;
	head = new Node*[N]();

	for (int i=0; i<N; i++) {
		head[i] = nullptr;
	}

	for (int i=0; i<n; i++) {
		int src = edges[i].src;
		int dest = edges[i].dest;

		Node* newNode = getAdjListNode(dest, head[src]);
		head[src] = newNode;

		// Uncoment for undirected graph
		//newNode = getAdjListNode(src, head[dest]);
		//head[dest] = newNode;
	}


}

void Graph::dfs(int start) {
	std::cout << "Starting from " << start << std::endl;
	bool *visited = new bool[N];
	Graph::dfs(start, visited);
}

void Graph::dfs(int now, bool visited[]) {
	std::cout << "Visiting " << now << std::endl;
	visited[now] = true;
	Node* ptr = head[now];
	while (ptr != nullptr) {
		if (false == visited[ptr->data]) {
			Graph::dfs(ptr->data, visited);
		}
		ptr = ptr->next;
	}
}

Node* Graph::getAdjListNode(int dest, Node* head) {
	Node* newNode = new Node;
	newNode->data = dest;

	newNode->next = head;

	return newNode;
}

Graph::~Graph() {
	for (int i=0; i<N; i++) {
		delete[] head[i];
	}
	delete[] head;
}

