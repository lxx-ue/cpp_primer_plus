#pragma once
#ifndef stack_temp
#define stack_temp

template <class Type>
class TemplateStack
{
	enum { MAX = 10 };
	Type items[MAX];
	int top;
public:
	TemplateStack();
	bool isempty();
	bool isfull();
	bool push(const Type& item);
	bool pop(Type& item);
};

template <class Type>
TemplateStack<Type>::TemplateStack()
{
	top = 0;
}

template <class Type>
bool TemplateStack<Type>::isempty()
{
	return top == 0;
}

template <class Type>
bool TemplateStack<Type>::isfull()
{
	return top == MAX;
}

template <class Type>
bool TemplateStack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else return false;
}

template <class Type>
bool TemplateStack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else return false;
}


#endif // !stack_temp
