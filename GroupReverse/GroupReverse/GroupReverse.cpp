// GroupReverse.cpp : UVa # 11192	Travis Rowe	Thiefone18	9/13/18
//

//uses the reverse function, which is in-situ

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string inp, temp;
	
	int numGroups;
	while (cin >> numGroups)
	{
		if (numGroups == 0)
			break;
		inp = "";
		cin >> inp;
		int reverseNum = inp.length() / numGroups;
		int startIndex = 0;
		while (startIndex < inp.length() - 1)
		{
			reverse(inp[startIndex], inp[startIndex + reverseNum]);
			/*inp.copy(&inpCopy[0], reverseNum, startIndex);
			for (int i = 0; i < reverseNum; i++)
			{
				inp[startIndex] = inpCopy[reverseNum - i - 1];
				startIndex++;
			}*/
			startIndex += reverseNum;
		}
		cout << inp << endl;
	}
}
