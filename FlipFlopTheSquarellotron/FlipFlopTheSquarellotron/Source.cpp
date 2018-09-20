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
			cout << square[r][c] << " ";
		}
		cout << endl;
	}
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
		//Print(square, N);
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
				if (j != (int)numRings) //if flips won't affect the square, don't do them
				{
					switch (C)
					{
					case 1: //Up Down Swap
						for (int c = UL; c <= LR; c++)
							//swap top row with bottom
							swap(square[UL][c], square[LR][c]);
						for (int r = UL + 1; r < numRings; r++)
						{
							//swap left column until halfway point
							swap(square[r][UL], square[N - r - 1][UL]);
							//swap right column until halfway point
							swap(square[r][LR], square[N - r - 1][LR]);
						}
						/*cout << "Up Down swap" << endl;
						Print(square, N);*/
						break;
					case 2: //Left Right swap
						for (int r = UL; r <= LR; r++)
							//swap left column with right
							swap(square[r][UL], square[r][LR]);
						for (int c = UL + 1; c < numRings; c++)
						{
							//swap top row until halfway point
							swap(square[UL][c], square[UL][N - c - 1]);
							//swap bottom row until halfway point
							swap(square[LR][c], square[LR][N - c - 1]);
						}
						/*cout << "Left Right swap" << endl;
						Print(square, N);*/
						break;
					case 3: //Main diag swap
						for (int r = UL + 1; r <= LR; r++)
							//swaps left col and top row of selected ring
							swap(square[r][UL], square[UL][r]);
						for (int c = UL + 1; c < LR; c++)
							//swap bottom row and right col of selected ring
							swap(square[LR][c], square[c][LR]);
						/*cout << "Main diag swap" << endl;
						Print(square, N);*/
						break;
					case 4: //inv diag swap
						for (int r = UL + 1; r <= LR; r++)
							//swap bottom row and left column
							swap(square[LR][r], square[N - r - 1][UL]);
						for(int c = UL + 1; c < LR; c++)
							//swap top row and right column
							swap(square[UL][N - c - 1], square[c][LR]);

						/*cout << "Inv diag swap" << endl;
						Print(square, N);*/
						break;
					}//end switch
				}//end if
			}//end for each T
		}//end for each numRings
		Print(square, N);
		//cout << endl;
	}
}