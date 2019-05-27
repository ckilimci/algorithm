#include <iostream>
#include "Graph.h"

void printList(Node* ptr) {
	while(nullptr != ptr) {
		std::cout << "->" << ptr->data << " ";
		ptr = ptr->next;
	}
	std::cout << std::endl;
}

int number_of_visits(bool *visited, int max) {
	int result = 0;
	for(int i=0; i<max; i++) {
		if(visited[i]) {
			result++;
		}
	}
	return result;
}

int main() {
	std::cout << "Hello Counting the islands using DFS" << std::endl;
	Edge edges[] =
	{
		{0,1}, {1,0}, {1,2}, {2,0}, {2,1},
		{3,2}, {4,5}, {5,4}, {0,2}, {2,3}
	};

	int N = 6;
	int n = sizeof(edges)/sizeof(edges[0]);
	Graph graph(edges, n, N);
	for (int i=0; i<N; i++) {
		std::cout << i << " ==";
		printList(graph.head[i]);
	}

	bool *visited = new bool[N];
	int count = 0, last_visited = number_of_visits(visited, N);
	for(int i=0; i<N && last_visited < N; i++) {
		std::cout << "visits" << last_visited << std::endl;
		graph.dfs(i, visited);
		if (number_of_visits(visited, N) > last_visited) {
			count++;
		}
		last_visited = number_of_visits(visited, N);
	}
	std::cout << count << " island(s) found" << std::endl;

	return 0;
}
