#include "ch14_5.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

abstr_emp::abstr_emp()
{
	fname = lname = job = "none";
}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j)
{
	fname = fn;
	lname = ln;
	job = j;
}

void abstr_emp::ShowAll() const
{
	cout << "First name: " << fname << "\nLast name: " << lname << "\nJob: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "Enter job: ";
	cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "First name: " << e.fname << "\nLast name: " << e.lname << "\nJob: " << e.job;
	return os;
}


employee::employee() : abstr_emp() {}

employee::employee(const string& fn, const string& ln, const string& j)
	: abstr_emp(fn, ln, j) {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}


manager::manager() : abstr_emp(), inchargeof(0) {}

manager::manager(const string& fn, const string& ln, const string& j, int ico = 0)
	: abstr_emp(fn, ln, j), inchargeof(0) {}

manager::manager(const abstr_emp& e, int ico)
	: abstr_emp(e), inchargeof(0) {}

manager::manager(const manager& m)
	: abstr_emp(m), inchargeof(0) {}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << inchargeof << endl;
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> inchargeof;
}


fink::fink() : abstr_emp(), reportsto("none") {}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo)
	: abstr_emp(fn, ln, j), reportsto(rpo) {}

fink::fink(const abstr_emp& e, const string& rpo)
	: abstr_emp(e), reportsto(rpo) {}

fink::fink(const fink& e) : abstr_emp(e), reportsto("none") {}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "reportsto: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter reportsto: ";
	cin >> reportsto;
}

highfink::highfink() {}

highfink::highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico)
	: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}

highfink::highfink(const abstr_emp& e, const string& rpo, int ico)
	: abstr_emp(e), manager(e, ico), fink(e, rpo) {}

highfink::highfink(const fink& f, int ico)
	: abstr_emp(f), manager(f, ico), fink(f) {}

highfink::highfink(const manager& m, const string& rpo)
	: abstr_emp(m), manager(m), fink(m, rpo) {}

highfink::highfink(const highfink& h) 
	: abstr_emp(h), manager(h, 0), fink(h, "none") {}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout << "inchargeof: " << manager::InChargeOf() << endl;
	cout << "reportsto: " << fink::ReportsTo() << endl;
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Enter inchargeof: ";
	cin >> manager::InChargeOf();
	cout << "Enter reportsto: ";
	cin >> fink::ReportsTo();
}