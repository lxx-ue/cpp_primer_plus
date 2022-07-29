#include "ch14_5.h"
#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;


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

void abstr_emp::WriteAll(ofstream& fout)
{
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
void employee::WriteAll(ofstream& fout)
{
	fout << 0 << " " << fname << " " << lname << " " << job << endl;
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
void manager::WriteAll(ofstream& fout)
{
	fout << 1 << " " << fname << " " << lname << " " << job << " " << inchargeof << endl;
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
void fink::WriteAll(ofstream& fout)
{
	fout << 2 << " " << fname << " " << lname << " " << job << " " << reportsto << endl;
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
void highfink::WriteAll(ofstream& fout)
{
	fout << 3 << " " << fname << " " << lname << " " << job << " " << inchargeof << reportsto << endl;
}