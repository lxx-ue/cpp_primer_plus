#include <iostream>
using std::cout;
using std::cin;
#include "ch11_6.h"

Complex0::Complex0()
{
	a = 0.0;
	bi = 0.0;
}

Complex0::Complex0(double a, double bi)
{
	this->a = a;
	this->bi = bi;
}

Complex0 Complex0::operator+(const Complex0& b) const
{
	return Complex0(this->a + b.a, this->bi + b.bi);
}

Complex0 Complex0::operator-(const Complex0& b) const
{
	return Complex0(this->a - b.a, this->bi - b.bi);
}

Complex0 Complex0::operator*(const Complex0& b) const
{
	return Complex0(this->a * b.a - this->bi * b.bi, this->a * b.bi + bi * b.a);
}

Complex0 Complex0::operator*(double n) const
{
	return Complex0(this->a * n, this->bi * n);
}

Complex0 operator*(double n, const Complex0& a)
{
	return a * n;
}

Complex0 Complex0::operator-() const
{
	return Complex0(a, -bi);
}

std::ostream& operator <<(std::ostream& os, const Complex0& cx)
{
	return os << "(" << cx.a << ", " << cx.bi << "i)";
}

std::istream& operator >>(std::istream& ios, Complex0& cx)
{
	cout << "real: "; ios >> cx.a;
	cout << "imaginary: "; ios >> cx.bi;
	return ios;
}