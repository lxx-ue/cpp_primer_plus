#include <iostream>
#include "ch9_4.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[])
	{
		for (int i = 0; i < QUARTERS; i++)
		{
			s.sales[i] = ar[i];
		}
		setSales(s);
	}
	void setSales(Sales& s)
	{
		double min = s.sales[0], max = s.sales[0], avg = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			avg += s.sales[i];
			if (min > s.sales[i]) min = s.sales[i];
			if (max < s.sales[i]) max = s.sales[i];
		}
		avg /= 4;
		s.average = avg;
		s.max = max;
		s.min = min;
		showSales(s);
	}
	void showSales(const Sales& s)
	{
		using std::cout;
		using std::endl;
		cout << s.sales[0] << " " << s.sales[1];
		cout<< " " << s.sales[2] << " " << s.sales[3];
		cout << "\taverage=" << s.average << "\tmax=";
		cout << s.max << "\tmin=" << s.min << endl;
	}
}