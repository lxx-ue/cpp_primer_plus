#include <iostream>
#include "ch13_1.h"
using std::cout;
using std::endl;

Cd::Cd() {
	performers = new char[1];
	performers[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[std::strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[std::strlen(s2) + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[std::strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[std::strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d) return *this;
	delete[] performers;
	delete[] label;
	performers = new char[std::strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[std::strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

void Cd::Report() const
{
	cout << "performers: " << performers
		<< " label: " << label
		<< " selections: " << selections
		<< " playtime: " << playtime << endl;
}

Classic::Classic()
{
	song = new char[1];
	song[0] = '\0';
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
	: Cd(s2, s3, n, x)
{
	song = new char[std::strlen(s1) + 1];
	strcpy(song, s1);
}

Classic::Classic(const Classic& c) 
	: Cd(c)
{
	song = new char[std::strlen(c.song) + 1];
	strcpy(song, c.song);
}

Classic::~Classic()
{
	delete[] song;
}

void Classic::Report() const
{
	Cd::Report();
	cout << " song " << song << endl;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c) return *this;
	Cd::operator=(c);
	delete[] song;
	song = new char[std::strlen(c.song) + 1];
	strcpy(song, c.song);
	return *this;
}