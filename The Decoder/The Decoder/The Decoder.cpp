// The Decoder.cpp	UVA # 458	Travis Rowe	Thiefone18
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string inp;
	while (cin >> inp)
	{
		for (int i = 0; i < inp.length(); i++)
		{
			char letter = inp[i];
			cout << char(letter - 7);
		}
		cout << endl;
	}
}

