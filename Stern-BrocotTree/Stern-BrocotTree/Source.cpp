//Stern-Brocot Tree : UVa 11350 : Travis Rowe : Thiefone18 : 10/23/18
/* Can be a tree of tuples, the root node is 1/1
 * just have constants as 0/1 and 1/0
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

struct Fraction
{
	long long numerator;
	long long denominator;

	Fraction(long long n, long long d) { numerator = n; denominator = d; }
};

Fraction CalculateNext(Fraction l, Fraction r, Fraction curr, string inp)
{
	if (inp[0] == 'R')
	{
		l = curr;
		curr.numerator = curr.numerator + r.numerator;
		curr.denominator = curr.denominator + r.denominator;
	}
	else if (inp[0] == 'L')
	{
		r = curr;
		curr.numerator = curr.numerator + l.numerator;
		curr.denominator = curr.denominator + l.denominator;
	}
	else
		return curr;
	return CalculateNext(l, r, curr, inp.substr(1));
}

int main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		Fraction left(0, 1);
		Fraction right(1, 0);
		Fraction current(1, 1);
		string inp;
		cin >> inp;
		
		current = CalculateNext(left, right, current, inp);
		cout << current.numerator << "\/" << current.denominator << '\n';
	}
}