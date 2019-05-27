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
	void dfs(int, bool[]);
	public:
	Node **head;
	Graph(Edge[], int, int);
	void dfs(int);
	~Graph();
};
