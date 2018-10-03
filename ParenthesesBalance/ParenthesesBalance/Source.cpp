// Parentheses Balance	UVa 673	Travis Rowe	thiefone18	9/24/18

#include <stack>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, x = 1;
	cin >> n;
	cin.ignore(); // cin leaves a carriage return unread.
		//getline will grab that instead of the next line of data
		//unless we .ignore() it

	//iterate through each line of input
	for (int i = 0; i < n; i++)
	{
		stack<char> stk;
		string s;
		char c;
		getline(cin, s); //does not skip blank lines
		//iterate through each char of s
		for (int j = 0; j < s.length(); j++)
		{

			if (s[j] == '(' || s[j] == '[' || stk.empty())
				stk.push(s[j]);
			else if (s[j] == ')' || s[j] == ']') 
			{
				//the ASCII difference between ( and ) is 1.
				//the ASCII difference between [ and ] is 2.
				if (s[j] - stk.top() == 2 || s[j] - stk.top() == 1)
					stk.pop();
				else
					stk.push(s[j]);
			}
		}//end iterate through s
		//if (x == 5)
		//	int y = 0;
		//cout << x++ << ": ";
		if (stk.empty()) cout << "Yes\n";
		else cout << "No\n";
	}//end iterate through line of input
}