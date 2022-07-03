#pragma once
#include <iostream>
#include <stdexcept>

class base_exc : public std::logic_error
{
protected:
	double v1;
	double v2;
public:
	explicit base_exc(double a = 0, double b = 0, const std::string& s = "Index error in base_exc object\n")
		:v1(a), v2(b), std::logic_error(s) {}
};

class bad_hmean2 : public base_exc
{
public:
	//bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	explicit bad_hmean2(double a = 0, double b = 0, const std::string& s = "Index error in bad_hmean object\n")
		:base_exc(a, b, s) {}
	virtual const char* what() const noexcept
	{
		std::cout << "hmean(" << v1 << ", " << v2 << "): ivalid arguments: a=-b\n";
		return 		logic_error::what();
	}
};

class bad_gmean2 : public base_exc
{
public:
	explicit bad_gmean2(double a = 0, double b = 0, const std::string& s = "Index error in bad_gmean object\ngmean() arguments shold be >=0\n")
		:base_exc(a, b, s) {}
};