//TheJackpot : UVa 10684 : Travis Rowe : Thiefone18 : 11/13/18

/* This is a Range Sum Query (RSQ) problem. We can solve it in 3 ways
 * (see Halim & Halim p. 103), but to solve it in O(n) time, we will use
 * Kadane's greedy algorithm. By having a running sum of the numbers, we
 * assume the answer, ans = Max(ans, sum). Also, if sum ever drops below
 * 0, we re-initialize sum to 0 and continue addition.
 * After the run, if ans = 0, we have a "Losing streak".
 */

#include <iostream>
#include <algorithm> //max
using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N != 0)
	{
		int num;
		int sum = 0, ans = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			sum += num; //greedily extend running sum
			ans = max(ans, sum); //keep maximum RSQ overall
			if (sum < 0) //if sum ever drops below 0, we reset it
				sum = 0;
		}
		if (ans > 0)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
		cin >> N;
	}
}
