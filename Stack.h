#pragma once
#include "List.cpp"

template<class T>
class Stack
{
	List<T> elements;
public:
	Stack();
	~Stack();

	void Push(T element);
	void Pop();

	T Top();

	bool isEmpty();
};

