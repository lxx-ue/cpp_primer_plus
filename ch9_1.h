#pragma once

const int gLen = 40;
struct golf
{
	char fullname[gLen];
	int handicap;
};

void setGolf(golf& g, const char* name, int hc);
void setGolf(golf& g);
void handicap(golf& g, int hc);
void showGolf(const golf& g);