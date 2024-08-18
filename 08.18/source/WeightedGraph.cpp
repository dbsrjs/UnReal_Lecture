#include <iostream>
#include <vector>
#include <climits>
#include "WeightedGrap.h"

using namespace std;

WeightedGraph::WeightedGraph(int vertices) : V(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

void WeightedGraph::addEdge(int u, int v, int weight) {
	adjMatrix[u][v] = weight;
	adjMatrix[v][u] = weight;
}

void WeightedGraph::display() {
	cout << "Adjacency Matrix:" << endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << adjMatrix[i][j] << "";
		}
		cout << endl;
	}
}

void WeightedGraph::dijkstra(int src) {
	vector<int> dist(V, INT_MAX);
	vector<bool> visited(V, false);
	dist[src] = 0;

	for (int i = 0; i < V - 1; i++) {
		int u = minDistance(dist, visited);
		visited[u] = true;
	}
}