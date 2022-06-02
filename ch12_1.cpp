#include <iostream>
#include "ch12_1.h"

using std::cout;

Cow::Cow(const char* nm, const char* ho, double wt)
{
	len = std::strlen(ho);
	hobby = new char[len + 1];
	std::strcpy(hobby, ho);
	strcpy(name, nm);
	weight = wt;
}

Cow::Cow()
{
	len = 4;
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
	name[0] = '\0';
}

Cow::Cow(const Cow& c)
{
	len = c.len;
	hobby = new char[len + 1];
	std::strcpy(hobby, c.hobby);
	strcpy(name, c.name);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	delete[] hobby;
	len = c.len;
	hobby = new char[len + 1];
	std::strcpy(hobby, c.hobby);
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	if(weight !=0)
	cout << name<<" likes "<<hobby<<" and weight "<< weight;
}