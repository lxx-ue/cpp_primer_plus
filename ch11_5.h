#pragma once
#ifndef stonewt
#define stonewt
class Stonewt
{
public:
	enum class Mode { stn, lbs };
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	void set_mode(Mode m) { mode = m; }
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
	void show_lbs() const;
	void show_stn() const;
};
#endif // !stonewt
