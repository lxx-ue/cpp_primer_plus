#pragma once
#ifndef dynamic_stack_temp
#define dynamic_stack_temp

template <class Type>
class DynamicTemplateStack
{
	enum { SIZE = 10 };
	int stacksize;
	Type* items;
	int top;
public:
	explicit DynamicTemplateStack(int ss = SIZE);
	DynamicTemplateStack(const DynamicTemplateStack& dts);
	~DynamicTemplateStack() { delete[] items; }
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const Type& item);
	bool pop(Type& item);
	DynamicTemplateStack& operator=(const DynamicTemplateStack& dts);
};

template <class Type>
DynamicTemplateStack<Type>::DynamicTemplateStack(int ss) : stacksize(ss), top(0)
{
	items = new Type[stacksize];
}

template <class Type>
DynamicTemplateStack<Type>::DynamicTemplateStack(const DynamicTemplateStack & dts)
{
	stacksize = dts.stacksize;
	top = dts.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = dts.items[i];
}

template <class Type>
bool DynamicTemplateStack<Type>::push(const Type& item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return true;
	}
	else return false;
}

template <class Type>
bool DynamicTemplateStack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else return false;
}

template <class Type>
DynamicTemplateStack<Type>& DynamicTemplateStack<Type>::operator=(const DynamicTemplateStack<Type>& dts)
{
	if (this == &dts) return *this;
	delete[] items;
	stacksize = dts.stacksize;
	top = dts.top;
	items = new Type[stacksize];
	for (int i = 0; i < top; i++)
		items[i] = dts.items[i];
	return *this;
}
#endif // !dynamic_stack_temp
