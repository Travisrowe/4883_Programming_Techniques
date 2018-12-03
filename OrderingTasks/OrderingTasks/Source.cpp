//OrderingTasks : UVa 10305: Travis Rowe : Thiefone18 : 11/29/18

//This is an adjacency graph problem, which will utilize a DFS to create a n-ary tree
//Nodes without a parent will be printed first in numerical order, followed by
//nodes with one parent in numerical order, followed by nodes with two, etc.

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	while (n != 0)
	{
		int i, j;
		//this is a graph which actually shows which nodes have parents, as
		//well as what those parents are.
		vector<vector<int>> parents(n + 1); //note n + 1 because 0 index is unused
		for (int k = 0; k < m; k++) //read in ordered tasks loop
		{
			cin >> i >> j;
			parents[j].push_back(i);
		}
		
		for (int a = 1; a < n + 1; a++) //loop through parents vector
		{
			
		}
		
		cin >> n >> m;
	}
}