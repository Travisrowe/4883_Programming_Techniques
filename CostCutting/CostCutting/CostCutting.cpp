// Travis Rowe: CostCutting.cpp : 11727: Thiefone18
//

#include <iostream>

using namespace std;

int main()
{
	int n, x, y, z;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		cin >> z;
		cout << "Case " << i + 1 << ": ";
		if (x > y) //x is either the highest or middle
		{
			if (y > z) // x > y > z
				cout << y << endl;
			else if (x > z) //x > z > y
				cout << z << endl;
			else // z > x > y
				cout << x << endl;
		}
		else //y is either the highest or the middle
		{
			if (x > z) // y > x > z
				cout << x << endl;
			else if (y > z) // y > z > x
				cout << z << endl;
			else // z > y > x
				cout << y << endl;
		}
	}
}