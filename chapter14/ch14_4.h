#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

class Person14
{
	string name;
	string lastname;
public:
	Person14() : name("none "), lastname("none ") {}
	Person14(const string& n, const string& l) : name(n), lastname(l) {}
	Person14(const Person14& p) : name(p.name), lastname(p.lastname) {}
	virtual ~Person14() {}
	void Show() const { cout << "Name: " << name << "\nLastname: " << lastname << endl; }
};

class Gunslinger : virtual public Person14
{
	double start_time;
	int notches;
public:
	Gunslinger() {}
	Gunslinger(const string& n, const string& l, const int s = 0 , const int nn = 0 )
		: Person14(n, l), start_time(s), notches(nn) {}
	Gunslinger(const Person14& p, const int s = 0, const int nn = 0)
		: Person14(p), start_time(s), notches(nn) {}
	virtual ~Gunslinger() {}
	void Draw() const { cout << "Start to ready: " << start_time << endl; }
	void Show() const { Person14::Show();	Draw();  cout << "Notches on the rifle: " << notches << endl; }
	double get_start_time() { return start_time; }
};

class PokerPlayer : virtual public Person14
{
public:
	PokerPlayer() {}
	PokerPlayer(const string& n, const string& l) : Person14(n, l) {}
	PokerPlayer(const Person14& p) : Person14(p) {}
	virtual ~PokerPlayer() {}
	int Draw() const { std::srand(std::time(0)); rand() % 52 + 1; }
	void Show() const { Person14::Show(); }
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(const string& n, const string& l, const int s = 0, const int nn = 0)
		: Gunslinger(n, l, s ,nn) {}
	BadDude(const Gunslinger& g) : Gunslinger(g) {}
	double GDraw() { return Gunslinger::get_start_time(); }
	int CDraw() { return PokerPlayer::Draw(); }
	void Show() const { Gunslinger::Show(); }
};