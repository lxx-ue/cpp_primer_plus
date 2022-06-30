#pragma once
#ifndef TV_H_
#define TV_H_

class Tv; // телевизор
class Remote // пульт
{
public:
	enum { Off, On };
	enum { Minval, Maxval = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
public:
	Remote(int m = TV) : mode(m) {}
	bool volup(Tv& t);
	bool voldown(Tv& t);
	void onoff(Tv& t);
	void chanup(Tv& t);
	void chandown(Tv& t);
	void set_chan(Tv& t, int c);
	void set_mode(Tv& t);
	void set_input(Tv& t);
private:
	int mode;
};

class Tv // телевизор
{
public:
	friend void Remote::set_chan(Tv& t, int c);
	enum { Off, On };
	enum { Minval, Maxval = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) :state(s), volume(5),
		maxchannel(mc), channel(12), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;
private:
	int state; // вкл/выкл
	int volume; // громкость
	int maxchannel; //макс каналов
	int channel; // текущий канал
	int mode; //жфирное или кабельное тв
	int input; // тв или двд
};

inline bool Remote::volup(Tv& t) { return t.volup(); }
inline bool Remote::voldown(Tv& t) { return t.voldown(); }
inline void Remote::onoff(Tv& t) { t.onoff(); }
inline void Remote::chanup(Tv& t) { t.chanup(); }
inline void Remote::chandown(Tv& t) { t.chandown(); }
inline void Remote::set_chan(Tv& t, int c) { t.channel = c; }
inline void Remote::set_mode(Tv& t) { t.set_mode(); }
inline void Remote::set_input(Tv& t) { t.set_input(); }

#endif // !TV_H_
