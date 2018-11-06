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
	int decrN, n;
	set<int> primes; //list of prime numbers up to 1,000,000
	SetSieveOfEratosthenes(primes);
	
	//stores number of prime numbers whose product equals the key
	vector<int> primeMultiples;
	cin >> n;
	while (n != 0)
	{
		primeMultiples.assign(n, 0); //fill vector with n 0s
		int primeMultSize = 0; //used to keep from printing trailing 0s
		decrN = n; //Decrementing N
		while (decrN > 1)
		{
			int index;
			set<int>::iterator iter = primes.find(decrN);
			if (iter != primes.end()) // decrN is a prime number
			{
				//index that iter is pointing to
				index = distance(primes.begin(), iter); 
				primeMultiples[index]++;
			}
			else //decrN is a multiple of a prime number, we must find that number
			{
				set<int>::iterator it = primes.begin();
				int m = decrN;
				while (m > 1)
				{ //find all primes within the current factorial
					int o = m % (int)*it;
					while (o != 0 && it != primes.end())
					{ //find the prime which m is divisible by
						it++;
						o = m % (int)*it;
					}

					//index that iter is pointing to
					index = distance(primes.begin(), it);
					primeMultiples[index]++;

					//divide m by the prime it's divisible by
					m = m / (int)*it;
				}//end while m
			}//end else

			if (index > primeMultSize)
				primeMultSize = index;

			decrN--;
		} //end while decrN
		cout.width(3);
		cout << right << n << "! =";
		for (int i = 0; i <= primeMultSize; i++)
		{
			if (i == 0 || i % 15 != 0)
				cout.width(3);
			else
			{
				cout << '\n';
				cout.width(9);
			}
			cout << right << primeMultiples[i];
		}
		cout << '\n';
		cin >> n;
	}//end while n
}