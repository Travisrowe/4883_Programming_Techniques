//BasesAreLoaded : UVa 355 : Travis Rowe : Thiefone18 : 10/23/18

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> //includes reverse method
using namespace std;


int charVal(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

string convertToBaseB(long long baseTenNum, int b)
{
	string Nnum = "";
	while (baseTenNum != 0)
	{
		int digit = baseTenNum % b;
		if (digit < 10)
			Nnum += digit + '0';
		else
			Nnum += digit - 10 + 'A';
		baseTenNum /= b;
	}
	//Num is backwards, reverse it
	reverse(Nnum.begin(), Nnum.end());
	return Nnum;
}

long long convertToBaseTen(string num, int base)
{
	long long deciNum = 0;
	int len = num.length();
	long long power = 1;
	for (int i = 1; i <= len; i++)
	{
		int val = charVal(num[len - i]);
		if (val >= base)
		{
			cout << num << " is an illegal base " << base << " number\n";
			return -1;
		}
		deciNum += val * power;
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
		long long baseTenNum = convertToBaseTen(Onum, Obase);

		if (baseTenNum != -1 && Nbase == 10)
			PrintOutput(Obase, Nbase, Onum, std::to_string(baseTenNum));
		else if(baseTenNum != -1) //-1 if illegal number
		{
			Nnum = convertToBaseB(baseTenNum, Nbase);
			PrintOutput(Obase, Nbase, Onum, Nnum);
		}
	}
}