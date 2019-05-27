#include <iostream>
#include <vector>

struct Node {
	int data;
	Node* next;
};

struct Edge {
	int src, dest;
};

class Graph {
	int N;
	Node* getAdjListNode(int, Node*);
	public:
	Node **head;
	Graph(Edge[], int, int);
	void dfs(int);
	void dfs(int, bool[]);
	~Graph();
};
