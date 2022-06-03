#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
	return num_strings;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

String::String()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

String::String(const String& st)
{
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	num_strings++;
}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

String& String::operator+=(const String& st)
{

	int size = len + st.len;
	char* ts = new char[size + 1];
	for (int i = 0; i < len; i++)
		ts[i] = str[i];
	for (int i = len, j=0; i < size; i++, j++)
		ts[i] = st.str[j];
	ts[size] = '\0';
	*this = ts;
	return *this;
}

String operator+(const String& rls, const String& rrs)
{
	String ts = rls;
	return ts += rrs;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
	return st2.str < st1.str;
}

bool operator==(const String& st1, const String& st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

void String::string_low()
{
	for (int i = 0; i < len; i++) 
		if (isupper(str[i])) 
			str[i] = tolower(str[i]);
}

void String::string_up()
{
	for (int i = 0; i < len; i++) 
		if (islower(str[i])) 
			str[i] = toupper(str[i]);
}

int String::has(char c)
{
	int count = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == c) 
			count++;
	return count;
}