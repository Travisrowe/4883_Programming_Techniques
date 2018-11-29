//Vertex : UVa 280 : Travis Rowe : Thiefone18 : 11/27/18

//Here we use a Breadth-First-Search (or DFS, either way) to find the answer.
//Note that we use two vectors. The first is 
//	vector<vector<int>> graph
//and the second is
//	vector<string> colors
//it's kind of nice to store colors in another vector rather than messing
//with enumerated types.

#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

//implement a Breadth-First-Search to see what vertices we can find
void BFS(vector<vector<int>> &G, vector<string> &colors, int s)
{
	queue<int> Q;
	Q.push(s);
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		for (auto u : G[v]) //u is all the adjacent vertices of v
		{
			if (colors[u] == "white") //if u has not been found before
			{
				colors[u] = "grey"; //u has been found but not handled
				Q.push(u);
			}
		}
		/*Note that this line is commented out solely because this UVa problem does not seem to consider the start vertex, s, as being inherently accessible. We still find which vertices are innaccessible based on whether they're white, so that's fine.*/
		//colors[v] = "black"; //v has been completely handled
	}
}

int main()
{
	int n;
	cin >> n; //number of vertices
	while (n != 0) //full graph loop
	{
		vector<vector<int>> graph(n + 1); //n + 1 because 0 index is not used
		int v, e;
		cin >> v;
		while (v != 0) //read in vertexes of this graph
		{
			cin >> e;
			while (e != 0) //read in edges of this vertex
			{
				graph[v].push_back(e);
				cin >> e;
			}
			cin >> v;
		}
		// graph is read in

		int t; //number of starting vertices to test
		cin >> t;
		for (int i = 0; i < t; i++) //handle different start vertices
		{
			//note again the n + 1 because index 0 is not used
			vector<string> colors(n + 1, "white"); //white, grey, or black depending on if the node has been searched
			int startVertex;
			cin >> startVertex;
			BFS(graph, colors, startVertex); //find which vertices are colored black

			vector<int> whiteVerts;

			//skip index 0
			for (int j = 1; j <= n; j++) //push vertices that are white onto whiteVerts
			{
				if (colors[j] == "white")
					whiteVerts.push_back(j);
			}
			//print num of white vertices followed by which vertices they are
			cout << whiteVerts.size() << ' ';
			for (int k = 0; k < whiteVerts.size(); k++)
			{
				cout << whiteVerts[k];
				if (k < whiteVerts.size() - 1)
					cout << ' ';
				else
					cout << '\n';
			}
			if (whiteVerts.size() == 0)
				cout << '\n';
		}

		cin >> n;
	}
}