// Relational Operators		UVa #11172	Travis Rowe	Thiefone18	9/4/18

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> y;
		if (x > y)
			cout << ">" << endl;
		else if (x < y)
			cout << "<" << endl;
		else
			cout << "=" << endl;
	}
}