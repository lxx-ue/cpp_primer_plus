#include <cmath>
#include "ch11_1.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double rad_to_deg = 45.0 / atan(1.0);

	void Vector::set_x(double n1, double n2)
	{
		x = n1 * cos(n2);
	}

	void Vector::set_y(double n1, double n2)
	{
		y = n1 * sin(n2);
	}

	Vector::Vector()
	{
		x = y = 0.0;
		mode = Mode::RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == Mode::RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == Mode::POL)
		{
			set_x(n1, n2);
			set_y(n1, n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
			x = y = 0.0;
			mode = Mode::RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == Mode::RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == Mode::POL)
		{
			set_x(n1, n2);
			set_y(n1, n2);
		}
		else
		{
			cout << "Incorrect 3rd argument to Vector() -- vector set to 0\n";
			x = y = 0.0;
			mode = Mode::RECT;
		}
	}

	Vector::~Vector() {}

	void Vector::polar_mode()
	{
		mode = Mode::POL;
	}

	void Vector::rect_mode()
	{
		mode = Mode::RECT;
	}

	double Vector::magval() const
	{
		return sqrt(x * x + y * y);
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
			return 0;
		else
			return atan2(y, x);
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x * n, y * n);
	}

	Vector operator*(double n, const Vector & a)
	{
		return a * n;
	}

	std::ostream& operator <<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::Mode::RECT)
		{
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		}
		else if (v.mode == Vector::Mode::POL)
		{
			os << "(m, a) = (" << v.magval() << ", " << v.angval() * rad_to_deg << ")";
		}
		else
		{
			os << "Vector object mode is invalid";
		}
		return os;
	}
}

