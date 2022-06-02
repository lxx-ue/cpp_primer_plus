#pragma once
#ifndef cow
#define cow
class Cow
{
	char name[20];
	int len;
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm, const char* ho, double wt);
	Cow(const Cow &c);
	~Cow();
	Cow& operator=(const Cow&);
	void ShowCow() const;
};
#endif // !cow