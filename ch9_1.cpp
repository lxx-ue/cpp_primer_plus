#include <iostream>
#include "ch9_1.h"

void setGolf(golf& g, const char* name, int hc) 
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

void setGolf(golf& g)
{
	std::cout << "Enter name: ";
	std::cin.getline(g.fullname, gLen);
	std::cout << "Enter handicap: ";
	std::cin >> g.handicap;
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showGolf(const golf& g)
{
	std::cout << "Name: " << g.fullname << "\t handicap: " << g.handicap << std::endl;
}