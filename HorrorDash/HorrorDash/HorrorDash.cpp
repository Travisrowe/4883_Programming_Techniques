// Travis Rowe: HorrorDash.cpp : 11799: Thiefone18
//

#include <iostream>

using namespace std;

int main()
{
	int t, n, greatest, x;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cout << "Case " << i + 1 << ": ";
		cin >> n;
		cin >> greatest;
		for (int j = 1; j < n; j++)
		{
			cin >> x;
			if (x > greatest)
				greatest = x;
		}
		cout << greatest << endl;
	}
}
