#pragma once
#ifndef QUEUETP_H_
#define QUEUETP_H_

template <class Item>
class queueTP
{
	enum { Q_SIZE = 10 };
	class Node
	{
	public:
		Item item;
		Node* next;
		Node(const Item& i) : item(i), next(0) {}
	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	queueTP(const queueTP& q) : qsize(0) {}
	queueTP& operator=(const queueTP& q) { return *this; }
public:
	queueTP(int qs = Q_SIZE);
	~queueTP();
	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }
	int queuecount() const { return items; }
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

template <class Item>
queueTP<Item>::queueTP(int qs) : qsize(qs)
{
	front = rear = 0;
	items = 0;
}

template <class Item>
queueTP<Item>::~queueTP()
{
	Node* temp;
	while (front != 0)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <class Item>
bool queueTP<Item>::enqueue(const Item& item)
{
	if (isfull()) return false;
	Node* add = neq Node(item);
	items++;
	if (front == 0) front = add;
	else rear->next = add;
	rear = add;
	return true;
}

template <class Item>
bool queueTP<Item>::dequeue(Item& item)
{
	if (front == 0) return false;
	item = front->item;
	item--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0) rear = 0;
	return true;
}
#endif // !QUEUETP_H_
