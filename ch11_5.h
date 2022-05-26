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
	void show_lbs() const;
	void show_stn() const;
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
};
#endif // !stonewt
