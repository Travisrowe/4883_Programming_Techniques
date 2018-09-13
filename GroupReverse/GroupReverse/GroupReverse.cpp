// GroupReverse.cpp : UVa # 11192	Travis Rowe	Thiefone18	9/13/18
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string inp, temp;
	int groupNum;
	while (cin >> groupNum)
	{
		if (groupNum == 0)
			break;
		inp = "";
		cin >> inp;
		int reverseNum = inp.length() / groupNum;
		vector<char> inpCopy(reverseNum);
		int index = 0;
		while (index < inp.length() - 1)
		{
			inp.copy(&inpCopy[0], reverseNum, index);
			for (int i = 0; i < reverseNum; i++)
			{
				inp[index] = inpCopy[reverseNum - i - 1];
				index++;
			}
		}
		cout << inp << endl;
	}
}
