//Andy's First Dictionary : UVa 10815 : Travis Rowe : Thiefone18 : 10/11/18

#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	set<string> dict;
	string word;
	while (cin >> word)
	{
		for (int i = 0; i < word.length(); i++)
		{
			word[i] = tolower(word[i]); //make word lowercase

			//check for non-letters, insert word before symbol
			if (!((char)word[i] >= 97 && (char)word[i] <= 122))
			{
				string tempWord = word.substr(i);
				word = word.substr(0, i);
				if ((char)word[0] >= 97 && (char)word[0] <= 123) //not a blank line
					dict.insert(word); //insert the first word

				//and loop through the second
				word = tempWord;
				i = 0;
				word.erase(i, 1);
				i--; //this ensures that all letters are checked even with an erase
			}
		}
		if ((char)word[0] >= 97 && (char)word[0] <= 123) //not a blank line
			dict.insert(word);
	}
	//print dictionary
	for (auto key : dict)
		cout << key << endl;
}