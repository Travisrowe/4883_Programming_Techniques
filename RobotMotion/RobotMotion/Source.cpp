//RobotMotion : UVa 10116 : Travis Rowe : Thiefone18 : 11/29/18

//This is an adjacency graph problem where I use colored nodes similarly to
//a DFS or BFS.

#include <vector>
#include <string>
#include <iostream>
using namespace std;

void ColorNode(vector<vector<string>> &colors, int currRow, int currCol, bool &loop)
{
	//color node
	if (colors[currRow][currCol] == "white")
		colors[currRow][currCol] = "grey";

	else if (colors[currRow][currCol] == "grey")
		colors[currRow][currCol] = "black";

	else //color is black
		loop = true; //exit while loop;
}

void MoveRobot(vector<vector<char>> &graph, int &currRow, int &currCol)
{
	//handle Robot Motion
	switch (graph[currRow][currCol])
	{
	case 'N':
		currRow--;
		break;
	case 'S':
		currRow++;
		break;
	case 'E':
		currCol++;
		break;
	case 'W':
		currCol--;
		break;
	}
}

int main()
{
	int numRows, numCols, startPos;
	cin >> numRows >> numCols >> startPos;
	while (numRows != 0) //handle new graph
	{
		string inp;
		vector<vector<char>> graph(numRows, vector<char>(numCols));
		for (int r = 0; r < numRows; r++) //read in graph
		{
			cin >> inp;
			for (int c = 0; c < numCols; c++)
			{
				graph[r][c] = inp[c];
			}
		}
		//graph is read in

		vector<vector<string>> colors(numRows, vector<string>(numCols, "white"));
		int currRow = 0;
		int currCol = startPos - 1; //account for 0 index being used
		bool loop = false; //will be set to true if a black node is found
		while (currRow > -1 && currRow < numRows && currCol > -1 && currCol < numCols && loop == false)
		{ //this loop will handle the Robot's motion, coloring nodes that the robot lands on

			ColorNode(colors, currRow, currCol, loop);
			MoveRobot(graph, currRow, currCol);
		}

		//Robot is done and graph is colored, count number of grey and black nodes
		int greyCount = 0, blackCount = 0;
		for (int r = 0; r < numRows; r++)
		{
			for (int c = 0; c < numCols; c++)
			{
				if (colors[r][c] == "grey")
					greyCount++;
				else if (colors[r][c] == "black")
					blackCount++;
			}
		}

		//print
		if (blackCount == 0)
			cout << greyCount << " step(s) to exit\n";
		else
			cout << greyCount << " step(s) before a loop of " << blackCount << " step(s)\n";

		cin >> numRows >> numCols >> startPos;
	} //end new graph loop
}