#include "ch14_5.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;


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

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}


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