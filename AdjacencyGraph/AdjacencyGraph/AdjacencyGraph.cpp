#include "AdjacencyGraph.h"

void AdjacencyGraph::AddEdge(int p, int q)
{
	graph[p].push_back(q);
}

AdjacencyGraph::AdjacencyGraph(int N)
{
	graph.resize(N);
}


AdjacencyGraph::~AdjacencyGraph()
{
}
