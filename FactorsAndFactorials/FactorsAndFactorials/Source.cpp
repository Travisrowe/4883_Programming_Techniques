//FactorsAndFactorials : UVa 160 : Travis Rowe : Thiefone18 : 10/30/18

#include <vector>
#include <bitset>
#include <unordered_map>
#include <map>
#include <iostream>
#include <set>

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
	int m, n;
	set<int> primes; //list of prime numbers between up to 1,000,000
	SetSieveOfEratosthenes(primes);
	
	//map that stores number of prime numbers whose product equals the key
	unordered_map<int, vector<int>> primeMultiples;
	cin >> n;
	while (n != 0)
	{
		m = n - 1;


		cin >> n;
	}
}