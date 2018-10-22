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
	int numerator;
	int denominator;

	Fraction(int n, int d) { numerator = n; denominator = d; }
	//void InsertLeft;
};

int main()
{
	int N;
	cin >> N;

	const Fraction ZERO(0, 1);
	const Fraction INFIN(1, 0);

	vector<Fraction> tree;
	Fraction fract(1, 1);
	tree.push_back(fract);

	for (int i = 0; i < N; i++)
	{
		string inp;
		cin >> inp;
		if (inp.length() > log( (double)tree.size() )); //needs more inserts
	}
}