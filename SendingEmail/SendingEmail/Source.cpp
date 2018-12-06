//SendingEmail : UVa 10986 : Travis Rowe : Thiefone18 : 12/5/18

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge
{
	int toVert;
	int latency;

	Edge(int to, int lat) { toVert = to; latency = lat; }
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
		}
		//graph is read in

	}
}