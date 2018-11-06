//GoldbachsConjecture : UVa 543 : Travis Rowe : Thiefone18 : 10/30/18

#include <set>
#include <bitset>
#include <iostream>
using namespace std;

void SetSieveOfEratosthenes(set<int> &primes)
{
	bitset<1000001> sieve; // 1,000,001
	sieve.set();
	for (long long i = 2; i < sieve.size(); i++)
	{
		if (sieve[i] == 1) //mark all multiples of this number as false
		{
			for (long long j = i * i; j < sieve.size(); j += i)
				sieve.set(j, false); //mark as false
			primes.insert(i); //makes this algorithm O(log(n))
		}
		//else this number has already been marked as not prime
		//and does not need to be processed
	}
}

int main()
{
	set<int> sieve;
	SetSieveOfEratosthenes(sieve);

	int n;
	cin >> n;
	while (n != 0)
	{
		set<int>::iterator iter;
		int difference = 0, greatestDiff = 0;
		iter = sieve.begin();

		//if(n - iter = a prime number, we've found our answer
		while (sieve.find(n - (int)*iter) == sieve.end())
		{
			iter++; //iterate iter
		}
		printf("%d = %d + %d\n", n, (int)*iter, n - (int)*iter);

		cin >> n;
	}
}