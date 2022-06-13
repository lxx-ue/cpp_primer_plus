#include <iostream>
#include "ch13_1.h"
using std::cout;
using std::endl;

Cd::Cd() {
	performers[0] = '\0';
	label[0] = '\0';
	selections = 0;
	playtime = 0.0;
}

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::~Cd()
{

}

void Cd::Report() const
{
	cout << "performers: " << performers
		<< " label: " << label
		<< " selections: " << selections
		<< " playtime: " << playtime << endl;
}

Cd& Cd::operator=(const Cd& d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic()
{
	song[0] = '\0';
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x)
	: Cd(s2, s3, n, x)
{
	strcpy(song, s1);
}

Classic::Classic(const Classic& c) 
	: Cd(c)
{
	strcpy(song, c.song);
}

Classic::~Classic()
{

}

void Classic::Report() const
{
	Cd::Report();
	cout << " song " << song << endl;
}