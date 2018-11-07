//IsThisIntegration.cpp : UVa 10209 : Travis Rowe : Thiefone18 : 11/5/18
#include <iostream>
#include <iomanip>
using namespace std;

#define PI 3.14159265

int main()
{
	long double a;
	while (cin >> a)
	{
		//based on diagram in notes.pdf

		//calculate center, striped area
		//find area of square + area of slivers outside the square
		long double FE = 2.0 * (a * sin(30.0 * PI / 180.0));
		long double centerSquareArea = FE * FE;
		long double coneBEFArea = PI * a * a * (30.0 / 360.0);

		//Heron's Rule
		long double s = (2.0 * a + FE) / 2.0;
		long double triangleBEFArea = sqrt(s * (s - FE) * (s - a) * (s - a));
		long double centerSliversArea = (coneBEFArea - triangleBEFArea);
		long double centerArea = centerSquareArea + centerSliversArea * 4;

		//calculate dotted region
		//find (area of triangle - area of inner sliver) + area of slivers outside of triangle
		//Heron's Rule
		//triangle DEF is equilateral
		s = (3.0 * FE) / 2.0;
		long double triangleDEFArea = sqrt(s * (s - FE) * (s - FE) * (s - FE)); 
		//area of outer slivers is equal to area of center slivers
		long double DEFOuterSlivers = centerSliversArea;
		long double dottedArea = (triangleDEFArea + DEFOuterSlivers) * 4.0;

		//calculate grid region
		//find area of triangle - area of slivers inside triangle
		//Heron's rule again
		//triangle DFC is isosceles
		s = (2.0 * FE + a) / 2.0;
		long double triangleDFCArea = sqrt(s * (s - FE) * (s - FE) * (s - a));
		//the same slivers we added to the dotted region, we subtract here
		long double gridArea = (triangleDFCArea - 2 * DEFOuterSlivers) * 4.0;

		cout << fixed;
		cout << setprecision(3) << centerArea << ' ';
		cout << dottedArea << ' ';
		cout << gridArea << '\n';
	}
}