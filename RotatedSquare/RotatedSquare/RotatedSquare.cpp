// RotatedSquare.cpp : UVa 10855	9/15/18	Travis Rowe	Thiefone18
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N, n;
	string inp;
	
	while (cin >> N && cin >> n)
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
	}
}

void RotateSquare(vector<string> square, int n)
{

}

void PrintSquares(vector<string> bigSquare, vector<string> lilSquare, int N, int n)
{
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			cout << bigSquare[r][c];
		}
		cout << endl;
	}
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << lilSquare[r][c];
		}
		cout << endl;
	}
}