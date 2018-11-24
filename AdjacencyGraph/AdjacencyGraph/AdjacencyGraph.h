#pragma once
#include <vector>
#include <iostream>
using namespace std;

class AdjacencyGraph
{
	vector<vector<int>> graph;
public:
	AdjacencyGraph() = delete;
	AdjacencyGraph(int);
	~AdjacencyGraph();
	void AddEdge(int, int);
	void BFS();
};

