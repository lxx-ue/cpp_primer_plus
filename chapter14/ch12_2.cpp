#include "ch14_2.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

Wine2::Wine2(const char* l, int y, const int yr[], const int bot[])
	: string(l), years(y), PairArray(y, y)
{
	for (int i = 0; i < y; i++)
	{
		PairArray::first[i] = yr[i];
		PairArray::second[i] = bot[i];
	}
}

void Wine2::GetBottles()
{
	cout << "Enter " << (const string&)*this << " data for " << years << " year(s):\n";
	for (int i = 0; i < years; i++)
	{
		cout << "Enter year: ";
		cin >> PairArray::first[i];
		cout << "Enter bottles for that year: ";
		cin >> PairArray::second[i];
	}
}

int Wine2::sum() const
{
	int sum = 0;
	for (int i = 0; i < years; i++)
		sum += PairArray::second[i];
	return sum;
}

void Wine2::Show() const 
{
	cout << "Wine: " << (const string&)*this << "\n\tYear\tBottles\n";
	for (int i = 0; i < years; i++)
		cout << "\t" << PairArray::first[i] << "\t" << PairArray::second[i] << endl;
}