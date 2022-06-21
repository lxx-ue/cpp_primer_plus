#pragma once

#include <string>
#include <valarray>

using std::string;

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
	string label;
	PairArray bottles; // first - yeats, second - count
	int years;

public:
	Wine() : label("No label"), years(0), bottles(0, 0) {}
	Wine(const char* l, int y) : label(l), years(y), bottles(y, y) {}
	Wine(const char* l, int y, const int yr[], const int bot[]);
	string& Label() { return label; }
	void GetBottles();
	int sum();
	void Show();
};