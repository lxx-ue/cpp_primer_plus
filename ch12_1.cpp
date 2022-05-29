#include <iostream>
#include "ch12_1.h"
using std::cout;

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, nm);
	int len = std::strlen(ho);
	hobby = new char(len + 1);
	strcpy_s(hobby, strlen(c.hobby) + 1, ho);
	weight = wt;
}

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, c.name);
	int len = strlen(c.hobby);
	hobby = new char(len + 1);
	strcpy_s(hobby, strlen(c.hobby)+1, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c) return *this;
	delete[] hobby; //очищаем для новой строки
	hobby = new char(strlen(c.hobby) + 1);
	strcpy_s(hobby, strlen(c.hobby)+1, c.hobby);
	return *this;
}

void Cow::ShowCow() const
{
	cout << name;
}