#include "ch14_1.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	: label(l), years(y), bottles(y, y)
{
	for (int i = 0; i < y; i++)
	{
		bottles.first[i] = yr[i];
		bottles.second[i] = bot[i];
	}
}

void Wine::GetBottles()
{
	cout << "Enter " << label << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> bottles.first[i];
		cout << "Enter bottles for that year: ";
		cin >> bottles.second[i];
	}
}

int Wine::sum()
{
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += bottles.second[i];
	return sum;
}

void Wine::Show()
{
	cout << "Wine: " << label << "\n\tYear\tBottles\n";
	for (int i = 0; i < years; i++)
		cout << "\t" << bottles.first[i] << "\t" << bottles.second[i] << endl;
}