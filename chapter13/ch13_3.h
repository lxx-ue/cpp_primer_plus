#pragma once
#ifndef dma
#define dma
#include <iostream>

class BaseDMA
{
	char* label;
	int rating;
public:
	BaseDMA(const char* l = "null", int r = 0);
	BaseDMA(const BaseDMA& rs);
	virtual ~BaseDMA();
	BaseDMA& operator=(const BaseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const BaseDMA& rs);
};

class LacksDMA : public BaseDMA
{
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	LacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	LacksDMA(const char* c, const BaseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const LacksDMA& rs);
};

class HasDMA : public BaseDMA
{
	char* style;
public:
	HasDMA(const char* s = "none", const char* l = "null", int r = 0);
	HasDMA(const char* s, const BaseDMA& rs);
	HasDMA(const HasDMA& hs);
	~HasDMA();
	HasDMA& operator=(const HasDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const HasDMA& rs);
};
#endif // !dma
