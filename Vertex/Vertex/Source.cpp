//Vertex : UVa 280 : Travis Rowe : Thiefone18 : 11/21/18

//This is an adjacency graph problem. In it we will use either a breadth-first
//search or depth-first search, along with enum types to color the nodes we've
//never visited (white), visited but not explored (grey), and explored completely
//(black)

#include <iostream>
#include <vector>
using namespace std;

struct Vertex
{
	vector<int> edges;

};

class AdjacencyGraph 
{
	vector<vector<int>> graph;

public:
	AdjacencyGraph(int N)
	{
		graph.resize(N + 1);
	}
	void AddEdge(int p, int q)
	{
		AdjacencyGraph::graph[p].push_back(q);
	}

	void BFS();
};

int main()
{
	int N; //number of vertices
	cin >> N;
	while (N != 0) //graph loop, where N is the number of vertices in this graph
	{
		for (int i = 1; i <= N; i++)
		{

		}
		cin >> N;
	}
}