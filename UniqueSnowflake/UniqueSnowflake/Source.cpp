#include <iostream>
#include <unordered_map>
using namespace std;

typedef unordered_map<int, bool>::iterator mapIter;

int main()
{
	int T, n, snowflake;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		unordered_map<int, bool> myMap(n * 2); //pre-allocate double the necessary size
		int greatestCount = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> snowflake;
			mapIter iter;
			iter = myMap.find(snowflake);
			if (iter != myMap.end()) //snowflake was found
			{
				//erase all values before and including iter
				mapIter newStart = myMap.begin();
				iter++; //increment iter so the clone gets erased
				while (newStart != iter)
				{
					mapIter temp = newStart;
					newStart++;
					myMap.erase(temp);
				}
			}
			myMap[snowflake] = true;
			//set greatestCount
			if (myMap.size() > greatestCount)
				greatestCount = myMap.size();
		}
		cout << greatestCount << '\n';
	}
}