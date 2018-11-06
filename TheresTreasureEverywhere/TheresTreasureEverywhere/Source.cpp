//TheresTreasureEverywhere.cpp : UVa 587 : Travis Rowe : Thiefone18 : 11/4/18
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string input;
	int mapNum = 1;
	const string DELIM = ",";
	getline(cin, input, '.'); //input is the full line minus the period
	while (input != "END")
	{
		size_t pos = input.find(DELIM);
		double x = 0;
		double y = 0;
		double mag; //magnitude
		string dir; //direction
		while (input != "")
		{
			stringstream ss;
			string token = input.substr(0, pos);
			if (pos + 1 < input.length())
				input = input.substr(pos + 1);
			else //this is the last direction
				input = "";
			ss << token;
			
			ss >> mag >> dir;

			if (dir.length() > 1) //45 degree cardinal direction
				mag = sqrt((mag * mag) / 2); //Pytharogm's theorem
			for (int i = 0; i < dir.length(); i++)
			{
				switch (dir[i])
				{
				case 'N':
					y += mag;
					break;
				case 'S':
					y -= mag;
					break;
				case 'W':
					x -= mag;
					break;
				case 'E':
					x += mag;
					break;
				}//end switch
			}//end for
		}//end while pos

		double distance = sqrt(x * x + y * y);
		printf("Map #%d\n", mapNum++);
		printf("The treasure is located at (%.3f, %.3f).\n", x, y);
		printf("The distance to the treasure is %.3f.\n\n", distance);
		getline(cin, input, '.');
	}
}