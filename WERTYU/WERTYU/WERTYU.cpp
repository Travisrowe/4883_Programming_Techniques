// WERTYU.cpp	 UVA # 10082	Travis Rowe	Thiefone18
//

//This relies on ASCII indexing and a vector with similar indices

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string Alphabet = "'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`";
	string WERTY    = ";897-M0,.9`12345678LLM-,.1 VXSWDFGUHJKNBIO EARYCQZT P][50 ";
	char letter;
	while (cin >> noskipws >> letter)
	{
		if (char(letter) == 32)
			cout << ' ';
		else if (char(letter == 10))
			cout << endl;
		else
			cout << WERTY[char(letter) - 39];
	}
}
