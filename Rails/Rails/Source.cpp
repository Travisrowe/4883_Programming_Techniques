// Rails : UVa 514 : Travis Rowe Thiefone18

#include <stack>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int N, r;
	cin >> N;
	while (N != 0)
	{
		//cout << N << endl;
		//build incoming train (vector)
		vector<int> train(N); 
		for (int i = 1; i <= N; i++)
			train[i - 1] = i;
		//train is established

		//check for reorder requests
		cin >> r;
		while (r != 0)
		{
			queue<int> reorderQueue;
			stack<int> stationStack;
			reorderQueue.push(r);
			for (int i = 1; i < N; i++)
			{
				cin >> r;
				reorderQueue.push(r);
			} //current reorder request is read in
			
			//process reorder, cout yes or no
			for (int i = 0; i < N; i++)
			{
				stationStack.push(train[i]);
				while(!stationStack.empty() && 
					stationStack.top() == reorderQueue.front())
				{
					//check the stack for the current order
					//otherwise, check the train
					stationStack.pop();
					reorderQueue.pop();
				}
			}
			if (stationStack.empty())
				cout << "Yes\n";
			else
				cout << "No\n";

			//check for more reorder requests
			cin >> r;
		} //all reorders processed for this block
		cout << '\n';
		//check for more blocks
		cin >> N;
	}
}