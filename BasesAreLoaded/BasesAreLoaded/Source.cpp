//BasesAreLoaded : UVa 355 : Travis Rowe : Thiefone18 : 10/23/18

#include <iostream>
#include <string>
using namespace std;

string convertToBaseB(unsigned long u1, int b)
{
	string Nnum = "";
	while (u1 != 0)
	{
		int digit = u1 % b;
		Nnum += digit + '0';
		u1 /= b;
	}
	return Nnum;
}

void PrintOutput(int Obase, int Nbase, string Onum, string Nnum)
{
	cout << Onum << " base " << Obase << " = " << Nnum << " base " << Nbase << '\n';
	//printf("%s base %d = %s base %d", Onum, Obase, Nnum, Nbase);
}

int main()
{
	int Obase, Nbase;
	string Onum, Nnum;
	unsigned long u1;
	while (cin >> Obase)
	{
		cin >> Nbase >> Onum;
		//convert string to int to check if number is legal
		int tempNum = std::stoi(Onum); 
		bool isLegal = true;
		while (tempNum > 0 && isLegal)
		{
			//ensure each digit is less than the base it is in
			if (tempNum % 10 >= Obase)
				isLegal = false;
			tempNum /= 10;
		}

		if (isLegal)
		{
			//stoul converts a string to an unsigned long, given the base of the string
			u1 = std::stoul(Onum, nullptr, Obase);
			//now u1 is our number in base 10

			if (Nbase == 10)
				PrintOutput(Obase, Nbase, Onum, std::to_string(u1));
			else
			{
				Nnum = convertToBaseB(u1, Nbase);
				PrintOutput(Obase, Nbase, Onum, Nnum);
			}
		}
		else 
			cout << Onum << " is an illegal base " << Obase << " number\n";
	}
}