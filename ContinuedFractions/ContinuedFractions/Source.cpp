//Continued Fractions : UVa 834 : Travis Rowe : Thiefone18 : 10/25/18
#include <vector>
#include <iostream>
using namespace std;

struct Fraction
{
	int numerator;
	int denominator;

	Fraction(int n, int d)
	{
		numerator = n;
		denominator = d;
	}
};

int main()
{
	int n, d, line = 1;
	while (cin >> n)
	{
		/*if (line++ == 44)
			int x = 0;*/
		vector<int> contFraction;
		cin >> d;
		Fraction fract(n, d);
		while (d > 0)
		{
			if (n >= d)
			{
				contFraction.push_back((int)n / d);
				n = n % d;
			}
			else
				contFraction.push_back(0);
			//flip fraction
			int temp = n;
			n = d;
			d = temp;
		}
		cout << "[";
		for (int i = 0; i < contFraction.size(); i++)
		{
			cout << contFraction[i];
			if (i == 0 && i < contFraction.size() - 1)
				cout << ";";
			else if(i < contFraction.size() - 1)
				 cout << ",";
			else
				cout << "]\n";
		}
		
	}
}