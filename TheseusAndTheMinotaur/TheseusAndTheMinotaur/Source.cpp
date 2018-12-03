//TheseusAndTheMinotaur : UVa 168 : Travis Rowe : Thiefone18 : 11/29/18

//This is an adjacency graph problem

#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string inp;
	cin >> inp; //inp is the line of input up to the period
	while (inp != "#")
	{
		vector<vector<char>> graph;
		for (auto c : inp) //iterate a char through inp
		{
			if (c - 65 >= 0 && c - 65 <= 26) //this is an alpha character

		} //graph is read in, now read in start positions and int k
		cin >> inp;
	}//end while(inp != #)
}