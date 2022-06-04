#include "ch12_4.h"
#include <iostream>
using std::cout;
using std::endl;

Stack1::Stack1(int n)
{
	if (n < 0)
	{
		cout << "Stack size cant be negative. Set at 1\n";
		pitems = new Item[1];
	}
	else if (n > MAX)
	{
		cout << "Stack size cant more then " << MAX << ". Set at " << MAX << endl;
		pitems = new Item[MAX];
	}
	else pitems = new Item[n];
	top = 0;
}

Stack1::Stack1(const Stack1& st)
{
	size = st.size;
	pitems = new Item[size]; 
	for (int i = 0; i < size; i++) {
		pitems[i] = st.pitems[i];
	}
	top = st.top;
}

Stack1::~Stack1()
{
	delete[] pitems;
}

Stack1& Stack1::operator=(const Stack1& st)
{
	if (this == &st) return *this;
	delete[] pitems;
	size = st.size;
	pitems = new Item[size];
	for (int i = 0; i < size; i++) {
		pitems[i] = st.pitems[i];
	}
	top = st.top;
	return *this;
}

bool Stack1::is_empty() const
{
	return top == 0;
}

bool Stack1::is_full() const
{
	return top == MAX;
}

bool Stack1::push(const Item& item)
{
	if (top < MAX)
	{
		pitems[top++] = item;
		return true;
	}
	else return false;
}

bool Stack1::pop(Item& item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else return false;
}
