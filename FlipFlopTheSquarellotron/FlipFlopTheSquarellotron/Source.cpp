//Flip-Flop the Squarellotron:	UVa 10016	Travis Rowe	Thiefone18	9/20/18

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Print(vector<vector<int>> square, int N)
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << square[r][c] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int M, N, T, C;
	cin >> M; //number of squares
	for (int i = 0; i < M; i++)
	{
		cin >> N; //length,width of square
		vector<vector <int>> square(N, vector<int> (N));

		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < N; c++)
			{
				cin >> square[r][c];
			}
		}
		Print(square, N);
		double numRings = (double)N / 2;
		int UL, LR; //Upper left and lower right corner
		for (int j = 0; j < numRings; j++)
		{
			UL = j;
			LR = N - j - 1;
			cin >> T; //number of flips to be done on square
			for (int k = 0; k < T; k++)
			{
				cin >> C; //type of flip to be done on square
				switch (C)
				{
				case 1: //Up Down Swap
					break;
				case 2: //Left Right swap
					break;
				case 3: //Main diag swap
					for (int r = UL + 1; r <= LR; r++)
						//swaps left col and top row of selected ring
						swap(square[r][UL], square[UL][r]);
					for (int c = UL + 1; c < LR; c++)
						//swap bottom row and right col of selected ring
						swap(square[LR][c], square[c][LR]);
					Print(square, N);
					break;
				case 4: //inv diag swap
					int tempLR = LR, tempUL = UL;
					while (tempLR >= 0)
						//swap right col and top row
						swap(square[UL][tempLR--], square[tempUL++][LR]);
					tempLR = LR, tempUL = UL;
					while(tempLR > 0)
						//swap left col and bottom row
						swap(square[LR][tempUL++], square[tempLR--][UL]);
					Print(square, N);
					break;
				}

			}
		}

		cout << endl;
	}
}