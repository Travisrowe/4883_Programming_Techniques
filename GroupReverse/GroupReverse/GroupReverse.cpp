// GroupReverse.cpp : UVa # 11192	Travis Rowe	Thiefone18	9/13/18
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string inp, temp;
	int reverseNum;
	while (cin >> reverseNum)
	{
		inp = "";
		cin >> inp;
		vector<char> inpCopy;
		int index = 0;
		while (index < inp.length())
		{
			//copy letters to be reversed
			for (int i = 0; i < reverseNum; i++)
			{
				inpCopy[i] = inp[i];
			}

			for (int i = reverseNum - 1; i >= 0; i--)
			{
				inpCopy.push_back(inp[i]);
				inp[index] = inpCopy[i];
			}
			index += reverseNum;
		}
		cout << inp << endl;
	}
}
