#include <iostream>
#include "ch13_4.h"

Port::Port(const char* br, const char* st, int b)
{
	brand = new char[std::strlen(br) + 1];
	std::strcpy(brand, br);
	std::strcpy(style, st);
	bottles = b;
}

Port::Port(const Port& p)
{
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
}

Port& Port::operator=(const Port& p)
{
	if (this == &p) return *this;
	delete[] brand;
	brand = new char[std::strlen(p.brand) + 1];
	std::strcpy(brand, p.brand);
	std::strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}

void Port::Show() const
{
	cout << "Brand: " << brand << endl
		<< "Kind: " << style << endl
		<< "Bottles: " << bottles << endl;
}
ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}


VintagePort::VintagePort() : Port()
{
	const char* n = "none";
	nickname = new char[std::strlen(n) + 1];
	std::strcpy(nickname, n);
	year = 0;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y) 
	: Port(br, "vintage", b)
{
	nickname = new char[std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp)
{
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp) return *this;
	delete[] nickname;
	nickname = new char[std::strlen(vp.nickname) + 1];
	std::strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	cout << "Nickname: " << nickname << endl
		<< "Year: " << year << endl;
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << (const Port&)vp << ", ";
	os << vp.nickname << ", " << vp.year;
	return os;
}