#pragma once
#include <iostream>
#include <typeinfo>

using std::cout;


class Grand
{
	int hold;
public:
	Grand(int h = 0) : hold(h) {}
	virtual void Speak() const { cout << "I am à grand class!\n"; }
	virtual int Value() const { return hold; }
};

class Superb : public Grand
{
public:
	Superb(int h = 0) : Grand(h) {}
	void Speak() const { cout << "I am à superb class!! \n "; }
	virtual void Say() const
	{
		cout << "I hold the superb value of " << Value() << "! \n ";
	}
};

class Magnificent : public Superb
{
	char ch;
public:
	Magnificent(int h = 0, char cv = 'À') : Superb(h), ch(cv) {}
	void Speak() const
	{
		cout << "I am à magnificent class!!! \n ";
	}
	void Say() const
	{
		cout << "I hold the character " << ch << " and the integer " << Value() << "! \n";
	}
};