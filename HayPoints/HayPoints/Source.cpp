#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	map<string, int> myMap;
	map<string, int>::iterator it;
	string word;
	int val;
	for (int i = 0; i < m; i++) //read in map
	{
		cin >> word >> val;
		myMap[word] = val;
	}
	for (int i = 0; i < n; i++) //read each job description
	{
		int salary = 0;
		cin >> word;
		while (word != ".")
		{
			it = myMap.find(word);
			if (it != myMap.end())
				salary += myMap[word];
			cin >> word;
		}
		cout << salary << '\n';
	}
}