//RankTheLanguage : UVa 10336 : Travis Rowe : Thiefone18 : 12/6/18

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility> //used for pairs

using namespace std;

void SearchState(vector<vector<char>> &graph, int r, int c, char ch)
{
	graph[r][c] = '.'; //mark this node as searched
	//recursively search nodes around this node
	if (graph[r - 1][c] == ch)
		SearchState(graph, r - 1, c, ch);
	else if (graph[r + 1][c] == ch)
		SearchState(graph, r + 1, c, ch);
	else if (graph[r][c - 1] == ch)
		SearchState(graph, r, c - 1, ch);
	else if (graph[r][c + 1] == ch)
		SearchState(graph, r, c + 1, ch);
}

//comparison method used in sorting
bool comp(const pair<char, int> &a, const pair<char, int> &b)
{
	if (a.first == b.first)
		return(a.second < b.second);
	else
		return((int)a.first < (int)b.first);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		//read in graph
		int h, w;
		cin >> h >> w;
		//add a border of null chars around the graph
		vector<vector<char>> graph(h + 2, vector<char>(w + 2, '.'));
		for (int r = 1; r <= h; r++)
		{
			for (int c = 1; c <= w; c++)
			{
				cin >> graph[r][c];
			}
		}
		//graph is read in

		vector<pair<char, int>> langContainer;
		for (int r = 1; r <= h; r++)
		{
			for (int c = 1; c <= w; c++)
			{
				if (graph[r][c] != '.') //we've found a state
				{
					//add 1 to the number of states for this language
					bool found = false;
					//check if this language is already in the vector
					for (int i = 0; i < langContainer.size(); i++)
						if (langContainer[i].first == graph[r][c])
						{
							langContainer[i].second++;
							found = true;
						}
					if(!found)
						langContainer.push_back(make_pair(graph[r][c], 1));
					
					//see how far the state reaches
					SearchState(graph, r, c, graph[r][c]);
				}
			}
		}
		//we now have an unordered list of the number of states per 
		//language spoken in the world.

		//let's order that list using the comp() function above
		std::sort(langContainer.front(), langContainer.back(), comp);
	}
}