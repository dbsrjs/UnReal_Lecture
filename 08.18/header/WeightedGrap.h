#pragma once
#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
using namespace std;

class WeightedGraph {
private:
	int V;
	vector<vector<int>>adjMatrix;
	
	int minDistance(vector<int>& dist, vector<bool>& visited);
	void printSolution(vector<int>$dist);

public:
	WeightedGraph(int vertices);
	void addEdge(int u, int v, int weight);
	void display();
	void dijkstra(int src);
};

#endif // !WEIGHTEDGRAPH_H