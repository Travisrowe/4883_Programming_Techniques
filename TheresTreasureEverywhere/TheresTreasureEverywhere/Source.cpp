//TheresTreasureEverywhere.cpp : UVa 587 : Travis Rowe : Thiefone18 : 11/4/18
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool IsDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool IsAlpha(char c)
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

int main()
{
	string input;
	int mapNum = 1;
	const string DELIM = ",";
	getline(cin, input); //input is the full line minus the period
	while (input != "END")
	{
		size_t pos = input.find(DELIM);
		double x = 0;
		double y = 0;
		double mag = 0; //magnitude
		string dir = ""; //direction

		for (auto c : input)
		{
			//input is number followed by letters followed by comma
			if (IsDigit(c))
			{
				mag = mag * 10 + c - 48;
			}
			else if (IsAlpha(c))
			{
				dir = dir + c;
			}
			else //either a comma or a period
			{
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

				//reset mag and dir for next set of directions
				mag = 0;
				dir = "";
			}//end else
		}

		double distance = sqrt(x * x + y * y);
		cout << fixed << setprecision(3);
		cout << "Map #" << mapNum++ << '\n';
		cout << "The treasure is located at (" << x << ',' << y << ").\n";
		cout << "The distance to the treasure is " << distance << ".\n\n";
		getline(cin, input);
	}
}