//IsThisIntegration.cpp : UVa 10209 : Travis Rowe : Thiefone18 : 11/5/18
#include <iostream>
using namespace std;

int main()
{
	double a;
	while (cin >> a)
	{
		//based on diagram in notes.pdf
		double BF = a;
		double GF = a * sin(30); //wrong
		double BG = a * cos(30); //wrong
		cout << GF << ' ' << BG;
	}
}