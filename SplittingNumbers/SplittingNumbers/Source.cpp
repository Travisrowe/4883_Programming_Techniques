//SplittingNumbers: UVa 11933: Thiefone18: Travis Rowe: 10/5/2018

#include <bitset>
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		bitset<32> binNum(n);
		bitset<32> a;
		bitset<32> b;
		int oddEven = 1;
		for (int n = 0; n < 32; n++)
		{
			if (binNum.test(n))
			{
				if (oddEven++ % 2 == 1)
					a.set(n);
				else
					b.set(n);
			}
		}
		cout << a.to_ulong() << ' ' << b.to_ulong() << '\n';
		cin >> n;
	}
	return 0;
}