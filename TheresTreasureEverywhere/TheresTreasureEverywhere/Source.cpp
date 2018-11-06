//TheresTreasureEverywhere.cpp : UVa 587 : Travis Rowe : Thiefone18 : 11/4/18
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	string input;
	const string DELIM = ",";
	getline(cin, input); //input is the full line
	while (input != "END")
	{
		size_t pos = input.find(DELIM);
		double x = 0;
		double y = 0;
		while (pos != 0)
		{
			stringstream ss;
			string token = input.substr(0, pos);
			input = input.substr(pos + 1);
			ss << token;
			int mag; //magnitude
			string dir; //direction
			ss >> mag >> dir;

			cout << mag << dir << endl;
		}
		getline(cin, input);
	}
}