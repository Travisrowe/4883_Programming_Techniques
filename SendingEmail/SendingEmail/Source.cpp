//SendingEmail : UVa 10986 : Travis Rowe : Thiefone18 : 12/5/18

#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
#include <stdint.h>

using namespace std;

struct Edge
{
	int index;
	int latency;

	Edge(int ind, int lat) { index = ind; latency = lat; }
};

int main()
{
	int N;
	cin >> N; //number of test cases
	for (int i = 0; i < N; i++)
	{
		int n; //number of vertices
		int m; //number of edges
		int s, t; //source node and destination node, respectively
		cin >> n >> m >> s >> t;
		vector<vector<Edge>> graph(n);
		for (int j = 0; j < m; j++) //read in graph
		{
			int a, b, lat; //vertex a, vertex b, latency from a to b
			cin >> a >> b >> lat;
			graph[a].push_back(Edge(b, lat));
			graph[b].push_back(Edge(a, lat));
		}
		//graph is read in

		//dist is the distance from source node to node n.
		//If no distance has been found from source to n, then dist holds INT_MAX
		vector<int> dist(n, INT_MAX);

		/*This algorithm is Djikstra's Shortest Path algorithm. 
		See Hamlin & Hamlin p. 148*/
		queue<Edge> que;
		que.push(Edge(s, 0));
		while (!que.empty())
		{
			int d = que.front().latency;
			int u = que.front().index;
			que.pop();

			//if the current distance is less than the distance on file
			if (d < dist[u])
			{
				//update distance on file
				dist[u] = d;
				//enqueue u's adjacent nodes
				for (int j = 0; j < graph[u].size(); j++)
				{
					que.push(Edge(graph[u][j].index, dist[u] + graph[u][j].latency));
				}
			}
		}
		cout << "Case #" << i + 1 << ": ";
		if (dist[t] < INT_MAX)
			cout << dist[t] << '\n';
		else
			cout << "unreachable\n";
	}
}