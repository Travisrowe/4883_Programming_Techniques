//TheseusAndTheMinotaur : UVa 168 : Travis Rowe : Thiefone18 : 11/29/18

//This is an adjacency graph problem

#include <vector>
#include <bitset>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	char inp;
	cin >> inp; //inp is the first char of the line
	while (inp != '#')
	{
		vector<vector<char>> graph(26); //allocate one space for every letter
		char vertex = inp;
		while (vertex != '.')
		{
			char edge;
			cin >> edge >> edge; //edge is the first node that vertex is connected to
			while (edge != ';' && edge != '.')
			{
				graph[vertex - 65].push_back(edge);
				cin >> edge;
			}
			if (edge != '.')
				cin >> vertex; //continue the loop
			else
				vertex = edge; //exit the loop
		}//end while(c !- '.')
		char minot, theseus;
		int k;
		cin >> minot >> theseus >> k;

		bitset<26> litRooms;
		int count = 0;
		bool trapped = false;
		while (!trapped)
		{
			theseus = minot; //theseus chases the minotaur
			//minotaur runs from theseus
			char nextRoom = '.';
			while (nextRoom == '.' && !trapped)
			{
				//find next room for minotaur to run

			}
			if (count % k == 0 && count != 0)
				litRooms[theseus - 65] = 1; //light theseus's current room
		}
		//while(not trapped)
			//chase and light

		cin >> inp; //start next line
	}//end while(inp != #)
}