//TheresTreasureEverywhere.cpp : UVa 587 : Travis Rowe : Thiefone18 : 11/4/18
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string input;
	getline(cin, input, ',');
	while (input != "END")
	{
		stringstream ss;
		ss << input;
		int mag; //magnitude
		string dir; //direction
		ss >> mag >> dir;

		double x = 0;
		double y = 0;

		bool endOfLine = false;
		if (dir[dir.length() - 1] == '.')
		{
			endOfLine = true; //will reset coordinates
			dir = dir.substr(0, dir.length() - 1); //cut off the period
		}

		cout << mag << dir << endl;

		getline(cin, input, ',');
	}
}