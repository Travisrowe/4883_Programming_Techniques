// MagicNumbers : UVa 471 : Travis Rowe : Thiefone18 : 10/9/18
#include <bitset>
#include <iostream>
using namespace std;

bool NoRepeatingDigits(long long s)
{
	bitset<10> tracker;
	while (s > 0)
	{
		if (tracker[s % 10] != 1)
		{
			tracker[s % 10].flip();
			s /= 10;
		}
		else //the bit has been flipped already, therefore we have a repeat
			return false;
	}
	return true;
}

int main()
{
	long long T, N; //num test cases
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		long long s1 = 1, s2;
		while (N * s1 <= 9876543210)
		{
			if (NoRepeatingDigits(s1))
			{
				s2 = N * s1;
				if (NoRepeatingDigits(s2))
					cout << s2 << " / " << s1 << " = " << N << '\n';
			}
			s1++;
		}
		if(i < T - 1) cout << '\n';
	}
}