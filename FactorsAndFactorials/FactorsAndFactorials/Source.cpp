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
	set<int> primes; //list of prime numbers up to 1,000,000
	SetSieveOfEratosthenes(primes);
	
	//stores number of prime numbers whose product equals the key
	vector<int> primeMultiples;
	cin >> n;
	while (n != 0)
	{
		primeMultiples.assign(15, 0); //fill vector with 15 0s
		m = n;
		while (m > 1)
		{
			set<int>::iterator iter = primes.find(m);
			if (iter != primes.end()) // m is a prime number
			{
				//index that iter is pointing to
				int index = distance(primes.begin(), iter); 
				primeMultiples[index]++;
				m--;
			}
			else //m is a multiple of a prime number, we must find that number
			{
				set<int>::iterator it = primes.begin();
				int o = m % (int)*it;
				while (o != 0 && it != primes.end())
				{
					it++;
					o = m % (int)*it;
				} //the prime which m is divisible by has been found
				int index = distance(primes.begin(), it);
				primeMultiples[index]++;
				m = m / (int)*it;
			}
		}
		cout.width(3);
		cout << right << n << "! = ";
		for (auto i : primeMultiples)
		{
			cout.width(3);
			cout << right << primeMultiples[i];
		}
		cout << '\n';
		cin >> n;
	}
}