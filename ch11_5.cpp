#include <iostream>
using std::cout;
#include "ch11_5.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = Mode::lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = Mode::stn;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode = Mode::lbs;
}

Stonewt::~Stonewt() {}

void Stonewt::show_stn() const
{
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
	cout << pounds << " pounds\n";
}

std::ostream& operator <<(std::ostream& os, const Stonewt& s)
{
	if (s.mode == Stonewt::Mode::lbs)
	{
		s.show_lbs();
	}
	else if (s.mode == Stonewt::Mode::stn)
	{
		s.show_stn();
	}
	else
	{
		os << "Stonewt object mode is invalid";
	}
	return os;
}

bool Stonewt::operator==(const Stonewt& st) const
{
	return pounds == st.pounds;
}

