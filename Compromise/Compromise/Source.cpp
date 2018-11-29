//Compromise : UVa 531 : Travis Rowe : Thiefone18 : 11/20/18

//Longest Common Subsequence problem

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
	string inp;
	while (cin >> inp) //full test case loop
	{
		//make 0 index unused to match the lcsLengthMatrix
		vector<string> A = { "nullIndex" };
		vector<string> B = { "nullIndex" };
		while (inp != "#") //first vector loop
		{
			A.push_back(inp);
			cin >> inp;
		} //inp is now the # after the first document

		cin >> inp; //inp is the first word in the second document
		while (inp != "#") //second vector loop
		{
			B.push_back(inp);
			cin >> inp;
		} //inp is now the # after the second document

		//both vectors are filled, now check them for LCS

		//Initialize Matrix of size (A.size, B.size) with zeroes
		//Note the first row and column remains 0. This allows us to avoid
		//out of bounds exceptions if we start our loops at 1
		vector<vector<int>> lcsLengthMatrix(A.size(), vector<int>(B.size(), 0));
		for (int r = 1; r < A.size(); r++)
		{
			if (A[r] == "delegates")
				int x = 0;
			for (int c = 1; c < B.size(); c++)
			{
				int lcsLength;
				if (A[r] == B[c]) //we have common words, add them to the LCS
				{
					lcsLength = lcsLengthMatrix[r - 1][c - 1] + 1;
				}
				else
				{
					lcsLength = max(lcsLengthMatrix[r][c - 1], lcsLengthMatrix[r - 1][c]);
				}
				lcsLengthMatrix[r][c] = lcsLength;
			}
		}
		
		////print Matrix
		//for (int r = 0; r < A.size(); r++)
		//{
		//	for (int c = 0; c < B.size(); c++)
		//	{
		//		cout << lcsLengthMatrix[r][c] << ' ';
		//	}
		//	cout << '\n';
		//}

		//now our length matrix is filled, we just need to find the actual LCS
		int r = A.size() - 1, c = B.size() - 1;
		vector<string> lcs(lcsLengthMatrix[r][c]);
		while (r > 0 && c > 0)
		{
			int currNode = lcsLengthMatrix[r][c];
			//if currNode is greater than both the node to its left and the node above it
			if(currNode > lcsLengthMatrix[r - 1][c] && currNode > lcsLengthMatrix[r][c - 1])
			{
				//add this word to front of LCS and decrement both r and c
				lcs[currNode - 1] = A[r];
				--r;
				--c;
			}
			//otherwise the next currnode will be the greater value of the nodes
			//to the left and above currnode
			else if (lcsLengthMatrix[r][c - 1] >= lcsLengthMatrix[r - 1][c])
				--c; //move currnode to the left
			else
				--r; //move currnode upward
		}

		//LCS is filled in order (does not need to be reversed)
		for (auto str : lcs)
			cout << str << ' ';
		cout << '\n';
	}
}