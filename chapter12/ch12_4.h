#pragma once
#ifndef stack1
#define stack1

typedef unsigned long Item;
class Stack1
{
private:
	static const int MAX = 10;
	Item* pitems;
	int size;
	int top;
public:
	Stack1(int n = 10);
	Stack1(const Stack1& st);
	~Stack1();
	bool is_empty() const;
	bool is_full() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack1& operator=(const Stack1& st);
};
#endif // !stack1