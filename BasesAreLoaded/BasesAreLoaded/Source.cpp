//BasesAreLoaded : UVa 355 : Travis Rowe : Thiefone18 : 10/23/18

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int charVal(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

string convertToBaseB(int baseTenNum, int b)
{
	string Nnum = "";
	while (baseTenNum != 0)
	{
		int digit = baseTenNum % b;
		Nnum += digit + '0';
		baseTenNum /= b;
	}
	return Nnum;
}

int convertToBaseTen(string num, int base)
{
	int deciNum = 0;
	int len = num.length();
	int power = 1;
	for (int i = 1; i <= len; i++)
	{
		if (charVal(num[len - i]) >= base)
		{
			cout << num << " is an illegal base " << base << " number\n";
			return -1;
		}
		deciNum += charVal(num[len - i]) * power;
		power = power * base;
	}
	return deciNum;
}


void PrintOutput(int Obase, int Nbase, string Onum, string Nnum)
{
	cout << Onum << " base " << Obase << " = " << Nnum << " base " << Nbase << '\n';
	//printf("%s base %d = %s base %d", Onum, Obase, Nnum, Nbase);
}

int main()
{
	int Obase, Nbase;
	string line;
	string Onum, Nnum;
	while (getline(cin, line))
	{
		stringstream(line) >> Obase >> Nbase >> Onum;

		//convert our Onum to an integer in base ten
		int baseTenNum = convertToBaseTen(Onum, Obase);

		if (Nbase == 10)
			PrintOutput(Obase, Nbase, Onum, std::to_string(baseTenNum));
		else if(baseTenNum != -1) //-1 if illegal number
		{
			Nnum = convertToBaseB(baseTenNum, Nbase);
			PrintOutput(Obase, Nbase, Onum, Nnum);
		}
	}
}