#pragma once
#ifndef complex0
#define complex0
class Complex0
{
public:
	Complex0(double a, double bi);
	Complex0();

	Complex0 operator+(const Complex0& b) const;
	Complex0 operator-(const Complex0& b) const;
	Complex0 operator*(const Complex0& b) const;
	Complex0 operator*(double n) const;
	friend Complex0 operator*(double n, const Complex0& a);
	Complex0 operator-() const;

	friend std::ostream& operator<<(std::ostream& os, const Complex0& s);
	friend std::istream& operator>>(std::istream& os, Complex0& s);

private:
	double a;
	double bi;
};
#endif // !complex0
