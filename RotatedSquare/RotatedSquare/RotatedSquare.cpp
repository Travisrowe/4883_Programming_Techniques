// RotatedSquare.cpp : UVa 10855	9/15/18	Travis Rowe	Thiefone18
//

//This is an advanced indexing problem, not much else to it than that

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int CheckNumCopies(vector<string> bigSquare, vector<string> lilSquare, int N, int n)
{
	int count = 0;
	bool isCopy;
	//N is width of big square, n is width of little square
	for (int c = 0; c <= N - n; c++) 
	{
		for (int r = 0; r <= N - n; r++)
		{
			//[r][c] is the current top-left
			//corner of the little square
			isCopy = true;
			for (int i = 0; i < n; i++)
			{
				if (lilSquare[i] != bigSquare[r + i].substr(c, n))
				{
					isCopy = false;
					goto NextSquare;
				} //end if
			}// end for i
NextSquare:
			if (isCopy)
				count++;
		}//end for r
	}//end for c
	return count;
}

void RotateSquare(vector<string>& square, int n)
{
	int numRings = n / 2;
	for (int r = 0; r < numRings; r++) 
		//r can actually stand for ring as well as row
		//because row only ever needs to equal ring
	{
		for (int c = r; c < n - r - 1; c++)
		{
				//value -> variable = value goes into variable
			char temp1 = square[c][n - 1 - r]; // top right -> temp1
			square[c][n - 1 - r] = square[r][c]; //top left -> top right
			char temp2 = square[n - 1 - r][n - 1 - c]; //bottom right -> temp2
			square[n - 1 - r][n - 1 - c] = temp1; //temp1 -> bottom right
			temp1 = square[n - 1 - c][r]; //bottom left -> temp1
			square[n - 1 - c][r] = temp2; //temp2 -> bottom left
			square[r][c] = temp1; //temp1 -> top left
		}
	}
}

void PrintSquare(vector<string> Square, int n)
{
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << Square[r][c];
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int N, n;
	string inp;

	while (cin >> N && cin >> n && N > 0)
	{
		vector<string> bigSquare(N);
		vector<string> lilSquare(n);
		for (int i = 0; i < N; i++)
		{
			cin >> bigSquare[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> lilSquare[i];
		}
		//0 degrees
		cout << CheckNumCopies(bigSquare, lilSquare, N, n) << " ";
		//90 degrees (clockwise)
		RotateSquare(lilSquare, n);
		cout << CheckNumCopies(bigSquare, lilSquare, N, n) << " ";
		//180 degrees
		RotateSquare(lilSquare, n);
		cout << CheckNumCopies(bigSquare, lilSquare, N, n) << " ";
		//270 degrees
		RotateSquare(lilSquare, n);
		cout << CheckNumCopies(bigSquare, lilSquare, N, n) << endl;
	}
}