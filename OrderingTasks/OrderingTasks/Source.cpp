//OrderingTasks : UVa 10305: Travis Rowe : Thiefone18 : 11/29/18

//This is an adjacency graph problem, which will utilize a DFS to create a n-ary tree
//Nodes without a parent will be printed first in numerical order, followed by
//nodes with one parent in numerical order, followed by nodes with two, etc.

#include <stack>
#include <vector>
#include <iostream>
#include <algorithm> //used for sort
#include <set>
using namespace std;

struct Task
{
	int taskNum;
	set<int> parents;

	Task() { taskNum = -1; }

	void AlterTask(int tN, int p) { taskNum = tN; parents.insert(p); }

	static bool CompareTask(const Task a, const Task b)
	{
		if (a.parents.size() == b.parents.size())
			return a.taskNum > b.taskNum;
		else
			return a.parents.size() < b.parents.size();
	}
};

//static bool comp(const pair<int, int> a, const pair<int, int> b)
//{
//	if (a.second == b.second)
//		return a.first < b.first;
//	else
//		return a.second < b.second;
//}

int main()
{
	int n, m;
	cin >> n >> m;
	while (n != 0)
	{
		int i, j;
		//count the number of parents each node has
		//note n + 1 because 0 index is unused
		vector<Task> taskGraph(n + 1);

		for (int a = 0; a < m; a++) //read in ordered tasks loop
		{
			cin >> i >> j;
			taskGraph[j].AlterTask(j, i);
		}
		//handle the nodes with no parents who are named wrong
		for (int b = 1; b <= n; b++)
		{
			if (taskGraph[b].taskNum == -1)
				taskGraph[b].taskNum = b;
		}
		//numParents graph is read in

		//sort numParents graph by least number of parents, then in numerical order
		sort(taskGraph.begin() + 1, taskGraph.end(), Task::CompareTask);
		
		//print
		for (int c = 1; c <= n; c++)
			cout << taskGraph[c].taskNum << ' ';
		cout << '\n';

		cin >> n >> m;
	}
}