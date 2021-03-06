// VitosFamily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T; //number of test cases
	int n; //number of streets we're about to read
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		cin >> n;
		vector<int> H(n);
		for (int j = 0; j < n; j++)
		{
			cin >> H[j];
		}
		sort(H.begin(), H.end()); //end points after the last variable in a vector

		// Have a left and right pointer which start to begin and end, then increment/decrement by one
		// Subtract those two street numbers and add that to a sum. When the pointers hit each other
		// the sum is your output.
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
