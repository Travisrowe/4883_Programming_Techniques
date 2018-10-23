//BasesAreLoaded : UVa 355 : Travis Rowe : Thiefone18 : 10/23/18

#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;

string convertToBaseB(long baseTenNum, int b)
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

void PrintOutput(int Obase, int Nbase, string Onum, string Nnum)
{
	cout << Onum << " base " << Obase << " = " << Nnum << " base " << Nbase << '\n';
	//printf("%s base %d = %s base %d", Onum, Obase, Nnum, Nbase);
}

int main()
{
	int Obase, Nbase;
	string Onum, Nnum;
	long baseTenNum;
	while (cin >> Obase)
	{
		cin >> Nbase >> Onum;
		bool isLegal = true;

		////convert string to int to check if number is legal
		//int tempNum = std::stoi(Onum, nullptr, Obase); 
		//while (tempNum > 0 && isLegal)
		//{
		//	//ensure each digit is less than the base it is in
		//	if (tempNum % 10 >= Obase)
		//		isLegal = false;
		//	tempNum /= 10;
		//}

		long temp = std::stol("126", nullptr, 5);

		if (isLegal)
		{
			//stoul converts a string to an unsigned long, given the base of the string
			baseTenNum = std::stol(Onum, nullptr, Obase);
			//now baseTenNum is our number in base 10

			if (Nbase == 10)
				PrintOutput(Obase, Nbase, Onum, std::to_string(baseTenNum));
			else
			{
				Nnum = convertToBaseB(baseTenNum, Nbase);
				PrintOutput(Obase, Nbase, Onum, Nnum);
			}
		}
		else 
			cout << Onum << " is an illegal base " << Obase << " number\n";
	}
}