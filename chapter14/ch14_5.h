#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ofstream;

class abstr_emp
{
protected:
	string fname;
	string lname;
	string job;
public:
	abstr_emp() : fname("none"), lname("none"), job("none") {}
	abstr_emp(const string& fn, const string& ln, const string& j)
		: fname(fn), lname(ln), job(j) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream& fout);
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
};

class employee : public abstr_emp
{
public:
	employee() : abstr_emp() {}
	employee(const string& fn, const string& ln, const string& j)
		: abstr_emp(fn, ln, j) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream& fout);
};

class manager : virtual public abstr_emp
{
protected:
	int inchargeof;
protected:
	int InChargeOf() const { return inchargeof; }
	int& InChargeOf() { return inchargeof; }
public:
	manager() : abstr_emp(), inchargeof(0) {}
	manager(const string& fn, const string& ln, const string& j, int ico = 0)
		: abstr_emp(fn, ln, j), inchargeof(ico) {}
	manager(const abstr_emp& e, int ico) 
		: abstr_emp(e), inchargeof(ico) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream& fout);
};

class fink : virtual public abstr_emp
{
protected:
	string reportsto;
protected:
	const string ReportsTo() const { return reportsto; }
	string& ReportsTo() { return reportsto; }
public:
	fink() : abstr_emp(), reportsto("none") {}
	fink(const string& fn, const string& ln, const string& j, const string& rpo)
		: abstr_emp(fn, ln, j), reportsto(rpo) {}
	fink(const abstr_emp& e, const string& rpo)
		: abstr_emp(e), reportsto(rpo) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream& fout);
};

class highfink : public manager, public fink
{
public:
	highfink() {}
	highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico)
		: abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
	highfink(const abstr_emp& e, const string& rpo, int ico)
		: abstr_emp(e), manager(e, ico), fink(e, rpo) {}
	highfink(const fink& f, int ico)
		: abstr_emp(f), manager(f, ico), fink(f) {}
	highfink(const manager& m, const string& rpo)
		: abstr_emp(m), manager(m), fink(m, rpo) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream& fout);
};