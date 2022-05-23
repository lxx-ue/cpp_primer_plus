#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR
{
	class Vector
	{
	public:
		enum class Mode{RECT, POL};
		Vector();
		Vector(double n1, double n2, Mode form = Mode::RECT);
		~Vector();
		void reset(double n1, double n2, Mode form = Mode::RECT);
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const;
		double angval() const;
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);

	private:
		double x;
		double y;
		Mode mode;
		void set_x(double n1, double n2);
		void set_y(double n1, double n2);
	};
}

#endif // !VECTOR_H_
