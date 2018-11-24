//LargestSubmatrix : UVa 836 : Travis Rowe : Thiefone18 : 11/20/18

//This is a 2D Range Sum Query (RSQ) problem.
//For a 1D RSQ problem see Jackpot or Halim & Halim p. 103

//For this we will store in i,j the sum of all indexes from 0, 0 to i, j

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> //max function
using namespace std;

int main()
{
	int T; //test cases
	cin >> T;
	cin.ignore(2); //ignore the crlf after int T and ignore the blank line
	for (int i = 0; i < T; i++) //test case loop
	{
		vector<vector<int>> mat;
		string inp;
		while (cin >> inp && inp != "")
		{
			vector<int> matRow;

			//matRow is a 1D RSQ of the current row
			matRow.push_back(inp[0] - 48);
			for (int i = 1; i < inp.length(); i++)
				matRow.push_back((inp[i] - 48) + matRow[i - 1]);

			//now to make matRow the 2D RSQ, we add the 1D RSQ of matRow to the 2D RSQ
			//of the node right above matRow in mat
			if (!mat.empty())
			{
				for (int i = 0; i < matRow.size(); i++)
				{
					//add matRow[i] the node at [bottom row of mat][i]
					matRow[i] += mat[mat.size() - 1][i];
				}
			}
			//add matRow to mat
			mat.push_back(matRow);
		} //mat is read in with Range Sums



		////print mat
		//for (int r = 0; r < mat.size(); r++)
		//{
		//	for (int c = 0; c < mat[r].size(); c++)
		//	{
		//		cout.width(3);
		//		cout << mat[r][c] << ' ';
		//	}
		//	cout << '\n';
		//}
	}
}