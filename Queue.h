#pragma once
#include "List.cpp"

template<class T>
class Queue
{
	List<T> elements;
public:
	Queue();
	~Queue();

	void Enqueue(T element);
	void Dequeue();

	T Front();

	bool isEmpty();
};

