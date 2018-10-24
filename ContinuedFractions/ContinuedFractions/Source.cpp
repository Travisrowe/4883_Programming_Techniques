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
	int n, d;
	while (cin >> n)
	{
		vector<int> contFraction;
		cin >> d;
		Fraction fract(n, d);
		while (d > 1)
		{
			if (n >= d)
			{
				contFraction.push_back((int)n / d);
				n = n % d;
			}

			//flip fraction
			int temp = n;
			n = d;
			d = temp;
		}
		cout << "[" << contFraction[0] << ";";
		for (int i = 1; i < contFraction.size(); i++)
			cout << contFraction[i] << ",";
		cout << "]\n";
	}
}