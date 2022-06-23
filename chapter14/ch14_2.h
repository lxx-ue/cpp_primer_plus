#pragma once

#include <string>
#include <valarray>

using std::string;

typedef std::valarray<int> ArrayInt;
typedef std::pair<ArrayInt, ArrayInt> PairArray;

class Wine2 : private string, private PairArray
{
	int years;

public:
	Wine2() : string("No label"), years(0), PairArray(0, 0) {}
	Wine2(const char* l, int y) : string(l), years(y), PairArray(y, y) {}
	Wine2(const char* l, int y, const int yr[], const int bot[]);
	const string& Label() const { return (const string&) *this; }
	void GetBottles();
	int sum() const;
	void Show() const;
};