#pragma once
#ifndef TV_H_
#define TV_H_

class Tv // телевизор
{
public:
	friend class Remote;
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
	void change_remotemode(Remote& r);
private:
	int state; // вкл/выкл
	int volume; // громкость
	int maxchannel; //макс каналов
	int channel; // текущий канал
	int mode; //жфирное или кабельное тв
	int input; // тв или двд
};

class Remote // пульт
{
public:
	friend class Tv;
	Remote(int m = Tv::TV) : mode(m) {}
	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }
	void view_mode();
private:
	int mode;
	bool remotemode;
};

#endif // !TV_H_
